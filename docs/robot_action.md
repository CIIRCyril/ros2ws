# robot_action

The `robot_action` package ships a standalone web-based GUI application (`app.bin`) for recording, editing, and replaying custom robot action sequences (poses and motions). When launched via `run.sh`, it starts a local HTTP server on port 8080 and exposes a browser interface where users can capture joint positions, arrange them into sequences, and play them back on the robot. Recorded actions are saved as files under `bin/actions/`. This package is self-contained and does not require a full ROS 2 environment to be sourced.

## Launch

```bash
cd ~/ros2ws/install/robot_action
bash run.sh
```

Then open a browser and navigate to:

```
http://localhost:8080
```

or from a remote machine:

```
http://<robot-IP>:8080
```

## Examples

### Start the action recorder from any terminal

```bash
cd ~/ros2ws/install/robot_action
bash run.sh
```

### Access the recorder from a remote computer

```bash
# On your laptop – the robot IP is typically 192.168.0.12
xdg-open http://192.168.0.12:8080
```

### List saved action files

```bash
ls ~/ros2ws/install/robot_action/bin/actions/
```

### Python snippet – trigger a saved action via HTTP API (if supported)

```python
import requests

robot_ip = "192.168.0.12"
action_name = "wave_hand"
response = requests.post(
    f"http://{robot_ip}:8080/api/play",
    json={"action": action_name}
)
print(response.status_code, response.text)
```
