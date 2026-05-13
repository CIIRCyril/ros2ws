#!/usr/bin/env python3
"""
visualize_robot_ik.py — IK control of S2full robot in PyBullet.

Loads S2full.urdf and drives all non-fixed joints via the PyBullet IK solver.
Six debug sliders control the target end-effector pose (X, Y, Z, Roll, Pitch, Yaw).
A coloured box tracks the target; colour indicates IK accuracy:
  Green — position and orientation both within threshold
  Blue  — one of the two within threshold
  Red   — both outside threshold

Keyboard controls (click the PyBullet window first):
    o     — open gripper fingers (from init_pos.json)
    c     — close gripper fingers (from init_pos.json)
    t     — print current joint values and end-effector pose to console
    q     — quit
"""

import csv
import datetime
import json
import os
import time

import numpy as np
import pybullet as p
import pybullet_data

ROBOT_KEY = 'S2full'

# ---------------------------------------------------------------------------
# URDF joint name  →  (motion_control_GUI limb key, index within that array)
#
# GUI limb arrays (all values in degrees, matching motion_control_GUI.py):
#   left_leg_pos  [0-5]  motors 51-56: Hip Roll/Pitch/Yaw, Knee Pitch, Ankle Pitch/Roll
#   right_leg_pos [0-5]  motors 61-66: same order
#   left_arm_pos  [0-6]  motors 11-17: Shoulder Pitch/Roll/Yaw, Elbow Pitch,
#                                       Wrist Yaw/Pitch/Roll
#   right_arm_pos [0-6]  motors 21-27: same order
#   waist_pos     [0]    motor  31:    Waist Yaw
#   head_pos      [0-2]  motors 3,2,1: Roll, Pitch, Yaw  (HEAD_IDS=[3,2,1])
# ---------------------------------------------------------------------------
URDF_TO_GUI = {
    # Left leg  (motors 51-56)
    'hip_roll_l_joint':    ('left_leg_pos',  0),
    'hip_pitch_l_joint':   ('left_leg_pos',  1),
    'hip_yaw_l_joint':     ('left_leg_pos',  2),
    'knee_pitch_l_joint':  ('left_leg_pos',  3),
    'ankle_pitch_l_joint': ('left_leg_pos',  4),
    'ankle_roll_l_joint':  ('left_leg_pos',  5),
    # Right leg  (motors 61-66)
    'hip_roll_r_joint':    ('right_leg_pos', 0),
    'hip_pitch_r_joint':   ('right_leg_pos', 1),
    'hip_yaw_r_joint':     ('right_leg_pos', 2),
    'knee_pitch_r_joint':  ('right_leg_pos', 3),
    'ankle_pitch_r_joint': ('right_leg_pos', 4),
    'ankle_roll_r_joint':  ('right_leg_pos', 5),
    # Waist  (motor 31)
    'body_yaw_rjoint':     ('waist_pos',     0),
    # Head  [roll(m3), pitch(m2), yaw(m1)]  — order matches HEAD_IDS=[3,2,1]
    'head_roll_joint':     ('head_pos',      0),
    'head_pitch_joint':    ('head_pos',      1),
    'head_yaw_joint':      ('head_pos',      2),
    # Left arm  (motors 11-17)
    'shoulder_pitch_l_joint':  ('left_arm_pos', 0),
    'shoulder_roll_l_joint':   ('left_arm_pos', 1),
    'shoulder_yaw_l_joint':    ('left_arm_pos', 2),
    'elbow_pitch_l_joint':     ('left_arm_pos', 3),
    'wrist_yaw_l_joint':       ('left_arm_pos', 4),
    'wrist_pitch_l_joint':     ('left_arm_pos', 5),
    'wrist_roll_l_joint':      ('left_arm_pos', 6),
    # Right arm  (motors 21-27)
    'shoulder_pitch_r_rjoint': ('right_arm_pos', 0),
    'shoulder_roll_r_rjoint':  ('right_arm_pos', 1),
    'shoulder_yaw_r_rjoint':   ('right_arm_pos', 2),
    'elbow_pitch_r_rjoint':    ('right_arm_pos', 3),
    'wrist_yaw_r_rjoint':      ('right_arm_pos', 4),
    'wrist_pitch_r_rjoint':    ('right_arm_pos', 5),
    'wrist_roll_r_rjoint':     ('right_arm_pos', 6),
}


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _load_init_pos(path):
    """Load r_dict / g_dict from init_pos.json, or return empty dicts."""
    if os.path.exists(path):
        with open(path, 'r', encoding='utf-8') as f:
            return json.load(f)
    return {'r_dict': {}, 'g_dict': {}}


