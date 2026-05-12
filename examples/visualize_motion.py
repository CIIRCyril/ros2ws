#!/usr/bin/env python3
"""Visualize motion1.txt from the rl_control package as a fullscreen time-series plot."""

import os
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

# Path to motion_1.txt relative to this script (examples/)
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
MOTION_FILE = os.path.join(
    SCRIPT_DIR,
    "..",
    "install", "rl_control", "share", "python_scripts", "traced", "motion",
    "motion_1.txt",
)


def load_motion(path):
    """Load motion file into a 2-D numpy array (rows x columns).

    Each text line has a leading integer index followed by space-separated
    float values.  The index column is dropped; only the data columns are
    returned together with the time-step array.
    """
    rows = []
    with open(path, "r") as fh:
        for line in fh:
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            # First token is the row index – skip it
            rows.append([float(v) for v in parts[1:]])
    data = np.array(rows)          # shape: (n_steps, n_cols)
    timesteps = np.arange(1, len(data) + 1)
    return timesteps, data


def main():
    motion_path = os.path.normpath(MOTION_FILE)
    if not os.path.isfile(motion_path):
        raise FileNotFoundError(f"Motion file not found: {motion_path}")

    timesteps, data = load_motion(motion_path)
    n_cols = data.shape[1]

    # Assign a distinct color to each column using a colormap
    colors = cm.tab20(np.linspace(0, 1, n_cols))

    fig, ax = plt.subplots(figsize=(16, 8))
    for col_idx in range(n_cols):
        ax.plot(
            timesteps,
            data[:, col_idx],
            color=colors[col_idx],
            linewidth=0.8,
            label=f"col {col_idx + 1}",
        )

    ax.set_title("motion_1.txt – all columns", fontsize=14)
    ax.set_xlabel("Time step")
    ax.set_ylabel("Value")
    ax.legend(loc="upper right", fontsize=7, ncol=2, framealpha=0.6)
    ax.grid(True, linewidth=0.4, alpha=0.5)

    # Display fullscreen
    manager = plt.get_current_fig_manager()
    try:
        manager.full_screen_toggle()
    except AttributeError:
        try:
            manager.window.showMaximized()
        except AttributeError:
            pass

    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()
