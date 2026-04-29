#!/usr/bin/env python3
import tkinter as tk
import random
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState


class FingerSliderGUI(Node):
    def __init__(self):
        super().__init__('finger_slider_gui')

        # Publishers for both hands
        self.pub_left = self.create_publisher(
            JointState,
            '/inspire_hand/ctrl/left_hand',
            10
        )
        
        self.pub_right = self.create_publisher(
            JointState,
            '/inspire_hand/ctrl/right_hand',
            10
        )

        # Finger joints configuration
        self.finger_names = ['1', '2', '3', '4', '5', '6']
        self.num_fingers = len(self.finger_names)

        # Initial values for left hand
        self.left_positions = [0.0] * self.num_fingers
        self.left_positions[4] = 1.0  # Finger 5 fixed at 1
        self.left_velocities = [1.0] * self.num_fingers
        
        # Initial values for right hand
        self.right_positions = [0.0] * self.num_fingers
        self.right_positions[4] = 1.0  # Finger 5 fixed at 1
        self.right_velocities = [1.0] * self.num_fingers
        
        self.effort = 1.0

        # Publish rate: 20 Hz
        self.timer = self.create_timer(0.05, self.publish_cmd)
        
        # Random mode state
        self.random_mode = False
        self.random_timer_id = None
        self.random_period = 0.5  # Random update period in seconds
        self.spin_timer_id = None  # For tracking the spin callback

        # Create GUI
        self.root = tk.Tk()
        self.root.title("Finger Control - Both Hands")

        # Main container with two columns
        main_frame = tk.Frame(self.root)
        main_frame.pack(padx=10, pady=10)
        
        # Left hand frame
        left_frame = tk.Frame(main_frame, relief=tk.RIDGE, borderwidth=2)
        left_frame.grid(row=0, column=0, padx=10, pady=5)
        
        tk.Label(left_frame, text="LEFT HAND", font=("Arial", 14, "bold")).pack(pady=5)
        
        self.left_position_sliders = []
        self.left_velocity_sliders = []
        
        # Create sliders for left hand
        self.create_hand_sliders(left_frame, self.left_position_sliders, 
                                self.left_velocity_sliders, 'left')
        
        # Left hand buttons
        left_button_frame = tk.Frame(left_frame)
        left_button_frame.pack(pady=10)
        
        tk.Button(
            left_button_frame,
            text="OPEN",
            command=self.open_left,
            height=2,
            width=10
        ).pack(side="left", padx=3)
        
        tk.Button(
            left_button_frame,
            text="CLOSE",
            command=self.close_left,
            height=2,
            width=10
        ).pack(side="left", padx=3)
        
        # Right hand frame
        right_frame = tk.Frame(main_frame, relief=tk.RIDGE, borderwidth=2)
        right_frame.grid(row=0, column=1, padx=10, pady=5)
        
        tk.Label(right_frame, text="RIGHT HAND", font=("Arial", 14, "bold")).pack(pady=5)
        
        self.right_position_sliders = []
        self.right_velocity_sliders = []
        
        # Create sliders for right hand
        self.create_hand_sliders(right_frame, self.right_position_sliders,
                                self.right_velocity_sliders, 'right')
        
        # Right hand buttons
        right_button_frame = tk.Frame(right_frame)
        right_button_frame.pack(pady=10)
        
        tk.Button(
            right_button_frame,
            text="OPEN",
            command=self.open_right,
            height=2,
            width=10
        ).pack(side="left", padx=3)
        
        tk.Button(
            right_button_frame,
            text="CLOSE",
            command=self.close_right,
            height=2,
            width=10
        ).pack(side="left", padx=3)

        # Global controls below both hands
        global_frame = tk.Frame(self.root)
        global_frame.pack(pady=10)

        # Global controls below both hands
        global_frame = tk.Frame(self.root)
        global_frame.pack(pady=10)

        # Effort control
        tk.Label(global_frame, text="Effort (all fingers)").pack(pady=(5, 0))
        self.effort_slider = tk.Scale(
            global_frame,
            from_=0.0,
            to=2.0,
            resolution=0.1,
            orient=tk.HORIZONTAL,
            length=400,
            command=self.set_effort
        )
        self.effort_slider.set(self.effort)
        self.effort_slider.pack()

        # Random period control
        tk.Label(global_frame, text="Random Update Period (seconds)").pack(pady=(10, 0))
        self.random_period_slider = tk.Scale(
            global_frame,
            from_=0.05,
            to=2.0,
            resolution=0.05,
            orient=tk.HORIZONTAL,
            length=400,
            command=self.set_random_period
        )
        self.random_period_slider.set(self.random_period)
        self.random_period_slider.pack()

        # Random and Exit buttons
        button_frame = tk.Frame(global_frame)
        button_frame.pack(pady=10)

        self.random_button = tk.Button(
            button_frame,
            text="START RANDOM",
            command=self.toggle_random,
            height=2,
            width=15,
            bg="lightgreen"
        )
        self.random_button.pack(side="left", padx=5)

        tk.Button(
            button_frame,
            text="EXIT",
            command=self.exit_program,
            height=2,
            width=15,
            bg="red",
            fg="white"
        ).pack(side="left", padx=5)
    
    def create_hand_sliders(self, parent_frame, position_sliders, velocity_sliders, hand):
        """Create position and velocity sliders for one hand"""
        for i in range(self.num_fingers):
            frame = tk.Frame(parent_frame)
            frame.pack(fill="x", padx=5, pady=2)

            tk.Label(frame, text=f"Finger {self.finger_names[i]}", width=8).pack(side="left")

            # Position slider
            pos_slider = tk.Scale(
                frame,
                from_=0.0,
                to=1.0,
                resolution=0.01,
                orient=tk.HORIZONTAL,
                length=200,
                command=lambda v, i=i, h=hand: self.set_position(h, i, v)
            )
            # Disable finger 5 (index 4) and set to 1
            if i == 4:
                pos_slider.set(1.0)
                pos_slider.config(state='disabled')
            pos_slider.pack(side="left")
            position_sliders.append(pos_slider)

            tk.Label(frame, text="v:", width=2).pack(side="left")
            
            # Velocity slider
            vel_slider = tk.Scale(
                frame,
                from_=0.0,
                to=2.0,
                resolution=0.1,
                orient=tk.HORIZONTAL,
                length=80,
                command=lambda v, i=i, h=hand: self.set_velocity(h, i, v)
            )
            vel_slider.set(1.0)
            vel_slider.pack(side="left")
            velocity_sliders.append(vel_slider)

    def set_position(self, hand, i, v):
        """Set position for a specific finger on a specific hand"""
        # Keep finger 5 (index 4) fixed at 1
        if i == 4:
            if hand == 'left':
                self.left_positions[4] = 1.0
            else:
                self.right_positions[4] = 1.0
        else:
            if hand == 'left':
                self.left_positions[i] = float(v)
            else:
                self.right_positions[i] = float(v)

    def set_velocity(self, hand, i, v):
        """Set velocity for a specific finger on a specific hand"""
        if hand == 'left':
            self.left_velocities[i] = float(v)
        else:
            self.right_velocities[i] = float(v)

    def set_effort(self, v):
        self.effort = float(v)
    
    def set_random_period(self, v):
        """Set the random update period"""
        self.random_period = float(v)

    def open_left(self):
        """Open left hand: set fingers 1-4 to 1"""
        for i in range(4):  # Only fingers 1-4 (indices 0-3)
            self.left_position_sliders[i].set(1.0)
            self.left_positions[i] = 1.0

    def close_left(self):
        """Close left hand: set all motors to 0 (except finger 5)"""
        for i in range(self.num_fingers):
            if i != 4:
                self.left_position_sliders[i].set(0.0)
                self.left_positions[i] = 0.0
    
    def open_right(self):
        """Open right hand: set fingers 1-4 to 1"""
        for i in range(4):  # Only fingers 1-4 (indices 0-3)
            self.right_position_sliders[i].set(1.0)
            self.right_positions[i] = 1.0

    def close_right(self):
        """Close right hand: set all motors to 0 (except finger 5)"""
        for i in range(self.num_fingers):
            if i != 4:
                self.right_position_sliders[i].set(0.0)
                self.right_positions[i] = 0.0

    def apply_random_values(self):
        """Apply random position values to all fingers except finger 5 on both hands"""
        # Randomize left hand
        for i in range(self.num_fingers):
            if i != 4:  # Skip finger 5 (index 4)
                random_val = round(random.uniform(0.0, 1.0), 2)
                self.left_position_sliders[i].set(random_val)
                self.left_positions[i] = random_val
        
        # Randomize right hand
        for i in range(self.num_fingers):
            if i != 4:  # Skip finger 5 (index 4)
                random_val = round(random.uniform(0.0, 1.0), 2)
                self.right_position_sliders[i].set(random_val)
                self.right_positions[i] = random_val
        
        # Schedule next random change if still in random mode
        if self.random_mode:
            delay_ms = int(self.random_period * 1000)
            self.random_timer_id = self.root.after(delay_ms, self.apply_random_values)

    def toggle_random(self):
        """Toggle random mode on/off"""
        self.random_mode = not self.random_mode
        
        if self.random_mode:
            # Start random mode
            self.random_button.config(text="STOP RANDOM", bg="orange")
            self.apply_random_values()
        else:
            # Stop random mode
            self.random_button.config(text="START RANDOM", bg="lightgreen")
            if self.random_timer_id:
                self.root.after_cancel(self.random_timer_id)
                self.random_timer_id = None

    def exit_program(self):
        """Clean shutdown of ROS2 node and GUI"""
        # Stop random timer if active
        if self.random_timer_id:
            self.root.after_cancel(self.random_timer_id)
            self.random_timer_id = None
        
        # Stop the spin callback
        if self.spin_timer_id:
            self.root.after_cancel(self.spin_timer_id)
            self.spin_timer_id = None
        
        # Destroy the window first
        self.root.quit()
        
        # Then clean up ROS2
        if rclpy.ok():
            self.destroy_node()
            rclpy.shutdown()

    def publish_cmd(self):
        """Publish commands to both left and right hands"""
        # Ensure finger 5 always stays at 1 for both hands
        self.left_positions[4] = 1.0
        self.right_positions[4] = 1.0
        
        # Publish left hand
        msg_left = JointState()
        msg_left.header.stamp = self.get_clock().now().to_msg()
        msg_left.name = self.finger_names
        msg_left.position = self.left_positions
        msg_left.velocity = self.left_velocities
        msg_left.effort = [self.effort] * self.num_fingers
        self.pub_left.publish(msg_left)
        
        # Publish right hand
        msg_right = JointState()
        msg_right.header.stamp = self.get_clock().now().to_msg()
        msg_right.name = self.finger_names
        msg_right.position = self.right_positions
        msg_right.velocity = self.right_velocities
        msg_right.effort = [self.effort] * self.num_fingers
        self.pub_right.publish(msg_right)


def main(args=None):
    rclpy.init(args=args)

    node = FingerSliderGUI()

    def spin_once():
        if rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0)
            node.spin_timer_id = node.root.after(10, spin_once)

    node.spin_timer_id = node.root.after(10, spin_once)
    
    try:
        node.root.mainloop()
    except KeyboardInterrupt:
        pass
    finally:
        # Clean up if not already done
        if node.random_timer_id:
            node.root.after_cancel(node.random_timer_id)
        if node.spin_timer_id:
            node.root.after_cancel(node.spin_timer_id)
        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()


if __name__ == '__main__':
    main()
