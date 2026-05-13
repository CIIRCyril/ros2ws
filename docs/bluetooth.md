# bluetooth

The `bluetooth` package provides a ROS 2 composable node (`com::xhumanoid::BluetoothNodelet`) that runs a BLE (Bluetooth Low Energy) server on the robot. It allows external devices such as a mobile app or companion computer to connect wirelessly and exchange control or status data with the robot. The node is configured through parameters for server mode and log level and integrates with the body-control subsystem via `bodyctrl_msgs`.

## Launch

```bash
source install/setup.bash
ros2 launch bluetooth bluetooth.launch.py
```

## Examples

### List active ROS nodes to confirm the server is running

```bash
ros2 node list | grep bluetooth
```

### Check topics published by the bluetooth node

```bash
ros2 node info /bluetooth_server_node
```

### Python snippet – verify the node is alive

```python
import subprocess, sys

result = subprocess.run(["ros2", "node", "list"], capture_output=True, text=True)
if "bluetooth_server_node" in result.stdout:
    print("Bluetooth server is running")
else:
    print("Bluetooth server NOT found – check launch")
    sys.exit(1)
```
