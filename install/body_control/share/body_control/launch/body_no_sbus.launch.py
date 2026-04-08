from launch import LaunchDescription
from launch_ros.actions import Node, ComposableNodeContainer
from launch.actions import DeclareLaunchArgument
from launch.actions import LogInfo
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.descriptions import ComposableNode
from launch.substitutions import LaunchConfiguration

def check_yaml_files(yaml_configs):
    """
    检查 YAML 配置文件是否存在。
    :param yaml_configs: 绝对路径的 YAML 文件列表
    :return: 缺失的文件列表
    """
    missing_files = [file_path for config in yaml_configs for file_path in config.values() if not os.path.exists(file_path)]
    if missing_files:
        print("❌ 以下 YAML 文件不存在:")
        for file in missing_files:
            print(f"   - {file}")
    else:
        print("✅ 所有 YAML 文件都存在！")
    return missing_files

def generate_launch_description():
    # yaml config file control
    package_share_directory = get_package_share_directory('body_control')
    yamlConfigs = [
        {"motor_arms_right": os.path.join(package_share_directory, "param", "motor_arms7_right.yaml")},
        {"motor_arms_left": os.path.join(package_share_directory, "param", "motor_arms7_left.yaml")},
        {"motor_waist": os.path.join(package_share_directory, "param", "motor_waist.yaml")},
        {"motor_head": os.path.join(package_share_directory, "param", "motor_head.yaml")},
        {"motor_legs": os.path.join(package_share_directory, "param", "motor_legs.yaml")},
        {"imu": os.path.join(package_share_directory, "param", "imu.yaml")},
        {"sri_6dof": os.path.join(package_share_directory, "param", "sri_6dof.yaml")},
        {"u2c_sn" : os.path.join(package_share_directory, "param", "/home/ubuntu/data/param/u2c_sn.yaml")},
        {"config_ethercat": os.path.join(package_share_directory, "param", "config_ethercat.yaml")},
        {"inspire_hands": os.path.join(package_share_directory, "param", "inspire_hands.yaml")},
        # {"powerboard": os.path.join(package_share_directory, "param", "powerboard.yaml")},
    ]

    if (check_yaml_files(yamlConfigs)) : 
        return LaunchDescription([])

        # 创建 ComposableNodeContainer
    componentContainer = ComposableNodeContainer(
        name='bodyctrl_nodes',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[
            ComposableNode(
                package='body_control',
                plugin='body_control::BodyControl',
                name='bodyctrl',
                extra_arguments=[{'use_intra_process_comms': True}],
                parameters = yamlConfigs,
            )
        ],
        output='screen',
    )

    n1 =Node(
        package = "usb_sbus",
        executable = 'usb_sbus_node',
        name = 'usb_sbus',
        # namespace = 'usb_sbus',
        output = 'screen',
    )

    # 返回 LaunchDescription
    return LaunchDescription([componentContainer])
