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
    package_share_directory = get_package_share_directory('audio')

    componentContainer = ComposableNodeContainer(
        name='audio_node_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container_mt',
        composable_node_descriptions=[
            ComposableNode(
                package='audio',
                plugin='com::xhumanoid::AudioNodelet',
                name='audio_node',
                extra_arguments=[{'use_intra_process_comms': True}],
                parameters = [
                    { "json_config_file": "param/audio_tg2.0_plus.json" }
                ],
            )
        ],
        output='screen',
    )

    # 返回 LaunchDescription
    return LaunchDescription([componentContainer])


