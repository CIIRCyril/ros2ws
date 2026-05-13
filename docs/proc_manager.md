# proc_manager

The `proc_manager` package provides a ROS 2 composable node (`com::xhumanoid::ProcManagerNodelet`) that acts as a supervisor and sequencer for all robot subsystems. Using a JSON configuration file (e.g. `proc_manager.json`), it defines the startup order of processes (power board, SBUS, body control, motion, audio …), monitors their readiness topics, plays audio cues on key lifecycle events (boot, stand-up, shutdown), and reacts to remote-control button presses via SBUS triggers. In production the node runs as a `systemd` service (`proc_manager.service`) so that the robot boots into a ready state automatically.

## Launch

```bash
source install/setup.bash
# Tiangong 2.0 Pro variant
ros2 launch proc_manager tg2.0_pro.launch.py

# Tiangong 2.0 Lite variant
ros2 launch proc_manager tg2.0_lite.launch.py
```

## Stop the auto-start service (for manual debugging)

```bash
sudo systemctl stop proc_manager.service
```

## Examples

### Check which processes proc_manager expects to be running

```bash
cat ~/ros2ws/install/proc_manager/share/proc_manager/param/proc_manager_tg2.0_pro.json
```

### Watch the body-control readiness topic that proc_manager monitors

```bash
ros2 topic echo /bodycontrol_state
```

### Python snippet – query proc_manager node status

```python
import subprocess

result = subprocess.run(["ros2", "node", "list"], capture_output=True, text=True)
if "proc_manager_node" in result.stdout:
    print("proc_manager is running")
else:
    print("proc_manager not found – start with ros2 launch proc_manager tg2.0_pro.launch.py")
```
