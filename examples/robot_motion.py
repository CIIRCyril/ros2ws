#!/usr/bin/env python3
"""
robot_motion.py — Play back recorded motion files on S2full robot in PyBullet.

Usage:
    python3 examples/robot_motion.py

A terminal selection menu will open pointing at examples/motion/.  Choose any
.txt motion file and the robot will execute the recorded motion in the
PyBullet GUI window.

Motion file format (space-separated, one time-step per row)::

    col0  col1  col2  ...  colN-1

Columns are indexed 0 … N-1 and referenced by JOINT_COLUMN_MAPPING below.

Keyboard controls (click the PyBullet window first):
    r     — restart motion from the beginning
    Space — pause / resume
    q     — quit
"""

import os
import sys
import time

import numpy as np
import pybullet as p
import pybullet_data

# ── file-selection ────────────────────────────────────────────────────────────
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
MOTION_DIR = os.path.join(SCRIPT_DIR, "motion")

# Fallback when examples/motion/ is absent or empty
FALLBACK_MOTION_DIR = os.path.normpath(
    os.path.join(
        SCRIPT_DIR, "..", "install", "rl_control",
        "share", "python_scripts", "traced", "motion",
    )
)

# ── playback parameters ───────────────────────────────────────────────────────
FRAME_DELAY = 0.02    # seconds between frames  (~50 Hz playback)
MAX_VELOCITY = 10.0   # rad/s  – position-control max joint velocity
MAX_FORCE = 500.0     # N·m   – position-control max torque

# ── joint → column mapping ────────────────────────────────────────────────────
# All revolute joints from S2full.urdf are listed here in URDF file order.
# Key:   exact URDF joint name  (must match joint_info[1] decoded from bytes)
# Value: 0-based column index in the motion data row, or None (joint not driven)
#
# Only 20 joints are assigned column indices 0-19; all others are set to None
# and will hold their default position (zero) throughout playback.
JOINT_COLUMN_MAPPING = {
    # ── legs ─────────────────────────────────────────────────────────────────
    "hip_roll_l_joint":           18,
    "hip_pitch_l_joint":          19,
    "hip_yaw_l_joint":            None,
    "knee_pitch_l_joint":         None, 
    "ankle_pitch_l_joint":        None,
    "ankle_roll_l_joint":         None,
    "hip_roll_r_joint":           None,
    "hip_pitch_r_joint":          None,
    "hip_yaw_r_joint":            None,
    "knee_pitch_r_joint":         None,
    "ankle_pitch_r_joint":        None,
    "ankle_roll_r_joint":         None,
    # ── torso / head ─────────────────────────────────────────────────────────
    "body_yaw_rjoint":            17,
    "head_yaw_joint":             0,
    "head_pitch_joint":           1,
    "head_roll_joint":            2,
    # ── left arm ─────────────────────────────────────────────────────────────
    "shoulder_pitch_l_joint":     3,
    "shoulder_roll_l_joint":      4,
    "shoulder_yaw_l_joint":       5,
    "elbow_pitch_l_joint":        6,
    "wrist_yaw_l_joint":          7,
    "wrist_pitch_l_joint":        8,
    "wrist_roll_l_joint":         9,
    # ── right arm ────────────────────────────────────────────────────────────
    "shoulder_pitch_r_rjoint":    10,
    "shoulder_roll_r_rjoint":     11,
    "shoulder_yaw_r_rjoint":      12,
    "elbow_pitch_r_rjoint":       13,
    "wrist_yaw_r_rjoint":         14,
    "wrist_pitch_r_rjoint":       15,
    "wrist_roll_r_rjoint":        16,
    # ── left hand fingers ────────────────────────────────────────────────────
    "left_thumb_1_joint":         None,
    "left_thumb_2_joint":         None,
    "left_thumb_3_joint":         None,
    "left_thumb_4_joint":         None,
    "left_index_1_joint":         None,
    "left_index_2_joint":         None,
    "left_middle_1_joint":        None,
    "left_middle_2_joint":        None,
    "left_ring_1_joint":          None,
    "left_ring_2_joint":          None,
    "left_little_1_joint":        None,
    "left_little_2_joint":        None,
    # ── right hand fingers ───────────────────────────────────────────────────
    "right_thumb_1_gjoint":       None,
    "right_thumb_2_joint":        None,
    "right_thumb_3_joint":        None,
    "right_thumb_4_joint":        None,
    "right_index_1_gjoint":       None,
    "right_index_2_joint":        None,
    "right_middle_1_gjoint":      None,
    "right_middle_2_joint":       None,
    "right_ring_1_gjoint":        None,
    "right_ring_2_joint":         None,
    "right_little_1_gjoint":      None,
    "right_little_2_joint":       None,
}

