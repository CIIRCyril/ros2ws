import os

from ament_index_python.packages import get_package_share_directory

import launch
from launch_ros.actions import ComposableNodeContainer
from launch.actions import SetEnvironmentVariable
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    # 找到参数文件的完整路径
    config_param = os.path.join(
      get_package_share_directory('motion_control'),
      'config',
      'param.yaml'
    )

    # 创建组件容器
    container = ComposableNodeContainer(
            name='container_component_demo',
            namespace='',
            package='rclcpp_components',
            
            # 标准组件容器
            # executable='component_container',

            #单线程执行器component_container_isolated,每个组件使用独立的线程
            # executable='component_container_isolated',

            # 多线程组件容器
            executable='component_container_mt',

            composable_node_descriptions=[
                ComposableNode(
                    package='motion_control',
                    plugin='motion_control::MotionControl',
                    name='MotionControl',
                    parameters=[{'reliability': False}],
                    extra_arguments=[{'use_intra_process_comms': True}] # 使用进程内通讯
                )
            ],
            output='both',
    )

    return launch.LaunchDescription([SetEnvironmentVariable(
            name='ROS_DOMAIN_ID', value='0'),container])
