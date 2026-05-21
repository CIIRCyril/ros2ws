#!/usr/bin/env python3
"""
manual_positioning.py — Manual joint positioning via physical manipulation.

Starts with the PyBullet visualisation mirroring the real robot.
All motors are set to a very low current (~0.3 A) so the human can
physically move the robot's joints while the URDF follows in real time.

Keyboard controls (click the PyBullet window first):
    SPACE  — freeze robot at current pose
               (legs 15 A  |  arms & waist 8 A  |  head & fingers 2 A)
    ENTER  — smoothly release back to free mode (0.3 A) over 1 second
    q      — quit

⚠  WARNING — ensure the robot is safely supported before use.
"""

import math
import os
import threading
import time

import numpy as np
import pybullet as p
import pybullet_data
import rclpy
from rclpy.node import Node
from bodyctrl_msgs.msg import (
    CmdSetMotorPosition,
    SetMotorPosition,
    MotorStatusMsg,
)


# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------

FREE_CURRENT_A    = 0.3   # current limit in free / compliant mode
RELEASE_RAMP_SEC  = 1.0   # duration of the freeze→free current ramp (s)
FREE_PROFILE_SPD  = 0.2   # rad/s – slow profile so motors don't fight

# Freeze currents per joint group
FREEZE_CURRENT = {
    'leg':    15.0,
    'arm':    8.0,
    'waist':  8.0,
    'head':   2.0,
    'finger': 2.0,
}

PUBLISH_RATE_HZ  = 25    # how often we push commands to the robot
PYBULLET_RATE_HZ = 50    # how often we step the simulation

# motor_id → URDF joint name
MOTOR_TO_URDF = {
    # Head
    1: 'head_roll_joint',
    2: 'head_pitch_joint',
    3: 'head_yaw_joint',
    # Left arm
    11: 'shoulder_pitch_l_joint', 12: 'shoulder_roll_l_joint',
    13: 'shoulder_yaw_l_joint',   14: 'elbow_pitch_l_joint',
    15: 'wrist_yaw_l_joint',      16: 'wrist_pitch_l_joint',  17: 'wrist_roll_l_joint',
    # Right arm
    21: 'shoulder_pitch_r_rjoint', 22: 'shoulder_roll_r_rjoint',
    23: 'shoulder_yaw_r_rjoint',   24: 'elbow_pitch_r_rjoint',
    25: 'wrist_yaw_r_rjoint',      26: 'wrist_pitch_r_rjoint', 27: 'wrist_roll_r_rjoint',
    # Waist
    31: 'body_yaw_rjoint',
    # Left leg
    51: 'hip_roll_l_joint',    52: 'hip_pitch_l_joint',   53: 'hip_yaw_l_joint',
    54: 'knee_pitch_l_joint',  55: 'ankle_pitch_l_joint', 56: 'ankle_roll_l_joint',
    # Right leg
    61: 'hip_roll_r_joint',    62: 'hip_pitch_r_joint',   63: 'hip_yaw_r_joint',
    64: 'knee_pitch_r_joint',  65: 'ankle_pitch_r_joint', 66: 'ankle_roll_r_joint',
}


def _motor_group(motor_id: int) -> str:
    """Return the group name for a motor ID."""
    if 1 <= motor_id <= 3:
        return 'head'
    if 11 <= motor_id <= 17 or 21 <= motor_id <= 27:
        return 'arm'
    if motor_id == 31:
        return 'waist'
    if 51 <= motor_id <= 66:
        return 'leg'
    return 'arm'   # fallback


def _motor_topic(motor_id: int) -> str:
    """Return the ROS topic key for position commands."""
    g = _motor_group(motor_id)
    if g in ('arm', 'leg', 'waist', 'head'):
        return g
    return 'arm'


# ---------------------------------------------------------------------------
# ROS 2 node
# ---------------------------------------------------------------------------

