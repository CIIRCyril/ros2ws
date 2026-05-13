# usb_sbus

The `usb_sbus` package provides a ROS 2 node (`usb_sbus_node`) that reads SBUS frames from a USB-to-SBUS adapter connected to the robot and re-publishes the decoded channel values as `bodyctrl_msgs/SbusData` and `sensor_msgs/Joy` messages on the `/sbus_data` topic. This makes remote-control joystick input (analog sticks, buttons, switches) available to all other ROS 2 nodes without any direct hardware dependency. A configurable key-filter (`key_filter_times: 2`) debounces button inputs before publication.

## Launch

```bash
source install/setup.bash
ros2 run usb_sbus usb_sbus_node
```

Or via launch file:

```bash
ros2 launch usb_sbus usb_sbus.launch.py
```

## Topics published

| Topic | Message type | Description |
|-------|-------------|-------------|
| `/sbus_data` | `sensor_msgs/Joy` | Raw channel values from the SBUS receiver |
| `/sbus_data/event` | `bodyctrl_msgs/SbusData` | Decoded button/joystick events |

## Examples

### Echo raw joystick data

```bash
ros2 topic echo /sbus_data
```

### Echo button events

```bash
ros2 topic echo /sbus_data/event
```

### Python snippet – read joystick axes from SBUS

```python
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy

class SbusReader(Node):
    def __init__(self):
        super().__init__('sbus_reader')
        self.create_subscription(Joy, '/sbus_data', self.cb, 10)

    def cb(self, msg):
        # axes[0] = left stick X, axes[1] = left stick Y
        self.get_logger().info(
            f'Left stick: x={msg.axes[0]:.2f}, y={msg.axes[1]:.2f}'
        )

rclpy.init()
rclpy.spin(SbusReader())
```
