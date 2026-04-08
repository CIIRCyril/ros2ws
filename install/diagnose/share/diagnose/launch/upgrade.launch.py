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
    package_share_directory = get_package_share_directory('diagnose')

    componentContainer = ComposableNodeContainer(
        name='diagnose_tiangong2_upgrade_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container_mt',
        composable_node_descriptions=[
            ComposableNode(
                package='diagnose',
                plugin='debugger::DebuggerNodelet',
                name='diagnose_tiangong2_upgrade_node',
                extra_arguments=[{'use_intra_process_comms': True}],
                parameters = [
                    { "xml_config_file": "param/upgrade.xml" }
                ],
            )
        ],
        output='screen',
    )

    componentContainer2 = ComposableNodeContainer(
        name='image_container_powerboard',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[
            ComposableNode(
                package='power_board',
                plugin='com::xhumanoid::PowerBoardNodelet',
                name='power_board_node',
                extra_arguments=[{'use_intra_process_comms': True}],
                parameters = [
                    { "com_port": "/dev/ttyS1" },
                    { "enable_power_light": "1" },
                    { "enable_power_status": "1" },
                    { "enable_power_battery_status": "1" },
                    { "enable_power_board_key_status": "1" },
                    { "enable_power_set_timestamp": "1" },
                ],
            )
        ],
        output='screen',
    )

    # 返回 LaunchDescription
    return LaunchDescription([componentContainer, componentContainer2])
