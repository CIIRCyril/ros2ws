#!/usr/bin/env python3
"""
visualize_real_robot.py — Live PyBullet mirror of the S2full robot state.

Subscribes to all motor-status ROS 2 topics and drives the PyBullet URDF
visualisation from the real robot's joint positions in real time.
Moving any slider sends a position command to the corresponding motor.

Sliders are initialised to the robot's live positions at startup.
Press 'f' at any time to re-sync all sliders to the current robot positions.

⚠  WARNING — Leg-joint sliders will move the physical robot.
   Do NOT operate while the robot is unsupported.

Keyboard controls (click the PyBullet window first):
    f   — re-sync all sliders to current robot joint positions
    q   — quit
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
from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition, MotorStatusMsg


# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------

SLIDER_DEAD_ZONE_RAD = math.radians(0.5)   # ignore sub-0.5° slider jitter

# motor_id → URDF joint name  (matches URDF_TO_GUI in motion_control_GUI.py)
MOTOR_TO_URDF = {
    # Head  (motor 1=roll, 2=pitch, 3=yaw)
    1: 'head_roll_joint',
    2: 'head_pitch_joint',
    3: 'head_yaw_joint',
    # Left arm  (11-17)
    11: 'shoulder_pitch_l_joint', 12: 'shoulder_roll_l_joint',
    13: 'shoulder_yaw_l_joint',   14: 'elbow_pitch_l_joint',
    15: 'wrist_yaw_l_joint',      16: 'wrist_pitch_l_joint',  17: 'wrist_roll_l_joint',
    # Right arm  (21-27)
    21: 'shoulder_pitch_r_rjoint', 22: 'shoulder_roll_r_rjoint',
    23: 'shoulder_yaw_r_rjoint',   24: 'elbow_pitch_r_rjoint',
    25: 'wrist_yaw_r_rjoint',      26: 'wrist_pitch_r_rjoint', 27: 'wrist_roll_r_rjoint',
    # Waist  (31)
    31: 'body_yaw_rjoint',
    # Left leg  (51-56)
    51: 'hip_roll_l_joint',    52: 'hip_pitch_l_joint',   53: 'hip_yaw_l_joint',
    54: 'knee_pitch_l_joint',  55: 'ankle_pitch_l_joint', 56: 'ankle_roll_l_joint',
    # Right leg  (61-66)
    61: 'hip_roll_r_joint',    62: 'hip_pitch_r_joint',   63: 'hip_yaw_r_joint',
    64: 'knee_pitch_r_joint',  65: 'ankle_pitch_r_joint', 66: 'ankle_roll_r_joint',
}


def _motor_route(motor_id):
    """Return (topic_key, profile_speed, current_limit) for a motor ID."""
    if 11 <= motor_id <= 27:
        return 'arm',   0.5, 8.0
    if 51 <= motor_id <= 66:
        return 'leg',   0.5, 8.0
    if motor_id == 31:
        return 'waist', 0.2, 8.0
    if 1 <= motor_id <= 3:
        return 'head',  0.2, 8.0
    return None, 0.5, 8.0


# ---------------------------------------------------------------------------
# ROS 2 node
# ---------------------------------------------------------------------------

class RobotMirrorNode(Node):
    """Subscribes to all motor-status topics; publishes position commands."""

    def __init__(self):
        super().__init__('visualize_real_robot')
        self._lock = threading.Lock()
        self._motor_pos: dict = {}   # motor_id (int) → pos (float, rad)

        for topic in ('/arm/status', '/leg/status', '/waist/status', '/head/status'):
            self.create_subscription(MotorStatusMsg, topic, self._status_cb, 10)

        self._pubs = {
            'arm':   self.create_publisher(CmdSetMotorPosition, '/arm/cmd_pos',   10),
            'leg':   self.create_publisher(CmdSetMotorPosition, '/leg/cmd_pos',   10),
            'waist': self.create_publisher(CmdSetMotorPosition, '/waist/cmd_pos', 10),
            'head':  self.create_publisher(CmdSetMotorPosition, '/head/cmd_pos',  10),
        }

    def _status_cb(self, msg):
        with self._lock:
            for st in msg.status:
                self._motor_pos[st.name] = st.pos

    def get_positions(self):
        with self._lock:
            return dict(self._motor_pos)

    def send_position(self, motor_id, pos_rad):
        topic_key, spd, cur = _motor_route(motor_id)
        if topic_key is None:
            return
        msg = CmdSetMotorPosition()
        c = SetMotorPosition()
        c.name = motor_id
        c.pos  = float(pos_rad)
        c.spd  = spd
        c.cur  = cur
        msg.cmds = [c]
        self._pubs[topic_key].publish(msg)


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _prepare_urdf_for_pybullet(src_urdf, examples_dir):
    with open(src_urdf, 'r', encoding='utf-8') as f:
        text = f.read()
    text = text.replace('package://ubtech/', '')
    src_name = os.path.splitext(os.path.basename(src_urdf))[0]
    out_path = os.path.join(examples_dir, f'_{src_name}_pybullet.urdf')
    with open(out_path, 'w', encoding='utf-8') as f:
        f.write(text)
    return out_path


def _build_sliders(robot_id, name_to_joint, initial_pos_rad):
    """Create one debug slider per mapped motor joint.

    Sliders are initialised to initial_pos_rad[motor_id] (radians).
    Returns a list of slider-info dicts.
    """
    sliders = []
    for motor_id in sorted(MOTOR_TO_URDF):
        urdf_name = MOTOR_TO_URDF[motor_id]
        if urdf_name not in name_to_joint:
            continue
        joint_idx = name_to_joint[urdf_name]
        ji = p.getJointInfo(robot_id, joint_idx)
        lo_rad, hi_rad = ji[8], ji[9]
        if lo_rad >= hi_rad:
            lo_rad, hi_rad = -math.pi, math.pi

        start_rad = initial_pos_rad.get(motor_id, 0.0)
        start_deg = math.degrees(np.clip(start_rad, lo_rad, hi_rad))

        label = f'{urdf_name}  [m{motor_id}]  (deg)'
        slider_id = p.addUserDebugParameter(
            label,
            math.degrees(lo_rad),
            math.degrees(hi_rad),
            start_deg,
        )
        sliders.append({
            'slider_id':    slider_id,
            'motor_id':     motor_id,
            'joint_idx':    joint_idx,
            'urdf_name':    urdf_name,
            'last_val_rad': start_rad,
        })
    return sliders


def _remove_sliders(sliders):
    for s in sliders:
        try:
            p.removeUserDebugItem(s['slider_id'])
        except Exception:
            pass


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    examples_dir = os.path.dirname(os.path.abspath(__file__))
    src_urdf     = os.path.join(examples_dir, 'S2full.urdf')

    # ── ROS 2 ─────────────────────────────────────────────────────────────────
    rclpy.init()
    ros_node = RobotMirrorNode()

    # Spin in a background daemon thread so callbacks fire continuously
    spin_thread = threading.Thread(target=rclpy.spin, args=(ros_node,), daemon=True)
    spin_thread.start()

    # Wait up to 3 s for the first status messages
    print('Waiting for robot status messages …', end='', flush=True)
    deadline = time.time() + 3.0
    while time.time() < deadline and not ros_node.get_positions():
        time.sleep(0.05)
    initial_pos = ros_node.get_positions()
    if initial_pos:
        print(f' received {len(initial_pos)} motor positions.')
    else:
        print(' timed out — no status received; sliders start at 0.')

    # ── PyBullet ──────────────────────────────────────────────────────────────
    p.connect(p.GUI)
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
        print(f'Loaded robot: {src_urdf}')
    except Exception as ex:
        print(f'Error loading URDF: {ex}')
        ros_node.destroy_node()
        rclpy.shutdown()
        return

    # Build URDF joint-name → PyBullet joint-index map
    num_joints = p.getNumJoints(robot_id)
    name_to_joint = {}
    for ji in range(num_joints):
        info = p.getJointInfo(robot_id, ji)
        name_to_joint[info[1].decode('utf-8')] = ji

    # Teleport robot to initial pose from status
    for motor_id, urdf_name in MOTOR_TO_URDF.items():
        if urdf_name in name_to_joint and motor_id in initial_pos:
            p.resetJointState(robot_id, name_to_joint[urdf_name], initial_pos[motor_id])

    # Create sliders
    sliders = _build_sliders(robot_id, name_to_joint, initial_pos)
    print(f'Created {len(sliders)} sliders.')
    print('⚠  Leg-joint sliders move the physical robot — ensure it is supported!')
    print('Controls: f = re-sync sliders to robot  |  q = quit')

    p.resetDebugVisualizerCamera(
        cameraDistance=1.5, cameraYaw=-60, cameraPitch=-20,
        cameraTargetPosition=[0, 0, 0.2],
    )

    try:
        while True:
            keys = p.getKeyboardEvents()

            # 'f' — re-sync sliders to current robot positions
            if ord('f') in keys and keys[ord('f')] & p.KEY_WAS_TRIGGERED:
                cur_pos = ros_node.get_positions()
                _remove_sliders(sliders)
                sliders = _build_sliders(robot_id, name_to_joint, cur_pos)
                print(f'[f] Re-synced {len(sliders)} sliders to current robot positions.')

            # 'q' — quit
            if ord('q') in keys and keys[ord('q')] & p.KEY_WAS_TRIGGERED:
                print('Quitting.')
                break

            # Pull latest robot positions
            robot_pos = ros_node.get_positions()

            # Mirror real robot → PyBullet joints
            for s in sliders:
                mid = s['motor_id']
                if mid in robot_pos:
                    p.resetJointState(robot_id, s['joint_idx'], robot_pos[mid])

            # Detect slider changes → command robot (in a daemon thread to
            # avoid blocking the loop on the first DDS publish call)
            for s in sliders:
                slider_deg = p.readUserDebugParameter(s['slider_id'])
                slider_rad = math.radians(slider_deg)
                if abs(slider_rad - s['last_val_rad']) > SLIDER_DEAD_ZONE_RAD:
                    threading.Thread(
                        target=ros_node.send_position,
                        args=(s['motor_id'], slider_rad),
                        daemon=True,
                    ).start()
                    s['last_val_rad'] = slider_rad

            p.stepSimulation()
            time.sleep(0.02)   # ~50 Hz

    except Exception as ex:
        print(f'Simulation error: {ex}')
    finally:
        ros_node.destroy_node()
        rclpy.shutdown()
        p.disconnect()


if __name__ == '__main__':
    main()
