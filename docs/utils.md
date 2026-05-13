# utils

The `utils` package is a collection of robot-side utility services that run in parallel with the main control stack. It contains three main components:

- **bag_record** – a ROS 2 bag recording tool that can capture all topics or a configured subset, with a trigger mechanism and a 4 GB rotation limit.
- **disk_manager** – a daemon that monitors available disk space and automatically deletes the oldest bag files to prevent the SSD from filling up.
- **system_monitor** – a lightweight native binary that periodically samples CPU (per-core, 200 ms), memory (2 s), and per-process resource usage (5 s) and publishes them using `monitor_msgs` types on `/monitor/*` topics.

## Launch individual utilities

```bash
source install/setup.bash

# Record all ROS topics
ros2 launch utils record_all_topic.py

# Record only configured topics
ros2 launch utils record_config_topic.py

# Start disk manager (runs as init script automatically)
ros2 launch utils disk_manager.py

# Start cloud proxy / service
ros2 launch utils cloud_proxy.py
```

## Examples

### Start bag recording manually

```bash
source install/setup.bash
ros2 run utils bag_record record --all-topics --total 4096
```

### Monitor CPU usage published by system_monitor

```bash
ros2 topic echo /monitor/cpu_monitor_data
```

### Monitor memory usage

```bash
ros2 topic echo /monitor/mem_monitor_data
```

### Monitor per-process stats

```bash
ros2 topic echo /monitor/proc_monitor_data
```

### Python snippet – check disk space topic

```python
import rclpy
from rclpy.node import Node
from monitor_msgs.msg import SysMemData

class MemWatch(Node):
    def __init__(self):
        super().__init__('mem_watch')
        self.create_subscription(SysMemData, '/monitor/mem_monitor_data', self.cb, 10)

    def cb(self, msg):
        self.get_logger().info(f'Free memory: {msg.free_mb:.0f} MB')

rclpy.init()
rclpy.spin(MemWatch())
```
