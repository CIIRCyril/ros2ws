#!/usr/bin/env python3
"""
leg_slider.py — Tkinter GUI for direct leg joint control.

Motor IDs:
  Left leg : 51-56  (hip roll/yaw/pitch, knee flex, ankle pitch/roll)
  Right leg: 61-66  (hip roll/yaw/pitch, knee flex, ankle pitch/roll)

Leg control modes:
  MIT      — /leg/cmd_ctrl  (CmdMotorCtrl)         kp/kd PD position control
  Position — /leg/cmd_pos   (CmdSetMotorPosition)  trapezoidal profile to target pos
  Speed    — /leg/cmd_spd   (CmdSetMotorSpeed)     constant velocity per joint

WARNING: Never command leg joints while the robot is standing without support.
         Click "STOP MOTION" first to stop the locomotion controller.
"""

import threading
import tkinter as tk
from tkinter import ttk

import rclpy
from rclpy.node import Node

from bodyctrl_msgs.msg import (
    CmdMotorCtrl, MotorCtrl,
    CmdSetMotorPosition, SetMotorPosition,
    CmdSetMotorSpeed, SetMotorSpeed,
    MotorStatusMsg,
)
from hric_msgs.srv import SetMotionMode

# Leg control modes
MODE_MIT      = "MIT"
MODE_POSITION = "Position"
MODE_SPEED    = "Speed"


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

# Joint names (from tiangong2.0_pro.xml / motor_legs.yaml)
LEFT_LEG_NAMES = [
    "L Hip roll",
    "L Hip yaw",
    "L Hip pitch",
    "L Knee flex",
    "L Ankle pitch",
    "L Ankle roll",
]
RIGHT_LEG_NAMES = [
    "R Hip roll",
    "R Hip yaw",
    "R Hip pitch",
    "R Knee flex",
    "R Ankle pitch",
    "R Ankle roll",
]

# Conservative joint limits in radians
LEG_LIMITS = [(-3.14, 3.14)] * 6


