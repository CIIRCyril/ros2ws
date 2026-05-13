# rl_control

The `rl_control` package implements a reinforcement-learning-based locomotion controller for the robot (`rl_control::RLControlPlugin`). It loads a pre-trained policy (stored as traced model files under `share/python_scripts/traced/`) and uses it to compute low-level joint torque commands from high-level velocity or motion targets received over ROS topics. The node subscribes to `bodyctrl_msgs` motor-state feedback and publishes motor commands, enabling smooth bipedal walking and balance without hand-crafted gait controllers.

## Launch

```bash
sudo su
cd ~/ros2ws
source install/setup.bash
ros2 run rl_control rl_control_node
```

Or via the convenience script:

```bash
sudo ~/ros2ws/scripts/start_rl.bash
```

Or via launch file:

```bash
ros2 launch rl_control rl.py
```

## Examples

### Start RL control after body control is already running

```bash
# Terminal 1 – body control
sudo ~/ros2ws/scripts/start_debug.bash

# Terminal 2 – RL locomotion controller
sudo ~/ros2ws/scripts/start_rl.bash
```

### Check RL node is publishing motor commands

```bash
ros2 topic list | grep cmd
ros2 topic echo /leg/cmd_ctrl
```

### Python snippet – send a walk-forward velocity goal

```python
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class WalkForward(Node):
    def __init__(self):
        super().__init__('walk_forward')
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.timer = self.create_timer(0.1, self.send)

    def send(self):
        msg = Twist()
        msg.linear.x = 0.2   # 0.2 m/s forward
        self.pub.publish(msg)

rclpy.init()
rclpy.spin(WalkForward())
```
