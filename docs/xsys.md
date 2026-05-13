# xsys

The `xsys` package provides core system-level services for the X-Humanoid robot platform through the composable node `x::sys::Node`. Its primary function is exposing a ROS 2 service (`/xsys/get_serial_number`) that returns the unique hardware serial number of the robot, enabling other nodes and external tools to identify which physical robot they are communicating with. It is intended to be launched early in the robot's startup sequence as a lightweight background service.

## Launch

```bash
source install/setup.bash
ros2 launch xsys xsys.launch.py
```

## Services provided

| Service | Type | Description |
|---------|------|-------------|
| `/xsys/get_serial_number` | `xsys_msgs/srv/GetSerialNumber` | Returns the robot's unique hardware serial number |

## Examples

### Query the robot serial number from the terminal

```bash
source install/setup.bash
ros2 service call /xsys/get_serial_number xsys_msgs/srv/GetSerialNumber
```

Expected output:

```
response:
xsys_msgs.srv.GetSerialNumber_Response(serial_number='<serial_number>')
```

### Python snippet – retrieve the serial number programmatically

```python
import rclpy
from rclpy.node import Node
from xsys_msgs.srv import GetSerialNumber

class SerialQuery(Node):
    def __init__(self):
        super().__init__('serial_query')
        client = self.create_client(GetSerialNumber, '/xsys/get_serial_number')
        client.wait_for_service(timeout_sec=5.0)
        future = client.call_async(GetSerialNumber.Request())
        rclpy.spin_until_future_complete(self, future)
        print('Serial number:', future.result().serial_number)

rclpy.init()
SerialQuery()
```
