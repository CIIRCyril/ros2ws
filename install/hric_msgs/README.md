# hric_msgs — ROS 2 Message Package

Custom ROS 2 message package for the HRIC (Humanoid Robot Interface & Control) system.  
It defines the topics, services, and actions used to monitor and control the robot's navigation, localization, motion, and map-marker subsystems.

---

## Table of Contents

1. [Package layout](#package-layout)
2. [Messages (Topics)](#messages-topics)
   - [FloatBaseRPYZ](#floatbaserpyz)
   - [LocStatus](#locstatus)
   - [MarkerInfo](#markerinfo)
   - [MotionStatus](#motionstatus)
   - [NavStatus](#navstatus)
3. [Services](#services)
   - [SetMotionMode](#setmotionmode)
   - [SetMotionNumber](#setmotionnumber)
   - [SetGoal](#setgoal)
   - [Relocate](#relocate)
   - [VisualRelocate](#visualrelocate)
   - [SetVisualLocMode](#setvisuallocmode)
   - [MarkHere](#markhere)
   - [MarkAtPose](#markatpose)
   - [UpdateMarker](#updatemarker)
   - [OperateMarker](#operatemarker)
   - [ListMarkers](#listmarkers)
4. [Actions](#actions)
   - [NavToPose](#navtopose)
   - [NavThroughPoses](#navthroughposes)
5. [Useful CLI Commands](#useful-cli-commands)
6. [Python Usage Examples](#python-usage-examples)

---

## Package layout

```
install/hric_msgs/
├── include/hric_msgs/   # C++ headers (generated)
├── lib/                 # Shared libraries
└── share/hric_msgs/
    ├── msg/             # Message definitions
    ├── srv/             # Service definitions
    └── action/          # Action definitions
```

---

## Messages (Topics)

### FloatBaseRPYZ

`hric_msgs/msg/FloatBaseRPYZ`

Robot base orientation and height.

| Field   | Type      | Description              |
|---------|-----------|--------------------------|
| `roll`  | `float64` | Roll angle (rad)         |
| `pitch` | `float64` | Pitch angle (rad)        |
| `yaw`   | `float64` | Yaw angle (rad)          |
| `z`     | `float64` | Height / Z position (m)  |

---

### LocStatus

`hric_msgs/msg/LocStatus`

Laser/LiDAR localization status published by the localization module.

| Field        | Type                           | Description               |
|--------------|--------------------------------|---------------------------|
| `status`     | `uint8`                        | Current status code       |
| `confidence` | `float64`                      | Localization confidence   |
| `error_code` | `uint32`                       | Error code                |
| `pose`       | `geometry_msgs/PoseStamped`    | Estimated robot pose      |

**Status constants**

| Constant        | Value | Meaning                                           |
|-----------------|-------|---------------------------------------------------|
| `IDLE`          | 100   | Idle — navigation not possible                    |
| `INITIALIZING`  | 101   | Initializing — navigation not possible            |
| `RUNNING`       | 102   | Normal operation                                  |
| `WEAK`          | 103   | Weak localization signal                          |
| `LOST`          | 104   | Localization lost — navigation not possible       |
| `BLOCKED`       | 105   | Sensor error / init failed — navigation blocked   |

**Error code constants**

| Constant               | Value | Meaning              |
|------------------------|-------|----------------------|
| `NONE`                 | 0     | No error             |
| `UNKNOWN`              | 200   | Unknown error        |
| `TF_ERROR`             | 201   | TF transform error   |
| `SENSOR_ERROR`         | 202   | Sensor anomaly       |
| `RELOCALIZATION_ERROR` | 203   | Relocalization failed|

---

### MarkerInfo

`hric_msgs/msg/MarkerInfo`

Describes a named map marker (waypoint).

| Field    | Type                     | Description                          |
|----------|--------------------------|--------------------------------------|
| `name`   | `string`                 | Unique marker name                   |
| `map_id` | `string`                 | Map identifier                       |
| `floor`  | `string`                 | Floor/level name                     |
| `pose`   | `geometry_msgs/Pose2D`   | 2-D position (x, y, theta in rad)   |

---

### MotionStatus

`hric_msgs/msg/MotionStatus`

Real-time motion controller status.

| Field              | Type                      | Description                                                  |
|--------------------|---------------------------|--------------------------------------------------------------|
| `header`           | `std_msgs/Header`         | Timestamp and frame ID                                       |
| `velocity`         | `geometry_msgs/Twist`     | Velocity in robot waist frame                                |
| `walk_mode`        | `uint8`                   | Current walk state (see table below)                         |
| `is_console_control` | `bool`               | `true` = joystick control, `false` = navigation control      |
| `is_swing_arm`     | `bool`                    | Whether arm-swing is active during walk                      |
| `error_code`       | `uint32`                  | Error code (`NONE=0`, `UNKNOWN=400`)                         |

**Walk mode values**

| Value | State  | Description                    |
|-------|--------|--------------------------------|
| 0     | stop   | Stopped                        |
| 1     | zero   | Zero / home position           |
| 2     | Z2S    | Transitioning zero → stand     |
| 3     | stand  | Standing still                 |
| 4     | S2W    | Transitioning stand → walk     |
| 5     | walk   | Walking                        |
| 6     | start  | Starting up                    |
| 7     | run    | Running                        |

---

### NavStatus

`hric_msgs/msg/NavStatus`

Navigation task status.

| Field        | Type     | Description           |
|--------------|----------|-----------------------|
| `status`     | `uint8`  | Current status code   |
| `error_code` | `uint32` | Error code            |

**Status constants**

| Constant       | Value | Meaning                         |
|----------------|-------|---------------------------------|
| `IDLE`         | 0     | No active navigation task       |
| `EXECUTE_TASK` | 1     | Navigating to goal              |
| `CANCELED`     | 2     | Task was cancelled              |
| `FAILED`       | 3     | Task failed                     |
| `REACHED_GOAL` | 4     | Goal reached successfully       |

**Error code constants**

| Constant         | Value | Meaning              |
|------------------|-------|----------------------|
| `NONE`           | 0     | No error             |
| `UNKNOWN`        | 100   | Unknown error        |
| `GOAL_OCCUPIED`  | 101   | Goal position blocked|
| `TIMEOUT`        | 102   | Planning timed out   |
| `NO_VALID_PATH`  | 103   | No valid path found  |

---

## Services

### SetMotionMode

`hric_msgs/srv/SetMotionMode`  
**ROS 2 path:** `/hric/motion/set_motion_mode`

Switch the robot's motion mode (stand / walk / run / etc.).  
> **Important:** Request `WALK` mode before navigation starts; request `STAND` mode after navigation ends.

**Request**

| Field                | Type    | Description                            |
|----------------------|---------|----------------------------------------|
| `walk_mode_request`  | `uint8` | Target mode (see constants below)      |
| `is_need_swing_arm`  | `bool`  | Enable arm swing while walking         |

**Mode constants**

| Constant | Value | Description  |
|----------|-------|--------------|
| `START`  | 0     | Start up     |
| `STOP`   | 1     | Stop         |
| `ZERO`   | 2     | Zero/home    |
| `STAND`  | 3     | Stand still  |
| `WALK`   | 4     | Walk         |
| `RUN`    | 5     | Run          |

**Response**

| Field        | Type     | Description                     |
|--------------|----------|---------------------------------|
| `success`    | `bool`   | `true` if mode switch succeeded |
| `error_code` | `uint32` | Error code                      |

---

### SetMotionNumber

`hric_msgs/srv/SetMotionNumber`  
**ROS 2 path:** `/hric/motion/set_motion_number`

Trigger a predefined motion by index number.

**Request**

| Field           | Type    | Description                     |
|-----------------|---------|---------------------------------|
| `is_motion`     | `bool`  | Enable/disable predefined motion|
| `motion_number` | `int32` | Index of the predefined motion  |

**Response**

| Field     | Type   | Description                     |
|-----------|--------|---------------------------------|
| `success` | `bool` | `true` if the call succeeded    |

---

### SetGoal

`hric_msgs/srv/SetGoal`

Send a single navigation goal pose.

**Request**

| Field  | Type                          | Description                                                             |
|--------|-------------------------------|-------------------------------------------------------------------------|
| `goal` | `geometry_msgs/PoseStamped`   | Target pose. `frame_id="map"` for global; `"base_link"` for local/relative |

**Response**

| Field        | Type     | Description             |
|--------------|----------|-------------------------|
| `success`    | `bool`   | `true` on success       |
| `message`    | `string` | Failure reason          |
| `error_code` | `uint32` | Error code (see NavStatus) |

---

### Relocate

`hric_msgs/srv/Relocate`

Trigger laser-based relocalization.

**Request**

| Field        | Type                          | Description                                   |
|--------------|-------------------------------|-----------------------------------------------|
| `pose_robot` | `geometry_msgs/PoseStamped`   | Robot pose hint (required for `LOCAL_MATCH`)  |
| `match_type` | `uint8`                       | `LOCAL_MATCH=1` or `GLOBAL_MATCH=2`           |

**Response**

| Field        | Type     | Description              |
|--------------|----------|--------------------------|
| `success`    | `bool`   | `true` on success        |
| `error_code` | `uint32` | Error code               |
| `message`    | `string` | Failure reason           |

**Error codes:** `NONE=0`, `UNKNOWN=200`, `TF_ERROR=201`, `SENSOR_ERROR=202`, `LOW_CONFIDENCE=203`

---

### VisualRelocate

`hric_msgs/srv/VisualRelocate`

Trigger camera-based relocalization.

**Request**

| Field       | Type                          | Description                                         |
|-------------|-------------------------------|-----------------------------------------------------|
| `pose_ref`  | `geometry_msgs/PoseStamped`   | Reference pose hint (required for `LOCAL_MATCH`)    |
| `match_type`| `uint8`                       | `LOCAL_MATCH=1` or `GLOBAL_MATCH=2`                 |

**Response**

| Field         | Type                          | Description               |
|---------------|-------------------------------|---------------------------|
| `pose_robot`  | `geometry_msgs/PoseStamped`   | Estimated robot pose      |
| `success`     | `bool`                        | `true` on success         |
| `error_code`  | `uint32`                      | Error code                |
| `message`     | `string`                      | Failure reason            |

**Error codes:** same as `Relocate`

---

### SetVisualLocMode

`hric_msgs/srv/SetVisualLocMode`

Switch the visual localization mode.

**Request**

| Field      | Type    | Description               |
|------------|---------|---------------------------|
| `loc_mode` | `uint8` | Target mode (see below)   |

**Mode constants**

| Constant          | Value | Description                    |
|-------------------|-------|--------------------------------|
| `IDLE_MODE`       | 0     | Inactive                       |
| `ODOM_MODE`       | 1     | Odometry only                  |
| `MAP_REFINE_MODE` | 2     | Map-assisted refinement        |
| `MAP_LOC_MODE`    | 3     | Full map-based localization    |

**Response**

| Field        | Type     | Description     |
|--------------|----------|-----------------|
| `success`    | `bool`   | `true` on success|
| `error_code` | `uint32` | Error code       |
| `message`    | `string` | Failure reason   |

---

### MarkHere

`hric_msgs/srv/MarkHere`

Create a marker at the robot's **current** position.

**Request**

| Field    | Type     | Description                                 |
|----------|----------|---------------------------------------------|
| `name`   | `string` | Unique marker name                          |
| `map_id` | `string` | Map ID (empty = current map)                |
| `floor`  | `string` | Floor name (empty = current floor)          |

**Response**

| Field     | Type                      | Description              |
|-----------|---------------------------|--------------------------|
| `success` | `bool`                    | `true` on success        |
| `message` | `string`                  | Failure reason           |
| `marker`  | `hric_msgs/MarkerInfo`    | Created marker info      |

---

### MarkAtPose

`hric_msgs/srv/MarkAtPose`

Create a marker at a **specified** pose.

**Request**

| Field    | Type                   | Description                                    |
|----------|------------------------|------------------------------------------------|
| `name`   | `string`               | Unique marker name                             |
| `map_id` | `string`               | Map ID (empty = current map)                   |
| `floor`  | `string`               | Floor name (empty = current floor)             |
| `pose`   | `geometry_msgs/Pose2D` | Target 2-D pose; `theta` in `[-π, π)`          |

**Response**

| Field     | Type                      | Description              |
|-----------|---------------------------|--------------------------|
| `success` | `bool`                    | `true` on success        |
| `message` | `string`                  | Failure reason           |
| `marker`  | `hric_msgs/MarkerInfo`    | Created marker info      |

---

### UpdateMarker

`hric_msgs/srv/UpdateMarker`

Update an existing marker's pose.

**Request**

| Field    | Type                   | Description                                    |
|----------|------------------------|------------------------------------------------|
| `name`   | `string`               | Marker to update                               |
| `map_id` | `string`               | Map ID (empty = current map)                   |
| `floor`  | `string`               | Floor name (empty = current floor)             |
| `pose`   | `geometry_msgs/Pose2D` | New 2-D pose; `theta` in `[-π, π)`             |

**Response**

| Field        | Type                      | Description              |
|--------------|---------------------------|--------------------------|
| `success`    | `bool`                    | `true` on success        |
| `message`    | `string`                  | Failure reason           |
| `marker_old` | `hric_msgs/MarkerInfo`    | Previous marker info     |
| `marker_new` | `hric_msgs/MarkerInfo`    | Updated marker info      |

---

### OperateMarker

`hric_msgs/srv/OperateMarker`

Operate on (e.g., delete) a named marker.

**Request**

| Field  | Type     | Description        |
|--------|----------|--------------------|
| `name` | `string` | Marker name        |

**Response**

| Field     | Type                      | Description              |
|-----------|---------------------------|--------------------------|
| `success` | `bool`                    | `true` on success        |
| `message` | `string`                  | Failure reason           |
| `marker`  | `hric_msgs/MarkerInfo`    | Affected marker info     |

---

### ListMarkers

`hric_msgs/srv/ListMarkers`

Retrieve all stored markers.

**Request** — *(empty)*

**Response**

| Field     | Type                        | Description              |
|-----------|-----------------------------|--------------------------|
| `markers` | `hric_msgs/MarkerInfo[]`    | List of all markers      |

---

## Actions

### NavToPose

`hric_msgs/action/NavToPose`

Navigate the robot to a single goal pose.

**Goal**

| Field  | Type                        | Description    |
|--------|-----------------------------|----------------|
| `pose` | `geometry_msgs/PoseStamped` | Target pose    |

**Result**

| Field        | Type     | Description                          |
|--------------|----------|--------------------------------------|
| `error_code` | `uint32` | `NONE=0`, `GOAL_OCCUPIED=101`, `TIMEOUT=102`, `NO_VALID_PATH=103` |

**Feedback** — *(none defined)*

---

### NavThroughPoses

`hric_msgs/action/NavThroughPoses`

Navigate the robot through an ordered sequence of waypoints.

**Goal**

| Field   | Type                          | Description         |
|---------|-------------------------------|---------------------|
| `poses` | `geometry_msgs/PoseStamped[]` | Ordered waypoints   |

**Result**

| Field        | Type     | Description                          |
|--------------|----------|--------------------------------------|
| `error_code` | `uint32` | `NONE=0`, `GOAL_OCCUPIED=101`, `TIMEOUT=102`, `NO_VALID_PATH=103` |

**Feedback** — *(none defined)*

---

## Useful CLI Commands

All commands assume the workspace is sourced:

```bash
source ~/ros2ws/install/setup.bash
```

### Introspection

```bash
# List all running topics
ros2 topic list

# List all available services
ros2 service list

# List all available actions
ros2 action list

# Show live message on a topic (e.g. motion status)
ros2 topic echo /hric/motion/motion_status

# Show live localization status
ros2 topic echo /hric/loc/loc_status

# Show live navigation status
ros2 topic echo /hric/nav/nav_status

# Check message type for a topic
ros2 topic info /hric/motion/motion_status

# Print full message structure
ros2 interface show hric_msgs/msg/MotionStatus
ros2 interface show hric_msgs/msg/LocStatus
ros2 interface show hric_msgs/msg/NavStatus
ros2 interface show hric_msgs/srv/SetMotionMode
ros2 interface show hric_msgs/action/NavToPose
```

### Motion Control

```bash
# Switch to STAND mode (mode=3)
ros2 service call /hric/motion/set_motion_mode hric_msgs/srv/SetMotionMode \
  "{walk_mode_request: 3, is_need_swing_arm: false}"

# Switch to WALK mode with arm swing (mode=4)
ros2 service call /hric/motion/set_motion_mode hric_msgs/srv/SetMotionMode \
  "{walk_mode_request: 4, is_need_swing_arm: true}"

# Switch to WALK mode without arm swing (mode=4)
ros2 service call /hric/motion/set_motion_mode hric_msgs/srv/SetMotionMode \
  "{walk_mode_request: 4, is_need_swing_arm: false}"

# Stop robot (mode=1)
ros2 service call /hric/motion/set_motion_mode hric_msgs/srv/SetMotionMode \
  "{walk_mode_request: 1, is_need_swing_arm: false}"

# Trigger predefined motion number 3
ros2 service call /hric/motion/set_motion_number hric_msgs/srv/SetMotionNumber \
  "{is_motion: true, motion_number: 3}"
```

### Navigation

```bash
# Send a navigation goal using the SetGoal service (global frame)
ros2 service call /hric/nav/set_goal hric_msgs/srv/SetGoal \
  "{goal: {header: {frame_id: 'map'}, pose: {position: {x: 1.0, y: 0.5, z: 0.0}, orientation: {w: 1.0}}}}"

# Navigate to a pose via action (global frame)
ros2 action send_goal /hric/nav/nav_to_pose hric_msgs/action/NavToPose \
  "{pose: {header: {frame_id: 'map'}, pose: {position: {x: 2.0, y: 1.0, z: 0.0}, orientation: {w: 1.0}}}}"

# Navigate through multiple waypoints
ros2 action send_goal /hric/nav/nav_through_poses hric_msgs/action/NavThroughPoses \
  "{poses: [{header: {frame_id: 'map'}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}},
            {header: {frame_id: 'map'}, pose: {position: {x: 2.0, y: 1.0, z: 0.0}, orientation: {w: 1.0}}}]}"

# Cancel all active navigation goals
ros2 action cancel /hric/nav/nav_to_pose
```

### Localization

```bash
# Trigger global laser relocalization (no pose hint needed)
ros2 service call /hric/loc/relocate hric_msgs/srv/Relocate \
  "{match_type: 2}"

# Trigger local laser relocalization with a pose hint
ros2 service call /hric/loc/relocate hric_msgs/srv/Relocate \
  "{pose_robot: {header: {frame_id: 'map'}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}}, match_type: 1}"

# Switch visual localization to full map mode
ros2 service call /hric/loc/set_visual_loc_mode hric_msgs/srv/SetVisualLocMode \
  "{loc_mode: 3}"
```

### Map Markers

```bash
# Create a marker at the robot's current position
ros2 service call /hric/map/mark_here hric_msgs/srv/MarkHere \
  "{name: 'my_waypoint', map_id: '', floor: ''}"

# Create a marker at a specific pose
ros2 service call /hric/map/mark_at_pose hric_msgs/srv/MarkAtPose \
  "{name: 'desk', map_id: '', floor: '', pose: {x: 3.0, y: 2.0, theta: 1.57}}"

# List all stored markers
ros2 service call /hric/map/list_markers hric_msgs/srv/ListMarkers "{}"

# Update an existing marker's pose
ros2 service call /hric/map/update_marker hric_msgs/srv/UpdateMarker \
  "{name: 'desk', map_id: '', floor: '', pose: {x: 3.1, y: 2.0, theta: 1.57}}"

# Delete a marker
ros2 service call /hric/map/operate_marker hric_msgs/srv/OperateMarker \
  "{name: 'my_waypoint'}"
```

---

## Python Usage Examples

### Switch to Walk mode

```python
import rclpy
from rclpy.node import Node
from hric_msgs.srv import SetMotionMode

rclpy.init()
node = Node('motion_client')
cli = node.create_client(SetMotionMode, '/hric/motion/set_motion_mode')
cli.wait_for_service()

req = SetMotionMode.Request()
req.walk_mode_request = SetMotionMode.Request.WALK  # 4
req.is_need_swing_arm = True

future = cli.call_async(req)
rclpy.spin_until_future_complete(node, future)
print('success:', future.result().success)
node.destroy_node()
rclpy.shutdown()
```

### Send a navigation goal

```python
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from hric_msgs.action import NavToPose
from geometry_msgs.msg import PoseStamped

rclpy.init()
node = Node('nav_client')
action_client = ActionClient(node, NavToPose, '/hric/nav/nav_to_pose')
action_client.wait_for_server()

goal = NavToPose.Goal()
goal.pose = PoseStamped()
goal.pose.header.frame_id = 'map'
goal.pose.pose.position.x = 2.0
goal.pose.pose.position.y = 1.0
goal.pose.pose.orientation.w = 1.0

future = action_client.send_goal_async(goal)
rclpy.spin_until_future_complete(node, future)
result_future = future.result().get_result_async()
rclpy.spin_until_future_complete(node, result_future)
print('error_code:', result_future.result().result.error_code)
node.destroy_node()
rclpy.shutdown()
```

### List all markers

```python
import rclpy
from rclpy.node import Node
from hric_msgs.srv import ListMarkers

rclpy.init()
node = Node('marker_client')
cli = node.create_client(ListMarkers, '/hric/map/list_markers')
cli.wait_for_service()

future = cli.call_async(ListMarkers.Request())
rclpy.spin_until_future_complete(node, future)
for m in future.result().markers:
    print(f'{m.name}: ({m.pose.x:.2f}, {m.pose.y:.2f}, {m.pose.theta:.2f})')
node.destroy_node()
rclpy.shutdown()
```
