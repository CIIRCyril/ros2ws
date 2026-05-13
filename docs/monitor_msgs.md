# monitor_msgs

The `monitor_msgs` package defines the custom ROS 2 message types used by the system-monitoring subsystem (`utils/system_monitor`). It provides structured messages for reporting CPU usage (per-core and aggregate), memory consumption, disk I/O, and per-process resource statistics (CPU, memory, I/O). These messages are published by the `system_monitor` binary on topics such as `/monitor/cpu_monitor_data`, `/monitor/mem_monitor_data`, and `/monitor/proc_monitor_data`, enabling external tools or dashboards to track robot-computer health in real time.

## Message types (`monitor_msgs/msg`)

| Type | Description |
|------|-------------|
| `SysCpuData` | Single CPU-core utilisation sample |
| `SysCpuDatas` | Array of per-core CPU samples |
| `SysMemData` | System-wide memory statistics |
| `SysIoData` | System-wide disk I/O statistics |
| `ProcData` | Aggregate resource data for one process |
| `ProcCpuData` | Per-process CPU usage |
| `ProcMemData` | Per-process memory usage |
| `ProcIoData` | Per-process disk I/O |
| `ProcDatas` | Array of `ProcData` for all monitored processes |

## Examples

### Watch CPU usage in real time

```bash
ros2 topic echo /monitor/cpu_monitor_data
```

### Watch memory usage

```bash
ros2 topic echo /monitor/mem_monitor_data
```

### Watch per-process resource stats

```bash
ros2 topic echo /monitor/proc_monitor_data
```

### Python snippet – print CPU load from a subscriber

```python
import rclpy
from rclpy.node import Node
from monitor_msgs.msg import SysCpuDatas

class CpuMonitor(Node):
    def __init__(self):
        super().__init__('cpu_monitor')
        self.create_subscription(
            SysCpuDatas, '/monitor/cpu_monitor_data', self.cb, 10
        )

    def cb(self, msg):
        for core in msg.datas:
            self.get_logger().info(f'Core usage: {core.usage:.1f}%')

rclpy.init()
rclpy.spin(CpuMonitor())
```
