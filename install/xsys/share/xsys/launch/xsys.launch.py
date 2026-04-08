from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():

    return LaunchDescription([
        ComposableNodeContainer(
            name='xsys_container',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='xsys',
                    plugin='x::sys::Node',
                    name='xsys',
                    extra_arguments=[{'use_intra_process_comms': True}]
                )
            ],
            output='screen',
        )
    ])
