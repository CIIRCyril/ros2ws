#!/usr/bin/env python3
"""
robot_motion.py — Play back recorded motion files on S2full robot in PyBullet.

Usage:
    python3 examples/robot_motion.py

A file-selection dialog will open pointing at examples/motion/.  Choose any
.txt motion file and the robot will execute the recorded motion in the
PyBullet GUI window.

Motion file format (space-separated, one time-step per row)::

    <ignored>  col0  col1  col2  ...  colN-1

The first token on each row is skipped.  The remaining values are indexed
0 … N-1 and referenced by JOINT_COLUMN_MAPPING below.

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
# Key:   exact URDF joint name  (must match joint_info[1] decoded from bytes)
# Value: 0-based column index in the data row *after* the first skipped token
#
# Motion-file column layout (0-based, after first token is dropped):
#   0 – 2  : reserved / flag fields (constant 1)
#   3 – 6  : base-orientation quaternion [w, x, y, z]
#   7 – 12 : left leg  (hip_roll, hip_pitch, hip_yaw, knee_pitch,
#                        ankle_pitch, ankle_roll)
#   13 – 18: right leg (hip_roll, hip_pitch, hip_yaw, knee_pitch,
#                        ankle_pitch, ankle_roll)
#
# Add or remove entries here to change which joints are driven.
# Joints not listed keep their default position (zero).
JOINT_COLUMN_MAPPING = {
    # Left leg
    "hip_roll_l_joint":    7,
    "hip_pitch_l_joint":   8,
    "hip_yaw_l_joint":     9,
    "knee_pitch_l_joint":  10,
    "ankle_pitch_l_joint": 11,
    "ankle_roll_l_joint":  12,
    # Right leg
    "hip_roll_r_joint":    13,
    "hip_pitch_r_joint":   14,
    "hip_yaw_r_joint":     15,
    "knee_pitch_r_joint":  16,
    "ankle_pitch_r_joint": 17,
    "ankle_roll_r_joint":  18,
}

# ─────────────────────────────────────────────────────────────────────────────


def _pick_motion_file() -> str:
    """Let the user choose a motion .txt file.

    First tries a tkinter file dialog; falls back to a numbered console menu
    when a display is not available.
    """
    initial_dir = MOTION_DIR if os.path.isdir(MOTION_DIR) else FALLBACK_MOTION_DIR

    try:
        import tkinter as tk
        from tkinter import filedialog

        root = tk.Tk()
        root.withdraw()
        path = filedialog.askopenfilename(
            title="Select a motion file",
            initialdir=initial_dir,
            filetypes=[("Motion files", "*.txt"), ("All files", "*.*")],
        )
        root.destroy()
        if path:
            return path
        print("No file selected – exiting.")
        sys.exit(0)
    except Exception:
        # Headless fallback: show a numbered console menu
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

    The first token of each row is skipped (row-index / reserved field).
    """
    rows = []
    with open(path, "r") as fh:
        for line in fh:
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            rows.append([float(v) for v in parts[1:]])  # drop first token
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
    # ── 1. select motion file ─────────────────────────────────────────────────
    motion_path = _pick_motion_file()
    print(f"\nLoading motion: {motion_path}")
    motion_data = _load_motion(motion_path)
    n_frames, n_cols = motion_data.shape
    print(f"  Frames: {n_frames},  data columns per frame: {n_cols}")

    # Validate that every mapped column index is within bounds
    for jname, col in JOINT_COLUMN_MAPPING.items():
        if col >= n_cols:
            print(
                f"  WARNING: column {col} for '{jname}' is out of range "
                f"(file has {n_cols} data columns after row-index).  "
                "That joint will be skipped."
            )

    # ── 2. initialise PyBullet ────────────────────────────────────────────────
    p.connect(p.GUI)
    p.setAdditionalSearchPath(pybullet_data.getDataPath())
    p.setGravity(0, 0, -9.81)

    # Empty scene: only a ground plane
    p.loadURDF("plane.urdf", basePosition=[0, 0, -0.72])

    # ── 3. load S2full robot ──────────────────────────────────────────────────
    src_urdf = os.path.join(SCRIPT_DIR, "S2full.urdf")
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