class LegSliderGUI(Node):
    def __init__(self):
        super().__init__('leg_slider_gui')

        # publishers
        self.leg_mit_pub = self.create_publisher(CmdMotorCtrl,       '/leg/cmd_ctrl', 10)
        self.leg_pos_pub = self.create_publisher(CmdSetMotorPosition, '/leg/cmd_pos',  10)
        self.leg_spd_pub = self.create_publisher(CmdSetMotorSpeed,    '/leg/cmd_spd',  10)

        # subscribers
        self.create_subscription(MotorStatusMsg, '/leg/status', self._leg_status_cb, 10)

        # service client to stop motion
        self._motion_client = self.create_client(
            SetMotionMode, '/hric/motion/set_motion_mode'
        )

        # motor IDs
        self.left_ids  = list(range(51, 57))   # 51-56
        self.right_ids = list(range(61, 67))    # 61-66

        # current leg control mode
        self.leg_mode = MODE_POSITION

        # desired positions (radians) — used by MIT and Position modes
        self.left_pos  = [0.0] * 6
        self.right_pos = [0.0] * 6

        # desired speeds (rpm) per joint — used by Speed mode
        self.left_spd  = [0.0] * 6
        self.right_spd = [0.0] * 6

        # MIT control parameters
        self.leg_kp = 20.0
        self.leg_kd = 4.0

        # Position-mode parameters (shared across all joints)
        self.leg_pos_spd = 0.5    # rpm — trapezoidal profile speed
        self.leg_pos_cur = 8.0    # A   — current limit

        # Speed-mode parameter (shared current limit)
        self.leg_spd_cur = 8.0    # A

        # initialization flags – wait for first status message before publishing
        self.left_initialized  = [False] * 6
        self.right_initialized = [False] * 6

        # publish at 20 Hz
        self.timer = self.create_timer(0.05, self._publish)

        self._build_gui()

    # -------------------------------------------------------------------------
    # GUI
    # -------------------------------------------------------------------------

    def _build_gui(self):
        self.root = tk.Tk()
        self.root.title("Leg Control")

        # ── warning banner ────────────────────────────────────────────────────
        warn = tk.Label(
            self.root,
            text="⚠  DANGER — Do NOT command legs while robot is standing unsupported!  ⚠",
            bg='#882200', fg='white', font=('Arial', 10, 'bold'),
        )
        warn.pack(fill='x', padx=0, pady=0)

        # ── top bar: motion control + mode selector ───────────────────────────
        top = tk.Frame(self.root, bg='#222')
        top.pack(fill='x', padx=4, pady=4)

        tk.Button(
            top, text="STOP MOTION (release legs)",
            bg='#cc2222', fg='white', font=('Arial', 10, 'bold'),
            height=2, command=self._stop_motion,
        ).pack(side='left', padx=8, pady=4)

        self._motion_status_var = tk.StringVar(value='motion: —')
        tk.Label(
            top, textvariable=self._motion_status_var,
            bg='#222', fg='#ffff88', font=('Courier', 9), anchor='w',
        ).pack(side='left', padx=8)

        # mode selector
        mode_frame = tk.LabelFrame(top, text="Leg mode", bg='#222', fg='white')
        mode_frame.pack(side='left', padx=16, pady=4)
        self._mode_var = tk.StringVar(value=MODE_POSITION)
        for mode in (MODE_MIT, MODE_POSITION, MODE_SPEED):
            tk.Radiobutton(
                mode_frame, text=mode, variable=self._mode_var, value=mode,
                bg='#222', fg='white', selectcolor='#555',
                command=self._on_mode_change,
            ).pack(side='left', padx=4)

        # ── two column layout ─────────────────────────────────────────────────
        cols = tk.Frame(self.root)
        cols.pack(padx=4, pady=4)

        left_frame  = ttk.LabelFrame(cols, text="LEFT LEG  (motors 51-56)")
        left_frame.grid(row=0, column=0, padx=6, pady=4, sticky='n')

        right_frame = ttk.LabelFrame(cols, text="RIGHT LEG  (motors 61-66)")
        right_frame.grid(row=0, column=1, padx=6, pady=4, sticky='n')

        # left leg
        (self.left_sliders, self.left_spd_sliders,
         self.left_status) = self._build_leg_section(
            left_frame, LEFT_LEG_NAMES, LEG_LIMITS,
            pos_setter=lambda i, v: self._set_left_pos(i, v),
            spd_setter=lambda i, v: self._set_left_spd(i, v),
        )
        tk.Button(
            left_frame, text="ZERO LEFT LEG",
            command=self._zero_left,
        ).pack(fill='x', padx=4, pady=(4, 2))

        # right leg
        (self.right_sliders, self.right_spd_sliders,
         self.right_status) = self._build_leg_section(
            right_frame, RIGHT_LEG_NAMES, LEG_LIMITS,
            pos_setter=lambda i, v: self._set_right_pos(i, v),
            spd_setter=lambda i, v: self._set_right_spd(i, v),
        )
        tk.Button(
            right_frame, text="ZERO RIGHT LEG",
            command=self._zero_right,
        ).pack(fill='x', padx=4, pady=(4, 2))

        # ── shared params panel (row 1, spans both columns) ───────────────────
        self._params_frame = ttk.LabelFrame(cols, text="Leg parameters")
        self._params_frame.grid(row=1, column=0, columnspan=2, padx=6, pady=4, sticky='ew')

        # MIT gains sub-frame
        self._mit_frame = tk.Frame(self._params_frame)
        self._mit_frame.pack(fill='x')

        tk.Label(self._mit_frame, text="kp  (position gain, N·m/rad)").pack()
        self._kp_slider = tk.Scale(
            self._mit_frame, from_=0.0, to=500.0, resolution=1.0,
            orient=tk.HORIZONTAL, length=360, command=self._set_kp,
        )
        self._kp_slider.set(self.leg_kp)
        self._kp_slider.pack()

        tk.Label(self._mit_frame, text="kd  (damping, N·m·s/rad)").pack()
        self._kd_slider = tk.Scale(
            self._mit_frame, from_=0.0, to=50.0, resolution=0.1,
            orient=tk.HORIZONTAL, length=360, command=self._set_kd,
        )
        self._kd_slider.set(self.leg_kd)
        self._kd_slider.pack()

        # Position-mode params sub-frame
        self._pos_params_frame = tk.Frame(self._params_frame)

        tk.Label(self._pos_params_frame, text="Profile speed  (rpm)").pack()
        self._pos_spd_slider = tk.Scale(
            self._pos_params_frame, from_=0.0, to=4.0, resolution=0.1,
            orient=tk.HORIZONTAL, length=360,
            command=lambda v: setattr(self, 'leg_pos_spd', float(v)),
        )
        self._pos_spd_slider.set(self.leg_pos_spd)
        self._pos_spd_slider.pack()

        tk.Label(self._pos_params_frame, text="Current limit  (A)").pack()
        self._pos_cur_slider = tk.Scale(
            self._pos_params_frame, from_=0.0, to=15.0, resolution=0.1,
            orient=tk.HORIZONTAL, length=360,
            command=lambda v: setattr(self, 'leg_pos_cur', float(v)),
        )
        self._pos_cur_slider.set(self.leg_pos_cur)
        self._pos_cur_slider.pack()

        # Speed-mode params sub-frame
        self._spd_params_frame = tk.Frame(self._params_frame)

        tk.Label(self._spd_params_frame, text="Current limit  (A)").pack()
        self._spd_cur_slider = tk.Scale(
            self._spd_params_frame, from_=0.0, to=15.0, resolution=0.1,
            orient=tk.HORIZONTAL, length=360,
            command=lambda v: setattr(self, 'leg_spd_cur', float(v)),
        )
        self._spd_cur_slider.set(self.leg_spd_cur)
        self._spd_cur_slider.pack()

        # apply initial mode visibility
        self._on_mode_change()

    def _build_leg_section(self, parent, names, limits, pos_setter, spd_setter):
        """Build per-joint rows for one leg.

        Each row contains:
          - a position slider (MIT / Position modes)
          - a speed slider    (Speed mode, hidden initially)
          - a status label
        """
        pos_sliders = []
        spd_sliders = []
        status_labels = []
        for i, (name, (lo, hi)) in enumerate(zip(names, limits)):
            tk.Label(parent, text=name, anchor='w', width=18).pack(anchor='w', padx=4)

            ps = tk.Scale(
                parent, from_=lo, to=hi, resolution=0.01,
                orient=tk.HORIZONTAL, length=300,
                command=lambda v, idx=i: pos_setter(idx, v),
            )
            ps.pack()
            pos_sliders.append(ps)

            ss = tk.Scale(
                parent, from_=-200.0, to=200.0, resolution=1.0,
                orient=tk.HORIZONTAL, length=300,
                label=f"{name} spd (rpm)",
                command=lambda v, idx=i: spd_setter(idx, v),
            )
            # not packed yet — shown only in Speed mode
            spd_sliders.append(ss)

            lbl = tk.Label(parent, text="--", font=("Courier", 9), anchor='w', width=55)
            lbl.pack(fill='x', padx=4, pady=(0, 4))
            status_labels.append(lbl)

        return pos_sliders, spd_sliders, status_labels

    def _on_mode_change(self):
        mode = self._mode_var.get()
        self.leg_mode = mode

        # swap params panel
        self._mit_frame.pack_forget()
        self._pos_params_frame.pack_forget()
        self._spd_params_frame.pack_forget()

        if mode == MODE_MIT:
            self._mit_frame.pack(fill='x')
        elif mode == MODE_POSITION:
            self._pos_params_frame.pack(fill='x')
        else:  # Speed
            self._spd_params_frame.pack(fill='x')

        # show/hide per-joint position vs speed sliders
        for ps, ss in zip(self.left_sliders,  self.left_spd_sliders):
            self._toggle_joint_sliders(ps, ss, mode)
        for ps, ss in zip(self.right_sliders, self.right_spd_sliders):
            self._toggle_joint_sliders(ps, ss, mode)

    @staticmethod
    def _toggle_joint_sliders(pos_slider, spd_slider, mode):
        if mode == MODE_SPEED:
            pos_slider.pack_forget()
            spd_slider.pack()
        else:
            spd_slider.pack_forget()
            pos_slider.pack()

    # -------------------------------------------------------------------------
    # Setters
    # -------------------------------------------------------------------------

    def _set_left_pos(self, i, v):
        self.left_pos[i] = float(v)

    def _set_right_pos(self, i, v):
        self.right_pos[i] = float(v)

    def _set_left_spd(self, i, v):
        self.left_spd[i] = float(v)

    def _set_right_spd(self, i, v):
        self.right_spd[i] = float(v)

    def _set_kp(self, v):
        self.leg_kp = float(v)

    def _set_kd(self, v):
        self.leg_kd = float(v)

    def _zero_left(self):
        for i, s in enumerate(self.left_sliders):
            s.set(0.0)
            self.left_pos[i] = 0.0
        for i, s in enumerate(self.left_spd_sliders):
            s.set(0.0)
            self.left_spd[i] = 0.0

    def _zero_right(self):
        for i, s in enumerate(self.right_sliders):
            s.set(0.0)
            self.right_pos[i] = 0.0
        for i, s in enumerate(self.right_spd_sliders):
            s.set(0.0)
            self.right_spd[i] = 0.0

    # -------------------------------------------------------------------------
    # Publishing
    # -------------------------------------------------------------------------

    def _publish(self):
        if all(self.left_initialized) and all(self.right_initialized):
            mode = self.leg_mode
            if mode == MODE_MIT:
                self._publish_mit()
            elif mode == MODE_POSITION:
                self._publish_pos()
            else:
                self._publish_spd()

    def _publish_mit(self):
        msg = CmdMotorCtrl()
        msg.cmds = []
        for i, mid in enumerate(self.left_ids):
            c = MotorCtrl()
            c.name = mid
            c.kp   = float(self.leg_kp)
            c.kd   = float(self.leg_kd)
            c.pos  = float(self.left_pos[i])
            c.spd  = 0.0
            c.tor  = 0.0
            msg.cmds.append(c)
        for i, mid in enumerate(self.right_ids):
            c = MotorCtrl()
            c.name = mid
            c.kp   = float(self.leg_kp)
            c.kd   = float(self.leg_kd)
            c.pos  = float(self.right_pos[i])
            c.spd  = 0.0
            c.tor  = 0.0
            msg.cmds.append(c)
        self.leg_mit_pub.publish(msg)

    def _publish_pos(self):
        msg = CmdSetMotorPosition()
        msg.cmds = []
        for i, mid in enumerate(self.left_ids):
            c = SetMotorPosition()
            c.name = mid
            c.pos  = float(self.left_pos[i])
            c.spd  = float(self.leg_pos_spd)
            c.cur  = float(self.leg_pos_cur)
            msg.cmds.append(c)
        for i, mid in enumerate(self.right_ids):
            c = SetMotorPosition()
            c.name = mid
            c.pos  = float(self.right_pos[i])
            c.spd  = float(self.leg_pos_spd)
            c.cur  = float(self.leg_pos_cur)
            msg.cmds.append(c)
        self.leg_pos_pub.publish(msg)

    def _publish_spd(self):
        msg = CmdSetMotorSpeed()
        msg.cmds = []
        for i, mid in enumerate(self.left_ids):
            c = SetMotorSpeed()
            c.name = mid
            c.spd  = float(self.left_spd[i])
            c.cur  = float(self.leg_spd_cur)
            msg.cmds.append(c)
        for i, mid in enumerate(self.right_ids):
            c = SetMotorSpeed()
            c.name = mid
            c.spd  = float(self.right_spd[i])
            c.cur  = float(self.leg_spd_cur)
            msg.cmds.append(c)
        self.leg_spd_pub.publish(msg)

    # -------------------------------------------------------------------------
    # Status callback
    # -------------------------------------------------------------------------

    def _leg_status_cb(self, msg):
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
                result = 'motion: STOPPED — legs released'
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
    node = LegSliderGUI()
    try:
        node.spin()
    except tk.TclError:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