class ManualPositioningNode(Node):
    """Reads motor status; publishes compliant position commands."""

    def __init__(self):
        super().__init__('manual_positioning')
        self._lock = threading.Lock()
        self._motor_pos: dict[int, float] = {}   # motor_id → rad

        for topic in ('/arm/status', '/leg/status', '/waist/status', '/head/status'):
            self.create_subscription(MotorStatusMsg, topic, self._status_cb, 10)

        self._pubs = {
            'arm':   self.create_publisher(CmdSetMotorPosition, '/arm/cmd_pos',   10),
            'leg':   self.create_publisher(CmdSetMotorPosition, '/leg/cmd_pos',   10),
            'waist': self.create_publisher(CmdSetMotorPosition, '/waist/cmd_pos', 10),
            'head':  self.create_publisher(CmdSetMotorPosition, '/head/cmd_pos',  10),
        }

    # ── status callback ───────────────────────────────────────────────────────

    def _status_cb(self, msg: MotorStatusMsg):
        with self._lock:
            for st in msg.status:
                self._motor_pos[st.name] = st.pos

    def get_positions(self) -> dict[int, float]:
        with self._lock:
            return dict(self._motor_pos)

    # ── command helpers ───────────────────────────────────────────────────────

    def _build_cmd(self, motor_id: int, pos_rad: float,
                   current_a: float, spd: float) -> tuple[str, CmdSetMotorPosition]:
        topic_key = _motor_topic(motor_id)
        msg = CmdSetMotorPosition()
        c = SetMotorPosition()
        c.name = motor_id
        c.pos  = float(pos_rad)
        c.spd  = float(spd)
        c.cur  = float(current_a)
        msg.cmds = [c]
        return topic_key, msg

    def send_free_commands(self, positions: dict[int, float]):
        """Send low-current tracking commands so joints are back-drivable."""
        self.send_ramp_commands(positions, current_scale=0.0)

    def send_ramp_commands(self, positions: dict[int, float], current_scale: float):
        """Send position commands with per-group current interpolated by scale.

        current_scale=1.0 → freeze currents
        current_scale=0.0 → FREE_CURRENT_A
        """
        batches: dict[str, list[SetMotorPosition]] = {
            'arm': [], 'leg': [], 'waist': [], 'head': []
        }
        for motor_id in MOTOR_TO_URDF:
            if motor_id not in positions:
                continue
            group = _motor_group(motor_id)
            freeze_cur = FREEZE_CURRENT.get(group, 8.0)
            cur = FREE_CURRENT_A + (freeze_cur - FREE_CURRENT_A) * current_scale
            c = SetMotorPosition()
            c.name = motor_id
            c.pos  = float(positions[motor_id])
            c.spd  = FREE_PROFILE_SPD
            c.cur  = float(cur)
            batches[_motor_topic(motor_id)].append(c)

        for topic_key, cmds in batches.items():
            if cmds:
                msg = CmdSetMotorPosition()
                msg.cmds = cmds
                self._pubs[topic_key].publish(msg)

    def send_freeze_commands(self, freeze_positions: dict[int, float]):
        """Send high-current commands to hold the frozen pose."""
        batches: dict[str, list[SetMotorPosition]] = {
            'arm': [], 'leg': [], 'waist': [], 'head': []
        }
        for motor_id in MOTOR_TO_URDF:
            if motor_id not in freeze_positions:
                continue
            group = _motor_group(motor_id)
            current_a = FREEZE_CURRENT.get(group, 8.0)

            c = SetMotorPosition()
            c.name = motor_id
            c.pos  = float(freeze_positions[motor_id])
            c.spd  = 0.5
            c.cur  = current_a
            batches[_motor_topic(motor_id)].append(c)

        for topic_key, cmds in batches.items():
            if cmds:
                msg = CmdSetMotorPosition()
                msg.cmds = cmds
                self._pubs[topic_key].publish(msg)


# ---------------------------------------------------------------------------
# URDF helpers
# ---------------------------------------------------------------------------

