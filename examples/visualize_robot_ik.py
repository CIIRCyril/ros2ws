#!/usr/bin/env python3
"""
visualize_robot_ik.py — Dual-arm + left-leg IK control of S2full robot in PyBullet.

Loads S2full.urdf and drives joints via the PyBullet IK solver.
Twenty-four debug sliders control the target end-effector poses for the RIGHT arm
(prefixed "R "), LEFT arm (prefixed "L "), LEFT LEG (prefixed "LL "), and
RIGHT LEG (prefixed "RL ").
Each limb gets a coloured target box; colour indicates IK accuracy:
  Green — position and orientation both within threshold
  Blue  — one of the two within threshold
  Red   — both outside threshold

Keyboard controls (click the PyBullet window first):
    o     — open gripper fingers (from init_pos.json)
    c     — close gripper fingers (from init_pos.json)
    r     — save current IK pose to saved_positions.csv
    x     — send right arm + waist positions directly to the real robot (ROS2)
    t     — print current joint values and both end-effector poses to console
    q     — quit
"""

import csv
import datetime
import json
import math
import os
import threading
import time

import numpy as np
import pybullet as p
import pybullet_data

try:
    import rclpy
    from rclpy.node import Node
    from bodyctrl_msgs.msg import CmdSetMotorPosition, SetMotorPosition
    _ROS2_AVAILABLE = True
except ImportError:
    _ROS2_AVAILABLE = False

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