# ─────────────────────────────────────────────────────────────────────────────


def _pick_motion_file() -> str:
    """Let the user choose a motion .txt file from a terminal menu."""
    initial_dir = MOTION_DIR if os.path.isdir(MOTION_DIR) else FALLBACK_MOTION_DIR

    candidates = sorted(
        os.path.join(initial_dir, f)
        for f in os.listdir(initial_dir)
        if f.endswith(".txt")
    )
    if not candidates:
        print(f"No .txt files found in {initial_dir}")
        sys.exit(1)

    print("\nAvailable motion files:")
    for i, path in enumerate(candidates):
        print(f"  [{i + 1}] {os.path.basename(path)}")

    while True:
        try:
            choice = int(input("Select file number: ").strip())
            if 1 <= choice <= len(candidates):
                return candidates[choice - 1]
        except (ValueError, KeyboardInterrupt):
            pass
        print("Invalid choice, try again.")


def _load_motion(path: str) -> np.ndarray:
    """Load a motion .txt file into a 2-D array (n_frames × n_data_cols).

    All numeric tokens in each row are loaded as columns 0..N-1.
    """
    rows = []
    with open(path, "r", encoding="utf-8") as fh:
        for line in fh:
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            rows.append([float(v) for v in parts])
    if not rows:
        raise ValueError(f"Motion file is empty: {path}")
    return np.array(rows)  # shape: (n_frames, n_data_cols)


def _prepare_urdf(src_urdf: str, out_dir: str) -> str:
    """Rewrite package:// URIs so PyBullet can resolve the mesh paths."""
    with open(src_urdf, "r", encoding="utf-8") as fh:
        text = fh.read()
    text = text.replace("package://ubtech/", "")
    basename = os.path.splitext(os.path.basename(src_urdf))[0]
    out_path = os.path.join(out_dir, f"_{basename}_pybullet.urdf")
    with open(out_path, "w", encoding="utf-8") as fh:
        fh.write(text)
    return out_path


def _build_joint_index_map(robot_id: int) -> dict:
    """Return {joint_name: joint_index} for all non-fixed joints."""
    mapping = {}
    for idx in range(p.getNumJoints(robot_id)):
        info = p.getJointInfo(robot_id, idx)
        if info[2] != p.JOINT_FIXED:
            name = info[1].decode("utf-8")
            mapping[name] = idx
    return mapping


