#!/usr/bin/env python3
import tkinter as tk
from functools import partial

import rclpy
from rclpy.node import Node

from bodyctrl_msgs.msg import CmdSetMotorPosition, CmdMotorPosition


class HeadSliderGUI(Node):
    def __init__(self):
        super().__init__('head_slider_gui')

        self.pub = self.create_publisher(
            CmdSetMotorPosition,
            '/head/cmd_pos',
            10
        )

        # store slider values
        self.positions = [0.0, 0.0, 0.0]

        # publish timer
        self.timer = self.create_timer(0.05, self.publish_cmd)  # 20 Hz

        # GUI
        self.root = tk.Tk()
        self.root.title("Head Motor Control")

        self.sliders = []

        for i in range(3):
            frame = tk.Frame(self.root)
            frame.pack(padx=10, pady=5)

            label = tk.Label(frame, text=f"Motor {i+1}")
            label.pack()

            slider = tk.Scale(
                frame,
                from_=-0.3,
                to=0.3,
                resolution=0.01,
                length=300,
                orient=tk.HORIZONTAL,
                command=partial(self.on_slider, i)
            )
            slider.set(0.0)
            slider.pack()

            self.sliders.append(slider)

    def on_slider(self, index, value):
        self.positions[index] = float(value)

    def publish_cmd(self):
        msg = CmdSetMotorPosition()
        msg.cmds = []

        for i in range(3):
            cmd = CmdMotorPosition()
            cmd.name = i + 1
            cmd.pos = float(self.positions[i])
            cmd.spd = 0.2
            cmd.cur = 8.0
            msg.cmds.append(cmd)

        self.pub.publish(msg)

    def spin(self):
        while rclpy.ok():
            self.root.update()
            rclpy.spin_once(self, timeout_sec=0.0)


def main():
    rclpy.init()
    node = HeadSliderGUI()
    node.spin()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()