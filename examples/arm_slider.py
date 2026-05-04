#!/usr/bin/env python3
"""
arm_slider.py — Tkinter GUI for direct arm and waist joint control.

Motor IDs:
  Left arm : 11-17  (shoulder pitch/roll/yaw, elbow, wrist yaw/pitch/roll)
  Right arm: 21-27  (shoulder pitch/roll/yaw, elbow, wrist yaw/pitch/roll)
  Waist    : 31

Arm motors (11-17, 21-27) are commanded via /arm/cmd_ctrl (CmdMotorCtrl – MIT mode).
Waist motor (31) is commanded via /waist/cmd_pos (CmdSetMotorPosition).

IMPORTANT: The rl_control node takes over arm commands during locomotion.
Click "STOP MOTION" first to release arm control before moving the sliders.
"""

import threading
import tkinter as tk
from tkinter import ttk

import rclpy
from rclpy.node import Node

from bodyctrl_msgs.msg import (
    CmdMotorCtrl, MotorCtrl,
    CmdSetMotorPosition, SetMotorPosition,
    MotorStatusMsg,
)
from hric_msgs.srv import SetMotionMode


ERROR_MAP = {
    0: "OK",
    33072: "Disconnected",
    33073: "OutLimit",
    1: "Overheat",
    2: "Overcurrent",
    3: "Undervoltage",
    4: "MOS Overheat",
    5: "Stall",
    6: "Overvoltage",
    7: "Phase loss",
    8: "Encoder",
}

# Joint names (from tiangong2.0_pro.xml diagnose config)
LEFT_ARM_NAMES = [
    "L Shoulder pitch",
    "L Shoulder roll",
    "L Shoulder yaw",
    "L Elbow flex",
    "L Wrist yaw",
    "L Wrist pitch",
    "L Wrist roll",
]
RIGHT_ARM_NAMES = [
    "R Shoulder pitch",
    "R Shoulder roll",
    "R Shoulder yaw",
    "R Elbow flex",
    "R Wrist yaw",
    "R Wrist pitch",
    "R Wrist roll",
]

# Conservative joint limits in radians (±π from motor param files)
ARM_LIMITS = [(-3.14, 3.14)] * 7

WAIST_LIMITS = (-0.8, 0.8)


