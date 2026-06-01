#!/usr/bin/env python3

import cv2

import rclpy
from rclpy.node import Node

from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge


class RemoteCameraViewer(Node):

    def __init__(self):
        super().__init__("remote_camera_viewer")

        self.bridge = CvBridge()

        qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=1,
        )

        self.subscription = self.create_subscription(
            Image,
            "/camera/color/image_raw",
            self.image_callback,
            qos,
        )

        self.get_logger().info(
            "Waiting for images on /camera/color/image_raw"
        )

    def image_callback(self, msg):

        try:
            frame = self.bridge.imgmsg_to_cv2(
                msg,
                desired_encoding="bgr8"
            )

            cv2.imshow("Orbbec Remote Camera", frame)
            cv2.waitKey(1)

        except Exception as e:
            self.get_logger().error(str(e))


def main(args=None):

    rclpy.init(args=args)

    node = RemoteCameraViewer()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    cv2.destroyAllWindows()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()