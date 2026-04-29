#!/usr/bin/env python3
import tkinter as tk
import rclpy
from rclpy.node import Node

from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition, MotorStatusMsg


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


class HeadWaistGUI(Node):
    def __init__(self):
        super().__init__('head_waist_gui')

        # publishers
        self.head_pub = self.create_publisher(
            CmdSetMotorPosition, '/head/cmd_pos', 10)

        self.waist_pub = self.create_publisher(
            CmdSetMotorPosition, '/waist/cmd_pos', 10)

        # subscribers
        self.create_subscription(
            MotorStatusMsg, '/head/status', self.head_status_cb, 10)

        self.create_subscription(
            MotorStatusMsg, '/waist/status', self.waist_status_cb, 10)

        # motor IDs (adjust if needed)
        self.head_ids = [3, 2, 1]     # roll pitch yaw
        self.waist_ids = [31]         # waist yaw (doc)

        # limits
        self.head_limits = [
            (-0.45, 0.45),   # roll
            (-0.44, 0.44),   # pitch
            (-1.57, 1.57),   # yaw
        ]

        self.waist_limits = [
            (-0.8, 0.8),     # safe default
        ]

        self.head_pos = [0.0]*3
        self.waist_pos = [0.0]

        self.head_speed = 0.2
        self.waist_speed = 0.2

        # track initialization from status
        self.head_initialized = [False] * 3
        self.waist_initialized = [False]

        self.root = tk.Tk()
        self.root.title("Walker Head + Waist Control")

        self.build_head_ui()
        self.build_waist_ui()

        self.timer = self.create_timer(0.05, self.publish)

    # ---------------- UI ----------------

    def build_head_ui(self):
        tk.Label(self.root, text="HEAD", font=("Arial", 12, "bold")).pack()

        self.head_status = []

        names = ["Head roll", "Head pitch", "Head yaw"]

        self.head_sliders = []
        for i in range(3):
            tk.Label(self.root, text=names[i]).pack()

            s = tk.Scale(
                self.root,
                from_=self.head_limits[i][0],
                to=self.head_limits[i][1],
                resolution=0.01,
                orient=tk.HORIZONTAL,
                length=420,
                command=lambda v, i=i: self.set_head(i, v)
            )
            s.pack()
            self.head_sliders.append(s)

            lbl = tk.Label(self.root, text="--", font=("Courier", 10), anchor="w", width=70)
            lbl.pack()
            self.head_status.append(lbl)

        tk.Label(self.root, text="Head speed").pack()

        tk.Scale(
            self.root,
            from_=0.0,
            to=1.0,
            resolution=0.01,
            orient=tk.HORIZONTAL,
            length=420,
            command=self.set_head_speed
        ).pack()

        tk.Button(
            self.root,
            text="ZERO HEAD",
            command=self.zero_head
        ).pack(fill="x", pady=5)

    def build_waist_ui(self):
        tk.Label(self.root, text="WAIST", font=("Arial", 12, "bold")).pack()

        self.waist_status = []

        tk.Label(self.root, text="Waist yaw").pack()

        self.waist_slider = tk.Scale(
            self.root,
            from_=self.waist_limits[0][0],
            to=self.waist_limits[0][1],
            resolution=0.01,
            orient=tk.HORIZONTAL,
            length=420,
            command=lambda v: self.set_waist(0, v)
        )
        self.waist_slider.pack()

        lbl = tk.Label(self.root, text="--", font=("Courier", 10), anchor="w", width=70)
        lbl.pack()
        self.waist_status.append(lbl)

        tk.Label(self.root, text="Waist speed").pack()

        tk.Scale(
            self.root,
            from_=0.0,
            to=1.0,
            resolution=0.01,
            orient=tk.HORIZONTAL,
            length=420,
            command=self.set_waist_speed
        ).pack()

        tk.Button(
            self.root,
            text="ZERO WAIST",
            command=self.zero_waist
        ).pack(fill="x", pady=5)

    # ---------------- setters ----------------

    def set_head(self, i, v):
        self.head_pos[i] = float(v)

    def set_waist(self, i, v):
        self.waist_pos[i] = float(v)

    def set_head_speed(self, v):
        self.head_speed = float(v)

    def set_waist_speed(self, v):
        self.waist_speed = float(v)

    def zero_head(self):
        for i, s in enumerate(self.head_sliders):
            s.set(0.0)
            self.head_pos[i] = 0.0

    def zero_waist(self):
        self.waist_slider.set(0.0)
        self.waist_pos[0] = 0.0

    # ---------------- publish ----------------

    def publish(self):
        # don't publish until we've initialized from status
        if not all(self.head_initialized + self.waist_initialized):
            return

        # head
        msg = CmdSetMotorPosition()
        msg.cmds = []

        for i, mid in enumerate(self.head_ids):
            c = SetMotorPosition()
            c.name = mid
            c.pos = self.head_pos[i]
            c.spd = self.head_speed
            c.cur = 8.0
            msg.cmds.append(c)

        self.head_pub.publish(msg)

        # waist
        msg = CmdSetMotorPosition()
        msg.cmds = []

        for i, mid in enumerate(self.waist_ids):
            c = SetMotorPosition()
            c.name = mid
            c.pos = self.waist_pos[i]
            c.spd = self.waist_speed
            c.cur = 8.0
            msg.cmds.append(c)

        self.waist_pub.publish(msg)

    # ---------------- status callbacks ----------------

    def head_status_cb(self, msg):
        for st in msg.status:
            if st.name in self.head_ids:
                i = self.head_ids.index(st.name)
                err = ERROR_MAP.get(st.error, str(st.error))

                # initialize slider from first status
                if not self.head_initialized[i]:
                    self.head_sliders[i].set(st.pos)
                    self.head_pos[i] = st.pos
                    self.head_initialized[i] = True

                self.head_status[i].config(
                    text=f"pos {st.pos:6.2f}  spd {st.speed:6.2f}  "
                         f"cur {st.current:5.2f}A  "
                         f"tmp {st.temperature:5.2f}C  {err:13s}"
                )

    def waist_status_cb(self, msg):
        for st in msg.status:
            if st.name in self.waist_ids:
                err = ERROR_MAP.get(st.error, str(st.error))

                # initialize slider from first status
                if not self.waist_initialized[0]:
                    self.waist_slider.set(st.pos)
                    self.waist_pos[0] = st.pos
                    self.waist_initialized[0] = True

                self.waist_status[0].config(
                    text=f"pos {st.pos:6.2f}  spd {st.speed:6.2f}  "
                         f"cur {st.current:5.2f}A  "
                         f"tmp {st.temperature:5.2f}C  {err:13s}"
                )

    def spin(self):
        while rclpy.ok():
            self.root.update()
            rclpy.spin_once(self, timeout_sec=0.0)


def main():
    rclpy.init()
    node = HeadWaistGUI()
    node.spin()


if __name__ == "__main__":
    main()