def main() -> None:
    src_urdf = os.path.join(SCRIPT_DIR, "S2full.urdf")

    # ── 1. select motion file ─────────────────────────────────────────────────
    motion_path = _pick_motion_file()
    print(f"\nLoading motion: {motion_path}")
    motion_data = _load_motion(motion_path)
    n_frames, n_cols = motion_data.shape
    print(f"  Frames: {n_frames},  data columns per frame: {n_cols}")
    mapped_joint_count = sum(1 for c in JOINT_COLUMN_MAPPING.values() if c is not None)
    print(f"  Mapped joints: {mapped_joint_count} (columns 0..{mapped_joint_count - 1})")

    # Validate that every mapped column index is within bounds
    for jname, col in JOINT_COLUMN_MAPPING.items():
        if col is None:
            continue
        if col >= n_cols:
            print(
                f"  WARNING: column {col} for '{jname}' is out of range "
                f"(file has {n_cols} data columns).  "
                "That joint will be skipped."
            )

    # ── 2. initialise PyBullet ────────────────────────────────────────────────
    p.connect(p.GUI)
    p.setAdditionalSearchPath(pybullet_data.getDataPath())
    p.setGravity(0, 0, -9.81)

    # Empty scene: only a ground plane
    p.loadURDF("plane.urdf", basePosition=[0, 0, -0.72])

    # ── 3. load S2full robot ──────────────────────────────────────────────────
    urdf_path = _prepare_urdf(src_urdf, SCRIPT_DIR)

    robot_id = p.loadURDF(
        urdf_path,
        basePosition=[0.0, 0.0, 0.2],
        baseOrientation=p.getQuaternionFromEuler([0.0, 0.0, 0.0]),
        useFixedBase=True,
    )
    print(f"Loaded robot: {src_urdf}")

    # Reset all movable joints to zero
    joint_name_to_idx = _build_joint_index_map(robot_id)
    for idx in joint_name_to_idx.values():
        p.resetJointState(robot_id, idx, 0.0)

    # Build the active (mapped) joint list
    # Each entry: (joint_index, data_column_index)
    active_joints = []
    for jname, col in JOINT_COLUMN_MAPPING.items():
        if col is None:
            continue
        if jname not in joint_name_to_idx:
            print(f"  WARNING: joint '{jname}' not found in URDF – skipping.")
            continue
        if col >= n_cols:
            continue  # already warned above
        active_joints.append((joint_name_to_idx[jname], col))

    if not active_joints:
        print("ERROR: No valid joint-column pairs found.  Check JOINT_COLUMN_MAPPING.")
        p.disconnect()
        return

    print(f"  Driving {len(active_joints)} joint(s) from the motion file.")

    # ── 4. camera & HUD ───────────────────────────────────────────────────────
    p.resetDebugVisualizerCamera(
        cameraDistance=3.0,
        cameraYaw=70,
        cameraPitch=-30,
        cameraTargetPosition=[0, 0, 0.0],
    )
    p.setRealTimeSimulation(0)  # we control the stepping ourselves

    hud_text = p.addUserDebugText(
        text="",
        textPosition=[0, 0, 1.8],
        textColorRGB=[1, 1, 1],
        textSize=1.2,
    )

    # ── 5. playback loop ──────────────────────────────────────────────────────
    frame_idx = 0
    paused = False
    motion_name = os.path.basename(motion_path)

    print("\nPlayback started.  Focus the PyBullet window and press:")
    print("  r     – restart   |  Space – pause/resume   |  q – quit\n")

    try:
        while True:
            keys = p.getKeyboardEvents()

            # q → quit
            if ord("q") in keys and keys[ord("q")] & p.KEY_WAS_TRIGGERED:
                break

            # r → restart
            if ord("r") in keys and keys[ord("r")] & p.KEY_WAS_TRIGGERED:
                frame_idx = 0
                for idx in joint_name_to_idx.values():
                    p.resetJointState(robot_id, idx, 0.0)
                print("Restarted motion.")

            # Space → pause / resume
            if ord(" ") in keys and keys[ord(" ")] & p.KEY_WAS_TRIGGERED:
                paused = not paused
                print("Paused." if paused else "Resumed.")

            if not paused:
                row = motion_data[frame_idx]
                for joint_idx, col in active_joints:
                    p.setJointMotorControl2(
                        bodyIndex=robot_id,
                        jointIndex=joint_idx,
                        controlMode=p.POSITION_CONTROL,
                        targetPosition=float(row[col]),
                        maxVelocity=MAX_VELOCITY,
                        force=MAX_FORCE,
                    )

                p.stepSimulation()
                frame_idx = (frame_idx + 1) % n_frames

            # update HUD
            status = "PAUSED" if paused else "PLAYING"
            p.addUserDebugText(
                text=(
                    f"{motion_name}  [{status}]\n"
                    f"Frame {frame_idx}/{n_frames}   "
                    f"r=restart  Space=pause  q=quit"
                ),
                textPosition=[0, 0, 1.8],
                textColorRGB=[1, 1, 0] if paused else [0, 1, 0],
                textSize=1.2,
                replaceItemUniqueId=hud_text,
            )

            time.sleep(FRAME_DELAY)

    except KeyboardInterrupt:
        pass

    p.disconnect()
    print("Done.")


if __name__ == "__main__":
    main()