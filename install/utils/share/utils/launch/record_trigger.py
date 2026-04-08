from launch import LaunchDescription
from launch_ros.actions import Node, ComposableNodeContainer
from launch.actions import DeclareLaunchArgument
from launch.actions import LogInfo
from launch.actions import ExecuteProcess
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.descriptions import ComposableNode
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    config_file = DeclareLaunchArgument(
        'config_file',
        default_value='topic.config',
        description='Path to configuration file'
    )

    package_directory = f"{get_package_share_directory('utils')}/../../lib/utils/bag_record"
    print(package_directory)

    process = ExecuteProcess(
        cmd=[f'{package_directory}/scripts/init.sh'],
        output='screen'
    )
    
    return LaunchDescription([process])

