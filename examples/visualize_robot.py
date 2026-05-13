import csv
import datetime
import json
import os
import time

import numpy as np
import pybullet as p
import pybullet_data


def _prepare_urdf_for_pybullet(src_urdf, examples_dir):
    """Create a local URDF copy with package:// paths rewritten for PyBullet."""
    with open(src_urdf, 'r', encoding='utf-8') as f:
        urdf_text = f.read()

    # S2.urdf and S2full.urdf use package://ubtech/... while meshes live in examples/meshes.
    urdf_text = urdf_text.replace('package://ubtech/', '')

    # Generate unique temp filename based on input name
    src_basename = os.path.basename(src_urdf)
    src_name = os.path.splitext(src_basename)[0]
    rewritten_urdf = os.path.join(examples_dir, f'_{src_name}_pybullet.urdf')
    with open(rewritten_urdf, 'w', encoding='utf-8') as f:
        f.write(urdf_text)
    return rewritten_urdf

def _load_init_pos(path):
    """Load r_dict / g_dict from init_pos.json, or return empty dicts."""
    if os.path.exists(path):
        with open(path, 'r', encoding='utf-8') as f:
            return json.load(f)
    return {'r_dict': {}, 'g_dict': {}}


def _save_init_pos(data, path):
    """Save r_dict / g_dict to init_pos.json."""
    with open(path, 'w', encoding='utf-8') as f:
        json.dump(data, f, indent=2)
    return True


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


def _save_to_gui_positions(robot_id, sliders, positions_file):
    """Collect current slider values and append a named position to
    saved_positions.csv in the format expected by motion_control_GUI.py.

    Limb arrays store degrees (same convention as the GUI sliders).
    Returns the position name used.
    """
    limb_sizes = {
        'left_leg_pos': 6, 'right_leg_pos': 6,
        'left_arm_pos': 7, 'right_arm_pos': 7,
        'waist_pos':    1, 'head_pos':      3,
    }
    positions = {k: [0.0] * n for k, n in limb_sizes.items()}

    for joint_idx, slider_id in sliders:
        joint_info = p.getJointInfo(robot_id, joint_idx)
        joint_name = joint_info[1].decode('utf-8')
        if joint_name not in URDF_TO_GUI:
            continue
        limb_key, idx = URDF_TO_GUI[joint_name]
        # Slider already holds degrees for revolute joints
        positions[limb_key][idx] = round(p.readUserDebugParameter(slider_id), 2)

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

    name = datetime.datetime.now().strftime('sim_%Y%m%d_%H%M%S')

    # Merge with any existing positions in the file
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

def check_gripper_status(gripper_values, close_gripper, open_gripper):
    """
    Check gripper status using Min-Max normalization.
    Converts gripper joint values to a normalized 0-1 metric where 0 corresponds to
    close_gripper and 1 corresponds to open_gripper.
    
    Parameters:
        :param gripper_values: (list) Current gripper joint values
        :param close_gripper: (list) Closed gripper joint values
        :param open_gripper: (list) Open gripper joint values
    Returns:
        :return (status, metric): (tuple) Status string ("close", "open", or "neutral")
                                  and normalized metric (0=closed, 1=open)
    """
    close_vec = np.array(close_gripper)
    open_vec = np.array(open_gripper)
    current_vec = np.array(gripper_values)
    
    # Min-Max normalization: 0 at close_gripper, 1 at open_gripper (element-wise)
    range_vec = open_vec - close_vec
    if np.allclose(range_vec, 0):
        metric = 0.0
    else:
        # Element-wise normalization, then take mean
        normalized = (current_vec - close_vec) / range_vec
        metric = np.mean(np.clip(normalized, 0.0, 1.0))
    
    if metric <= 0.15:
        status = "close"
    elif metric >= 0.85:
        status = "open"
    else:
        status = "neutral"
    
    return status, metric