def _save_to_gui_positions(robot_id, joint_idxs, joint_names, positions_file):
    """Read current joint states (radians), convert to degrees, and append
    a named position to saved_positions.csv for motion_control_GUI.py.
    Returns the position name used.
    """
    limb_sizes = {
        'left_leg_pos': 6, 'right_leg_pos': 6,
        'left_arm_pos': 7, 'right_arm_pos': 7,
        'waist_pos':    1, 'head_pos':      3,
    }
    positions = {k: [0.0] * n for k, n in limb_sizes.items()}

    for joint_idx, joint_name in zip(joint_idxs, joint_names):
        if joint_name not in URDF_TO_GUI:
            continue
        limb_key, idx = URDF_TO_GUI[joint_name]
        pos_rad = p.getJointState(robot_id, joint_idx)[0]
        positions[limb_key][idx] = round(np.degrees(pos_rad), 2)

    payload = {
        'leg_mode':              'Position',
        'arm_mode':              'Position',
        'left_leg_pos':          positions['left_leg_pos'],
        'right_leg_pos':         positions['right_leg_pos'],
        'left_arm_pos':          positions['left_arm_pos'],
        'right_arm_pos':         positions['right_arm_pos'],
        'leg_profile_speed':     0.5,
        'leg_position_current':  8.0,
        'leg_speed_current':     8.0,
        'arm_profile_speed':     0.5,
        'arm_position_current':  8.0,
        'arm_speed_current':     8.0,
        'waist_pos':             positions['waist_pos'],
        'waist_speed':           [0.2],
        'head_pos':              positions['head_pos'],
        'head_speed':            [0.2],
        'left_finger_pos':       [0.0, 0.0, 0.0, 0.0, 1.0, 0.0],
        'right_finger_pos':      [0.0, 0.0, 0.0, 0.0, 1.0, 0.0],
        'left_finger_vel':       [1.0] * 6,
        'right_finger_vel':      [1.0] * 6,
        'hand_effort':           [1.0],
    }

    name = datetime.datetime.now().strftime('sim_ik_%Y%m%d_%H%M%S')

    saved = {}
    if os.path.exists(positions_file):
        try:
            with open(positions_file, 'r', newline='', encoding='utf-8') as f:
                reader = csv.DictReader(f)
                for row in reader:
                    n  = (row.get('name') or '').strip()
                    pl = row.get('payload')
                    if n and pl:
                        try:
                            saved[n] = json.loads(pl)
                        except json.JSONDecodeError:
                            pass
        except OSError:
            pass

    saved[name] = payload

    with open(positions_file, 'w', newline='', encoding='utf-8') as f:
        writer = csv.DictWriter(f, fieldnames=['name', 'payload'])
        writer.writeheader()
        for n in sorted(saved.keys()):
            writer.writerow({'name': n, 'payload': json.dumps(saved[n])})

    return name


def _set_gripper(robot_id, gjoint_idxs, values):
    """Apply position control to gripper joints."""
    for i, ji in enumerate(gjoint_idxs):
        if i < len(values):
            p.setJointMotorControl2(
                bodyIndex=robot_id,
                jointIndex=ji,
                controlMode=p.POSITION_CONTROL,
                targetPosition=values[i],
                force=200,
            )


def _prepare_urdf_for_pybullet(src_urdf, examples_dir):
    """Create a local URDF copy with package:// paths rewritten for PyBullet."""
    with open(src_urdf, 'r', encoding='utf-8') as f:
        urdf_text = f.read()
    urdf_text = urdf_text.replace('package://ubtech/', '')
    src_name = os.path.splitext(os.path.basename(src_urdf))[0]
    rewritten_urdf = os.path.join(examples_dir, f'_{src_name}_pybullet.urdf')
    with open(rewritten_urdf, 'w', encoding='utf-8') as f:
        f.write(urdf_text)
    return rewritten_urdf


def apply_ik_solution(robot_id, ik_solution, joint_idxs):
    """Apply an IK solution to the robot joints via position control."""
    for index, joint_idx in enumerate(joint_idxs):
        p.setJointMotorControl2(
            bodyIndex=robot_id,
            jointIndex=joint_idx,
            controlMode=p.POSITION_CONTROL,
            targetPosition=ik_solution[index],
            force=500,
        )


