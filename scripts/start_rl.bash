#!/bin/bash
cd /home/ubuntu/ros2ws
source install/setup.bash
cd ros2ws

source install/setup.bash

ros2 run rl_control rl_control_node