class ArmSliderGUI(Node):
    def __init__(self):
        super().__init__('arm_slider_gui')

        # publishers
        self.arm_pub = self.create_publisher(CmdMotorCtrl, '/arm/cmd_ctrl', 10)
        self.waist_pub = self.create_publisher(CmdSetMotorPosition, '/waist/cmd_pos', 10)

        # subscribers
        self.create_subscription(MotorStatusMsg, '/arm/status', self._arm_status_cb, 10)
        self.create_subscription(MotorStatusMsg, '/waist/status', self._waist_status_cb, 10)

        # service client to stop motion / release arm control
        self._motion_client = self.create_client(
            SetMotionMode, '/hric/motion/set_motion_mode'
        )

        # motor IDs
        self.left_ids  = list(range(11, 18))   # 11-17
        self.right_ids = list(range(21, 28))    # 21-27
        self.waist_ids = [31]

        # desired positions (radians)
        self.left_pos  = [0.0] * 7
        self.right_pos = [0.0] * 7
        self.waist_pos = [0.0]

        # MIT control parameters
        self.arm_kp = 100.0
        self.arm_kd = 5.0

        # waist speed
        self.waist_speed = 0.2

        # initialization flags – wait for first status message before publishing
        self.left_initialized  = [False] * 7
        self.right_initialized = [False] * 7
        self.waist_initialized = [False]

        # publish at 20 Hz
        self.timer = self.create_timer(0.05, self._publish)

        self._build_gui()

    # -------------------------------------------------------------------------
    # GUI
    # -------------------------------------------------------------------------

    def _build_gui(self):
        self.root = tk.Tk()
        self.root.title("Arm + Waist Control")

        # ── top bar: motion control ──────────────────────────────────────────
        top = tk.Frame(self.root, bg='#222')
        top.pack(fill='x', padx=4, pady=4)

        tk.Button(
            top, text="STOP MOTION (release arms)",
            bg='#cc2222', fg='white', font=('Arial', 10, 'bold'),
            height=2, command=self._stop_motion,
        ).pack(side='left', padx=8, pady=4)

        self._motion_status_var = tk.StringVar(value='motion: —')
        tk.Label(
            top, textvariable=self._motion_status_var,
            bg='#222', fg='#ffff88', font=('Courier', 9), anchor='w',
        ).pack(side='left', padx=8)

        # ── three column layout ───────────────────────────────────────────────
        cols = tk.Frame(self.root)
        cols.pack(padx=4, pady=4)

        left_frame  = ttk.LabelFrame(cols, text="LEFT ARM  (motors 11-17)")
        left_frame.grid(row=0, column=0, padx=6, pady=4, sticky='n')

        right_frame = ttk.LabelFrame(cols, text="RIGHT ARM  (motors 21-27)")
        right_frame.grid(row=0, column=1, padx=6, pady=4, sticky='n')

        waist_frame = ttk.LabelFrame(cols, text="WAIST  (motor 31)")
        waist_frame.grid(row=0, column=2, padx=6, pady=4, sticky='n')

        # left arm
        self.left_sliders, self.left_status = self._build_arm_section(
            left_frame, LEFT_ARM_NAMES, ARM_LIMITS,
            setter=lambda i, v: self._set_left(i, v)
        )
        tk.Button(
            left_frame, text="ZERO LEFT ARM",
            command=self._zero_left,
        ).pack(fill='x', padx=4, pady=(4, 2))

        # right arm
        self.right_sliders, self.right_status = self._build_arm_section(
            right_frame, RIGHT_ARM_NAMES, ARM_LIMITS,
            setter=lambda i, v: self._set_right(i, v)
        )
        tk.Button(
            right_frame, text="ZERO RIGHT ARM",
            command=self._zero_right,
        ).pack(fill='x', padx=4, pady=(4, 2))

        # shared kp / kd below the arm columns
        gains_frame = ttk.LabelFrame(cols, text="MIT Gains (both arms)")
        gains_frame.grid(row=1, column=0, columnspan=2, padx=6, pady=4, sticky='ew')

        tk.Label(gains_frame, text="kp (position gain)").pack()
        self._kp_slider = tk.Scale(
            gains_frame, from_=0.0, to=500.0, resolution=1.0,
            orient=tk.HORIZONTAL, length=360, command=self._set_kp,
        )
        self._kp_slider.set(self.arm_kp)
        self._kp_slider.pack()

        tk.Label(gains_frame, text="kd (damping)").pack()
        self._kd_slider = tk.Scale(
            gains_frame, from_=0.0, to=50.0, resolution=0.1,
            orient=tk.HORIZONTAL, length=360, command=self._set_kd,
        )
        self._kd_slider.set(self.arm_kd)
        self._kd_slider.pack()

        # waist
        self._build_waist_section(waist_frame)

    def _build_arm_section(self, parent, names, limits, setter):
        sliders = []
        status_labels = []
        for i, (name, (lo, hi)) in enumerate(zip(names, limits)):
            tk.Label(parent, text=name, anchor='w', width=18).pack(anchor='w', padx=4)
            s = tk.Scale(
                parent, from_=lo, to=hi, resolution=0.01,
                orient=tk.HORIZONTAL, length=300,
                command=lambda v, idx=i: setter(idx, v),
            )
            s.pack()
            sliders.append(s)

            lbl = tk.Label(parent, text="--", font=("Courier", 9), anchor='w', width=55)
            lbl.pack(fill='x', padx=4, pady=(0, 4))
            status_labels.append(lbl)
        return sliders, status_labels

    def _build_waist_section(self, parent):
        tk.Label(parent, text="Waist yaw").pack()
        self._waist_slider = tk.Scale(
            parent,
            from_=WAIST_LIMITS[0], to=WAIST_LIMITS[1],
            resolution=0.01, orient=tk.HORIZONTAL, length=220,
            command=lambda v: self._set_waist(0, v),
        )
        self._waist_slider.pack()

        self._waist_status_lbl = tk.Label(
            parent, text="--", font=("Courier", 9), anchor='w', width=40,
        )
        self._waist_status_lbl.pack(fill='x', padx=4, pady=(0, 4))

        tk.Label(parent, text="Waist speed").pack()
        self._waist_speed_slider = tk.Scale(
            parent, from_=0.0, to=1.0, resolution=0.01,
            orient=tk.HORIZONTAL, length=220,
            command=lambda v: setattr(self, 'waist_speed', float(v)),
        )
        self._waist_speed_slider.set(self.waist_speed)
        self._waist_speed_slider.pack()

        tk.Button(parent, text="ZERO WAIST", command=self._zero_waist).pack(
            fill='x', padx=4, pady=(8, 2)
        )

    # -------------------------------------------------------------------------
    # Setters
    # -------------------------------------------------------------------------

    def _set_left(self, i, v):
        self.left_pos[i] = float(v)

    def _set_right(self, i, v):
        self.right_pos[i] = float(v)

    def _set_waist(self, i, v):
        self.waist_pos[i] = float(v)

    def _set_kp(self, v):
        self.arm_kp = float(v)

    def _set_kd(self, v):
        self.arm_kd = float(v)

    def _zero_left(self):
        for i, s in enumerate(self.left_sliders):
            s.set(0.0)
            self.left_pos[i] = 0.0

    def _zero_right(self):
        for i, s in enumerate(self.right_sliders):
            s.set(0.0)
            self.right_pos[i] = 0.0

    def _zero_waist(self):
        self._waist_slider.set(0.0)
        self.waist_pos[0] = 0.0

    # -------------------------------------------------------------------------
    # Publishing
    # -------------------------------------------------------------------------

    def _publish(self):
        # arm cmd_ctrl (MIT mode)
        if all(self.left_initialized) and all(self.right_initialized):
            msg = CmdMotorCtrl()
            msg.cmds = []
            for i, mid in enumerate(self.left_ids):
                c = MotorCtrl()
                c.name = mid
                c.kp   = float(self.arm_kp)
                c.kd   = float(self.arm_kd)
                c.pos  = float(self.left_pos[i])
                c.spd  = 0.0
                c.tor  = 0.0
                msg.cmds.append(c)
            for i, mid in enumerate(self.right_ids):
                c = MotorCtrl()
                c.name = mid
                c.kp   = float(self.arm_kp)
                c.kd   = float(self.arm_kd)
                c.pos  = float(self.right_pos[i])
                c.spd  = 0.0
                c.tor  = 0.0
                msg.cmds.append(c)
            self.arm_pub.publish(msg)

        # waist cmd_pos
        if all(self.waist_initialized):
            msg = CmdSetMotorPosition()
            msg.cmds = []
            c = SetMotorPosition()
            c.name = self.waist_ids[0]
            c.pos  = float(self.waist_pos[0])
            c.spd  = float(self.waist_speed)
            c.cur  = 8.0
            msg.cmds.append(c)
            self.waist_pub.publish(msg)

    # -------------------------------------------------------------------------
    # Status callbacks
    # -------------------------------------------------------------------------

    def _arm_status_cb(self, msg):
        for st in msg.status:
            err = ERROR_MAP.get(st.error, str(st.error))
            text = (
                f"pos {st.pos:6.3f}  spd {st.speed:5.2f}  "
                f"cur {st.current:5.2f}A  tmp {st.temperature:5.1f}°C  {err}"
            )

            if st.name in self.left_ids:
                i = self.left_ids.index(st.name)
                if not self.left_initialized[i]:
                    self.left_sliders[i].set(st.pos)
                    self.left_pos[i] = st.pos
                    self.left_initialized[i] = True
                self.left_status[i].config(text=text)

            elif st.name in self.right_ids:
                i = self.right_ids.index(st.name)
                if not self.right_initialized[i]:
                    self.right_sliders[i].set(st.pos)
                    self.right_pos[i] = st.pos
                    self.right_initialized[i] = True
                self.right_status[i].config(text=text)

    def _waist_status_cb(self, msg):
        for st in msg.status:
            if st.name in self.waist_ids:
                err = ERROR_MAP.get(st.error, str(st.error))
                text = (
                    f"pos {st.pos:6.3f}  spd {st.speed:5.2f}  "
                    f"cur {st.current:5.2f}A  tmp {st.temperature:5.1f}°C  {err}"
                )
                if not self.waist_initialized[0]:
                    self._waist_slider.set(st.pos)
                    self.waist_pos[0] = st.pos
                    self.waist_initialized[0] = True
                self._waist_status_lbl.config(text=text)

    # -------------------------------------------------------------------------
    # Motion service
    # -------------------------------------------------------------------------

    def _stop_motion(self):
        if not self._motion_client.service_is_ready():
            self._motion_status_var.set('motion: service not available')
            return
        self._motion_status_var.set('motion: stopping…')
        req = SetMotionMode.Request()
        req.walk_mode_request = SetMotionMode.Request.STOP   # 1
        req.is_need_swing_arm = False
        threading.Thread(target=self._do_stop_motion, args=(req,), daemon=True).start()

    def _do_stop_motion(self, req):
        future = self._motion_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.done() and future.result() is not None:
            resp = future.result()
            if resp.success:
                result = 'motion: STOPPED — arms released'
            else:
                result = f'motion: STOP failed (err={resp.error_code})'
        else:
            result = 'motion: STOP timeout'
        self.root.after(0, lambda: self._motion_status_var.set(result))

    # -------------------------------------------------------------------------
    # Main loop
    # -------------------------------------------------------------------------

    def spin(self):
        while rclpy.ok():
            self.root.update()
            rclpy.spin_once(self, timeout_sec=0.0)


def main():
    rclpy.init()
    node = ArmSliderGUI()
    try:
        node.spin()
    except tk.TclError:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