def _prepare_urdf_for_pybullet(src_urdf: str, examples_dir: str) -> str:
    with open(src_urdf, 'r', encoding='utf-8') as f:
        text = f.read()
    text = text.replace('package://ubtech/', '')
    src_name = os.path.splitext(os.path.basename(src_urdf))[0]
    out_path = os.path.join(examples_dir, f'_{src_name}_pybullet.urdf')
    with open(out_path, 'w', encoding='utf-8') as f:
        f.write(text)
    return out_path


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    examples_dir = os.path.dirname(os.path.abspath(__file__))
    src_urdf     = os.path.join(examples_dir, 'S2full.urdf')

    # ── ROS 2 ─────────────────────────────────────────────────────────────────
    rclpy.init()
    ros_node = ManualPositioningNode()

    spin_thread = threading.Thread(target=rclpy.spin, args=(ros_node,), daemon=True)
    spin_thread.start()

    print('Waiting for robot status messages …', end='', flush=True)
    deadline = time.time() + 5.0
    while time.time() < deadline and not ros_node.get_positions():
        time.sleep(0.05)
    initial_pos = ros_node.get_positions()
    if initial_pos:
        print(f' received {len(initial_pos)} motor positions.')
    else:
        print(' timed out — no status received; URDF starts at zero.')

    # ── PyBullet ──────────────────────────────────────────────────────────────
    p.connect(p.GUI)
    p.configureDebugVisualizer(p.COV_ENABLE_GUI, 0)
    p.setAdditionalSearchPath(pybullet_data.getDataPath())
    p.setGravity(0, 0, -9.81)
    p.loadURDF('plane.urdf', basePosition=[0, 0, -1.02])

    urdf = _prepare_urdf_for_pybullet(src_urdf, examples_dir)
    try:
        robot_id = p.loadURDF(
            urdf,
            useFixedBase=True,
            basePosition=[0.0, 0.0, 0.0],
            baseOrientation=[0, 0, 0, 1],
        )
        print(f'Loaded URDF: {urdf}')
    except Exception as ex:
        print(f'Error loading URDF: {ex}')
        ros_node.destroy_node()
        rclpy.shutdown()
        return

    # Build URDF joint-name → PyBullet joint-index map
    num_joints = p.getNumJoints(robot_id)
    name_to_joint: dict[str, int] = {}
    for ji in range(num_joints):
        info = p.getJointInfo(robot_id, ji)
        name_to_joint[info[1].decode('utf-8')] = ji

    # Set initial URDF pose from robot
    for motor_id, urdf_name in MOTOR_TO_URDF.items():
        if urdf_name in name_to_joint and motor_id in initial_pos:
            p.resetJointState(robot_id, name_to_joint[urdf_name], initial_pos[motor_id])

    p.resetDebugVisualizerCamera(
        cameraDistance=1.05, cameraYaw=80, cameraPitch=-25,
        cameraTargetPosition=[0, 0, 0.0],
    )

    # ── Status label ──────────────────────────────────────────────────────────
    status_label_id = p.addUserDebugText(
        'MODE: FREE  (SPACE=freeze | ENTER=release | q=quit)',
        textPosition=[0, 0, 1.1],
        textColorRGB=[0.2, 0.8, 0.2],
        textSize=1.2,
    )

    # ── State machine ─────────────────────────────────────────────────────────
    MODE_FREE      = 'free'
    MODE_FROZEN    = 'frozen'
    MODE_RELEASING = 'releasing'   # ramp-down transition
    mode = MODE_FREE
    freeze_positions: dict[int, float] = {}
    release_start_time: float = 0.0

    # Send initial free commands right away
    if initial_pos:
        ros_node.send_free_commands(initial_pos)
        print('Motors set to free mode (0.3 A). You can move the joints manually.')
    else:
        print('No initial positions — skipping first command burst.')

    print('Controls: SPACE = freeze  |  ENTER = release  |  q = quit')

    cmd_interval   = 1.0 / PUBLISH_RATE_HZ
    sim_interval   = 1.0 / PYBULLET_RATE_HZ
    last_cmd_time  = 0.0

    SPACE_KEY = ord(' ')   # 32
    ENTER_KEY = 65309      # pybullet Return key code
    ENTER_ALT = 13         # alternative Enter keycode

    try:
        while True:
            loop_start = time.time()

            # ── keyboard ──────────────────────────────────────────────────────
            keys = p.getKeyboardEvents()

            if ord('q') in keys and keys[ord('q')] & p.KEY_WAS_TRIGGERED:
                print('Quitting.')
                break

            if SPACE_KEY in keys and keys[SPACE_KEY] & p.KEY_WAS_TRIGGERED:
                if mode in (MODE_FREE, MODE_RELEASING):
                    freeze_positions = ros_node.get_positions()
                    mode = MODE_FROZEN
                    ros_node.send_freeze_commands(freeze_positions)
                    p.removeUserDebugItem(status_label_id)
                    status_label_id = p.addUserDebugText(
                        'MODE: FROZEN  (ENTER=release | q=quit)',
                        textPosition=[0, 0, 1.1],
                        textColorRGB=[0.9, 0.4, 0.1],
                        textSize=1.2,
                    )
                    print('[SPACE] Robot FROZEN — legs 15 A, arms/waist 8 A, head 2 A.')

            if (ENTER_KEY in keys and keys[ENTER_KEY] & p.KEY_WAS_TRIGGERED) or \
               (ENTER_ALT in keys and keys[ENTER_ALT] & p.KEY_WAS_TRIGGERED):
                if mode == MODE_FROZEN:
                    mode = MODE_RELEASING
                    release_start_time = time.time()
                    p.removeUserDebugItem(status_label_id)
                    status_label_id = p.addUserDebugText(
                        'MODE: RELEASING …',
                        textPosition=[0, 0, 1.1],
                        textColorRGB=[0.8, 0.8, 0.2],
                        textSize=1.2,
                    )
                    print('[ENTER] Releasing — ramping current to 0.3 A over 1 s …')

            # ── publish commands at PUBLISH_RATE_HZ ───────────────────────────
            now = time.time()
            if now - last_cmd_time >= cmd_interval:
                last_cmd_time = now
                current_pos = ros_node.get_positions()

                if mode == MODE_FREE:
                    if current_pos:
                        ros_node.send_free_commands(current_pos)

                elif mode == MODE_FROZEN:
                    if freeze_positions:
                        ros_node.send_freeze_commands(freeze_positions)

                elif mode == MODE_RELEASING:
                    elapsed_release = now - release_start_time
                    # scale goes from 1.0 → 0.0 over RELEASE_RAMP_SEC
                    scale = max(0.0, 1.0 - elapsed_release / RELEASE_RAMP_SEC)
                    if scale > 0.0:
                        # hold frozen position while ramping current down
                        ros_node.send_ramp_commands(freeze_positions, scale)
                    else:
                        # ramp finished — switch to free tracking mode
                        mode = MODE_FREE
                        freeze_positions = {}
                        p.removeUserDebugItem(status_label_id)
                        status_label_id = p.addUserDebugText(
                            'MODE: FREE  (SPACE=freeze | ENTER=release | q=quit)',
                            textPosition=[0, 0, 1.1],
                            textColorRGB=[0.2, 0.8, 0.2],
                            textSize=1.2,
                        )
                        print('[RELEASE] Free mode restored (0.3 A).')
                        if current_pos:
                            ros_node.send_free_commands(current_pos)

            # ── mirror robot → PyBullet ───────────────────────────────────────
            display_pos = ros_node.get_positions()
            for motor_id, urdf_name in MOTOR_TO_URDF.items():
                if urdf_name in name_to_joint and motor_id in display_pos:
                    p.resetJointState(
                        robot_id,
                        name_to_joint[urdf_name],
                        display_pos[motor_id],
                    )

            p.stepSimulation()

            # ── rate limit ────────────────────────────────────────────────────
            elapsed = time.time() - loop_start
            sleep_time = sim_interval - elapsed
            if sleep_time > 0:
                time.sleep(sleep_time)

    except Exception as ex:
        print(f'Simulation error: {ex}')
    finally:
        ros_node.destroy_node()
        rclpy.shutdown()
        p.disconnect()


if __name__ == '__main__':
    main()
