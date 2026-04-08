#!/bin/bash

# ROS2环境诊断脚本
# 用途：检查ROS2跨网络通信问题的常见原因

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # 无颜色

# 检查命令是否存在
check_command() {
  if ! command -v $1 &> /dev/null; then
    echo -e "${RED}[✗] 未找到命令: $1${NC}"
    return 1
  else
    echo -e "${GREEN}[✓] 命令存在: $1${NC}"
    return 0
  fi
}

# 检查环境变量
check_env_var() {
  if [ -z "${!1}" ]; then
    echo -e "${YELLOW}[!] 未设置环境变量: $1${NC}"
    return 1
  else
    echo -e "${GREEN}[✓] 环境变量 $1 已设置: ${!1}${NC}"
    return 0
  fi
}

# 检查网络连通性
check_network() {
  echo -e "\n${YELLOW}[网络连通性检查]${NC}"

  local ip_list=(
    "192.168.41.1"
    "192.168.41.2"
  )

  for target in "${ip_list[@]}"; do
    echo -n "正在ping $target... "

    if ping -c 3 $target &> /dev/null; then
      echo -e "${GREEN}成功${NC}"

      # 检查端口连通性
      echo -n "正在检查ROS2默认端口(7400 UDP)... "
      if nc -zu -w 2 $target 7400 &> /dev/null; then
        echo -e "${GREEN}端口可达${NC}"
      else
        echo -e "${RED}端口不可达，可能是防火墙问题${NC}"
      fi
    else
      echo -e "${RED}失败，网络不通或目标不可达${NC}"
      echo -e "${YELLOW}建议: 检查IP地址、子网掩码、网关和防火墙设置${NC}"
    fi
  done
}

# 检查ROS2环境
check_ros2_env() {
  echo -e "\n${YELLOW}[ROS2环境检查]${NC}"

  # 检查ros2命令
  check_command "ros2"

  # 检查环境变量
  check_env_var "ROS_DOMAIN_ID"
  check_env_var "RMW_IMPLEMENTATION"

  # 检查ROS_LOCALHOST_ONLY
  if [ "$ROS_LOCALHOST_ONLY" = "1" ]; then
    echo -e "${RED}[✗] ROS_LOCALHOST_ONLY 设置为1，禁止外部连接${NC}"
    echo -e "${YELLOW}建议: export ROS_LOCALHOST_ONLY=0${NC}"
  else
    echo -e "${GREEN}[✓] ROS_LOCALHOST_ONLY 允许外部连接${NC}"
  fi

  # 检查ROS_DISCOVERY_SERVER
  if [ ! -z "$ROS_DISCOVERY_SERVER" ]; then
    echo -e "${GREEN}[✓] 使用发现服务器: $ROS_DISCOVERY_SERVER${NC}"
  else
    echo -e "${YELLOW}[!] 未设置 ROS_DISCOVERY_SERVER，使用默认发现机制${NC}"
  fi
}

# 检查ROS2节点和话题
check_ros2_nodes() {
  echo -e "\n${YELLOW}[ROS2节点和话题检查]${NC}"

  echo -n "正在列出节点... "
  nodes=$(ros2 node list 2>/dev/null)
  if [ $? -eq 0 ]; then
    if [ -z "$nodes" ]; then
      echo -e "${YELLOW}警告: 未发现节点${NC}"
    else
      echo -e "${GREEN}找到 $(echo "$nodes" | wc -l) 个节点:${NC}"
      echo "$nodes" | sed 's/^/  - /'
    fi
  else
    echo -e "${RED}失败，无法列出节点${NC}"
  fi

  echo -n "正在列出话题... "
  topics=$(ros2 topic list 2>/dev/null)
  if [ $? -eq 0 ]; then
    if [ -z "$topics" ]; then
      echo -e "${YELLOW}警告: 未发现话题${NC}"
    else
      echo -e "${GREEN}找到 $(echo "$topics" | wc -l) 个话题:${NC}"
      echo "$topics" | sed 's/^/  - /'
    fi
  else
    echo -e "${RED}失败，无法列出话题${NC}"
  fi
}

