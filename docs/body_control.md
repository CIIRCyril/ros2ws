# body_control

The `body_control` package is the central hardware-abstraction layer for the Cyril humanoid robot. It hosts the `body_control::BodyControl` composable node that communicates over EtherCAT with all joint motors (7-DOF arms left/right, waist, head, legs), the Inspire dexterous hands, IMU, and SRI 6-DOF force/torque sensors. Its main launch file (`body.launch.py`) additionally starts the `diagnose`, `power_board`, `usb_sbus`, bag-recording, and disk-management nodes, making it the single entry point for a full robot bring-up. Motor configurations are loaded from YAML files under `param/`.

## Launch

```bash
sudo su
cd ~/ros2ws
source install/setup.bash
ros2 launch body_control body.launch.py
```

> Use `body_no_sbus.launch.py` when the USB SBUS receiver is not connected.

## Examples

### Check body-control node state

```bash
ros2 topic echo /bodycontrol_state
```

### Send a zero-torque command to the left arm motors (IDs 11–17)

```bash
ros2 topic pub -1 /arm/cmd_ctrl bodyctrl_msgs/msg/CmdMotorCtrl "{
  header: {stamp: {sec: 0, nanosec: 0}, frame_id: ''},
  cmds: [
    {name: 11, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 12, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 13, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 14, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 15, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 16, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 17, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0}
  ]
}"
```

### Read IMU data

```bash
ros2 topic echo /imu/data
```

### Read force/torque sensor from the left arm

```bash
ros2 topic echo /arm_6dof_left
```
