from launch import LaunchDescription
from launch_ros.actions import Node, ComposableNodeContainer
from launch.actions import DeclareLaunchArgument
from launch.actions import LogInfo
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

    package_share_directory = get_package_share_directory('utils')
    print(package_share_directory)
    bag = Node(
        package='utils',           # 包名称
        executable='bag_record',  # 可执行脚本名称
        name='utils_node',             # 节点名称
        output='screen',            # 输出到终端
        respawn=False,               # 节点崩溃时自动重启
        arguments=[                      # 传递命令行参数
            'record',
            '--all-topics',
            '--total', '4096'
            # 或直接写死：'-c', 'topic.config'
        ],
    )

    # 返回 LaunchDescription
    return LaunchDescription([bag])