def get_controllable_joints(robot_id, num_joints):
    """Return (indices, names) of all non-fixed joints."""
    joint_idxs = []
    joint_names = []
    for joint_idx in range(num_joints):
        joint_info = p.getJointInfo(robot_id, joint_idx)
        if joint_info[2] != p.JOINT_FIXED:
            joint_idxs.append(joint_idx)
            joint_names.append(joint_info[1].decode('utf-8'))
    print(f'Controllable joints: {len(joint_idxs)}')
    return joint_idxs, joint_names


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    examples_dir = os.path.dirname(os.path.abspath(__file__))
    src_urdf = os.path.join(examples_dir, 'S2full.urdf')

    # Load stored positions
    init_pos_path = os.path.join(examples_dir, 'init_pos.json')
    init_pos = _load_init_pos(init_pos_path)
    rd = init_pos.get('r_dict', {})
    gd = init_pos.get('g_dict', {})
    default_joint_ori = rd.get(ROBOT_KEY, {}).get('default_joint_ori', [])
    gripper_open      = gd.get(ROBOT_KEY, {}).get('open', [])
    gripper_close     = gd.get(ROBOT_KEY, {}).get('close', [])
    print(f'Loaded init_pos.json: body joints={len(default_joint_ori)}, '
          f'gripper open={len(gripper_open)}, close={len(gripper_close)}')

    # Initialize PyBullet
    p.connect(p.GUI)
    p.setAdditionalSearchPath(pybullet_data.getDataPath())
    p.setGravity(0, 0, -9.81)

    # Load ground plane
    p.loadURDF('plane.urdf', basePosition=[0, 0, -1.0])
    print('Loaded ground plane at z=-1.0')

    # Load robot
    urdf = _prepare_urdf_for_pybullet(src_urdf, examples_dir)
    try:
        robot_id = p.loadURDF(
            urdf,
            useFixedBase=True,
            basePosition=[0.0, 0.0, 0.0],
            baseOrientation=[0, 0, 0, 1],
            flags=p.URDF_USE_SELF_COLLISION_EXCLUDE_PARENT,
        )
        print(f'Loaded robot: {src_urdf}')
    except Exception as ex:
        print(f'Error loading URDF: {ex}')
        return

    num_joints = p.getNumJoints(robot_id)

    # Collect non-fixed joints and gripper joint indices
    non_fixed_joints = []
    gjoint_idxs = []
    for joint_idx in range(num_joints):
        ji = p.getJointInfo(robot_id, joint_idx)
        if ji[2] != p.JOINT_FIXED:
            non_fixed_joints.append(joint_idx)
            if 'gjoint' in ji[1].decode('utf-8'):
                gjoint_idxs.append(joint_idx)

    # Initialise body joints from r_dict, fingers from g_dict open
    for i, joint_idx in enumerate(non_fixed_joints):
        val = default_joint_ori[i] if i < len(default_joint_ori) else 0.0
        p.resetJointState(robot_id, joint_idx, val)
    for i, joint_idx in enumerate(gjoint_idxs):
        if i < len(gripper_open):
            p.resetJointState(robot_id, joint_idx, gripper_open[i])

    # Find end-effector link
    end_effector_index = -1
    for joint_idx in range(num_joints):
        link_name = p.getJointInfo(robot_id, joint_idx)[12].decode('utf-8')
        if link_name == 'endeffector':
            end_effector_index = joint_idx
            print(f'End effector at joint index: {end_effector_index}')
            break
    if end_effector_index == -1:
        print('Warning: no link named "endeffector" found; using last joint')
        end_effector_index = num_joints - 1

    # Get controllable joints for IK (exclude gripper — driven separately)
    joint_idxs, joint_names = get_controllable_joints(robot_id, num_joints)
    ik_joint_idxs = [ji for ji in joint_idxs if ji not in gjoint_idxs]

    # Initial end-effector pose — use stored values if available
    link_state = p.getLinkState(robot_id, end_effector_index)
    stored = rd.get(ROBOT_KEY, {})
    ee_initial_pos   = stored.get('ee_pos',  list(link_state[0]))
    stored_ori = stored.get('ee_ori')
    ee_initial_euler = stored_ori if stored_ori else list(p.getEulerFromQuaternion(link_state[1]))
    print(f'Initial EE pos:   {ee_initial_pos}')
    print(f'Initial EE euler: {ee_initial_euler}')

    # Visual target box
    box_size = 0.02
    box_visual = p.createVisualShape(
        p.GEOM_BOX,
        halfExtents=[box_size / 2] * 3,
        rgbaColor=[1, 0, 0, 0.5],
    )
    box_id = p.createMultiBody(
        baseMass=0,
        baseCollisionShapeIndex=-1,
        baseVisualShapeIndex=box_visual,
        basePosition=ee_initial_pos,
        baseOrientation=p.getQuaternionFromEuler(ee_initial_euler),
    )

    # IK accuracy thresholds
    POSITION_THRESHOLD    = 0.05   # metres
    ORIENTATION_THRESHOLD = 0.1    # radians

    # Debug sliders for EE target pose
    x_sl     = p.addUserDebugParameter('Target X',     -1.0,    1.0,  ee_initial_pos[0])
    y_sl     = p.addUserDebugParameter('Target Y',     -1.0,    1.0,  ee_initial_pos[1])
    z_sl     = p.addUserDebugParameter('Target Z',     -1.0,    1.0,  ee_initial_pos[2])
    roll_sl  = p.addUserDebugParameter('Target Roll',  -np.pi, np.pi, ee_initial_euler[0])
    pitch_sl = p.addUserDebugParameter('Target Pitch', -np.pi, np.pi, ee_initial_euler[1])
    yaw_sl   = p.addUserDebugParameter('Target Yaw',   -np.pi, np.pi, ee_initial_euler[2])

    p.setRealTimeSimulation(1)
    p.resetDebugVisualizerCamera(
        cameraDistance=3,
        cameraYaw=70,
        cameraPitch=-30,
        cameraTargetPosition=[0, 0, 0.0],
    )

    try:
        while True:
            keys = p.getKeyboardEvents()

            # 'o' — open gripper
            if ord('o') in keys and keys[ord('o')] & p.KEY_WAS_TRIGGERED:
                if gripper_open:
                    _set_gripper(robot_id, gjoint_idxs, gripper_open)
                    print(f'Gripper open: {gripper_open}')
                else:
                    print('No gripper open values in init_pos.json')

            # 'c' — close gripper
            if ord('c') in keys and keys[ord('c')] & p.KEY_WAS_TRIGGERED:
                if gripper_close:
                    _set_gripper(robot_id, gjoint_idxs, gripper_close)
                    print(f'Gripper close: {gripper_close}')
                else:
                    print('No gripper close values in init_pos.json')

            # 'r' — save current IK pose to saved_positions.csv for motion_control_GUI
            if ord('r') in keys and keys[ord('r')] & p.KEY_WAS_TRIGGERED:
                positions_file = os.path.join(examples_dir, 'saved_positions.csv')
                pos_name = _save_to_gui_positions(robot_id, joint_idxs, joint_names, positions_file)
                print(f"Saved IK pose '{pos_name}' to {positions_file}")
                print('Load and execute it via motion_control_GUI.py → Positions tab')

            # 't' — print current joint values and EE pose
            if ord('t') in keys and keys[ord('t')] & p.KEY_WAS_TRIGGERED:
                joint_states = [
                    p.getJointState(robot_id, ji)[0] for ji in joint_idxs
                ]
                print(f'Joint values: {joint_states}')
                ls = p.getLinkState(robot_id, end_effector_index)
                ee_pos   = list(ls[0])
                ee_euler = list(p.getEulerFromQuaternion(ls[1]))
                print(f'EE pos:   {ee_pos}')
                print(f'EE euler: {ee_euler}')

            # 'q' — quit
            if ord('q') in keys and keys[ord('q')] & p.KEY_WAS_TRIGGERED:
                print('Quitting.')
                break

            # Read slider targets
            target_pos = [
                p.readUserDebugParameter(x_sl),
                p.readUserDebugParameter(y_sl),
                p.readUserDebugParameter(z_sl),
            ]
            target_euler = [
                p.readUserDebugParameter(roll_sl),
                p.readUserDebugParameter(pitch_sl),
                p.readUserDebugParameter(yaw_sl),
            ]
            target_quat = p.getQuaternionFromEuler(target_euler)

            # Update target box
            p.resetBasePositionAndOrientation(box_id, target_pos, target_quat)

            # Solve IK and apply (body joints only, not gripper)
            ik_solution = p.calculateInverseKinematics(
                robot_id, end_effector_index, target_pos, target_quat
            )
            apply_ik_solution(robot_id, ik_solution, ik_joint_idxs)

            # Colour the box based on IK accuracy
            ls = p.getLinkState(robot_id, end_effector_index)
            ee_pos   = np.array(ls[0])
            ee_euler = np.array(p.getEulerFromQuaternion(ls[1]))
            pos_ok = np.linalg.norm(ee_pos - np.array(target_pos)) < POSITION_THRESHOLD
            ori_ok = np.linalg.norm(ee_euler - np.array(target_euler)) < ORIENTATION_THRESHOLD

            if pos_ok and ori_ok:
                colour = [0, 1, 0, 0.5]   # green
            elif pos_ok or ori_ok:
                colour = [0, 0, 1, 0.5]   # blue
            else:
                colour = [1, 0, 0, 0.5]   # red
            p.changeVisualShape(box_id, -1, rgbaColor=colour)

            time.sleep(0.01)

    except Exception as ex:
        print(f'Simulation error: {ex}')
    finally:
        p.disconnect()


if __name__ == '__main__':
    main()
