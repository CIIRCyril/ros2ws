# bodyctrl_msgs — ROS 2 Message Package

Custom ROS 2 message package for the body control system of the Walker humanoid robot.  
It defines the topics and services used to monitor and control the robot's motors, hands, waist, power board, IMU, and force/torque sensors.

---

## Table of Contents

1. [Package layout](#package-layout)
2. [Motor naming convention](#motor-naming-convention)
3. [Messages (Topics)](#messages-topics)
   - [MotorStatus / MotorStatusMsg](#motorstatus--motorstatusmsg)
   - [MotorStatus1 / MotorStatusMsg1](#motorstatus1--motorstatusmsg1)
   - [MotorStatusMsg2](#motorstatusmsg2)
   - [MotorStatusMsgPlate](#motorstatusmsgplate)
   - [MotorCtrl / CmdMotorCtrl](#motorctrl--cmdmotorctrl)
   - [SetMotorPosition / CmdSetMotorPosition](#setmotorposition--cmdsetmotorposition)
   - [SetMotorSpeed / CmdSetMotorSpeed](#setmotorspeed--cmdsetmotorspeed)
   - [SetMotorDistance / CmdSetMotorDistance](#setmotordistance--cmdsetmotordistance)
   - [SetMotorCurTor / CmdSetMotorCurTor](#setmotorcurtor--cmdsetmotorcurtor)
   - [CmdSetWaistMotorPos](#cmdsetwaistmotorpos)
   - [WaistMotorStatus](#waistmotorstatus)
   - [TsHandStatus / TsHandStatusMsg](#tshandstatus--tshandstatusmsg)
   - [SetTsHandPosition / CmdSetTsHandPosition](#settshandposition--cmdsettshandposition)
   - [SetTsHandCtrl / CmdSetTsHandCtrl](#settshandctrl--cmdsettshandctrl)
   - [Imu](#imu)
   - [Euler](#euler)
   - [Sri](#sri)
   - [SbusData](#sbusdata)
   - [PowerStatus](#powerstatus)
   - [PowerBatteryStatus](#powerbatterystatus)
   - [PowerBoardCtrl](#powerboardctrl)
   - [PowerBoardKeyStatus](#powerboardkeystatus)
   - [PowerLightCtrl](#powerlightctrl)
   - [NodeState](#nodestate)
   - [Alarm / AlarmArray](#alarm--alarmarray)
   - [Exception / ExceptionArray](#exception--exceptionarray)
4. [Services](#services)
   - [MotorInit](#motorinit)
   - [MotorStart / MotorStop](#motorstart--motorstop)
   - [MotorResetPosition](#motorresetposition)
   - [SetMotorZeroOffset / ResetMotorZeroOffset](#setmotorzerooffset--resetmotorzerooffset)
   - [JointSetZero](#jointsetzero)
   - [SetAngle / GetAngleAct](#setangle--getangleact)
   - [SetAngleFlexible](#setangleflexible)
   - [SetSpeed](#setspeed)
   - [SetForce / GetForceAct](#setforce--getforceact)
   - [GetStatus / GetError / SetClearError](#getstatus--geterror--setclearerror)
   - [Movement](#movement)
   - [PlanJointTraj](#planjointegtraj)
   - [PlanEefLine / PlanEefRelLine](#planeefline--planeefrelline)
   - [XSensImuInit](#xsensimuinit)
   - [VersionUpgrade](#versionupgrade)
5. [Useful CLI Commands](#useful-cli-commands)
6. [Python Usage Examples](#python-usage-examples)

---

## Package layout

```
install/bodyctrl_msgs/
├── include/bodyctrl_msgs/   # C++ headers (generated)
├── lib/                     # Shared libraries
└── share/bodyctrl_msgs/
    ├── msg/                 # Message definitions
    └── srv/                 # Service definitions
```

---

## Motor naming convention

`bodyctrl_msgs/msg/MotorName` defines integer constants used to identify every joint motor on the robot. All motor-control messages use a `uint16 name` field that must be set to one of these constants.

| Constant              | Value | Body segment       |
|-----------------------|-------|--------------------|
| `MOTOR_HEAD_1`        | 1     | Head roll          |
| `MOTOR_HEAD_2`        | 2     | Head pitch         |
| `MOTOR_HEAD_3`        | 3     | Head yaw           |
| `MOTOR_ARM_LEFT_1`    | 11    | Left arm joint 1   |
| `MOTOR_ARM_LEFT_2`    | 12    | Left arm joint 2   |
| `MOTOR_ARM_LEFT_3`    | 13    | Left arm joint 3   |
| `MOTOR_ARM_LEFT_4`    | 14    | Left arm joint 4   |
| `MOTOR_ARM_LEFT_5`    | 15    | Left arm joint 5   |
| `MOTOR_ARM_LEFT_6`    | 16    | Left arm joint 6   |
| `MOTOR_ARM_LEFT_7`    | 17    | Left arm joint 7   |
| `MOTOR_ARM_RIGHT_1`   | 21    | Right arm joint 1  |
| `MOTOR_ARM_RIGHT_2`   | 22    | Right arm joint 2  |
| `MOTOR_ARM_RIGHT_3`   | 23    | Right arm joint 3  |
| `MOTOR_ARM_RIGHT_4`   | 24    | Right arm joint 4  |
| `MOTOR_ARM_RIGHT_5`   | 25    | Right arm joint 5  |
| `MOTOR_ARM_RIGHT_6`   | 26    | Right arm joint 6  |
| `MOTOR_ARM_RIGHT_7`   | 27    | Right arm joint 7  |
| `MOTOR_WAIST_1`       | 31    | Waist joint 1      |
| `MOTOR_WAIST_2`       | 32    | Waist joint 2      |
| `MOTOR_WAIST_3`       | 33    | Waist joint 3      |
| `MOTOR_LEG_LEFT_1`    | 51    | Left leg joint 1   |
| `MOTOR_LEG_LEFT_2`    | 52    | Left leg joint 2   |
| `MOTOR_LEG_LEFT_3`    | 53    | Left leg joint 3   |
| `MOTOR_LEG_LEFT_4`    | 54    | Left leg joint 4   |
| `MOTOR_LEG_LEFT_5`    | 55    | Left leg joint 5   |
| `MOTOR_LEG_LEFT_6`    | 56    | Left leg joint 6   |
| `MOTOR_LEG_RIGHT_1`   | 61    | Right leg joint 1  |
| `MOTOR_LEG_RIGHT_2`   | 62    | Right leg joint 2  |
| `MOTOR_LEG_RIGHT_3`   | 63    | Right leg joint 3  |
| `MOTOR_LEG_RIGHT_4`   | 64    | Right leg joint 4  |
| `MOTOR_LEG_RIGHT_5`   | 65    | Right leg joint 5  |
| `MOTOR_LEG_RIGHT_6`   | 66    | Right leg joint 6  |

---

## Messages (Topics)

### MotorStatus / MotorStatusMsg

`bodyctrl_msgs/msg/MotorStatus` — status of a single motor.

| Field         | Type      | Description                         |
|---------------|-----------|-------------------------------------|
| `name`        | `uint16`  | Motor ID (see MotorName constants)  |
| `pos`         | `float32` | Joint position (rad)                |
| `speed`       | `float32` | Joint speed (rad/s)                 |
| `current`     | `float32` | Motor current (A)                   |
| `temperature` | `float32` | Motor temperature (°C)              |
| `error`       | `uint32`  | Error bitmask                       |

`bodyctrl_msgs/msg/MotorStatusMsg` — array wrapper published as a topic.

| Field    | Type                        | Description            |
|----------|-----------------------------|------------------------|
| `header` | `std_msgs/Header`           | Timestamp / frame ID   |
| `status` | `bodyctrl_msgs/MotorStatus[]` | Array of motor statuses |

---

### MotorStatus1 / MotorStatusMsg1

`bodyctrl_msgs/msg/MotorStatus1` — temperature-only status for a single motor.

| Field              | Type      | Description                         |
|--------------------|-----------|-------------------------------------|
| `name`             | `uint16`  | Motor ID (see MotorName constants)  |
| `motortemperature` | `float32` | Motor winding temperature (°C)      |
| `mostemperature`   | `float32` | MOSFET driver temperature (°C)      |

`bodyctrl_msgs/msg/MotorStatusMsg1` — array wrapper.

| Field    | Type                         | Description            |
|----------|------------------------------|------------------------|
| `header` | `std_msgs/Header`            | Timestamp / frame ID   |
| `status` | `bodyctrl_msgs/MotorStatus1[]` | Array of temp statuses |

---

### MotorStatusMsg2

`bodyctrl_msgs/msg/MotorStatusMsg2` — compact multi-array status (bulk readout).

| Field    | Type                         | Description                 |
|----------|------------------------------|-----------------------------|
| `header` | `std_msgs/Header`            | Timestamp / frame ID        |
| `name`   | `std_msgs/Int32MultiArray`   | Motor IDs                   |
| `pos`    | `std_msgs/Float32MultiArray` | Joint positions (rad)       |
| `speed`  | `std_msgs/Float32MultiArray` | Joint speeds (rad/s)        |
| `current`| `std_msgs/Float32MultiArray` | Motor currents (A)          |

---

### MotorStatusMsgPlate

`bodyctrl_msgs/msg/MotorStatusMsgPlate` — flat struct for up to 12 motors on one control board (fields `name1`…`name12`, `pos1`…`pos12`, `speed1`…`speed12`, `current1`…`current12`, all `float32`/`uint16`).  
Used for low-latency bulk reads from a single motor driver board.

---

### MotorCtrl / CmdMotorCtrl

`bodyctrl_msgs/msg/MotorCtrl` — MIT-mode (torque + impedance) control command for a single motor.

| Field   | Type      | Description                            |
|---------|-----------|----------------------------------------|
| `name`  | `uint16`  | Motor ID (see MotorName constants)     |
| `kp`    | `float32` | Position gain                          |
| `kd`    | `float32` | Velocity / damping gain                |
| `pos`   | `float32` | Desired position (rad)                 |
| `spd`   | `float32` | Desired speed (rad/s)                  |
| `tor`   | `float32` | Feed-forward torque (N·m)              |

`bodyctrl_msgs/msg/CmdMotorCtrl` — array wrapper for publishing a batch of MIT commands.

| Field    | Type                        | Description                |
|----------|-----------------------------|----------------------------|
| `header` | `std_msgs/Header`           | Timestamp / frame ID       |
| `cmds`   | `bodyctrl_msgs/MotorCtrl[]` | Array of MIT ctrl commands |

---

### SetMotorPosition / CmdSetMotorPosition

`bodyctrl_msgs/msg/SetMotorPosition` — position-mode command for a single motor.

| Field    | Type      | Description                        |
|----------|-----------|------------------------------------|
| `name`   | `uint16`  | Motor ID                           |
| `pos`    | `float32` | Target position (rad)              |
| `spd`    | `float32` | Max speed limit (rpm)              |
| `cur`    | `float32` | Max current limit (A)              |

`bodyctrl_msgs/msg/CmdSetMotorPosition` — array wrapper.

---

### SetMotorSpeed / CmdSetMotorSpeed

`bodyctrl_msgs/msg/SetMotorSpeed` — speed-mode command for a single motor.

| Field  | Type      | Description              |
|--------|-----------|--------------------------|
| `name` | `uint16`  | Motor ID                 |
| `spd`  | `float32` | Target speed (rpm)       |
| `cur`  | `float32` | Max current limit (A)    |

`bodyctrl_msgs/msg/CmdSetMotorSpeed` — array wrapper.

---

### SetMotorDistance / CmdSetMotorDistance

`bodyctrl_msgs/msg/SetMotorDistance` — relative-distance command (incremental position move).

| Field      | Type      | Description                          |
|------------|-----------|--------------------------------------|
| `name`     | `uint16`  | Motor ID                             |
| `distance` | `float32` | Incremental move (rad)               |
| `spd`      | `float32` | Speed limit (rpm)                    |
| `cur`      | `float32` | Current limit (A)                    |

`bodyctrl_msgs/msg/CmdSetMotorDistance` — array wrapper.

---

### SetMotorCurTor / CmdSetMotorCurTor

`bodyctrl_msgs/msg/SetMotorCurTor` — current/torque-mode command for a single motor.

| Field         | Type     | Description                                      |
|---------------|----------|--------------------------------------------------|
| `name`        | `uint16` | Motor ID                                         |
| `cur_tor`     | `int16`  | Target current or torque (unit depends on driver)|
| `ctrl_status` | `uint8`  | Control status flags                             |

`bodyctrl_msgs/msg/CmdSetMotorCurTor` — array wrapper.

---

### CmdSetWaistMotorPos

`bodyctrl_msgs/msg/CmdSetWaistMotorPos` — dedicated waist-motor position command (single axis, high-level).

| Field    | Type      | Description                     |
|----------|-----------|---------------------------------|
| `header` | `std_msgs/Header` | Timestamp / frame ID    |
| `pos`    | `float64` | Target position (rad)           |
| `spd`    | `float64` | Max speed (rad/s)               |
| `accel`  | `float64` | Acceleration limit (rad/s²)     |
| `decel`  | `float64` | Deceleration limit (rad/s²)     |

---

### WaistMotorStatus

`bodyctrl_msgs/msg/WaistMotorStatus` — waist-motor feedback.

| Field    | Type              | Description              |
|----------|-------------------|--------------------------|
| `header` | `std_msgs/Header` | Timestamp / frame ID     |
| `pos`    | `float64`         | Current position (rad)   |
| `vel`    | `float64`         | Current velocity (rad/s) |
| `cur`    | `float64`         | Current draw (A)         |

---

### TsHandStatus / TsHandStatusMsg

`bodyctrl_msgs/msg/TsHandStatus` — state of one Tsinghua dexterous hand.

| Field            | Type       | Description                                               |
|------------------|------------|-----------------------------------------------------------|
| `name`           | `int32`    | Hand ID (see TsHandName: LEFT=1, RIGHT=2)                 |
| `rotation_angle` | `uint16`   | Thumb rotation angle (0–90°)                              |
| `bend_angle`     | `uint16[]` | Bend angles for 5 fingers (index 0=thumb … 4=little, 0–90°) |

`bodyctrl_msgs/msg/TsHandStatusMsg` — array wrapper.

---

### SetTsHandPosition / CmdSetTsHandPosition

`bodyctrl_msgs/msg/SetTsHandPosition` — absolute position command for one hand.

| Field            | Type       | Description                                               |
|------------------|------------|-----------------------------------------------------------|
| `name`           | `int32`    | Hand ID (LEFT=1, RIGHT=2)                                 |
| `rotation_angle` | `uint16`   | Thumb rotation target (0–90°)                             |
| `bend_angle`     | `uint16[]` | Bend targets for 5 fingers (0–90°)                        |

`bodyctrl_msgs/msg/CmdSetTsHandPosition` — array wrapper.

---

### SetTsHandCtrl / CmdSetTsHandCtrl

`bodyctrl_msgs/msg/SetTsHandCtrlItem` — velocity + angle range for one DOF.

| Field         | Type     | Description                          |
|---------------|----------|--------------------------------------|
| `vel`         | `uint16` | Velocity (20–200)                    |
| `start_angle` | `uint16` | Start angle (0–90°)                  |
| `max_angle`   | `uint16` | Maximum angle (0–90°)                |

`bodyctrl_msgs/msg/SetTsHandCtrl` — full hand control command.

| Field       | Type                          | Description                                      |
|-------------|-------------------------------|--------------------------------------------------|
| `name`      | `int32`                       | Hand ID (LEFT=1, RIGHT=2)                        |
| `rotation`  | `SetTsHandCtrlItem`           | Thumb rotation control item                      |
| `bend`      | `SetTsHandCtrlItem[]`         | Bend items for 5 fingers (0=thumb … 4=little)   |
| `threshold` | `uint16[]`                    | Force thresholds per finger (20–1000)            |

`bodyctrl_msgs/msg/CmdSetTsHandCtrl` — array wrapper.

---

### Imu

`bodyctrl_msgs/msg/Imu` — IMU sensor data.

| Field                           | Type                         | Description                           |
|---------------------------------|------------------------------|---------------------------------------|
| `header`                        | `std_msgs/Header`            | Timestamp / frame ID                  |
| `orientation`                   | `geometry_msgs/Quaternion`   | Orientation quaternion                |
| `angular_velocity`              | `geometry_msgs/Vector3`      | Angular velocity (rad/s)              |
| `linear_acceleration`           | `geometry_msgs/Vector3`      | Linear acceleration (m/s²)            |
| `euler`                         | `bodyctrl_msgs/Euler`        | Roll / pitch / yaw (rad)              |
| `error`                         | `uint32`                     | Error bitmask                         |
| `angular_velocity_covariance`   | `float64[3]`                 | Diagonal covariance of angular vel    |
| `orientation_covariance`        | `float64[3]`                 | Diagonal covariance of orientation    |
| `linear_acceleration_covariance`| `float64[3]`                 | Diagonal covariance of lin. accel     |

---

### Euler

`bodyctrl_msgs/msg/Euler` — simple RPY representation.

| Field   | Type      | Description       |
|---------|-----------|-------------------|
| `roll`  | `float64` | Roll angle (rad)  |
| `pitch` | `float64` | Pitch angle (rad) |
| `yaw`   | `float64` | Yaw angle (rad)   |

---

### Sri

`bodyctrl_msgs/msg/Sri` — force/torque sensor reading (SRI sensor).

| Field    | Type              | Description                              |
|----------|-------------------|------------------------------------------|
| `header` | `std_msgs/Header` | Timestamp / frame ID                     |
| `name`   | `int32`           | Sensor ID (SriName: LEFT=1, RIGHT=2)     |
| `fx`     | `float32`         | Force in X (N)                           |
| `fy`     | `float32`         | Force in Y (N)                           |
| `fz`     | `float32`         | Force in Z (N)                           |
| `mx`     | `float32`         | Torque about X (N·m)                     |
| `my`     | `float32`         | Torque about Y (N·m)                     |
| `mz`     | `float32`         | Torque about Z (N·m)                     |

---

### SbusData

`bodyctrl_msgs/msg/SbusData` — RC remote control / SBUS input data.

| Field           | Type              | Description                                     |
|-----------------|-------------------|-------------------------------------------------|
| `header`        | `std_msgs/Header` | Timestamp / frame ID                            |
| `key_event_new` | `int32`           | Latest key event code (see constants below)     |
| `key_event_old` | `int32`           | Previous key event code                         |
| `button_a`–`h`  | `int8`            | Button states: push buttons ±1, toggles −1/0/1 |
| `x1`, `y1`      | `float32`         | Left joystick axes (continuous, 0–1)            |
| `x2`, `y2`      | `float32`         | Right joystick axes (continuous, 0–1)           |

**Key event constants**

| Constant      | Value | Description              |
|---------------|-------|--------------------------|
| `KEY_NONE`    | 0     | No event                 |
| `KEY_A_UP`    | 1     | Button A released        |
| `KEY_A_DOWN`  | 2     | Button A pressed         |
| `KEY_B_UP`    | 3     | Button B released        |
| `KEY_B_DOWN`  | 4     | Button B pressed         |
| `KEY_C_UP`    | 5     | Button C released        |
| `KEY_C_DOWN`  | 6     | Button C pressed         |
| `KEY_D_UP`    | 7     | Button D released        |
| `KEY_D_DOWN`  | 8     | Button D pressed         |
| `KEY_E_UP`    | 9     | Switch E up position     |
| `KEY_E_MID`   | 10    | Switch E middle position |
| `KEY_E_DOWN`  | 11    | Switch E down position   |
| `KEY_F_UP`    | 12    | Switch F up position     |
| `KEY_F_MID`   | 13    | Switch F middle position |
| `KEY_F_DOWN`  | 14    | Switch F down position   |
| `KEY_G_LEFT`  | 15    | Switch G left position   |
| `KEY_G_MID`   | 16    | Switch G middle position |
| `KEY_G_RIGHT` | 17    | Switch G right position  |
| `KEY_H_LEFT`  | 18    | Switch H left position   |
| `KEY_H_MID`   | 19    | Switch H middle position |
| `KEY_H_RIGHT` | 20    | Switch H right position  |

---

### PowerStatus

`bodyctrl_msgs/msg/PowerStatus` — comprehensive power board status (temperatures, currents, voltages, battery).

Key field groups:

| Group              | Fields (per segment)                              | Units |
|--------------------|---------------------------------------------------|-------|
| Temperature (cur)  | `waist_temp`, `arm_a_temp`, `arm_b_temp`, `leg_a_temp`, `leg_b_temp` | °C |
| Temperature (max)  | `*_temp_max` variants                             | °C    |
| Temperature (min)  | `*_temp_min` variants                             | °C    |
| Current (cur)      | `arm_a_curr`, `arm_b_curr`, `leg_a_curr`, `leg_b_curr`, `waist_curr`, `head_curr` | A |
| Current (max/min)  | `*_curr_max` / `*_curr_min` variants              | A     |
| Voltage (cur)      | `arm_a_volt`, `arm_b_volt`, `leg_a_volt`, `leg_b_volt`, `waist_volt`, `bus_volt` | V |
| Voltage (max/min)  | `*_volt_max` / `*_volt_min` variants              | V     |
| Battery            | `battery_voltage`, `battery_current`, `battery_power` | V / A / % |
| Version            | `software_version`, `hardware_version`            | string |

---

### PowerBatteryStatus

`bodyctrl_msgs/msg/PowerBatteryStatus` — battery status (dual-battery support).

| Field                   | Type      | Description                                           |
|-------------------------|-----------|-------------------------------------------------------|
| `header`                | `std_msgs/Header` | Timestamp                                     |
| `battery_installed`     | `int32`   | Bitmask: 0x01=small, 0x02=large, 0x03=both            |
| `battery_working`       | `int32`   | Bitmask: 0x01=large active, 0x10=small active         |
| `master_battery_voltage`| `float32` | Main battery voltage (V)                              |
| `master_battery_current`| `float32` | Main battery current (A)                              |
| `master_battery_power`  | `float32` | Main battery charge (%)                               |
| `little_battery_voltage`| `float32` | Auxiliary battery voltage (V)                         |
| `little_battery_current`| `float32` | Auxiliary battery current (A)                         |
| `little_battery_power`  | `float32` | Auxiliary battery charge (%)                          |
| `pg12a`–`pg12d`, `pg5cd`, `pg5ab`, `pgrdc1/2`, `pgheader`, `pgbutton2` | `int8` | Power-good signals (0=low, 1=high) |

---

### PowerBoardCtrl

`bodyctrl_msgs/msg/PowerBoardCtrl` — command message sent **to** the power board.

| Field    | Type              | Description               |
|----------|-------------------|---------------------------|
| `header` | `std_msgs/Header` | Timestamp / frame ID      |
| `cmd`    | `int32`           | Command code (see below)  |

**Command constants**

| Constant                          | Value | Description                    |
|-----------------------------------|-------|--------------------------------|
| `POWER_LIGHT_POWER_ON_START`      | 1     | Power-on started               |
| `POWER_LIGHT_POWER_ON_FINISH`     | 2     | Power-on complete              |
| `POWER_LIGHT_SERVICE_START`       | 3     | Service started                |
| `POWER_LIGHT_SERVICE_FINISH`      | 4     | Service finished               |
| `POWER_LIGHT_SELF_CHECK_START`    | 5     | Self-check started             |
| `POWER_LIGHT_SELF_CHECK_FAILED`   | 6     | Self-check failed              |
| `POWER_LIGHT_SELF_CHECK_SUCCESS`  | 7     | Self-check passed              |
| `POWER_LIGHT_FAULT_OCCUR`         | 8     | Fault occurred                 |
| `POWER_LIGHT_FAULT_CLEAR`         | 9     | Fault cleared                  |
| `POWER_LIGHT_VOICE_WAKEUP`        | 10    | Voice wake-up                  |
| `POWER_LIGHT_VOICE_RESPONSE`      | 11    | Voice response                 |
| `POWER_LIGHT_VOICE_EXIT`          | 12    | Voice exit                     |
| `POWER_LIGHT_RUNNING_START`       | 13    | Running started                |
| `POWER_LIGHT_RUNNING_FINISH`      | 14    | Running finished               |
| `POWER_LIGHT_POWER_OFF`           | 15    | Power off                      |
| `POWER_LIGHT_WARN_OCCUR`          | 16    | Warning occurred               |
| `POWER_LIGHT_WARN_CLEAR`          | 17    | Warning cleared                |
| `POWER_SET_TIME_STAMP`            | 100   | Sync timestamp to power board  |
| `POWER_GET_DATA_STATUS`           | 101   | Request data status            |
| `POWER_GET_BATTERY_STATUS`        | 102   | Request battery status         |
| `POWER_GET_KEY_STATUS`            | 103   | Request key / button status    |

---

### PowerBoardKeyStatus

`bodyctrl_msgs/msg/PowerBoardKeyStatus` — physical button / E-stop state from the power board.

| Field              | Type              | Description                             |
|--------------------|-------------------|-----------------------------------------|
| `header`           | `std_msgs/Header` | Timestamp / frame ID                    |
| `work_time`        | `uint32`          | Total system uptime (s)                 |
| `is_estop`         | `std_msgs/Bool`   | Hardware emergency-stop pressed         |
| `is_remote_estop`  | `std_msgs/Bool`   | Remote E-stop active                    |
| `is_power_on`      | `std_msgs/Bool`   | Main power is on                        |

---

### PowerLightCtrl

`bodyctrl_msgs/msg/PowerLightCtrl` — LED/light control command (same structure as PowerBoardCtrl, extended command set).

| Field    | Type              | Description               |
|----------|-------------------|---------------------------|
| `header` | `std_msgs/Header` | Timestamp / frame ID      |
| `cmd`    | `int32`           | Light command (1–18)      |

Notable additional constant: `POWER_LIGHT_BATTERY_SUPPLY = 1` (battery supplying power).  
All other constants match `PowerBoardCtrl` shifted by one (values 2–18).

---

### NodeState

`bodyctrl_msgs/msg/NodeState` — lifecycle state of a body-control node.

| Field    | Type              | Description                            |
|----------|-------------------|----------------------------------------|
| `header` | `std_msgs/Header` | Timestamp / frame ID                   |
| `topic`  | `string`          | Topic or node name being reported      |
| `state`  | `uint16`          | `NODE_STATE_IDLE=0`, `NODE_STATE_RUNNING=1` |

---

### Alarm / AlarmArray

`bodyctrl_msgs/msg/Alarm` — a single alarm entry.

| Field         | Type                      | Description                              |
|---------------|---------------------------|------------------------------------------|
| `stamp`       | `builtin_interfaces/Time` | Time of alarm                            |
| `node_name`   | `string`                  | Source node name                         |
| `error_code`  | `int32`                   | Alarm/error code                         |
| `level`       | `int8`                    | Severity (INFO=0, WARN=1, ERROR=2, FATAL=3) |
| `description` | `string`                  | Human-readable alarm description         |

`bodyctrl_msgs/msg/AlarmArray` — array wrapper.

| Field    | Type                        | Description          |
|----------|-----------------------------|----------------------|
| `header` | `std_msgs/Header`           | Timestamp / frame ID |
| `alarm`  | `bodyctrl_msgs/Alarm[]`     | Array of alarms      |

---

### Exception / ExceptionArray

`bodyctrl_msgs/msg/Exception` — a single exception entry (legacy format).

| Field      | Type                      | Description              |
|------------|---------------------------|--------------------------|
| `stamp`    | `builtin_interfaces/Time` | Time of exception        |
| `code`     | `int64`                   | Exception code           |
| `desc`     | `string`                  | Exception description    |
| `nodename` | `string`                  | Source node name         |

`bodyctrl_msgs/msg/ExceptionArray` — array wrapper.

---

## Services

### MotorInit

`bodyctrl_msgs/srv/MotorInit`

Initialize the motor driver on a named CAN/EtherCAT network.

**Request**

| Field         | Type     | Description                          |
|---------------|----------|--------------------------------------|
| `name_of_net` | `string` | Network interface name (e.g. `can0`) |

**Response**

| Field | Type    | Description                  |
|-------|---------|------------------------------|
| `ret` | `int32` | 0 = success, non-zero = error|

---

### MotorStart / MotorStop

`bodyctrl_msgs/srv/MotorStart` and `bodyctrl_msgs/srv/MotorStop`

Enable or disable motor power output.

**Request**

| Field   | Type    | Description         |
|---------|---------|---------------------|
| `param` | `int32` | Reserved parameter  |

**Response**

| Field | Type    | Description              |
|-------|---------|--------------------------|
| `ret` | `int32` | 0 = success, else error  |

---

### MotorResetPosition

`bodyctrl_msgs/srv/MotorResetPosition`

Reset the position encoder of a single motor to zero.

**Request**

| Field  | Type     | Description                        |
|--------|----------|------------------------------------|
| `name` | `uint16` | Motor ID (see MotorName constants) |

**Response**

| Field | Type   | Description      |
|-------|--------|------------------|
| `ret` | `bool` | `true` on success|

---

### SetMotorZeroOffset / ResetMotorZeroOffset

`bodyctrl_msgs/srv/SetMotorZeroOffset` — store current position as the new zero offset.  
`bodyctrl_msgs/srv/ResetMotorZeroOffset` — clear a previously stored zero offset.

Both share the same interface:

**Request**

| Field  | Type     | Description |
|--------|----------|-------------|
| `name` | `uint16` | Motor ID    |

**Response**

| Field     | Type   | Description      |
|-----------|--------|------------------|
| `success` | `bool` | `true` on success|

---

### JointSetZero

`bodyctrl_msgs/srv/JointSetZero`

Zero multiple joints at once (by name strings).

**Request**

| Field  | Type       | Description                    |
|--------|------------|--------------------------------|
| `name` | `string[]` | Joint names to zero            |

**Response**

| Field           | Type   | Description             |
|-----------------|--------|-------------------------|
| `zero_accepted` | `bool` | `true` if all zeroed    |

---

### SetAngle / GetAngleAct

`bodyctrl_msgs/srv/SetAngle` — command 6 joint angles simultaneously (used for the arm end-effector or similar 6-DOF chains).

**Request**

| Field          | Type      | Description                    |
|----------------|-----------|--------------------------------|
| `angle0_ratio` | `float32` | Joint 0 angle ratio (0.0–1.0) |
| `angle1_ratio` | `float32` | Joint 1 angle ratio           |
| …              | …         | …                              |
| `angle5_ratio` | `float32` | Joint 5 angle ratio           |

**Response**

| Field            | Type   | Description           |
|------------------|--------|-----------------------|
| `angle_accepted` | `bool` | `true` on success     |

`bodyctrl_msgs/srv/GetAngleAct` — read the current 6 joint angles.

**Response**

| Field            | Type          | Description                   |
|------------------|---------------|-------------------------------|
| `curangle_ratio` | `float32[6]`  | Current angle ratios (0–1)    |

---

### SetAngleFlexible

`bodyctrl_msgs/srv/SetAngleFlexible`

Set arbitrary joint angles by name (flexible, variable-length list).

**Request**

| Field         | Type       | Description                          |
|---------------|------------|--------------------------------------|
| `name`        | `string[]` | Joint name strings                   |
| `angle_ratio` | `float32[]`| Target angle ratios (0.0–1.0)        |

**Response**

| Field            | Type   | Description       |
|------------------|--------|-------------------|
| `angle_accepted` | `bool` | `true` on success |

---

### SetSpeed

`bodyctrl_msgs/srv/SetSpeed`

Set end-effector / joint speed ratios for 6 DOF.

**Request**

| Field          | Type      | Description              |
|----------------|-----------|--------------------------|
| `speed0_ratio` | `float32` | Speed ratio for DOF 0    |
| …              | …         | …                        |
| `speed5_ratio` | `float32` | Speed ratio for DOF 5    |

**Response**

| Field            | Type   | Description      |
|------------------|--------|------------------|
| `speed_accepted` | `bool` | `true` on success|

---

### SetForce / GetForceAct

`bodyctrl_msgs/srv/SetForce` — set force/torque ratios for 6-axis force controller.

**Request**

| Field          | Type      | Description               |
|----------------|-----------|---------------------------|
| `force0_ratio` | `float32` | Force ratio for axis 0    |
| …              | …         | …                         |
| `force5_ratio` | `float32` | Force ratio for axis 5    |

**Response**

| Field            | Type   | Description      |
|------------------|--------|------------------|
| `force_accepted` | `bool` | `true` on success|

`bodyctrl_msgs/srv/GetForceAct` — read current 6-axis force ratios.

**Response**

| Field            | Type         | Description                  |
|------------------|--------------|------------------------------|
| `curforce_ratio` | `float32[6]` | Current force ratios (0–1)   |

---

### GetStatus / GetError / SetClearError

`bodyctrl_msgs/srv/GetStatus` — read 6-channel status values (no request body).

**Response**

| Field         | Type         | Description           |
|---------------|--------------|-----------------------|
| `statusvalue` | `uint32[6]`  | Status codes per channel |

`bodyctrl_msgs/srv/GetError` — read 6-channel error values.

**Response**

| Field        | Type         | Description           |
|--------------|--------------|-----------------------|
| `errorvalue` | `uint32[6]`  | Error codes per channel |

`bodyctrl_msgs/srv/SetClearError` — clear all active errors (no request body).

**Response**

| Field                    | Type   | Description      |
|--------------------------|--------|------------------|
| `setclear_error_accepted`| `bool` | `true` on success|

---

### Movement

`bodyctrl_msgs/srv/Movement`

Trigger a named predefined motion (e.g. bow, wave).

**Request**

| Field   | Type      | Description                         |
|---------|-----------|-------------------------------------|
| `name`  | `int32`   | Motion index / ID                   |
| `value` | `float32` | Optional motion parameter           |

**Response**

| Field              | Type   | Description                    |
|--------------------|--------|--------------------------------|
| `action_completed` | `bool` | `true` when motion finishes    |

---

### PlanJointTraj

`bodyctrl_msgs/srv/PlanJointTraj`

Plan and execute a joint-space trajectory for one arm.

**Request**

| Field          | Type        | Description                                              |
|----------------|-------------|----------------------------------------------------------|
| `arm_name`     | `string`    | `"left"` or `"right"`                                   |
| `joint_pos`    | `float64[]` | Target joint positions (rad)                             |
| `joint_vel`    | `float64[]` | Target joint velocities (rad/s)                          |
| `vel_percent`  | `float64`   | Velocity scaling factor (0.0–1.0)                        |
| `acc_percent`  | `float64`   | Acceleration scaling factor (0.0–1.0)                    |
| `jerk_percent` | `float64`   | Jerk scaling factor (0.0–1.0)                            |
| `mode`         | `int32`     | 0=position, 1=velocity, 2=acceleration, 3=jerk           |

**Response**

| Field     | Type     | Description          |
|-----------|----------|----------------------|
| `success` | `bool`   | `true` on success    |
| `message` | `string` | Failure reason       |

---

### PlanEefLine / PlanEefRelLine

`bodyctrl_msgs/srv/PlanEefLine` — move the end-effector to an **absolute** Cartesian pose in a straight line.

**Request**

| Field         | Type                    | Description                            |
|---------------|-------------------------|----------------------------------------|
| `arm_name`    | `string`                | `"left"` or `"right"`                 |
| `eef_pose`    | `geometry_msgs/Pose`    | Target end-effector pose               |
| `vel_percent` | `float64`               | Velocity scaling (0.0–1.0)             |
| `acc_percent` | `float64`               | Acceleration scaling (0.0–1.0)         |

**Response**

| Field     | Type     | Description       |
|-----------|----------|-------------------|
| `success` | `bool`   | `true` on success |
| `message` | `string` | Failure reason    |

`bodyctrl_msgs/srv/PlanEefRelLine` — move the end-effector by a **relative** Cartesian delta.

**Request**

| Field         | Type     | Description                        |
|---------------|----------|------------------------------------|
| `arm_name`    | `string` | `"left"` or `"right"`             |
| `dx`          | `float64`| Displacement along X (m)           |
| `dy`          | `float64`| Displacement along Y (m)           |
| `dz`          | `float64`| Displacement along Z (m)           |
| `vel_percent` | `float64`| Velocity scaling (0.0–1.0)         |
| `acc_percent` | `float64`| Acceleration scaling (0.0–1.0)     |

**Response** — same as `PlanEefLine`.

---

### XSensImuInit

`bodyctrl_msgs/srv/XSensImuInit`

Initialize the XSens IMU on a specified serial device.

**Request**

| Field      | Type     | Description                         |
|------------|----------|-------------------------------------|
| `dev_name` | `string` | Serial device path (e.g. `/dev/ttyUSB0`) |

**Response**

| Field | Type   | Description      |
|-------|--------|------------------|
| `ret` | `bool` | `true` on success|

---

### VersionUpgrade

`bodyctrl_msgs/srv/VersionUpgrade`

Trigger a firmware/software version upgrade.

**Request**

| Field   | Type     | Description                          |
|---------|----------|--------------------------------------|
| `param` | `string` | Upgrade parameters or package path   |

**Response**

| Field    | Type     | Description           |
|----------|----------|-----------------------|
| `result` | `string` | Result or status text |

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

# Show message structure
ros2 interface show bodyctrl_msgs/msg/MotorStatusMsg
ros2 interface show bodyctrl_msgs/msg/SbusData
ros2 interface show bodyctrl_msgs/msg/MotorName
ros2 interface show bodyctrl_msgs/srv/PlanJointTraj

# Echo live motor status
ros2 topic echo /motor_status

# Echo live hand status
ros2 topic echo /ts_hand_status

# Echo live waist status
ros2 topic echo /waist_motor_status

# Echo IMU data
ros2 topic echo /imu

# Echo remote control input
ros2 topic echo /sbus_data

# Echo power board status
ros2 topic echo /power_status

# Echo force/torque sensor
ros2 topic echo /sri
```

### Motor Control

```bash
# Start motors
ros2 service call /motor_start bodyctrl_msgs/srv/MotorStart "{param: 0}"

# Stop motors
ros2 service call /motor_stop bodyctrl_msgs/srv/MotorStop "{param: 0}"

# Reset position encoder for left arm joint 1 (motor 11)
ros2 service call /motor_reset_position bodyctrl_msgs/srv/MotorResetPosition "{name: 11}"

# Zero left arm joints by name
ros2 service call /joint_set_zero bodyctrl_msgs/srv/JointSetZero \
  "{name: ['arm_left_1', 'arm_left_2', 'arm_left_3']}"

# Move head motor 1 to position 0.5 rad (position mode)
ros2 topic pub --once /cmd_set_motor_position bodyctrl_msgs/msg/CmdSetMotorPosition \
  "{header: {stamp: {sec: 0}}, cmds: [{name: 1, pos: 0.5, spd: 50.0, cur: 2.0}]}"

# Set head motor 1 speed (speed mode)
ros2 topic pub --once /cmd_set_motor_speed bodyctrl_msgs/msg/CmdSetMotorSpeed \
  "{header: {stamp: {sec: 0}}, cmds: [{name: 1, spd: 30.0, cur: 2.0}]}"

# MIT impedance control for left arm joint 1
ros2 topic pub --once /cmd_motor_ctrl bodyctrl_msgs/msg/CmdMotorCtrl \
  "{header: {stamp: {sec: 0}}, cmds: [{name: 11, kp: 50.0, kd: 1.0, pos: 0.3, spd: 0.0, tor: 0.0}]}"
```

### Waist Control

```bash
# Move waist to 0.2 rad
ros2 topic pub --once /cmd_set_waist_motor_pos bodyctrl_msgs/msg/CmdSetWaistMotorPos \
  "{header: {stamp: {sec: 0}}, pos: 0.2, spd: 0.5, accel: 0.3, decel: 0.3}"
```

### Hand Control

```bash
# Open right hand (all fingers to 0°)
ros2 topic pub --once /cmd_set_ts_hand_position bodyctrl_msgs/msg/CmdSetTsHandPosition \
  "{header: {stamp: {sec: 0}}, cmds: [{name: 2, rotation_angle: 0, bend_angle: [0, 0, 0, 0, 0]}]}"

# Close right hand (all fingers to 90°)
ros2 topic pub --once /cmd_set_ts_hand_position bodyctrl_msgs/msg/CmdSetTsHandPosition \
  "{header: {stamp: {sec: 0}}, cmds: [{name: 2, rotation_angle: 0, bend_angle: [90, 90, 90, 90, 90]}]}"
```

### Arm Trajectory

```bash
# Plan joint trajectory for right arm
ros2 service call /plan_joint_traj bodyctrl_msgs/srv/PlanJointTraj \
  "{arm_name: 'right', joint_pos: [0.0, 0.3, 0.0, 0.5, 0.0, 0.2, 0.0], \
    joint_vel: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0], \
    vel_percent: 0.3, acc_percent: 0.2, jerk_percent: 0.1, mode: 0}"

# Move right arm end-effector to absolute pose (straight line)
ros2 service call /plan_eef_line bodyctrl_msgs/srv/PlanEefLine \
  "{arm_name: 'right', \
    eef_pose: {position: {x: 0.4, y: -0.3, z: 0.5}, orientation: {w: 1.0}}, \
    vel_percent: 0.3, acc_percent: 0.2}"

# Move right arm end-effector by relative delta (+10 cm in Z)
ros2 service call /plan_eef_rel_line bodyctrl_msgs/srv/PlanEefRelLine \
  "{arm_name: 'right', dx: 0.0, dy: 0.0, dz: 0.1, vel_percent: 0.2, acc_percent: 0.1}"
```

---

## Python Usage Examples

```python
import rclpy
from rclpy.node import Node
from bodyctrl_msgs.msg import (
    CmdMotorCtrl, MotorCtrl,
    CmdSetMotorPosition, SetMotorPosition,
    CmdSetTsHandPosition, SetTsHandPosition,
    MotorStatusMsg, SbusData,
)
from bodyctrl_msgs.msg import MotorName, TsHandName
from bodyctrl_msgs.srv import PlanJointTraj, MotorStart


class BodyCtrlExample(Node):
    def __init__(self):
        super().__init__('bodyctrl_example')

        # --- Publishers ---
        self.motor_pub = self.create_publisher(CmdMotorCtrl, '/cmd_motor_ctrl', 10)
        self.pos_pub   = self.create_publisher(CmdSetMotorPosition, '/cmd_set_motor_position', 10)
        self.hand_pub  = self.create_publisher(CmdSetTsHandPosition, '/cmd_set_ts_hand_position', 10)

        # --- Subscribers ---
        self.create_subscription(MotorStatusMsg, '/motor_status', self.on_motor_status, 10)
        self.create_subscription(SbusData, '/sbus_data', self.on_sbus, 10)

        # --- Service clients ---
        self.start_cli = self.create_client(MotorStart, '/motor_start')
        self.traj_cli  = self.create_client(PlanJointTraj, '/plan_joint_traj')

    # ---- Motor status callback ----
    def on_motor_status(self, msg: MotorStatusMsg):
        for s in msg.status:
            if s.name == MotorName.MOTOR_ARM_LEFT_1:
                self.get_logger().info(
                    f'Left arm j1: pos={s.pos:.3f} rad, '
                    f'spd={s.speed:.3f} rad/s, cur={s.current:.2f} A'
                )

    # ---- SBUS / remote callback ----
    def on_sbus(self, msg: SbusData):
        if msg.key_event_new == SbusData.KEY_A_DOWN:
            self.get_logger().info('Button A pressed')

    # ---- MIT impedance command ----
    def send_mit_cmd(self, motor_id: int, pos: float, kp=50.0, kd=1.0):
        cmd = CmdMotorCtrl()
        cmd.header.stamp = self.get_clock().now().to_msg()
        item = MotorCtrl()
        item.name = motor_id
        item.kp   = kp
        item.kd   = kd
        item.pos  = pos
        cmd.cmds  = [item]
        self.motor_pub.publish(cmd)

    # ---- Position command ----
    def send_position_cmd(self, motor_id: int, pos_rad: float,
                          spd_rpm=50.0, cur_a=2.0):
        cmd = CmdSetMotorPosition()
        cmd.header.stamp = self.get_clock().now().to_msg()
        item = SetMotorPosition()
        item.name = motor_id
        item.pos  = pos_rad
        item.spd  = spd_rpm
        item.cur  = cur_a
        cmd.cmds  = [item]
        self.pos_pub.publish(cmd)

    # ---- Hand open/close ----
    def set_hand(self, hand_id: int, close: bool):
        angle = 90 if close else 0
        cmd = CmdSetTsHandPosition()
        cmd.header.stamp = self.get_clock().now().to_msg()
        item = SetTsHandPosition()
        item.name           = hand_id
        item.rotation_angle = 0
        item.bend_angle     = [angle] * 5
        cmd.cmds = [item]
        self.hand_pub.publish(cmd)

    # ---- Arm joint trajectory ----
    async def plan_arm_traj(self, arm: str, joint_pos: list):
        req = PlanJointTraj.Request()
        req.arm_name    = arm
        req.joint_pos   = joint_pos
        req.joint_vel   = [0.0] * len(joint_pos)
        req.vel_percent = 0.3
        req.acc_percent = 0.2
        req.jerk_percent = 0.1
        req.mode = 0  # position mode
        resp = await self.traj_cli.call_async(req)
        if not resp.success:
            self.get_logger().error(f'Trajectory failed: {resp.message}')
        return resp.success


def main():
    rclpy.init()
    node = BodyCtrlExample()

    # Move head pitch motor to 0.3 rad
    node.send_position_cmd(MotorName.MOTOR_HEAD_2, 0.3)

    # MIT command on left arm joint 1
    node.send_mit_cmd(MotorName.MOTOR_ARM_LEFT_1, pos=0.5)

    # Close left hand
    node.set_hand(TsHandName.TSINGHUA_HAND_LEFT, close=True)

    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
```
