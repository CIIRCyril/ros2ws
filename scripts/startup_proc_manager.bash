#!/bin/bash

sleep 20
if [ -d /home/ubuntu/ros2ws ];then
  ros_home_dir=/home/ubuntu/ros2ws
  cd ${ros_home_dir}
  export ROS_HOME=${ros_home_dir}
  source /opt/ros/humble/setup.bash
  source install/setup.bash
  export FASTRTPS_DEFAULT_PROFILES_FILE=/home/ubuntu/data/param/dds_profile.xml
  export RMW_IMPLEMENTATION=rmw_fastrtps_cpp
  ros2 launch proc_manager tg2.0_pro.launch.py
elif [ -d /home/ubuntu/rosws ];then
  ros_home_dir=/home/ubuntu/rosws
  cd ${ros_home_dir}
  export ROS_HOME=${ros_home_dir}
  export LD_LIBRARY_PATH=${ros_home_dir}/install_isolated/lib:/opt/ros/noetic/lib
  source install_isolated/setup.bash
  roslaunch proc_manager proc_manager_tg2.0.launch
fi
