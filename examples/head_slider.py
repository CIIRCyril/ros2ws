#!/usr/bin/env python3
import tkinter as tk
import rclpy
from rclpy.node import Node

from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition, MotorStatusMsg


ERROR_MAP = {
    0: "OK",
    33072: "Disconnected",
    33073: "Out of limit",
    1: "Motor overheating",
    2: "Overcurrent",
    3: "Undervoltage",
    4: "MOS overheating",
    5: "Stalling",
    6: "Overvoltage",
    7: "Phase loss",
    8: "Encoder error",
}


class HeadSliderGUI(Node):
    def __init__(self):
        super().__init__('head_slider_gui')

        self.pub = self.create_publisher(
            CmdSetMotorPosition,
            '/head/cmd_pos',
            10
        )

        self.sub = self.create_subscription(
            MotorStatusMsg,
            '/head/status',
            self.status_callback,
            10
        )

        # adjust if mapping different
        # roll, pitch, yaw -> motor IDs
        self.motor_ids = [3, 2, 1]

        self.names = ["Head roll", "Head pitch", "Head yaw"]

        self.limits = [
            (-0.4538, 0.4538),
            (-0.4363, 0.4363),
            (-1.5708, 1.5708),
        ]

        self.positions = [0.0, 0.0, 0.0]
        self.speed = 0.2

        self.timer = self.create_timer(0.05, self.publish_cmd)

        self.root = tk.Tk()
        self.root.title("Head control")

        self.sliders = []
        self.status_labels = []

        for i in range(3):
            tk.Label(self.root, text=self.names[i]).pack()

            slider = tk.Scale(
                self.root,
                from_=self.limits[i][0],
                to=self.limits[i][1],
                resolution=0.01,
                orient=tk.HORIZONTAL,
                length=400,
                command=lambda v, i=i: self.set_pos(i, v)
            )
            slider.pack()
            self.sliders.append(slider)

            status = tk.Label(
                self.root,
                text="pos:0  speed:0  cur:0  temp:0  err:OK",
                anchor="w",
                justify="left"
            )
            status.pack(fill="x", padx=10, pady=(0,8))
            self.status_labels.append(status)

        tk.Label(self.root, text="Speed (all joints)").pack()

        self.speed_slider = tk.Scale(
            self.root,
            from_=0.0,
            to=1.0,
            resolution=0.01,
            orient=tk.HORIZONTAL,
            length=400,
            command=self.set_speed
        )
        self.speed_slider.set(self.speed)
        self.speed_slider.pack()

        tk.Button(
            self.root,
            text="ZERO ALL",
            command=self.zero_all,
            height=2
        ).pack(fill="x", pady=10)

    def set_pos(self, i, v):
        self.positions[i] = float(v)

    def set_speed(self, v):
        self.speed = float(v)

    def zero_all(self):
        for i in range(3):
            self.sliders[i].set(0.0)
            self.positions[i] = 0.0

    def publish_cmd(self):
        msg = CmdSetMotorPosition()
        msg.cmds = []

        for i in range(3):
            cmd = SetMotorPosition()
            cmd.name = self.motor_ids[i]
            cmd.pos = float(self.positions[i])
            cmd.spd = float(self.speed)
            cmd.cur = 8.0
            msg.cmds.append(cmd)

        self.pub.publish(msg)

    def status_callback(self, msg):
        for st in msg.status:
            if st.name in self.motor_ids:
                i = self.motor_ids.index(st.name)

                err = ERROR_MAP.get(st.error, str(st.error))

                text = (
                    f"pos: {st.pos:.3f} rad   "
                    f"speed: {st.speed:.3f}   "
                    f"cur: {st.current:.2f} A   "
                    f"temp: {st.temperature:.1f} C   "
                    f"err: {err}"
                )

                self.status_labels[i].config(text=text)

    def spin(self):
        while rclpy.ok():
            self.root.update()
            rclpy.spin_once(self, timeout_sec=0.0)


def main():
    rclpy.init()
    node = HeadSliderGUI()
    node.spin()


if __name__ == "__main__":
    main()
