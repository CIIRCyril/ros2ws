#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from bodyctrl_msgs.msg import MotorStatusMsg

class TopicTester(Node):
    def __init__(self):
        super().__init__('topic_tester')
        
        # Test head status
        self.create_subscription(
            MotorStatusMsg, '/head/status', 
            lambda msg: self.get_logger().info(f"HEAD STATUS: {len(msg.status)} motors"), 
            10)
        
        # Test left hand status
        self.create_subscription(
            JointState, '/inspire_hand/state/left_hand',
            lambda msg: self.get_logger().info(f"LEFT HAND: names={msg.name}, pos={len(msg.position)}"),
            10)
        
        # Test right hand status
        self.create_subscription(
            JointState, '/inspire_hand/state/right_hand',
            lambda msg: self.get_logger().info(f"RIGHT HAND: names={msg.name}, pos={len(msg.position)}"),
            10)
        
        self.get_logger().info("Listening for topics...")
        self.get_logger().info("  /head/status")
        self.get_logger().info("  /inspire_hand/state/left_hand")
        self.get_logger().info("  /inspire_hand/state/right_hand")

def main():
    rclpy.init()
    node = TopicTester()
    rclpy.spin(node)

if __name__ == "__main__":
    main()