def _publish_arm_waist_to_robot(joint_snapshot, arm_pub, waist_pub, node):
    """Publish right arm + waist position commands to the real robot via ROS2.

    joint_snapshot: list of (joint_idx, joint_name, pos_rad) captured in the
    main PyBullet thread to avoid cross-thread pybullet calls.
    Runs in a daemon thread so it never blocks the simulation loop.
    """
    right_arm_pos = [0.0] * 7   # motors 21-27
    waist_pos_rad = 0.0          # motor 31

    for _joint_idx, joint_name, pos_rad in joint_snapshot:
        if joint_name not in URDF_TO_GUI:
            continue
        limb_key, idx = URDF_TO_GUI[joint_name]
        if limb_key == 'right_arm_pos':
            right_arm_pos[idx] = pos_rad
        elif limb_key == 'waist_pos':
            waist_pos_rad = pos_rad

    # Right arm — position control, motors 21-27
    arm_msg = CmdSetMotorPosition()
    arm_msg.cmds = []
    for i, motor_id in enumerate(range(21, 28)):
        c = SetMotorPosition()
        c.name = motor_id
        c.pos  = float(right_arm_pos[i])
        c.spd  = 0.5   # profile speed
        c.cur  = 8.0   # current limit (A)
        arm_msg.cmds.append(c)
    arm_pub.publish(arm_msg)

    # Waist — position control, motor 31
    waist_msg = CmdSetMotorPosition()
    wc = SetMotorPosition()
    wc.name = 31
    wc.pos  = float(waist_pos_rad)
    wc.spd  = 0.2
    wc.cur  = 8.0
    waist_msg.cmds = [wc]
    waist_pub.publish(waist_msg)

    arm_deg   = [round(math.degrees(v), 1) for v in right_arm_pos]
    waist_deg = round(math.degrees(waist_pos_rad), 1)
    node.get_logger().info(f'Sent right arm {arm_deg} deg, waist {waist_deg} deg')
    print(f'[x] Right arm: {arm_deg} deg  |  waist: {waist_deg} deg')


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
    p.loadURDF('plane.urdf', basePosition=[0, 0, -1.1])
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

    # Find left end-effector link
    ee_index_l = -1
    for joint_idx in range(num_joints):
        link_name = p.getJointInfo(robot_id, joint_idx)[12].decode('utf-8')
        if link_name == 'endeffectol':
            ee_index_l = joint_idx
            print(f'Left end effector at joint index: {ee_index_l}')
            break
    if ee_index_l == -1:
        print('Warning: "endeffectol" link not found; left IK disabled')

    # Find left leg end-effector link
    ee_index_ll = -1
    for joint_idx in range(num_joints):
        link_name = p.getJointInfo(robot_id, joint_idx)[12].decode('utf-8')
        if link_name == 'endeffectoll':
            ee_index_ll = joint_idx
            print(f'Left leg end effector at joint index: {ee_index_ll}')
            break
    if ee_index_ll == -1:
        print('Warning: "endeffectoll" link not found; left leg IK disabled')

    # Find right leg end-effector link
    ee_index_rl = -1
    for joint_idx in range(num_joints):
        link_name = p.getJointInfo(robot_id, joint_idx)[12].decode('utf-8')
        if link_name == 'endeffectorl':
            ee_index_rl = joint_idx
            print(f'Right leg end effector at joint index: {ee_index_rl}')
            break
    if ee_index_rl == -1:
        print('Warning: "endeffectorl" link not found; right leg IK disabled')

    # Find head end-effector link
    ee_index_h = -1
    for joint_idx in range(num_joints):
        link_name = p.getJointInfo(robot_id, joint_idx)[12].decode('utf-8')
        if link_name == 'endeffectoh':
            ee_index_h = joint_idx
            print(f'Head end effector at joint index: {ee_index_h}')
            break
    if ee_index_h == -1:
        print('Warning: "endeffectoh" link not found; head IK disabled')

    # Get controllable joints for IK (exclude gripper — driven separately)
    joint_idxs, joint_names = get_controllable_joints(robot_id, num_joints)
    gjoint_set    = set(gjoint_idxs)
    ik_joint_idxs  = [ji for ji in joint_idxs if ji not in gjoint_set]
    ik_joint_names = [joint_names[joint_idxs.index(ji)] for ji in ik_joint_idxs]

    # Initial end-effector pose — use stored values if available
    link_state = p.getLinkState(robot_id, end_effector_index)
    stored = rd.get(ROBOT_KEY, {})
    ee_initial_pos   = stored.get('ee_pos',  list(link_state[0]))
    stored_ori = stored.get('ee_ori')
    ee_initial_euler = stored_ori if stored_ori else list(p.getEulerFromQuaternion(link_state[1]))
    print(f'Initial R EE pos:   {ee_initial_pos}')
    print(f'Initial R EE euler: {ee_initial_euler}')

    # Left EE initial pose
    if ee_index_l != -1:
        link_state_l      = p.getLinkState(robot_id, ee_index_l)
        ee_initial_pos_l   = list(link_state_l[0])
        ee_initial_euler_l = list(p.getEulerFromQuaternion(link_state_l[1]))
    else:
        ee_initial_pos_l   = [0.0, 0.2, 0.3]
        ee_initial_euler_l = [0.0, 0.0, 0.0]
    print(f'Initial L EE pos:   {ee_initial_pos_l}')
    print(f'Initial L EE euler: {ee_initial_euler_l}')

    # Left leg EE initial pose
    if ee_index_ll != -1:
        link_state_ll      = p.getLinkState(robot_id, ee_index_ll)
        ee_initial_pos_ll   = list(link_state_ll[0])
        ee_initial_euler_ll = list(p.getEulerFromQuaternion(link_state_ll[1]))
    else:
        ee_initial_pos_ll   = [0.0, 0.15, -0.8]
        ee_initial_euler_ll = [0.0, 0.0, 0.0]
    print(f'Initial LL EE pos:   {ee_initial_pos_ll}')
    print(f'Initial LL EE euler: {ee_initial_euler_ll}')

    # Right leg EE initial pose
    if ee_index_rl != -1:
        link_state_rl       = p.getLinkState(robot_id, ee_index_rl)
        ee_initial_pos_rl   = list(link_state_rl[0])
        ee_initial_euler_rl = list(p.getEulerFromQuaternion(link_state_rl[1]))
    else:
        ee_initial_pos_rl   = [0.0, -0.15, -0.8]
        ee_initial_euler_rl = [0.0, 0.0, 0.0]
    print(f'Initial RL EE pos:   {ee_initial_pos_rl}')
    print(f'Initial RL EE euler: {ee_initial_euler_rl}')

    # Head EE initial pose
    if ee_index_h != -1:
        link_state_h       = p.getLinkState(robot_id, ee_index_h)
        ee_initial_pos_h   = list(link_state_h[0])
        ee_initial_euler_h = list(p.getEulerFromQuaternion(link_state_h[1]))
    else:
        ee_initial_pos_h   = [0.2, 0.0, 0.7]
        ee_initial_euler_h = [0.0, 0.0, 0.0]
    print(f'Initial H EE pos:   {ee_initial_pos_h}')
    print(f'Initial H EE euler: {ee_initial_euler_h}')

    # Precompute which IK-solution indices map to each limb (for selective apply)
    _RIGHT_LIMBS     = {'right_arm_pos', 'waist_pos'}
    _LEFT_LIMBS      = {'left_arm_pos'}
    _LEFT_LEG_LIMBS  = {'left_leg_pos'}
    _RIGHT_LEG_LIMBS = {'right_leg_pos'}
    _HEAD_LIMBS      = {'head_pos'}
    right_sol_idxs:     list[int] = []
    right_jt_idxs:      list[int] = []
    left_sol_idxs:      list[int] = []
    left_jt_idxs:       list[int] = []
    left_leg_sol_idxs:  list[int] = []
    left_leg_jt_idxs:   list[int] = []
    right_leg_sol_idxs: list[int] = []
    right_leg_jt_idxs:  list[int] = []
    head_sol_idxs:      list[int] = []
    head_jt_idxs:       list[int] = []
    # calculateInverseKinematics returns one value per non-fixed joint
    # (joint_idxs), including gripper joints.  We must use each joint's
    # position in joint_idxs as the solution index — NOT the position in
    # ik_joint_idxs (which skips grippers) — otherwise any limb that appears
    # after finger joints in the URDF gets the wrong IK values applied.
    for _ji, _jn in zip(ik_joint_idxs, ik_joint_names):
        _si = joint_idxs.index(_ji)   # correct index into IK solution array
        _limb = URDF_TO_GUI.get(_jn, (None,))[0]
        if _limb in _RIGHT_LIMBS:
            right_sol_idxs.append(_si)
            right_jt_idxs.append(_ji)
        elif _limb in _LEFT_LIMBS:
            left_sol_idxs.append(_si)
            left_jt_idxs.append(_ji)
        elif _limb in _LEFT_LEG_LIMBS:
            left_leg_sol_idxs.append(_si)
            left_leg_jt_idxs.append(_ji)
        elif _limb in _RIGHT_LEG_LIMBS:
            right_leg_sol_idxs.append(_si)
            right_leg_jt_idxs.append(_ji)
        elif _limb in _HEAD_LIMBS:
            head_sol_idxs.append(_si)
            head_jt_idxs.append(_ji)

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

    # Visual target box — LEFT arm (cyan)
    box_vis_l = p.createVisualShape(
        p.GEOM_BOX,
        halfExtents=[box_size / 2] * 3,
        rgbaColor=[0, 0.8, 1, 0.5],
    )
    box_id_l = p.createMultiBody(
        baseMass=0,
        baseCollisionShapeIndex=-1,
        baseVisualShapeIndex=box_vis_l,
        basePosition=ee_initial_pos_l,
        baseOrientation=p.getQuaternionFromEuler(ee_initial_euler_l),
    )

    # Visual target box — LEFT LEG (orange)
    box_vis_ll = p.createVisualShape(
        p.GEOM_BOX,
        halfExtents=[box_size / 2] * 3,
        rgbaColor=[1, 0.5, 0, 0.5],
    )
    box_id_ll = p.createMultiBody(
        baseMass=0,
        baseCollisionShapeIndex=-1,
        baseVisualShapeIndex=box_vis_ll,
        basePosition=ee_initial_pos_ll,
        baseOrientation=p.getQuaternionFromEuler(ee_initial_euler_ll),
    )

    # Visual target box — RIGHT LEG (magenta)
    box_vis_rl = p.createVisualShape(
        p.GEOM_BOX,
        halfExtents=[box_size / 2] * 3,
        rgbaColor=[1, 0, 0.8, 0.5],
    )
    box_id_rl = p.createMultiBody(
        baseMass=0,
        baseCollisionShapeIndex=-1,
        baseVisualShapeIndex=box_vis_rl,
        basePosition=ee_initial_pos_rl,
        baseOrientation=p.getQuaternionFromEuler(ee_initial_euler_rl),
    )

    # Visual target box — HEAD (yellow)
    box_vis_h = p.createVisualShape(
        p.GEOM_BOX,
        halfExtents=[box_size / 2] * 3,
        rgbaColor=[1, 1, 0, 0.5],
    )
    box_id_h = p.createMultiBody(
        baseMass=0,
        baseCollisionShapeIndex=-1,
        baseVisualShapeIndex=box_vis_h,
        basePosition=ee_initial_pos_h,
        baseOrientation=p.getQuaternionFromEuler(ee_initial_euler_h),
    )

    # IK accuracy thresholds
    POSITION_THRESHOLD    = 0.05   # metres
    ORIENTATION_THRESHOLD = 0.1    # radians

    # Debug sliders for RIGHT EE target pose
    x_sl     = p.addUserDebugParameter('R Target X',     -1.0,    1.0,  ee_initial_pos[0])
    y_sl     = p.addUserDebugParameter('R Target Y',     -1.0,    1.0,  ee_initial_pos[1])
    z_sl     = p.addUserDebugParameter('R Target Z',     -1.0,    1.0,  ee_initial_pos[2])
    roll_sl  = p.addUserDebugParameter('R Target Roll',  -np.pi, np.pi, ee_initial_euler[0])
    pitch_sl = p.addUserDebugParameter('R Target Pitch', -np.pi, np.pi, ee_initial_euler[1])
    yaw_sl   = p.addUserDebugParameter('R Target Yaw',   -np.pi, np.pi, ee_initial_euler[2])

    # Debug sliders for LEFT EE target pose
    lx_sl     = p.addUserDebugParameter('L Target X',     -1.0,    1.0,  ee_initial_pos_l[0])
    ly_sl     = p.addUserDebugParameter('L Target Y',     -1.0,    1.0,  ee_initial_pos_l[1])
    lz_sl     = p.addUserDebugParameter('L Target Z',     -1.0,    1.0,  ee_initial_pos_l[2])
    lroll_sl  = p.addUserDebugParameter('L Target Roll',  -np.pi, np.pi, ee_initial_euler_l[0])
    lpitch_sl = p.addUserDebugParameter('L Target Pitch', -np.pi, np.pi, ee_initial_euler_l[1])
    lyaw_sl   = p.addUserDebugParameter('L Target Yaw',   -np.pi, np.pi, ee_initial_euler_l[2])

    # Debug sliders for LEFT LEG EE target pose
    llx_sl     = p.addUserDebugParameter('LL Target X',     -0.5,   0.5,  ee_initial_pos_ll[0])
    lly_sl     = p.addUserDebugParameter('LL Target Y',     -0.5,   0.5,  ee_initial_pos_ll[1])
    llz_sl     = p.addUserDebugParameter('LL Target Z',     -1.2,   0.0,  ee_initial_pos_ll[2])
    llroll_sl  = p.addUserDebugParameter('LL Target Roll',  -np.pi, np.pi, ee_initial_euler_ll[0])
    llpitch_sl = p.addUserDebugParameter('LL Target Pitch', -np.pi, np.pi, ee_initial_euler_ll[1])
    llyaw_sl   = p.addUserDebugParameter('LL Target Yaw',   -np.pi, np.pi, ee_initial_euler_ll[2])

    # Debug sliders for RIGHT LEG EE target pose
    rlx_sl     = p.addUserDebugParameter('RL Target X',     -0.5,   0.5,  ee_initial_pos_rl[0])
    rly_sl     = p.addUserDebugParameter('RL Target Y',     -0.5,   0.5,  ee_initial_pos_rl[1])
    rlz_sl     = p.addUserDebugParameter('RL Target Z',     -1.2,   0.0,  ee_initial_pos_rl[2])
    rlroll_sl  = p.addUserDebugParameter('RL Target Roll',  -np.pi, np.pi, ee_initial_euler_rl[0])
    rlpitch_sl = p.addUserDebugParameter('RL Target Pitch', -np.pi, np.pi, ee_initial_euler_rl[1])
    rlyaw_sl   = p.addUserDebugParameter('RL Target Yaw',   -np.pi, np.pi, ee_initial_euler_rl[2])

    # Debug sliders for HEAD EE target pose
    hx_sl     = p.addUserDebugParameter('H Target X',     -0.5,   0.5,  ee_initial_pos_h[0])
    hy_sl     = p.addUserDebugParameter('H Target Y',     -0.5,   0.5,  ee_initial_pos_h[1])
    hz_sl     = p.addUserDebugParameter('H Target Z',      0.3,   1.2,  ee_initial_pos_h[2])
    hroll_sl  = p.addUserDebugParameter('H Target Roll',  -np.pi, np.pi, ee_initial_euler_h[0])
    hpitch_sl = p.addUserDebugParameter('H Target Pitch', -np.pi, np.pi, ee_initial_euler_h[1])
    hyaw_sl   = p.addUserDebugParameter('H Target Yaw',   -np.pi, np.pi, ee_initial_euler_h[2])

    p.setRealTimeSimulation(1)
    p.resetDebugVisualizerCamera(
        cameraDistance=3,
        cameraYaw=70,
        cameraPitch=-30,
        cameraTargetPosition=[0, 0, 0.0],
    )

    # ROS2 publishers for live robot control
    ros_node = None
    arm_pub  = None
    waist_pub = None
    if _ROS2_AVAILABLE:
        rclpy.init()
        ros_node  = Node('visualize_robot_ik')
        arm_pub   = ros_node.create_publisher(CmdSetMotorPosition, '/arm/cmd_pos',   10)
        waist_pub = ros_node.create_publisher(CmdSetMotorPosition, '/waist/cmd_pos', 10)
        print('ROS2 ready — press X to send right arm + waist to robot')
    else:
        print('ROS2/bodyctrl_msgs not available — X key disabled')

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

            # 'x' — send right arm + waist directly to the real robot
            if ord('x') in keys and keys[ord('x')] & p.KEY_WAS_TRIGGERED:
                if ros_node is not None:
                    # Snapshot joint positions here (main thread) to avoid
                    # calling pybullet from the publisher thread
                    snapshot = [
                        (ji, jn, p.getJointState(robot_id, ji)[0])
                        for ji, jn in zip(joint_idxs, joint_names)
                    ]
                    threading.Thread(
                        target=_publish_arm_waist_to_robot,
                        args=(snapshot, arm_pub, waist_pub, ros_node),
                        daemon=True,
                    ).start()
                else:
                    print('[x] ROS2 not available — cannot send to robot')

            # 'r' — save current IK pose to saved_positions.csv for motion_control_GUI
            if ord('r') in keys and keys[ord('r')] & p.KEY_WAS_TRIGGERED:
                positions_file = os.path.join(examples_dir, 'saved_positions.csv')
                pos_name = _save_to_gui_positions(robot_id, joint_idxs, joint_names, positions_file)
                print(f"Saved IK pose '{pos_name}' to {positions_file}")
                print('Load and execute it via motion_control_GUI.py → Positions tab')

            # 't' — print current joint values and EE poses
            if ord('t') in keys and keys[ord('t')] & p.KEY_WAS_TRIGGERED:
                joint_states = [
                    p.getJointState(robot_id, ji)[0] for ji in joint_idxs
                ]
                print(f'Joint values: {joint_states}')
                ls = p.getLinkState(robot_id, end_effector_index)
                ee_pos   = list(ls[0])
                ee_euler = list(p.getEulerFromQuaternion(ls[1]))
                print(f'R EE pos:   {[round(v,4) for v in ee_pos]}')
                print(f'R EE euler: {[round(v,4) for v in ee_euler]}')
                if ee_index_l != -1:
                    ls_l = p.getLinkState(robot_id, ee_index_l)
                    ee_pos_l   = list(ls_l[0])
                    ee_euler_l = list(p.getEulerFromQuaternion(ls_l[1]))
                    print(f'L EE pos:   {[round(v,4) for v in ee_pos_l]}')
                    print(f'L EE euler: {[round(v,4) for v in ee_euler_l]}')
                if ee_index_ll != -1:
                    ls_ll = p.getLinkState(robot_id, ee_index_ll)
                    ee_pos_ll   = list(ls_ll[0])
                    ee_euler_ll = list(p.getEulerFromQuaternion(ls_ll[1]))
                    print(f'LL EE pos:   {[round(v,4) for v in ee_pos_ll]}')
                    print(f'LL EE euler: {[round(v,4) for v in ee_euler_ll]}')
                if ee_index_rl != -1:
                    ls_rl = p.getLinkState(robot_id, ee_index_rl)
                    ee_pos_rl   = list(ls_rl[0])
                    ee_euler_rl = list(p.getEulerFromQuaternion(ls_rl[1]))
                    print(f'RL EE pos:   {[round(v,4) for v in ee_pos_rl]}')
                    print(f'RL EE euler: {[round(v,4) for v in ee_euler_rl]}')
                if ee_index_h != -1:
                    ls_h = p.getLinkState(robot_id, ee_index_h)
                    ee_pos_h_now   = list(ls_h[0])
                    ee_euler_h_now = list(p.getEulerFromQuaternion(ls_h[1]))
                    print(f'H EE pos:   {[round(v,4) for v in ee_pos_h_now]}')
                    print(f'H EE euler: {[round(v,4) for v in ee_euler_h_now]}')

            # 'q' — quit
            if ord('q') in keys and keys[ord('q')] & p.KEY_WAS_TRIGGERED:
                print('Quitting.')
                break

            # Read RIGHT slider targets
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

            # Read LEFT slider targets
            target_pos_l = [
                p.readUserDebugParameter(lx_sl),
                p.readUserDebugParameter(ly_sl),
                p.readUserDebugParameter(lz_sl),
            ]
            target_euler_l = [
                p.readUserDebugParameter(lroll_sl),
                p.readUserDebugParameter(lpitch_sl),
                p.readUserDebugParameter(lyaw_sl),
            ]
            target_quat_l = p.getQuaternionFromEuler(target_euler_l)

            # Read LEFT LEG slider targets
            target_pos_ll = [
                p.readUserDebugParameter(llx_sl),
                p.readUserDebugParameter(lly_sl),
                p.readUserDebugParameter(llz_sl),
            ]
            target_euler_ll = [
                p.readUserDebugParameter(llroll_sl),
                p.readUserDebugParameter(llpitch_sl),
                p.readUserDebugParameter(llyaw_sl),
            ]
            target_quat_ll = p.getQuaternionFromEuler(target_euler_ll)

            # Read RIGHT LEG slider targets
            target_pos_rl = [
                p.readUserDebugParameter(rlx_sl),
                p.readUserDebugParameter(rly_sl),
                p.readUserDebugParameter(rlz_sl),
            ]
            target_euler_rl = [
                p.readUserDebugParameter(rlroll_sl),
                p.readUserDebugParameter(rlpitch_sl),
                p.readUserDebugParameter(rlyaw_sl),
            ]
            target_quat_rl = p.getQuaternionFromEuler(target_euler_rl)

            # Read HEAD slider targets
            target_pos_h = [
                p.readUserDebugParameter(hx_sl),
                p.readUserDebugParameter(hy_sl),
                p.readUserDebugParameter(hz_sl),
            ]
            target_euler_h = [
                p.readUserDebugParameter(hroll_sl),
                p.readUserDebugParameter(hpitch_sl),
                p.readUserDebugParameter(hyaw_sl),
            ]
            target_quat_h = p.getQuaternionFromEuler(target_euler_h)

            # Update target boxes
            p.resetBasePositionAndOrientation(box_id,    target_pos,    target_quat)
            p.resetBasePositionAndOrientation(box_id_l,  target_pos_l,  target_quat_l)
            p.resetBasePositionAndOrientation(box_id_ll, target_pos_ll, target_quat_ll)
            p.resetBasePositionAndOrientation(box_id_rl, target_pos_rl, target_quat_rl)
            p.resetBasePositionAndOrientation(box_id_h,  target_pos_h,  target_quat_h)

            # Solve IK — RIGHT arm, apply selectively to right arm + waist joints
            ik_solution = p.calculateInverseKinematics(
                robot_id, end_effector_index, target_pos, target_quat
            )
            for sol_idx, ji in zip(right_sol_idxs, right_jt_idxs):
                p.setJointMotorControl2(
                    bodyIndex=robot_id, jointIndex=ji,
                    controlMode=p.POSITION_CONTROL,
                    targetPosition=ik_solution[sol_idx], force=500,
                )

            # Solve IK — LEFT arm, apply selectively to left arm joints
            if ee_index_l != -1:
                ik_solution_l = p.calculateInverseKinematics(
                    robot_id, ee_index_l, target_pos_l, target_quat_l
                )
                for sol_idx, ji in zip(left_sol_idxs, left_jt_idxs):
                    p.setJointMotorControl2(
                        bodyIndex=robot_id, jointIndex=ji,
                        controlMode=p.POSITION_CONTROL,
                        targetPosition=ik_solution_l[sol_idx], force=500,
                    )

            # Solve IK — LEFT LEG, apply selectively to left leg joints
            if ee_index_ll != -1:
                ik_solution_ll = p.calculateInverseKinematics(
                    robot_id, ee_index_ll, target_pos_ll, target_quat_ll
                )
                for sol_idx, ji in zip(left_leg_sol_idxs, left_leg_jt_idxs):
                    p.setJointMotorControl2(
                        bodyIndex=robot_id, jointIndex=ji,
                        controlMode=p.POSITION_CONTROL,
                        targetPosition=ik_solution_ll[sol_idx], force=500,
                    )

            # Solve IK — RIGHT LEG, apply selectively to right leg joints
            if ee_index_rl != -1:
                ik_solution_rl = p.calculateInverseKinematics(
                    robot_id, ee_index_rl, target_pos_rl, target_quat_rl
                )
                for sol_idx, ji in zip(right_leg_sol_idxs, right_leg_jt_idxs):
                    p.setJointMotorControl2(
                        bodyIndex=robot_id, jointIndex=ji,
                        controlMode=p.POSITION_CONTROL,
                        targetPosition=ik_solution_rl[sol_idx], force=500,
                    )

            # Solve IK — HEAD, apply selectively to head joints
            if ee_index_h != -1:
                ik_solution_h = p.calculateInverseKinematics(
                    robot_id, ee_index_h, target_pos_h, target_quat_h
                )
                for sol_idx, ji in zip(head_sol_idxs, head_jt_idxs):
                    p.setJointMotorControl2(
                        bodyIndex=robot_id, jointIndex=ji,
                        controlMode=p.POSITION_CONTROL,
                        targetPosition=ik_solution_h[sol_idx], force=200,
                    )

            # Colour RIGHT box based on IK accuracy
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

            # Colour LEFT arm box based on IK accuracy
            if ee_index_l != -1:
                ls_l = p.getLinkState(robot_id, ee_index_l)
                ee_pos_l   = np.array(ls_l[0])
                ee_euler_l = np.array(p.getEulerFromQuaternion(ls_l[1]))
                pos_ok_l = np.linalg.norm(ee_pos_l - np.array(target_pos_l)) < POSITION_THRESHOLD
                ori_ok_l = np.linalg.norm(ee_euler_l - np.array(target_euler_l)) < ORIENTATION_THRESHOLD
                if pos_ok_l and ori_ok_l:
                    colour_l = [0, 1, 0, 0.5]      # green
                elif pos_ok_l or ori_ok_l:
                    colour_l = [0, 0.5, 1, 0.5]    # blue
                else:
                    colour_l = [0, 0.8, 1, 0.5]    # cyan (default)
                p.changeVisualShape(box_id_l, -1, rgbaColor=colour_l)

            # Colour LEFT LEG box based on IK accuracy
            if ee_index_ll != -1:
                ls_ll = p.getLinkState(robot_id, ee_index_ll)
                ee_pos_ll   = np.array(ls_ll[0])
                ee_euler_ll = np.array(p.getEulerFromQuaternion(ls_ll[1]))
                pos_ok_ll = np.linalg.norm(ee_pos_ll - np.array(target_pos_ll)) < POSITION_THRESHOLD
                ori_ok_ll = np.linalg.norm(ee_euler_ll - np.array(target_euler_ll)) < ORIENTATION_THRESHOLD
                if pos_ok_ll and ori_ok_ll:
                    colour_ll = [0, 1, 0, 0.5]       # green
                elif pos_ok_ll or ori_ok_ll:
                    colour_ll = [1, 0.8, 0, 0.5]     # yellow
                else:
                    colour_ll = [1, 0.5, 0, 0.5]     # orange (default)
                p.changeVisualShape(box_id_ll, -1, rgbaColor=colour_ll)

            # Colour RIGHT LEG box based on IK accuracy
            if ee_index_rl != -1:
                ls_rl = p.getLinkState(robot_id, ee_index_rl)
                ee_pos_rl   = np.array(ls_rl[0])
                ee_euler_rl = np.array(p.getEulerFromQuaternion(ls_rl[1]))
                pos_ok_rl = np.linalg.norm(ee_pos_rl - np.array(target_pos_rl)) < POSITION_THRESHOLD
                ori_ok_rl = np.linalg.norm(ee_euler_rl - np.array(target_euler_rl)) < ORIENTATION_THRESHOLD
                if pos_ok_rl and ori_ok_rl:
                    colour_rl = [0, 1, 0, 0.5]       # green
                elif pos_ok_rl or ori_ok_rl:
                    colour_rl = [0.8, 0, 1, 0.5]     # purple
                else:
                    colour_rl = [1, 0, 0.8, 0.5]     # magenta (default)
                p.changeVisualShape(box_id_rl, -1, rgbaColor=colour_rl)

            # Colour HEAD box based on IK accuracy
            if ee_index_h != -1:
                ls_h = p.getLinkState(robot_id, ee_index_h)
                ee_pos_h_cur   = np.array(ls_h[0])
                ee_euler_h_cur = np.array(p.getEulerFromQuaternion(ls_h[1]))
                pos_ok_h = np.linalg.norm(ee_pos_h_cur - np.array(target_pos_h)) < POSITION_THRESHOLD
                ori_ok_h = np.linalg.norm(ee_euler_h_cur - np.array(target_euler_h)) < ORIENTATION_THRESHOLD
                if pos_ok_h and ori_ok_h:
                    colour_h = [0, 1, 0, 0.5]       # green
                elif pos_ok_h or ori_ok_h:
                    colour_h = [1, 1, 0.3, 0.5]     # light yellow
                else:
                    colour_h = [1, 1, 0, 0.5]       # yellow (default)
                p.changeVisualShape(box_id_h, -1, rgbaColor=colour_h)

            time.sleep(0.01)

    except Exception as ex:
        print(f'Simulation error: {ex}')
    finally:
        if ros_node is not None:
            ros_node.destroy_node()
            rclpy.shutdown()
        p.disconnect()


if __name__ == '__main__':
    main()
