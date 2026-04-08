from launch import LaunchDescription
from launch_ros.actions import Node, ComposableNodeContainer
from launch.actions import DeclareLaunchArgument
from launch.actions import LogInfo
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.descriptions import ComposableNode
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # yaml config file control
    package_share_directory = get_package_share_directory('bluetooth')

    componentContainer = ComposableNodeContainer(
        name='bluetooth_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container_mt',
        composable_node_descriptions=[
            ComposableNode(
                package='bluetooth',
                plugin='com::xhumanoid::BluetoothNodelet',
                name='bluetooth_server_node',
                extra_arguments=[{'use_intra_process_comms': True}],
                parameters = [
                    { "bluetooth_server_mode": "ble" },
                    { "bluetooth_log_level": "error" }
                ],
            )
        ],
        output='screen',
    )

    # 返回 LaunchDescription
    return LaunchDescription([componentContainer])
