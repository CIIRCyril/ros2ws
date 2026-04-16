ros2 topic pub -1 /arm/cmd_ctrl bodyctrl_msgs/msg/CmdMotorCtrl "{
  header: {stamp: {sec: 0, nanosec: 0}, frame_id: ''},
  cmds: [
    {name: 21, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 22, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 23, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 24, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 25, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 26, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0},
    {name: 27, kp: 0.0, kd: 0.0, pos: 0.0, spd: 0.0, tor: 0.0}
  ]
}"

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

