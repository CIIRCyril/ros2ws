from launch import LaunchDescription
from launch_ros.actions import Node, ComposableNodeContainer
from launch.actions import DeclareLaunchArgument
from launch.actions import LogInfo
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.descriptions import ComposableNode
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    n1 =Node(
        package = "usb_sbus",
        executable = 'usb_sbus_node',
        name = 'usb_sbus',
        # namespace = 'usb_sbus',
        output = 'screen',
    )

    # 返回 LaunchDescription
    return LaunchDescription([n1])
