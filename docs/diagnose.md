# diagnose

The `diagnose` package provides a ROS 2 composable node (`debugger::DebuggerNodelet`) responsible for hardware diagnostics, firmware upgrade orchestration, and low-level device debugging across different robot variants (Tiangong 2.0 Pro/Plus/Lite, TianYi 2.0, wheel-based robots). Each variant has a dedicated launch file and XML configuration that defines which subsystems are monitored. The node is also embedded inside `body_control`'s main launch to run continuous health checks during normal operation.

## Launch

```bash
source install/setup.bash
# For Tiangong 2.0 Pro
ros2 launch diagnose tiangong2.0_pro.launch.py

# With firmware upgrade support
ros2 launch diagnose upgrade.launch.py
```

## Examples

### Standalone diagnostic launch for Tiangong 2.0 Lite

```bash
source install/setup.bash
ros2 launch diagnose tiangong2.0_lite.launch.py
```

### Check which diagnostic topics are being published

```bash
ros2 topic list | grep -i diag
```

### Python snippet – poll node availability

```python
import subprocess

result = subprocess.run(
    ["ros2", "node", "list"], capture_output=True, text=True
)
if any("diagnose" in line for line in result.stdout.splitlines()):
    print("Diagnose node is active")
else:
    print("Diagnose node not running")
```
