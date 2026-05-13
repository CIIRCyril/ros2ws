# power_board

The `power_board` package provides a ROS 2 composable node (`com::xhumanoid::PowerBoardNodelet`) that communicates with the robot's physical power management board over a serial port (`/dev/ttyS1`). It reads and publishes battery status, overall power status, board key-press events, and controls the power indicator LED. It also synchronises the board's real-time clock with the system timestamp on startup. The node is launched automatically as part of `body_control/body.launch.py` but can be started independently for power-only monitoring.

## Launch

```bash
source install/setup.bash
ros2 launch power_board power_board.launch.py
```

## Topics published

| Topic | Message type | Description |
|-------|-------------|-------------|
| `/power/board/status` | `bodyctrl_msgs/PowerStatus` | Battery voltage, current, charge level |
| `/power/board/battery_status` | `bodyctrl_msgs/PowerBatteryStatus` | Detailed battery cell data |
| `/power/board/key_status` | `bodyctrl_msgs/PowerBoardKeyStatus` | Physical button presses on the board |

## Examples

### Monitor battery / power status

```bash
ros2 topic echo /power/board/status
```

### Monitor key presses on the power board

```bash
ros2 topic echo /power/board/key_status
```

### Python snippet – print battery voltage

```python
import rclpy
from rclpy.node import Node
from bodyctrl_msgs.msg import PowerStatus

class BatteryMonitor(Node):
    def __init__(self):
        super().__init__('battery_monitor')
        self.create_subscription(PowerStatus, '/power/board/status', self.cb, 10)

    def cb(self, msg):
        self.get_logger().info(f'Voltage: {msg.voltage:.2f} V')

rclpy.init()
rclpy.spin(BatteryMonitor())
```
