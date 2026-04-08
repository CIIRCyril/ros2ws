
import launch
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    # 定义组件容器
    container = ComposableNodeContainer(
        name='rl_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        # 使用MultiThreadedExecutor
        parameters=[{'use_sim_time': False}],
        remappings=[
            # 可添加remap规则
        ],
        composable_node_descriptions=[
            # 您的RL控制组件
            ComposableNode(
                package='rl_control',
                plugin='rl_control::RLControlPlugin',
                name='rl_control',
                parameters=[{
                    # 组件参数
                }],
                extra_arguments=[{
                    'use_intra_process_comms': True  # 启用IPC
                }]
            ),
            
            # 可以添加更多组件...
        ],
        output='screen'
    )
    
    return LaunchDescription([container])