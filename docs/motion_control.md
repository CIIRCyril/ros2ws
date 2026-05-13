# motion_control — ROS 2 Package

The `motion_control` package is the primary locomotion controller for the Walker / S2 humanoid robot.  
It exposes ROS 2 topics and services for commanding all body joints (legs, arms, waist, head, hands) and for switching high-level walk modes (stop / stand / walk / run / predefined motions).

---

## Table of Contents

1. [Package overview](#package-overview)
2. [Starting the node](#starting-the-node)
3. [Motor IDs and joint mapping](#motor-ids-and-joint-mapping)
4. [ROS 2 topics](#ros-2-topics)
5. [ROS 2 services](#ros-2-services)
6. [Motion modes](#motion-modes)
7. [Useful CLI commands](#useful-cli-commands)
8. [Python SDK examples](#python-sdk-examples)
9. [GUI tools](#gui-tools)
10. [Configuration](#configuration)

---

## Package overview

| Item | Value |
|------|-------|
| Package name | `motion_control` |
| Executable | `motioncontrol_node` |
| Launch file | `motion.py` |
| Config | `config/param.yaml`, `config/yaml/parameters.yaml` |
| Publish rate | 20 Hz (GUI) / controller-driven (node) |

The node is registered as a **composable component** (`motion_control::MotionControl`) and is loaded inside a multi-threaded component container with intra-process communication enabled.

---

## Starting the node

### Fast method (recommended for daily use)

Run in two separate terminals:

```bash
# Terminal 1 — body control (stops auto-start service first)
sudo ~/ros2ws/scripts/manual_debug.bash

# Terminal 2 — reinforcement-learning locomotion controller
sudo ~/ros2ws/scripts/start_rl.bash
```

### Manual method

```bash
sudo su
cd ~/ros2ws
source install/setup.bash

# Option A: body control node only
ros2 launch body_control body.launch.py

# Option B: motion_control composable node
ros2 launch motion_control motion.py

# Option C: RL locomotion node (in a second terminal after Option A/B)
ros2 run rl_control rl_control_node
```

### Stop the auto-start service first (if running)

```bash
sudo systemctl stop proc_manager.service
```

---

## Motor IDs and joint mapping

### Arms

| Motor ID | Side  | Joint            | Range (°)         |
|----------|-------|------------------|-------------------|
| 11       | Left  | Shoulder Pitch   | −170 … +170       |
| 12       | Left  | Shoulder Roll    | −15 … +150        |
| 13       | Left  | Shoulder Yaw     | −170 … +170       |
| 14       | Left  | Elbow Pitch      | −150 … +15        |
| 15       | Left  | Wrist Yaw        | −170 … +170       |
| 16       | Left  | Wrist Pitch      | −45 … +60         |
| 17       | Left  | Wrist Roll       | −95 … +75         |
| 21       | Right | Shoulder Pitch   | −170 … +170       |
| 22       | Right | Shoulder Roll    | −150 … +15        |
| 23       | Right | Shoulder Yaw     | −170 … +170       |
| 24       | Right | Elbow Pitch      | −150 … +15        |
| 25       | Right | Wrist Yaw        | −170 … +170       |
| 26       | Right | Wrist Pitch      | −45 … +60         |
| 27       | Right | Wrist Roll       | −75 … +95         |

### Waist

| Motor ID | Joint      | Range (°)  |
|----------|------------|------------|
| 31       | Waist Yaw  | −170 … +170 |

### Head

| Motor ID | Joint       | Range (°)  |
|----------|-------------|------------|
| 1        | Head Yaw    | −90 … +90  |
| 2        | Head Pitch  | −25 … +25  |
| 3        | Head Roll   | −26 … +26  |

### Legs

| Motor ID | Side  | Joint        | Range (°)   |
|----------|-------|--------------|-------------|
| 51       | Left  | Hip Roll     | −45 … +45   |
| 52       | Left  | Hip Pitch    | −160 … +120 |
| 53       | Left  | Hip Yaw      | −60 … +60   |
| 54       | Left  | Knee Pitch   | 0 … +137    |
| 55       | Left  | Ankle Pitch  | −70 … +30   |
| 56       | Left  | Ankle Roll   | −30 … +30   |
| 61       | Right | Hip Roll     | −45 … +45   |
| 62       | Right | Hip Pitch    | −160 … +120 |
| 63       | Right | Hip Yaw      | −60 … +60   |
| 64       | Right | Knee Pitch   | 0 … +137    |
| 65       | Right | Ankle Pitch  | −70 … +30   |
| 66       | Right | Ankle Roll   | −30 … +30   |

---

## ROS 2 topics

### Command topics (publish to control joints)

| Topic | Message type | Description |
|-------|-------------|-------------|
| `/leg/cmd_ctrl` | `bodyctrl_msgs/CmdMotorCtrl` | Leg MIT PD control (kp, kd, pos, spd, tor) |
| `/leg/cmd_pos` | `bodyctrl_msgs/CmdSetMotorPosition` | Leg trapezoidal position profile |
| `/leg/cmd_spd` | `bodyctrl_msgs/CmdSetMotorSpeed` | Leg constant-velocity control |
| `/arm/cmd_ctrl` | `bodyctrl_msgs/CmdMotorCtrl` | Arm MIT PD control |
| `/arm/cmd_pos` | `bodyctrl_msgs/CmdSetMotorPosition` | Arm trapezoidal position profile |
| `/arm/cmd_spd` | `bodyctrl_msgs/CmdSetMotorSpeed` | Arm constant-velocity control |
| `/waist/cmd_pos` | `bodyctrl_msgs/CmdSetMotorPosition` | Waist yaw position command |
| `/head/cmd_pos` | `bodyctrl_msgs/CmdSetMotorPosition` | Head roll/pitch/yaw position command |
| `/inspire_hand/ctrl/left_hand` | `sensor_msgs/JointState` | Left hand finger positions, velocities, effort |
| `/inspire_hand/ctrl/right_hand` | `sensor_msgs/JointState` | Right hand finger positions, velocities, effort |

### Status topics (subscribe to read motor feedback)

| Topic | Message type | Description |
|-------|-------------|-------------|
| `/leg/status` | `bodyctrl_msgs/MotorStatusMsg` | Leg motor feedback (pos, spd, current, temp, error) |
| `/arm/status` | `bodyctrl_msgs/MotorStatusMsg` | Arm motor feedback |
| `/waist/status` | `bodyctrl_msgs/MotorStatusMsg` | Waist motor feedback |
| `/head/status` | `bodyctrl_msgs/MotorStatusMsg` | Head motor feedback |
| `/hric/motion/motion_status` | `hric_msgs/MotionStatus` | High-level motion controller status (walk mode, velocity, error) |

### Joystick / remote input

| Topic | Message type | Description |
|-------|-------------|-------------|
| `/sbus_data` | `bodyctrl_msgs/SbusData` | Raw remote-control input (joystick axes, buttons, triggers) |

---

## ROS 2 services

### SetMotionMode — `/hric/motion/set_motion_mode`

Switch the robot's high-level motion mode.

**Request fields**

| Field | Type | Description |
|-------|------|-------------|
| `walk_mode_request` | `uint8` | Target mode (see table below) |
| `is_need_swing_arm` | `bool` | Enable arm swing during walking |

**Mode constants**

| Constant | Value | Description |
|----------|-------|-------------|
| `START`  | 0 | Start up |
| `STOP`   | 1 | Stop motion controller |
| `ZERO`   | 2 | Move to zero / home position |
| `STAND`  | 3 | Stand still |
| `WALK`   | 4 | Walk (use before autonomous navigation) |
| `RUN`    | 5 | Run |

**Response fields**

| Field | Type | Description |
|-------|------|-------------|
| `success` | `bool` | `true` if mode switch succeeded |
| `error_code` | `uint32` | Error code (0 = OK) |

---

### SetMotionNumber — `/hric/motion/set_motion_number`

Trigger a predefined motion sequence by index.

**Request fields**

| Field | Type | Description |
|-------|------|-------------|
| `is_motion` | `bool` | `true` to start, `false` to stop |
| `motion_number` | `int32` | Index of the predefined motion |

**Response fields**

| Field | Type | Description |
|-------|------|-------------|
| `success` | `bool` | `true` if the call succeeded |

---

## Motion modes

The `MotionStatus` message (`/hric/motion/motion_status`) reports the current walk state:

| Value | State | Description |
|-------|-------|-------------|
| 0 | stop | Stopped |
| 1 | zero | Zero / home position |
| 2 | Z2S | Transitioning zero → stand |
| 3 | stand | Standing still |
| 4 | S2W | Transitioning stand → walk |
| 5 | walk | Walking |
| 6 | start | Starting up |
| 7 | run | Running |

> **Important:** Always request `WALK` mode (4) before autonomous navigation starts and `STAND` (3) or `STOP` (1) after navigation ends.

---

## Useful CLI commands

### Inspect motion status

```bash
# Stream live motion controller status
ros2 topic echo /hric/motion/motion_status

# Check topic info / publisher count
ros2 topic info /hric/motion/motion_status

# Check all active topics
ros2 topic list

# Show message definition
ros2 interface show hric_msgs/msg/MotionStatus
```

### Control motion mode

```bash
# Switch to STAND mode
ros2 service call /hric/motion/set_motion_mode hric_msgs/srv/SetMotionMode \
  "{walk_mode_request: 3, is_need_swing_arm: false}"

# Switch to WALK mode (with arm swing)
ros2 service call /hric/motion/set_motion_mode hric_msgs/srv/SetMotionMode \
  "{walk_mode_request: 4, is_need_swing_arm: true}"

# Switch to WALK mode (without arm swing)
ros2 service call /hric/motion/set_motion_mode hric_msgs/srv/SetMotionMode \
  "{walk_mode_request: 4, is_need_swing_arm: false}"

# Stop the motion controller
ros2 service call /hric/motion/set_motion_mode hric_msgs/srv/SetMotionMode \
  "{walk_mode_request: 1, is_need_swing_arm: false}"

# Move to zero/home position
ros2 service call /hric/motion/set_motion_mode hric_msgs/srv/SetMotionMode \
  "{walk_mode_request: 2, is_need_swing_arm: false}"
```

### Trigger predefined motions

```bash
# Start predefined motion number 3
ros2 service call /hric/motion/set_motion_number hric_msgs/srv/SetMotionNumber \
  "{is_motion: true, motion_number: 3}"

# Stop predefined motion
ros2 service call /hric/motion/set_motion_number hric_msgs/srv/SetMotionNumber \
  "{is_motion: false, motion_number: 0}"
```

### Monitor motor status

```bash
# Stream leg motor feedback
ros2 topic echo /leg/status

# Stream arm motor feedback
ros2 topic echo /arm/status

# Stream head motor feedback
ros2 topic echo /head/status

# Stream waist motor feedback
ros2 topic echo /waist/status
```

### Publish a head position command (yaw, pitch, roll to 0°)

```bash
ros2 topic pub --once /head/cmd_pos bodyctrl_msgs/msg/CmdSetMotorPosition \
  "{cmds: [{name: 1, pos: 0.0, spd: 0.2, cur: 8.0},
            {name: 2, pos: 0.0, spd: 0.2, cur: 8.0},
            {name: 3, pos: 0.0, spd: 0.2, cur: 8.0}]}"
```

### Publish a waist command (center position)

```bash
ros2 topic pub --once /waist/cmd_pos bodyctrl_msgs/msg/CmdSetMotorPosition \
  "{cmds: [{name: 31, pos: 0.0, spd: 0.2, cur: 8.0}]}"
```

---

## Python SDK examples

### Switch to Walk mode

```python
import rclpy
from rclpy.node import Node
from hric_msgs.srv import SetMotionMode

rclpy.init()
node = Node('motion_client')
cli = node.create_client(SetMotionMode, '/hric/motion/set_motion_mode')
cli.wait_for_service(timeout_sec=5.0)

req = SetMotionMode.Request()
req.walk_mode_request = SetMotionMode.Request.WALK  # 4
req.is_need_swing_arm = True

future = cli.call_async(req)
rclpy.spin_until_future_complete(node, future)
print(future.result())
node.destroy_node()
rclpy.shutdown()
```

### Trigger predefined motion

```python
import rclpy
from rclpy.node import Node
from hric_msgs.srv import SetMotionNumber

rclpy.init()
node = Node('motion_trigger')
cli = node.create_client(SetMotionNumber, '/hric/motion/set_motion_number')
cli.wait_for_service(timeout_sec=5.0)

req = SetMotionNumber.Request()
req.is_motion = True
req.motion_number = 3  # motion index

future = cli.call_async(req)
rclpy.spin_until_future_complete(node, future)
print(future.result())
node.destroy_node()
rclpy.shutdown()
```

### Subscribe to motion status

```python
import rclpy
from rclpy.node import Node
from hric_msgs.msg import MotionStatus

def cb(msg):
    print(f"walk_mode={msg.walk_mode}  vel_x={msg.velocity.linear.x:.3f}  "
          f"swing_arm={msg.is_swing_arm}  error={msg.error_code}")

rclpy.init()
node = Node('motion_monitor')
node.create_subscription(MotionStatus, '/hric/motion/motion_status', cb, 10)
rclpy.spin(node)
```

---

## GUI tools

### Unified motion control GUI

`examples/motion_control_GUI.py` — Tkinter GUI covering all joints in a single window.

```bash
cd ~/ros2ws
source install/setup.bash
python3 examples/motion_control_GUI.py
```

**Tabs**

| Tab | Motors | Modes |
|-----|--------|-------|
| Legs | 51–56 (L), 61–66 (R) | MIT \| Position \| Speed |
| Arms | 11–17 (L), 21–27 (R) | MIT \| Position \| Speed |
| Waist | 31 | Position |
| Head | 1–3 | Position |
| Hands | Left & right Inspire hand | Position + velocity per finger |
| Positions | Saved positions library | Save / load / execute named poses |

**Global controls**

| Button | Action |
|--------|--------|
| STOP MOTION | Call `/hric/motion/set_motion_mode` with `STOP` |
| ZERO ALL JOINTS | Set all sliders and motor commands to 0° |
| SAVE POSITION | Snapshot current joint positions to `saved_positions.csv` |

**Control modes (Legs & Arms)**

| Mode | Topic | Description |
|------|-------|-------------|
| MIT | `/leg/cmd_ctrl`, `/arm/cmd_ctrl` | Direct PD torque control with per-joint kp/kd gains |
| Position | `/leg/cmd_pos`, `/arm/cmd_pos` | Trapezoidal profile; set profile speed (rpm) and current limit (A) |
| Speed | `/leg/cmd_spd`, `/arm/cmd_spd` | Constant velocity per joint in rpm |

> ⚠ **Legs tab warning:** Never command leg motors while the robot is standing without a support fixture. Always press **STOP MOTION** first.

---

### Other available GUI scripts

| Script | Description |
|--------|-------------|
| `examples/arm_slider.py` | Tkinter GUI for left/right arm and waist joints (MIT \| Position \| Speed) |
| `examples/leg_slider.py` | Tkinter GUI dedicated to leg joints (MIT \| Position \| Speed) |
| `examples/head_slider.py` | Tkinter GUI for head roll/pitch/yaw |
| `examples/headwaist_slider.py` | Tkinter GUI combining head and waist control |
| `examples/finger_slider.py` | Tkinter GUI for left/right Inspire hand fingers |
| `examples/remote.py` | Virtual remote control (emulates physical joystick via SbusData) |
| `examples/remote2.py` | Extended remote control for Walker robot |

### Motion playback / visualization

| Script | Description |
|--------|-------------|
| `examples/robot_motion.py` | Play back recorded motion `.txt` files on the S2 robot in PyBullet simulation |
| `examples/visualize_motion.py` | Plot joint trajectories from a motion file as a time-series chart |
| `examples/motion/*.txt` | Recorded motion sequences (space-separated joint values, ~1 000 frames each) |

---

## Configuration

### `config/param.yaml`

Top-level node parameters.

| Parameter | Default | Description |
|-----------|---------|-------------|
| `intra_process_comms` | `true` | Use ROS 2 intra-process communication |

### `config/yaml/parameters.yaml`

MPC / controller tuning parameters for the Max2 / S2 robot.  
Key parameters (active values for Max2):

| Parameter | Value | Description |
|-----------|-------|-------------|
| `height` | 0.88 m | Target CoM height |
| `foot_height` | 0.06 m | Swing foot lift height |
| `period` | 0.4 s | Gait cycle period |
| `period_d` | 0.4 s | Double-support period |
| `period2` | 0.3 s | Sub-period |
| `early_terminate` | 0.95 | Early foot-landing threshold |
| `vel_y_osci` | 0.3 | Lateral oscillation amplitude |
| `x_bound` | 0.3 m | Foot placement x bound |
| `y_bound_out` | 0.4 m | Foot placement y outer bound |
| `imu_offset_roll` | 0.0 | IMU roll offset correction (rad) |
| `imu_offset_pitch` | 0.0 | IMU pitch offset correction (rad) |

**PD gain matrices (simulation defaults)**

| Group | kp | kd |
|-------|----|----|
| Leg joints | `[1000, 1000, 502, 298, 4, 1]` | `[10, 10, 10, 10, 0.1, 0.025]` |
| Waist | `[0]` | `[0]` |
| Arm joints (3 active) | `[0, 0, 0]` | `[0, 0, 0]` |

**Motor torque limits**

| Group | Max torque (N·m) |
|-------|-----------------|
| Leg | ±[150, 90, 150, 150, 60, 30] |
| Waist | ±100 |
| Arm (3 joints) | ±36 |

**Motor velocity limits**

| Group | Max velocity (rad/s) |
|-------|---------------------|
| Leg | [12, 14, 12, 12, 7.8, 7.8] |
| Waist | 100 |
| Arm (3 joints) | 7.8 |
