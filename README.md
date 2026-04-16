### LOG OF RANDOM FINDINGS

## How access robot remotely over ssh

Script to explore topics from external computer over ssh

python ./scripts/ros2_remote_explorer.py

## How access robot with ROS2 - Wifi and LAN

If you have new computer, you need to whitelist it in robot computers - there is ~/data/param/ xml file, whre you need to add your IP adress to whitelist, otherwise you do not see the topics.

More topics is visible over LAN (WIP)

## Known topics

Ubuntu machine

/arm_6dof_left,right - Force and torque sensors values from arms

/inspire_hand/state/left - States of fingers 

/sbus_data - keypress from remote (joystick has continuos values from 0-1), buttons -1,1 and triggers -1;0;1



