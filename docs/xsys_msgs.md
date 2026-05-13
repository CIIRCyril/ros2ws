# xsys_msgs

The `xsys_msgs` package defines the custom ROS 2 service interface types for the `xsys` core system package. Currently it contains a single service definition, `GetSerialNumber`, which returns the robot's unique hardware serial number as a string. The package is the shared interface layer between the `xsys` node (server) and any other node or tool that needs to identify the robot at runtime.

## Service types (`xsys_msgs/srv`)

| Type | Service name | Request | Response |
|------|-------------|---------|----------|
| `GetSerialNumber` | `/xsys/get_serial_number` | *(empty)* | `string serial_number` |

## Examples

### Call the service from the terminal

```bash
source install/setup.bash
ros2 service call /xsys/get_serial_number xsys_msgs/srv/GetSerialNumber
```

### List the service interface definition

```bash
ros2 interface show xsys_msgs/srv/GetSerialNumber
```

### Python snippet – use the service type directly

```python
import rclpy
from rclpy.node import Node
from xsys_msgs.srv import GetSerialNumber

class IdNode(Node):
    def __init__(self):
        super().__init__('id_node')
        client = self.create_client(GetSerialNumber, '/xsys/get_serial_number')
        if not client.wait_for_service(timeout_sec=3.0):
            self.get_logger().error('xsys service not available')
            return
        future = client.call_async(GetSerialNumber.Request())
        rclpy.spin_until_future_complete(self, future)
        self.get_logger().info(f'Robot ID: {future.result().serial_number}')

rclpy.init()
IdNode()
```
