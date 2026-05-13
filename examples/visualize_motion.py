#!/usr/bin/env python3
"""Select and visualize a motion text file as a maximized time-series plot."""

import os
import sys
import numpy as np
import matplotlib.pyplot as plt

# Motion directory relative to this script (examples/)
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
MOTION_DIR = os.path.join(
    SCRIPT_DIR,
    "..",
    "install", "rl_control", "share", "python_scripts", "traced", "motion",
)


def load_motion(path):
    """Load motion file into a 2-D numpy array (rows x columns).

    Each text line has a leading integer index followed by space-separated
    float values.  The index column is dropped; only the data columns are
    returned together with the time-step array.
    """
    rows = []
    with open(path, "r", encoding="utf-8") as fh:
        for line in fh:
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            # First token is the row index – skip it
            rows.append([float(v) for v in parts[1:]])
    data = np.array(rows)          # shape: (n_steps, n_cols)
    step_indices = np.arange(1, len(data) + 1)
    return step_indices, data


def pick_motion_file(motion_dir):
    """Return a user-selected motion file path from motion_dir."""
    candidates = sorted(
        [f for f in os.listdir(motion_dir) if f.endswith(".txt") and os.path.isfile(os.path.join(motion_dir, f))]
    )
    if not candidates:
        raise FileNotFoundError(f"No .txt motion files found in: {motion_dir}")

    if len(sys.argv) > 1:
        requested = sys.argv[1]
        requested_path = requested if os.path.isabs(requested) else os.path.join(motion_dir, requested)
        requested_path = os.path.normpath(requested_path)
        if not os.path.isfile(requested_path):
            raise FileNotFoundError(f"Requested motion file not found: {requested_path}")
        return requested_path

    default_name = "motion_1.txt" if "motion_1.txt" in candidates else candidates[0]
    default_idx = candidates.index(default_name)

    print("Available motion files:")
    for idx, name in enumerate(candidates, start=1):
        marker = " (default)" if idx - 1 == default_idx else ""
        print(f"  {idx}. {name}{marker}")

    choice = input(f"Select file [1-{len(candidates)}], Enter for default: ").strip()
    if not choice:
        return os.path.join(motion_dir, default_name)

    try:
        selected_idx = int(choice)
    except ValueError as exc:
        raise ValueError("Invalid selection. Enter a number from the list.") from exc

    if selected_idx < 1 or selected_idx > len(candidates):
        raise ValueError("Selection out of range.")

    return os.path.join(motion_dir, candidates[selected_idx - 1])


def main():
    motion_dir = os.path.normpath(MOTION_DIR)
    if not os.path.isdir(motion_dir):
        raise FileNotFoundError(f"Motion directory not found: {motion_dir}")

    motion_path = pick_motion_file(motion_dir)
    motion_name = os.path.basename(motion_path)

    step_indices, data = load_motion(motion_path)
    n_cols = data.shape[1]

    # Assign a distinct color to each column.  tab20 provides 20 distinct
    # colors; for files with more than 20 columns the palette wraps around.
    colors = plt.get_cmap("tab20")(np.linspace(0, 1, max(n_cols, 1)))

    _, ax = plt.subplots(figsize=(16, 8))
    for col_idx in range(n_cols):
        ax.plot(
            step_indices,
            data[:, col_idx],
            color=colors[col_idx],
            linewidth=0.8,
            label=f"col {col_idx + 1}",
        )

    ax.set_title(f"{motion_name} - all columns", fontsize=14)
    ax.set_xlabel("Time step")
    ax.set_ylabel("Value")
    ax.legend(loc="upper right", fontsize=7, ncol=2, framealpha=0.6)
    ax.grid(True, linewidth=0.4, alpha=0.5)

    # Maximize plot window (not fullscreen)
    manager = plt.get_current_fig_manager()
    try:
        manager.window.showMaximized()
    except AttributeError:
        try:
            manager.resize(*manager.window.maxsize())
        except (AttributeError, TypeError):
            pass

    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()