# 检查DDS配置
check_dds_config() {
  echo -e "\n${YELLOW}[DDS配置检查]${NC}"

  # 检查RMW实现
  case "$RMW_IMPLEMENTATION" in
    "rmw_fastrtps_cpp")
      echo -e "${GREEN}[✓] 使用FastRTPS实现${NC}"
      ;;
    "rmw_cyclonedds_cpp")
      echo -e "${GREEN}[✓] 使用CycloneDDS实现${NC}"
      ;;
    *)
      echo -e "${YELLOW}[!] 使用非标准RMW实现: $RMW_IMPLEMENTATION${NC}"
      ;;
    esac

  # 检查FastRTPS配置文件
  if [ ! -z "$FASTRTPS_DEFAULT_PROFILES_FILE" ]; then
    if [ -f "$FASTRTPS_DEFAULT_PROFILES_FILE" ]; then
      echo -e "${GREEN}[✓] 找到FastRTPS配置文件: $FASTRTPS_DEFAULT_PROFILES_FILE${NC}"

      # 检查配置文件中的interfaceWhiteList
      if grep -q "interfaceWhiteList" "$FASTRTPS_DEFAULT_PROFILES_FILE"; then
        echo -e "${GREEN}[✓] 配置文件包含interfaceWhiteList${NC}"
      else
        echo -e "${YELLOW}[!] 配置文件未设置interfaceWhiteList${NC}"
      fi

      cat $FASTRTPS_DEFAULT_PROFILES_FILE
    else
      echo -e "${RED}[✗] FastRTPS配置文件不存在: $FASTRTPS_DEFAULT_PROFILES_FILE${NC}"
    fi
  else
    echo -e "${YELLOW}[!] 未设置FASTRTPS_DEFAULT_PROFILES_FILE${NC}"
  fi
}

# 防火墙检查
check_firewall() {
  echo -e "\n${YELLOW}[防火墙检查]${NC}"

  # 检查常见防火墙服务
  if command -v systemctl &>/dev/null; then
    for service in ufw firewalld iptables; do
      if systemctl is-active --quiet $service; then
        echo -e "${RED}[✗] 防火墙服务 $service 正在运行${NC}"

        # 检查ROS2端口是否开放
        if [ "$service" = "ufw" ]; then
          if ufw status | grep -q "7400:7500/udp"; then
            echo -e "${GREEN}[✓] UFW已开放ROS2端口${NC}"
          else
            echo -e "${RED}[✗] UFW未开放ROS2端口${NC}"
            echo -e "${YELLOW}建议: sudo ufw allow 7400:7500/udp${NC}"
          fi
        elif [ "$service" = "firewalld" ]; then
          if firewall-cmd --list-ports | grep -q "7400-7500/udp"; then
            echo -e "${GREEN}[✓] firewalld已开放ROS2端口${NC}"
          else
            echo -e "${RED}[✗] firewalld未开放ROS2端口${NC}"
            echo -e "${YELLOW}建议: sudo firewall-cmd --permanent --add-port=7400-7500/udp${NC}"
          fi
        fi
      else
        echo -e "${GREEN}[✓] 防火墙服务 $service 未运行${NC}"
      fi
    done
  else
    echo -e "${YELLOW}[!] 无法检查防火墙状态${NC}"
  fi
}

show_summary() {
  echo -e "\n${YELLOW}[诊断总结]${NC}"

  # 这里可以根据前面的检查结果生成更具体的建议
  echo -e "请根据以上检查结果修复发现的问题。常见建议包括："
  echo -e "  1. 确保所有设备使用相同的ROS_DOMAIN_ID"
  echo -e "  2. 配置DDS网络接口白名单"
  echo -e "  3. 开放防火墙的7400-7500 UDP端口"
  echo -e "  4. 确保ROS_LOCALHOST_ONLY=0"

  echo -e "\n如需进一步帮助，请提供上述诊断结果的输出。"
}

# 主函数
main() {
  echo -e "${YELLOW}=========================================${NC}"
  echo -e "${YELLOW}         ROS2环境诊断工具 v1.0          ${NC}"
  echo -e "${YELLOW}=========================================${NC}"

  check_network
  check_ros2_env
  check_ros2_nodes
  check_dds_config
  check_firewall
  show_summary
}

# 运行主函数
main