def main():
    selected_robot = "S2full"

    # Load stored positions from init_pos.json
    examples_dir = os.path.dirname(os.path.abspath(__file__))
    init_pos_path = os.path.join(examples_dir, 'init_pos.json')
    init_pos = _load_init_pos(init_pos_path)
    rd = init_pos.get('r_dict', {})
    gd = init_pos.get('g_dict', {})
    print(f"\nUsing fixed robot: {selected_robot}")

    # Initialize PyBullet
    p.connect(p.GUI)
    p.setAdditionalSearchPath(pybullet_data.getDataPath())
    p.setGravity(0, 0, -9.81)

    # Load only ground plane (no table/workspace)
    p.loadURDF("plane.urdf", basePosition=[0, 0, -0.82])
    print("Loaded ground plane: plane.urdf at z=-0.82")

    # Load URDF
    try:
        robot_info = rd.get(selected_robot, {})
        src_urdf = os.path.join(examples_dir, "S2full.urdf")
        urdf = _prepare_urdf_for_pybullet(src_urdf, examples_dir)
        robot_base_pos = list(np.array(robot_info.get('position', [0.0, 0.0, 0.0])).astype(float))
        robot_base_pos[2] += 0.2
        robot_base_orientation = robot_info.get('orientation', [0.0, 0.0, 0.0])
        robot_base_quat = p.getQuaternionFromEuler(robot_base_orientation)
        
        robot_id = p.loadURDF(urdf, useFixedBase=True, 
                              basePosition=robot_base_pos,
                              baseOrientation=robot_base_quat)
        print(f"Loaded robot from: {src_urdf} (rewritten for PyBullet: {urdf})")
        print(f"Robot position: {robot_base_pos}")
        print(f"Robot orientation (euler): {robot_base_orientation}")
    except Exception as e:
        print(f"Error: Failed to load fixed URDF '{selected_robot}' from examples/S2full.urdf: {e}")
        return

    num_joints = p.getNumJoints(robot_id)

    # Find end effector link
    end_effector_index = -1
    for joint_idx in range(num_joints):
        joint_info = p.getJointInfo(robot_id, joint_idx)
        link_name = joint_info[12].decode("utf-8")
        if link_name == 'endeffector':
            end_effector_index = joint_idx
            print(f"Found end effector link at joint index: {end_effector_index}")
            break
    
    if end_effector_index == -1:
        print("Warning: Could not find end effector link named 'endeffector' in URDF")

    # Build ordered list of non-fixed joints
    non_fixed_joints = []
    gjoint_idxs = []
    for joint_idx in range(num_joints):
        joint_info = p.getJointInfo(robot_id, joint_idx)
        joint_type = joint_info[2]
        joint_name = joint_info[1].decode("utf-8")
        if joint_type != p.JOINT_FIXED:
            non_fixed_joints.append(joint_idx)
            if 'gjoint' in joint_name:
                gjoint_idxs.append(joint_idx)

    # Initialise joints from init_pos.json, falling back to zero
    default_joint_ori = rd.get(selected_robot, {}).get('default_joint_ori', [])
    gripper_open      = gd.get(selected_robot, {}).get('open', [])

    print(f"Initialising {len(non_fixed_joints)} joints "
          f"(stored={len(default_joint_ori)}, gripper open={len(gripper_open)})")

    for i, joint_idx in enumerate(non_fixed_joints):
        val = default_joint_ori[i] if i < len(default_joint_ori) else 0.0
        p.resetJointState(robot_id, joint_idx, val)

    # Override gripper joints with stored open values
    for i, joint_idx in enumerate(gjoint_idxs):
        if i < len(gripper_open):
            p.resetJointState(robot_id, joint_idx, gripper_open[i])

    # Create velocity and force control sliders
    velocity_slider = p.addUserDebugParameter(
        paramName="Velocity",
        rangeMin=0,
        rangeMax=300,
        startValue=100
    )
    force_slider = p.addUserDebugParameter(
        paramName="Force",
        rangeMin=0,
        rangeMax=300,
        startValue=500
    )
    
    # Get joint information
    sliders = []
    
    for joint_idx in range(num_joints):
        joint_info = p.getJointInfo(robot_id, joint_idx)
        joint_name = joint_info[1].decode("utf-8")
        joint_type = joint_info[2]
        
        # Only create sliders for non-fixed joints
        if joint_type != p.JOINT_FIXED:
            lower = joint_info[8]
            upper = joint_info[9]
            
            # Handle unlimited joints
            if lower >= upper:
                lower, upper = -180, 180  # Default to ±180° for rotation joints
            
            # Get current joint position for slider start value
            joint_state = p.getJointState(robot_id, joint_idx)
            current_pos = joint_state[0]
                
            # Convert joint limits from radians to degrees for display
            lower_deg = lower * 57.2958
            upper_deg = upper * 57.2958
            if joint_type == p.JOINT_REVOLUTE:
                current_pos_deg = current_pos * 57.2958
                slider = p.addUserDebugParameter(
                    paramName=joint_name + " (deg)",
                    rangeMin=lower_deg,
                    rangeMax=upper_deg,
                    startValue=current_pos_deg
                )
                sliders.append((joint_idx, slider))
            else:
                #Prismatic joints
                slider = p.addUserDebugParameter(
                    paramName=joint_name + " (m)",
                    rangeMin=lower,
                    rangeMax=upper,
                    startValue=current_pos
                )
                sliders.append((joint_idx,slider))

    # Box control variables
    #box_size = 0.03  # 5x5x5 cm
    #box_id = p.createMultiBody(
    #    baseMass=0.1,
    #    baseCollisionShapeIndex=p.createCollisionShape(p.GEOM_BOX, halfExtents=[box_size/2]*3),
    #    basePosition=[0.35, 0, 0.07]  # Initial position
    #)
    
    # Create sliders for box position control
    #x_slider = p.addUserDebugParameter("Box X", 0.05, 0.6, 0.35)
    #y_slider = p.addUserDebugParameter("Box Y", -0.45, 0.45, 0)
    #z_slider = p.addUserDebugParameter("Box Z", 0.07, 0.6, 0.07)

    # Main simulation loop
    p.setRealTimeSimulation(1)
    p.resetDebugVisualizerCamera(
        cameraDistance=3,
        cameraYaw=70,
        cameraPitch=-30,
        cameraTargetPosition=[0, 0, 0.0]
    )
    
    if selected_robot not in rd:
        rd[selected_robot] = {}

    # Initialize timer for periodic gripper status printing
    last_print_time = time.time()
    print_interval = 0.5  # Print gripper status every 0.5 seconds
    
    try:
        while True:
            # Update box position from sliders
            #box_pos = [
            #    p.readUserDebugParameter(x_slider),
            #    p.readUserDebugParameter(y_slider), 
            #    p.readUserDebugParameter(z_slider)
            #]
            #p.resetBasePositionAndOrientation(box_id, box_pos, [0,0,0,1])
            
            # Check keyboard events
            keys = p.getKeyboardEvents()
            
            if ord('o') in keys and keys[ord('o')] & p.KEY_WAS_TRIGGERED:
                # Save gripper open values
                gjoint_values = []
                gjoint_names = []
                for joint_idx, slider_id in sliders:
                    joint_info = p.getJointInfo(robot_id, joint_idx)
                    joint_name = joint_info[1].decode("utf-8")
                    if 'gjoint' in joint_name:
                        value_deg = p.readUserDebugParameter(slider_id)
                        joint_type = joint_info[2]
                        if joint_type == p.JOINT_REVOLUTE:
                            value = value_deg * 0.0174533  # Convert degrees to radians
                        else:
                            value = value_deg
                        gjoint_values.append(round(value, 2))
                        gjoint_names.append(joint_name)
                
                if gjoint_values:
                    print(f"Gripper joints found: {gjoint_names}")
                    print(f"Gripper open values: {gjoint_values}")
                    
                    # Update gripper dict with open values
                    if selected_robot not in gd:
                        gd[selected_robot] = {}
                    gd[selected_robot]['open'] = gjoint_values
                    
                    init_pos['g_dict'] = gd
                    if _save_init_pos(init_pos, init_pos_path):
                        print(f"Saved gripper open values for {selected_robot} to {init_pos_path}")
                    else:
                        print("Failed to save")
                else:
                    print("No gripper joints (containing 'gjoint') found in robot")
            
            if ord('c') in keys and keys[ord('c')] & p.KEY_WAS_TRIGGERED:
                # Save gripper closed values
                gjoint_values = []
                gjoint_names = []
                for joint_idx, slider_id in sliders:
                    joint_info = p.getJointInfo(robot_id, joint_idx)
                    joint_name = joint_info[1].decode("utf-8")
                    if 'gjoint' in joint_name:
                        value_deg = p.readUserDebugParameter(slider_id)
                        joint_type = joint_info[2]
                        if joint_type == p.JOINT_REVOLUTE:
                            value = value_deg * 0.0174533  # Convert degrees to radians
                        else:
                            value = value_deg
                        gjoint_values.append(round(value, 2))
                        gjoint_names.append(joint_name)
                
                if gjoint_values:
                    print(f"Gripper joints found: {gjoint_names}")
                    print(f"Gripper closed values: {gjoint_values}")
                    
                    # Update gripper dict with closed values
                    if selected_robot not in gd:
                        gd[selected_robot] = {}
                    gd[selected_robot]['close'] = gjoint_values
                    
                    init_pos['g_dict'] = gd
                    if _save_init_pos(init_pos, init_pos_path):
                        print(f"Saved gripper closed values for {selected_robot} to {init_pos_path}")
                    else:
                        print("Failed to save")
                else:
                    print("No gripper joints (containing 'gjoint') found in robot")

            if ord('r') in keys and keys[ord('r')] & p.KEY_WAS_TRIGGERED:
                # Save current pose to saved_positions.csv for motion_control_GUI
                positions_file = os.path.join(examples_dir, 'saved_positions.csv')
                pos_name = _save_to_gui_positions(robot_id, sliders, positions_file)
                print(f"Saved pose '{pos_name}' to {positions_file}")
                print("Load and execute it via motion_control_GUI.py → Positions tab")

            if ord('t') in keys and keys[ord('t')] & p.KEY_WAS_TRIGGERED:
                # Print current joint values
                joint_values = []
                for joint_idx, slider_id in sliders:
                    value_deg = p.readUserDebugParameter(slider_id)
                    joint_info = p.getJointInfo(robot_id, joint_idx)
                    joint_type = joint_info[2]
                    if joint_type == p.JOINT_REVOLUTE:
                        value = value_deg * 0.0174533  # Convert degrees to radians
                    else:
                        value = value_deg
                    joint_values.append(round(value, 2))
                print(f"Current joint values: {joint_values}")

                # Add default_joint_ori to robot dict first
                rd[selected_robot]['default_joint_ori'] = joint_values

                # Get end effector pose if available
                if end_effector_index != -1:
                    link_state = p.getLinkState(robot_id, end_effector_index)
                    ee_pos = [round(x, 4) for x in link_state[0]]
                    ee_quat = link_state[1]
                    ee_quat_ori = [round(x, 4) for x in ee_quat]
                    ee_ori = [round(x, 4) for x in p.getEulerFromQuaternion(ee_quat)]
                    print(f"End effector position: {ee_pos}")
                    print(f"End effector orientation (euler): {ee_ori}")
                    print(f"End effector orientation (quaternion): {ee_quat_ori}")
                    
                    # Store ee_pos, ee_ori, and ee_quat_ori in robot dict
                    rd[selected_robot]['ee_pos'] = ee_pos
                    rd[selected_robot]['ee_ori'] = ee_ori
                    rd[selected_robot]['ee_quat_ori'] = ee_quat_ori

                init_pos['r_dict'] = rd
                if _save_init_pos(init_pos, init_pos_path):
                    print(f"Saved joint values for {selected_robot} to {init_pos_path}")
                else:
                    print("Failed to save")
            
            # Read velocity and force slider values
            velocity = p.readUserDebugParameter(velocity_slider)
            force = p.readUserDebugParameter(force_slider)
            
            # Calculate and print gripper status periodically (only for gjoints)
            current_time = time.time()
            if current_time - last_print_time >= print_interval:
                # Get current gripper joint values
                gjoint_values = []
                gjoint_names = []
                for joint_idx, slider_id in sliders:
                    joint_info = p.getJointInfo(robot_id, joint_idx)
                    joint_name = joint_info[1].decode("utf-8")
                    if 'gjoint' in joint_name:
                        value_deg = p.readUserDebugParameter(slider_id)
                        joint_type = joint_info[2]
                        if joint_type == p.JOINT_REVOLUTE:
                            value = value_deg * 0.0174533  # Convert degrees to radians
                        else:
                            value = value_deg
                        gjoint_values.append(value)
                        gjoint_names.append(joint_name)
                
                # Calculate gripper status if gripper joints exist and gripper dict has open/close values
                if gjoint_values and selected_robot in gd:
                    if 'open' in gd[selected_robot] and 'close' in gd[selected_robot]:
                        status, metric = check_gripper_status(
                            gjoint_values, 
                            gd[selected_robot]['close'], 
                            gd[selected_robot]['open']
                        )
                        #print(f"Gripper Status: {status} | Metric: {metric:.3f} | Values: {[round(v, 3) for v in gjoint_values]}")
                    else:
                        print(f"Gripper values: {[round(v, 3) for v in gjoint_values]} (no open/close reference - press 'o' and 'c' to set)")
                
                last_print_time = current_time
            
            for joint_idx, slider_id in sliders:
                value_deg = p.readUserDebugParameter(slider_id)
                joint_info = p.getJointInfo(robot_id, joint_idx)
                joint_type = joint_info[2]
                if joint_type == p.JOINT_REVOLUTE:
                    value = value_deg * 0.0174533  # Convert degrees back to radians
                else:
                    value = value_deg
                p.setJointMotorControl2(
                    bodyIndex=robot_id,
                    jointIndex=joint_idx,
                    controlMode=p.POSITION_CONTROL,
                    targetPosition=value,
                    force=force,
                    maxVelocity=velocity
                )
            time.sleep(0.01)
    except KeyboardInterrupt:
        p.disconnect()

if __name__ == "__main__":
    main()