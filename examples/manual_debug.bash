#!/bin/bash
cd /home/ubuntu/ros2ws
source install/setup.bash
systemctl stop proc_manager.service
sleep 3
ros2 launch body_control body.launch.py

