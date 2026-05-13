# Our Code

The `examples/` folder contains our custom scripts for controlling and debugging the robot.

| Script | Description |
|--------|-------------|
| `arm_slider.py` | Tkinter GUI for directly controlling the robot's left/right arm and waist joints in MIT, position, or speed mode. |
| `finger_slider.py` | Tkinter GUI for controlling both hands' finger positions and velocities, with open/close buttons and a random motion mode. |
| `head_slider.py` | Tkinter GUI for controlling the robot head's roll, pitch, and yaw joints with live motor status feedback. |
| `headwaist_slider.py` | Tkinter GUI for simultaneously controlling both the head (roll, pitch, yaw) and waist (yaw) joints with status feedback. |
| `remote.py` | Tkinter GUI remote control that emulates the physical joystick by publishing SbusData messages, with push buttons, toggle switches, dual joysticks, motion mode selection, and custom action triggers. |
| `remote2.py` | Extended version of `remote.py` with the same remote control GUI for the Walker robot, publishing SbusData messages at 20 Hz. |
| `test_topics.py` | Minimal ROS2 node that subscribes to head status and hand state topics to verify they are active and publishing data. |
| `manual_debug.bash` | Bash script that stops the auto-start service and launches the body control node manually for debugging. |
| `start_rl.bash` | Bash script that launches the reinforcement learning control node (`rl_control_node`). |

## Documentation

Detailed documentation is maintained in the [`docs/`](docs/) folder.

| File | Description |
|------|-------------|
| [docs/motion_control.md](docs/motion_control.md) | Motion control package overview — topics, services, motion modes, motor IDs, CLI commands, Python SDK examples, GUI tools, and configuration reference. |
| [docs/hric_msgs.md](docs/hric_msgs.md) | Custom ROS 2 message/service/action definitions for the HRIC system (topics, services, actions for navigation, motion, and map-marker subsystems). |
| [docs/bodyctrl_msgs.md](docs/bodyctrl_msgs.md) | Custom ROS 2 message/service definitions for the body control system (motor control, hand control, waist, IMU, force/torque sensors, power board, and remote input). |

# TODO List

- [✅] Operate ROS2 from remote computer (Rviz,Rqt etc.)
- [✅] Python GUI to control head
- [✅] Python GUI to control hands
- [✅] Python GUI for remote control
- [✅] Python GUI for full body control
- [✅] Vision node with basic 3D vision
- [✅] Alignment of robot with model
- [✅] Custom poses execution
- [ ] Implement czech chatbot to the robot
- [ ] Implement inverse kinematics to control arms
- [ ] Implement 2D and 3D vision to the robot
- [ ] Implement teleoperation for Walker robot (Sonic etc.)
- [ ] Train RL policies for walking and manipulation in the simulator
- [ ] Implement native VLA to the robot
- [ ] Implement custom VLA to the robot
- [ ] Implement iChores architecture
- [ ] Develop and test Chatbot demo
- [ ] Develop and test Walking sequence from code demo
- [ ] Develop and test Name visually recognized objects demo
- [ ] Develop and test Reach object demo based on IK solver
- [ ] Develop and test Reach object demo based on pretrained RL policy
- [ ] Develop and test Pick and place demo
- [ ] Develop and test Locomanipulation demo 

# How to operate Cyril

## Turning on

1.Press battery button (left to Red emergency switch) - it will turn red.

2. Pres shortly the power button (right to red emergency switch) - the fan will start and robots boots 1 minute with the sound at the end)

3. Click the emergency button, the power button becomes green

## Remote control operation

1. Press A button and wait 20 sec to finish self check procedure (the sound played and the T logo becomes blue)
2. Press D button - legs will move to calibrate position
3. Move robot to the ground with loose leashes, hold the robot neck in stable position and wait 60 sec to calibrate IMU sensors (WARNING - robot is not stable at this stage and no sound played after calibration) 
4. Long press A button and robot will stand (carefull about crank position over head). If the robot does not stand safely, press C, hold robot, move him up and repeat calibration procesure again)
5. If robot stays, push G to the left and back to start walking mode and use joystick (very gently) to walk
6. Press A to stop walking mode and stay. 
7. Press A to start predefined motion. Cycle motion library with B press n times and A to activate
8. Move F to up postion and press A to activate predefined voices, with B n times for cycling voice output.



## Operational mode

FAST METHOD 
Run our scripts in 2 terminals
sudo ~/ros2ws/scripts/start_debug.bash
sudo ~/ros2ws/scripts/start_rl.bash

SLOW METHOD
1. To start manually, please ensure that the auto-start function has been turned
off first.

sudo systemctl stop proc_manager.service


2. First, open the first terminal and enter the following commands in sequence
to start the master control node: (OUR SCRIPT IS sudo ./ros2ws/scripts/manual_debug.)

sudo su

cd ros2ws

source install/setup.bash

ros2 launch body_control body.launch.py

3. If you need to start the Motion Control - Reinforcement Learning node, 
you should change it to enter the following commands in sequence:
Plain Text
sudo su
cd ros2ws
source install/setup.bash
ros2 run rl_control rl_control_node
You can start using the SDK for development and debugging at this time.

4. Config for auto-start mode is here - also sounds and remote key mapping (DOES NOT WORK)
/home/ubuntu/ros2ws/install/proc_manager/share/proc_manager/proc_manager.json


## Enable debug over wifi

FASTRTPS_DEFAULT_PROFILES_FILE: DDS configuration file. By default, using 
Wi-Fi for DDS communication debugging is prohibited


## Shutdown
1. Confirm that the robot has stopped and returned to the standing state.
2. Press the "C" key on the remote control to make the robot freeze.
3. Fix the robot on the bracket and lift it up.
4. Press the emergency stop button.5.
Long - press the on/off key for 6 seconds.
6. Press the main on/off key. At this time, all status lights will be completely
extinguished. First, briefly press and then immediately long - press the power key on


### LOG OF RANDOM FINDINGS

## How access robot remotely - Web browser

192.168.0.12:8080


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

## Chatbot

ssh Nvidia2
cd audio_ros2
bash start_xunfei.sh
second terminal
ssh Nvidia2
cd audio_ros2
bash start_voice.sh
third terminal
ssh Nvidia2
cd audio_ros2
bash start_kaiwu.sh

## Where rosbag is configured 
/home/ubuntu/ros2ws/install/utils/lib/utils/bag_record/config



