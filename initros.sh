#!/bin/bash
conda deactivate 2>/dev/null || true
source /opt/ros/humble/setup.bash
export ROS_DOMAIN_ID=0
export FASTRTPS_DEFAULT_PROFILES_FILE="$PWD/fastdds.xml"
source "/home/michal/code/ros2ws/install/setup.bash"
