#!/usr/bin/env python3
"""
motion_control_GUI.py — Unified Tkinter GUI for all robot joints.

Tabs:
  Legs   — Left/Right leg motors 51-56 / 61-66  (MIT | Position | Speed)
  Arms   — Left/Right arm motors 11-17 / 21-27  (MIT | Position | Speed)
  Waist  — Motor 31                              (Position, always)
  Head   — Motors 1-3                            (Position, always)
  Hands  — Inspire hand fingers, left & right

All arm/leg tabs default to Position mode.
Motor topics:
  /leg/cmd_ctrl   /leg/cmd_pos    /leg/cmd_spd    /leg/status
  /arm/cmd_ctrl   /arm/cmd_pos    /arm/cmd_spd    /arm/status
  /waist/cmd_pos  /waist/status
  /head/cmd_pos   /head/status
  /inspire_hand/ctrl/left_hand    /inspire_hand/ctrl/right_hand
"""

import math
import csv
import json
import os
import random
import threading
import tkinter as tk
from tkinter import simpledialog, messagebox, ttk

import rclpy
from rclpy.node import Node

from bodyctrl_msgs.msg import (
    CmdMotorCtrl, MotorCtrl,
    CmdSetMotorPosition, SetMotorPosition,
    CmdSetMotorSpeed, SetMotorSpeed,
    MotorStatusMsg,
)
from hric_msgs.srv import SetMotionMode
from sensor_msgs.msg import JointState

# ── shared control mode constants ─────────────────────────────────────────────
MODE_MIT      = "MIT"
MODE_POSITION = "Position"
MODE_SPEED    = "Speed"

# ── error map (shared) ────────────────────────────────────────────────────────
ERROR_MAP = {
    0: "OK",
    33072: "Disconnected",
    33073: "OutLimit",
    1: "Overheat",
    2: "Overcurrent",
    3: "Undervoltage",
    4: "MOS Overheat",
    5: "Stall",
    6: "Overvoltage",
    7: "Phase loss",
    8: "Encoder",
}

# ── joint metadata (sliders/display in degrees; radians sent to motors) ────────
LEFT_LEG_NAMES  = ["L Hip Roll", "L Hip Pitch", "L Hip Yaw",
                   "L Knee Pitch", "L Ankle Pitch", "L Ankle Roll"]
RIGHT_LEG_NAMES = ["R Hip Roll", "R Hip Pitch", "R Hip Yaw",
                   "R Knee Pitch", "R Ankle Pitch", "R Ankle Roll"]
# (min_deg, max_deg) — motor IDs 51-56 / 61-66
LEG_LIMITS_DEG = [(-45, 45), (-160, 120), (-60, 60),
                  (0, 137), (-70, 30), (-30, 30)]
LEG_JOINT_NAMES = ["Hip Roll", "Hip Pitch", "Hip Yaw",
                   "Knee Pitch", "Ankle Pitch", "Ankle Roll"]
LEG_KP_DEFAULTS = [100, 150, 100, 150, 80, 80]
LEG_KD_DEFAULTS = [10,  15,  10,  15,  8,  8]

LEFT_ARM_NAMES  = ["L Shoulder Pitch", "L Shoulder Roll", "L Shoulder Yaw",
                   "L Elbow Pitch", "L Wrist Yaw", "L Wrist Pitch", "L Wrist Roll"]
RIGHT_ARM_NAMES = ["R Shoulder Pitch", "R Shoulder Roll", "R Shoulder Yaw",
                   "R Elbow Pitch", "R Wrist Yaw", "R Wrist Pitch", "R Wrist Roll"]
# Left arm motor IDs 11-17
LEFT_ARM_LIMITS_DEG  = [(-170, 170), (-15, 150), (-170, 170),
                         (-150, 15),  (-170, 170), (-45, 60), (-95, 75)]
# Right arm motor IDs 21-27 (shoulder roll & wrist roll differ from left)
RIGHT_ARM_LIMITS_DEG = [(-170, 170), (-150, 15), (-170, 170),
                         (-150, 15),  (-170, 170), (-45, 60), (-75, 95)]
ARM_JOINT_NAMES = ["Shoulder Pitch", "Shoulder Roll", "Shoulder Yaw",
                   "Elbow Pitch", "Wrist Yaw", "Wrist Pitch", "Wrist Roll"]
ARM_KP_DEFAULTS = [100, 100, 80, 80, 50, 50, 50]
ARM_KD_DEFAULTS = [10,  10,  8,  8,  5,  5,  5]

WAIST_LIMITS_DEG = (-170, 170)   # motor 31

HEAD_NAMES      = ["Head Roll", "Head Pitch", "Head Yaw"]
HEAD_LIMITS_DEG = [(-26, 26), (-25, 25), (-90, 90)]
HEAD_IDS        = [1, 2, 3]   # motor IDs for roll, pitch, yaw

FINGER_NAMES = ['1', '2', '3', '4', '5', '6']


# =============================================================================
# Helpers shared between sections
# =============================================================================

def _status_text(st, pos_deg=None):
    err = ERROR_MAP.get(st.error, str(st.error))
    if pos_deg is not None:
        pos_str = f"pos {pos_deg:7.2f}°"
    else:
        pos_str = f"pos {st.pos:6.3f} rad"
    return (f"{pos_str}  spd {st.speed:5.2f}  "
            f"cur {st.current:5.2f}A  tmp {st.temperature:5.1f}°C  {err}")


def _build_joint_rows(parent, names, limits_deg, pos_setter, spd_setter, slider_len=300):
    """Build position (degrees) + speed slider rows for one limb group.
    Returns (pos_sliders, spd_sliders, status_labels).
    Speed sliders are created but not packed (shown only in Speed mode).
    """
    pos_sliders, spd_sliders, status_labels = [], [], []
    for i, (name, (lo, hi)) in enumerate(zip(names, limits_deg)):
        tk.Label(parent, text=f"{name}  ({lo}°…{hi}°)", anchor='w', width=28).pack(anchor='w', padx=4)
        ps = tk.Scale(parent, from_=lo, to=hi, resolution=0.1,
                      orient=tk.HORIZONTAL, length=slider_len,
                      command=lambda v, idx=i: pos_setter(idx, v))
        ps.pack()
        pos_sliders.append(ps)

        ss = tk.Scale(parent, from_=-200.0, to=200.0, resolution=1.0,
                      orient=tk.HORIZONTAL, length=slider_len,
                      label=f"{name} spd (rpm)",
                      command=lambda v, idx=i: spd_setter(idx, v))
        spd_sliders.append(ss)

        lbl = tk.Label(parent, text="--", font=("Courier", 9), anchor='w', width=55)
        lbl.pack(fill='x', padx=4, pady=(0, 4))
        status_labels.append(lbl)

    return pos_sliders, spd_sliders, status_labels


def _toggle_joint_sliders(pos_slider, spd_slider, mode):
    if mode == MODE_SPEED:
        pos_slider.pack_forget()
        spd_slider.pack()
    else:
        spd_slider.pack_forget()
        pos_slider.pack()


def _build_mode_params_panel(parent, joint_names, kp_defaults, kd_defaults,
                              spd_default, cur_default, cur_max=15.0):
    """Build the MIT / Position / Speed parameter sub-frames.
    Returns (mit_frame, pos_frame, spd_frame, kp_refs, kd_refs,
             pos_spd_ref, pos_cur_ref, spd_cur_ref,
             pos_spd_slider, pos_cur_slider, spd_cur_slider).
    kp_refs / kd_refs are lists of [value], one entry per joint.
    """
    n = len(joint_names)
    mit_frame = tk.Frame(parent)
    pos_frame = tk.Frame(parent)
    spd_frame = tk.Frame(parent)

    kp_refs  = [[float(kp_defaults[i])] for i in range(n)]
    kd_refs  = [[float(kd_defaults[i])] for i in range(n)]
    pspd_ref = [float(spd_default)]
    pcur_ref = [float(cur_default)]
    scur_ref = [float(cur_default)]

    # MIT frame — per-joint kp / kd table
    tk.Label(mit_frame, text="Joint", width=20, anchor='w').grid(
        row=0, column=0, sticky='w', padx=(4, 8))
    tk.Label(mit_frame, text="kp  (0 – 2000)", anchor='center').grid(row=0, column=1)
    tk.Label(mit_frame, text="kd  (0 – 300)",  anchor='center').grid(row=0, column=2)

    for i, name in enumerate(joint_names):
        tk.Label(mit_frame, text=name, width=20, anchor='w').grid(
            row=i + 1, column=0, padx=(4, 8), pady=1, sticky='w')
        kp_sl = tk.Scale(mit_frame, from_=0, to=2000, resolution=1,
                         orient=tk.HORIZONTAL, length=220,
                         command=lambda v, idx=i: kp_refs[idx].__setitem__(0, float(v)))
        kp_sl.set(kp_defaults[i])
        kp_sl.grid(row=i + 1, column=1, padx=4, pady=1)
        kd_sl = tk.Scale(mit_frame, from_=0, to=300, resolution=1,
                         orient=tk.HORIZONTAL, length=220,
                         command=lambda v, idx=i: kd_refs[idx].__setitem__(0, float(v)))
        kd_sl.set(kd_defaults[i])
        kd_sl.grid(row=i + 1, column=2, padx=4, pady=1)

    # Position-mode frame
    tk.Label(pos_frame, text="Profile speed  (rpm)").pack()
    pspd_sl = tk.Scale(pos_frame, from_=0.0, to=4.0, resolution=0.1,
                       orient=tk.HORIZONTAL, length=360,
                       command=lambda v: pspd_ref.__setitem__(0, float(v)))
    pspd_sl.set(spd_default)
    pspd_sl.pack()

    tk.Label(pos_frame, text="Current limit  (A)").pack()
    pcur_sl = tk.Scale(pos_frame, from_=0.0, to=cur_max, resolution=0.1,
                       orient=tk.HORIZONTAL, length=360,
                       command=lambda v: pcur_ref.__setitem__(0, float(v)))
    pcur_sl.set(cur_default)
    pcur_sl.pack()

    # Speed-mode frame
    tk.Label(spd_frame, text="Current limit  (A)").pack()
    scur_sl = tk.Scale(spd_frame, from_=0.0, to=cur_max, resolution=0.1,
                       orient=tk.HORIZONTAL, length=360,
                       command=lambda v: scur_ref.__setitem__(0, float(v)))
    scur_sl.set(cur_default)
    scur_sl.pack()

    return (mit_frame, pos_frame, spd_frame,
            kp_refs, kd_refs, pspd_ref, pcur_ref, scur_ref,
            pspd_sl, pcur_sl, scur_sl)


# =============================================================================
# Main node
# =============================================================================

class MotionControlGUI(Node):
    def __init__(self):
        super().__init__('motion_control_gui')

        # ── publishers ────────────────────────────────────────────────────────
        self._leg_mit_pub  = self.create_publisher(CmdMotorCtrl,       '/leg/cmd_ctrl',  10)
        self._leg_pos_pub  = self.create_publisher(CmdSetMotorPosition, '/leg/cmd_pos',   10)
        self._leg_spd_pub  = self.create_publisher(CmdSetMotorSpeed,    '/leg/cmd_spd',   10)

        self._arm_mit_pub  = self.create_publisher(CmdMotorCtrl,       '/arm/cmd_ctrl',  10)
        self._arm_pos_pub  = self.create_publisher(CmdSetMotorPosition, '/arm/cmd_pos',   10)
        self._arm_spd_pub  = self.create_publisher(CmdSetMotorSpeed,    '/arm/cmd_spd',   10)

        self._waist_pub    = self.create_publisher(CmdSetMotorPosition, '/waist/cmd_pos', 10)
        self._head_pub     = self.create_publisher(CmdSetMotorPosition, '/head/cmd_pos',  10)

        self._hand_left_pub  = self.create_publisher(JointState, '/inspire_hand/ctrl/left_hand',  10)
        self._hand_right_pub = self.create_publisher(JointState, '/inspire_hand/ctrl/right_hand', 10)

        # ── subscribers ───────────────────────────────────────────────────────
        self.create_subscription(MotorStatusMsg, '/leg/status',   self._leg_status_cb,   10)
        self.create_subscription(MotorStatusMsg, '/arm/status',   self._arm_status_cb,   10)
        self.create_subscription(MotorStatusMsg, '/waist/status', self._waist_status_cb, 10)
        self.create_subscription(MotorStatusMsg, '/head/status',  self._head_status_cb,  10)

        # ── motion service ────────────────────────────────────────────────────
        self._motion_client = self.create_client(SetMotionMode, '/hric/motion/set_motion_mode')

        # ── motor IDs ─────────────────────────────────────────────────────────
        self._left_leg_ids  = list(range(51, 57))
        self._right_leg_ids = list(range(61, 67))
        self._left_arm_ids  = list(range(11, 18))
        self._right_arm_ids = list(range(21, 28))
        self._waist_ids     = [31]
        self._head_ids      = HEAD_IDS

        # ── state: leg ────────────────────────────────────────────────────────
        self.leg_mode      = MODE_POSITION
        self.left_leg_pos  = [0.0] * 6
        self.right_leg_pos = [0.0] * 6
        self.left_leg_spd  = [0.0] * 6
        self.right_leg_spd = [0.0] * 6
        self._left_leg_init  = [False] * 6
        self._right_leg_init = [False] * 6

        # ── state: arm ────────────────────────────────────────────────────────
        self.arm_mode      = MODE_POSITION
        self.left_arm_pos  = [0.0] * 7
        self.right_arm_pos = [0.0] * 7
        self.left_arm_spd  = [0.0] * 7
        self.right_arm_spd = [0.0] * 7
        self._left_arm_init  = [False] * 7
        self._right_arm_init = [False] * 7

        # ── state: waist ──────────────────────────────────────────────────────
        self.waist_pos   = [0.0]
        self.waist_speed = [0.2]
        self._waist_init = [False]

        # ── state: head ───────────────────────────────────────────────────────
        self.head_pos    = [0.0, 0.0, 0.0]
        self.head_speed  = [0.2]

        # ── state: hands ──────────────────────────────────────────────────────
        self.left_finger_pos  = [0.0, 0.0, 0.0, 0.0, 1.0, 0.0]
        self.right_finger_pos = [0.0, 0.0, 0.0, 0.0, 1.0, 0.0]
        self.left_finger_vel  = [1.0] * 6
        self.right_finger_vel = [1.0] * 6
        self.finger_effort    = [1.0]
        self._random_mode     = False
        self._random_timer_id = None
        self._random_period   = [0.5]
        self._shutdown_requested = False
        self._positions_file = os.path.join(os.path.dirname(__file__), 'saved_positions.csv')

        # ── publish timer: 20 Hz ──────────────────────────────────────────────
        self.timer = self.create_timer(0.05, self._publish_all)

        self._build_gui()

    # =========================================================================
    # GUI construction
    # =========================================================================

    def _build_gui(self):
        self.root = tk.Tk()
        self.root.title("Robot Motion Control")

        # ── global top bar ────────────────────────────────────────────────────
        top = tk.Frame(self.root, bg='#222')
        top.pack(fill='x', padx=4, pady=4)

        tk.Button(
            top, text="STOP MOTION",
            bg='#cc2222', fg='white', font=('Arial', 11, 'bold'),
            height=2, command=self._stop_motion,
        ).pack(side='left', padx=8, pady=4)

        tk.Button(
            top, text="ZERO ALL JOINTS",
            bg='#2255aa', fg='white', font=('Arial', 10, 'bold'),
            height=2, command=self._zero_all_joints,
        ).pack(side='left', padx=6, pady=4)

        tk.Button(
            top, text="SAVE POSITION",
            bg='#2d7f3b', fg='white', font=('Arial', 10, 'bold'),
            height=2, command=self._save_named_position,
        ).pack(side='left', padx=6, pady=4)

        tk.Button(
            top, text="EXIT",
            bg='#444444', fg='white', font=('Arial', 10, 'bold'),
            height=2, command=self._exit_app,
        ).pack(side='right', padx=8, pady=4)

        self._motion_status_var = tk.StringVar(value='motion: —')
        tk.Label(
            top, textvariable=self._motion_status_var,
            bg='#222', fg='#ffff88', font=('Courier', 9), anchor='w',
        ).pack(side='left', padx=12)

        # ── notebook tabs ─────────────────────────────────────────────────────
        nb = ttk.Notebook(self.root)
        nb.pack(fill='both', expand=True, padx=4, pady=4)

        leg_tab   = ttk.Frame(nb)
        arm_tab   = ttk.Frame(nb)
        waist_tab = ttk.Frame(nb)
        head_tab  = ttk.Frame(nb)
        hand_tab  = ttk.Frame(nb)
        pos_tab   = ttk.Frame(nb)

        nb.add(leg_tab,   text="  Legs  ")
        nb.add(arm_tab,   text="  Arms  ")
        nb.add(waist_tab, text="  Waist  ")
        nb.add(head_tab,  text="  Head  ")
        nb.add(hand_tab,  text="  Hands  ")
        nb.add(pos_tab,   text="  Positions  ")

        self._build_leg_tab(leg_tab)
        self._build_arm_tab(arm_tab)
        self._build_waist_tab(waist_tab)
        self._build_head_tab(head_tab)
        self._build_hand_tab(hand_tab)
        self._build_positions_tab(pos_tab)

    # ── Leg tab ───────────────────────────────────────────────────────────────

    def _build_leg_tab(self, parent):
        warn = tk.Label(
            parent,
            text="⚠  DANGER — Do NOT command legs while robot is standing unsupported!  ⚠",
            bg='#882200', fg='white', font=('Arial', 10, 'bold'),
        )
        warn.pack(fill='x')

        # mode bar
        mbar = tk.Frame(parent, bg='#333')
        mbar.pack(fill='x', padx=4, pady=4)
        tk.Label(mbar, text="Leg mode:", bg='#333', fg='white').pack(side='left', padx=6)
        self._leg_mode_var = tk.StringVar(value=MODE_POSITION)
        for mode in (MODE_MIT, MODE_POSITION, MODE_SPEED):
            tk.Radiobutton(mbar, text=mode, variable=self._leg_mode_var, value=mode,
                           bg='#333', fg='white', selectcolor='#555',
                           command=self._on_leg_mode_change).pack(side='left', padx=4)

        # scrollable canvas so all joints fit
        canvas = tk.Canvas(parent)
        vsb = ttk.Scrollbar(parent, orient='vertical', command=canvas.yview)
        canvas.configure(yscrollcommand=vsb.set)
        vsb.pack(side='right', fill='y')
        canvas.pack(side='left', fill='both', expand=True)

        cols = tk.Frame(canvas)
        canvas.create_window((0, 0), window=cols, anchor='nw')
        cols.bind('<Configure>', lambda e: canvas.configure(
            scrollregion=canvas.bbox('all')))

        # joint columns
        lf = ttk.LabelFrame(cols, text="LEFT LEG  (motors 51-56)")
        lf.grid(row=0, column=0, padx=6, pady=4, sticky='n')
        rf = ttk.LabelFrame(cols, text="RIGHT LEG  (motors 61-66)")
        rf.grid(row=0, column=1, padx=6, pady=4, sticky='n')

        (self._ll_pos_sl, self._ll_spd_sl,
         self._ll_status) = _build_joint_rows(
            lf, LEFT_LEG_NAMES, LEG_LIMITS_DEG,
            lambda i, v: self._set_pos(self.left_leg_pos, i, v),
            lambda i, v: self._set_spd(self.left_leg_spd, i, v),
        )
        tk.Button(lf, text="ZERO LEFT LEG",
                  command=lambda: self._zero_limb(
                      self._ll_pos_sl, self._ll_spd_sl,
                      self.left_leg_pos, self.left_leg_spd)
                  ).pack(fill='x', padx=4, pady=(4, 2))

        (self._rl_pos_sl, self._rl_spd_sl,
         self._rl_status) = _build_joint_rows(
            rf, RIGHT_LEG_NAMES, LEG_LIMITS_DEG,
            lambda i, v: self._set_pos(self.right_leg_pos, i, v),
            lambda i, v: self._set_spd(self.right_leg_spd, i, v),
        )
        tk.Button(rf, text="ZERO RIGHT LEG",
                  command=lambda: self._zero_limb(
                      self._rl_pos_sl, self._rl_spd_sl,
                      self.right_leg_pos, self.right_leg_spd)
                  ).pack(fill='x', padx=4, pady=(4, 2))

        # params panel
        pf = ttk.LabelFrame(cols, text="Leg parameters")
        pf.grid(row=1, column=0, columnspan=2, padx=6, pady=4, sticky='ew')

        (self._leg_mit_frame, self._leg_pos_frame, self._leg_spd_frame,
         self._leg_kp, self._leg_kd,
         self._leg_pspd, self._leg_pcur,
         self._leg_scur,
         self._leg_pspd_sl, self._leg_pcur_sl, self._leg_scur_sl) = _build_mode_params_panel(
             pf, LEG_JOINT_NAMES, LEG_KP_DEFAULTS, LEG_KD_DEFAULTS,
             0.5, 8.0, cur_max=40.0)

        self._on_leg_mode_change()

    def _on_leg_mode_change(self):
        mode = self._leg_mode_var.get()
        self.leg_mode = mode
        self._leg_mit_frame.pack_forget()
        self._leg_pos_frame.pack_forget()
        self._leg_spd_frame.pack_forget()
        if mode == MODE_MIT:
            self._leg_mit_frame.pack(fill='x')
        elif mode == MODE_POSITION:
            self._leg_pos_frame.pack(fill='x')
        else:
            self._leg_spd_frame.pack(fill='x')
        for ps, ss in zip(self._ll_pos_sl, self._ll_spd_sl):
            _toggle_joint_sliders(ps, ss, mode)
        for ps, ss in zip(self._rl_pos_sl, self._rl_spd_sl):
            _toggle_joint_sliders(ps, ss, mode)

    # ── Arm tab ───────────────────────────────────────────────────────────────

    def _build_arm_tab(self, parent):
        # mode bar
        mbar = tk.Frame(parent, bg='#333')
        mbar.pack(fill='x', padx=4, pady=4)
        tk.Label(mbar, text="Arm mode:", bg='#333', fg='white').pack(side='left', padx=6)
        self._arm_mode_var = tk.StringVar(value=MODE_POSITION)
        for mode in (MODE_MIT, MODE_POSITION, MODE_SPEED):
            tk.Radiobutton(mbar, text=mode, variable=self._arm_mode_var, value=mode,
                           bg='#333', fg='white', selectcolor='#555',
                           command=self._on_arm_mode_change).pack(side='left', padx=4)

        canvas = tk.Canvas(parent)
        vsb = ttk.Scrollbar(parent, orient='vertical', command=canvas.yview)
        canvas.configure(yscrollcommand=vsb.set)
        vsb.pack(side='right', fill='y')
        canvas.pack(side='left', fill='both', expand=True)

        cols = tk.Frame(canvas)
        canvas.create_window((0, 0), window=cols, anchor='nw')
        cols.bind('<Configure>', lambda e: canvas.configure(
            scrollregion=canvas.bbox('all')))

        lf = ttk.LabelFrame(cols, text="LEFT ARM  (motors 11-17)")
        lf.grid(row=0, column=0, padx=6, pady=4, sticky='n')
        rf = ttk.LabelFrame(cols, text="RIGHT ARM  (motors 21-27)")
        rf.grid(row=0, column=1, padx=6, pady=4, sticky='n')

        (self._la_pos_sl, self._la_spd_sl,
         self._la_status) = _build_joint_rows(
            lf, LEFT_ARM_NAMES, LEFT_ARM_LIMITS_DEG,
            lambda i, v: self._set_pos(self.left_arm_pos, i, v),
            lambda i, v: self._set_spd(self.left_arm_spd, i, v),
        )
        tk.Button(lf, text="ZERO LEFT ARM",
                  command=lambda: self._zero_limb(
                      self._la_pos_sl, self._la_spd_sl,
                      self.left_arm_pos, self.left_arm_spd)
                  ).pack(fill='x', padx=4, pady=(4, 2))

        (self._ra_pos_sl, self._ra_spd_sl,
         self._ra_status) = _build_joint_rows(
            rf, RIGHT_ARM_NAMES, RIGHT_ARM_LIMITS_DEG,
            lambda i, v: self._set_pos(self.right_arm_pos, i, v),
            lambda i, v: self._set_spd(self.right_arm_spd, i, v),
        )
        tk.Button(rf, text="ZERO RIGHT ARM",
                  command=lambda: self._zero_limb(
                      self._ra_pos_sl, self._ra_spd_sl,
                      self.right_arm_pos, self.right_arm_spd)
                  ).pack(fill='x', padx=4, pady=(4, 2))

        pf = ttk.LabelFrame(cols, text="Arm parameters")
        pf.grid(row=1, column=0, columnspan=2, padx=6, pady=4, sticky='ew')

        (self._arm_mit_frame, self._arm_pos_frame, self._arm_spd_frame,
         self._arm_kp, self._arm_kd,
         self._arm_pspd, self._arm_pcur,
         self._arm_scur,
         self._arm_pspd_sl, self._arm_pcur_sl, self._arm_scur_sl) = _build_mode_params_panel(
             pf, ARM_JOINT_NAMES, ARM_KP_DEFAULTS, ARM_KD_DEFAULTS, 0.5, 8.0)

        self._on_arm_mode_change()

    def _on_arm_mode_change(self):
        mode = self._arm_mode_var.get()
        self.arm_mode = mode
        self._arm_mit_frame.pack_forget()
        self._arm_pos_frame.pack_forget()
        self._arm_spd_frame.pack_forget()
        if mode == MODE_MIT:
            self._arm_mit_frame.pack(fill='x')
        elif mode == MODE_POSITION:
            self._arm_pos_frame.pack(fill='x')
        else:
            self._arm_spd_frame.pack(fill='x')
        for ps, ss in zip(self._la_pos_sl, self._la_spd_sl):
            _toggle_joint_sliders(ps, ss, mode)
        for ps, ss in zip(self._ra_pos_sl, self._ra_spd_sl):
            _toggle_joint_sliders(ps, ss, mode)

    # ── Waist tab ─────────────────────────────────────────────────────────────

    def _build_waist_tab(self, parent):
        tk.Label(parent, text="Waist Yaw  (motor 31)",
                 font=('Arial', 11, 'bold')).pack(pady=(16, 4))

        self._waist_slider = tk.Scale(
            parent, from_=WAIST_LIMITS_DEG[0], to=WAIST_LIMITS_DEG[1],
            resolution=0.1, orient=tk.HORIZONTAL, length=340,
            label="degrees",
            command=lambda v: self.waist_pos.__setitem__(0, float(v)),
        )
        self._waist_slider.pack()

        self._waist_status_lbl = tk.Label(
            parent, text="--", font=("Courier", 9), anchor='w', width=55)
        self._waist_status_lbl.pack(fill='x', padx=8, pady=(0, 8))

        tk.Label(parent, text="Profile speed  (rpm)").pack()
        self._waist_spd_slider = tk.Scale(
            parent, from_=0.0, to=4.0, resolution=0.1,
            orient=tk.HORIZONTAL, length=340,
            command=lambda v: self.waist_speed.__setitem__(0, float(v)),
        )
        self._waist_spd_slider.set(self.waist_speed[0])
        self._waist_spd_slider.pack()

        tk.Button(parent, text="ZERO WAIST",
                  command=self._zero_waist).pack(padx=8, pady=16, fill='x')

    def _zero_waist(self):
        self._waist_slider.set(0.0)
        self.waist_pos[0] = 0.0

    # ── Head tab ──────────────────────────────────────────────────────────────

    def _build_head_tab(self, parent):
        tk.Label(parent, text="Head motors  (roll=motor 3, pitch=motor 2, yaw=motor 1)",
                 font=('Arial', 11, 'bold')).pack(pady=(16, 4))

        self._head_sliders = []
        self._head_status_lbls = []

        for i in range(3):
            lo, hi = HEAD_LIMITS_DEG[i]
            tk.Label(parent, text=f"{HEAD_NAMES[i]}  ({lo}°…{hi}°)").pack()
            sl = tk.Scale(
                parent,
                from_=lo, to=hi,
                resolution=0.1, orient=tk.HORIZONTAL, length=360,
                command=lambda v, idx=i: self.head_pos.__setitem__(idx, float(v)),
            )
            sl.pack()
            self._head_sliders.append(sl)

            lbl = tk.Label(parent, text="--", font=("Courier", 9), anchor='w', width=55)
            lbl.pack(fill='x', padx=8, pady=(0, 6))
            self._head_status_lbls.append(lbl)

        tk.Label(parent, text="Speed (all joints)").pack(pady=(8, 0))
        self._head_spd_slider = tk.Scale(
            parent, from_=0.0, to=1.0, resolution=0.01,
            orient=tk.HORIZONTAL, length=360,
            command=lambda v: self.head_speed.__setitem__(0, float(v)),
        )
        self._head_spd_slider.set(self.head_speed[0])
        self._head_spd_slider.pack()

        tk.Button(parent, text="ZERO HEAD",
                  command=self._zero_head).pack(padx=8, pady=12, fill='x')

    def _zero_head(self):
        for i, s in enumerate(self._head_sliders):
            s.set(0.0)
            self.head_pos[i] = 0.0

    def _zero_all_joints(self):
        # Legs
        self._zero_limb(self._ll_pos_sl, self._ll_spd_sl, self.left_leg_pos, self.left_leg_spd)
        self._zero_limb(self._rl_pos_sl, self._rl_spd_sl, self.right_leg_pos, self.right_leg_spd)

        # Arms
        self._zero_limb(self._la_pos_sl, self._la_spd_sl, self.left_arm_pos, self.left_arm_spd)
        self._zero_limb(self._ra_pos_sl, self._ra_spd_sl, self.right_arm_pos, self.right_arm_spd)

        # Waist + head
        self._zero_waist()
        self._zero_head()

        # Hands (finger 5 is fixed at 1.0)
        for i in range(6):
            if i == 4:
                self._lf_pos_sl[i].set(1.0)
                self._rf_pos_sl[i].set(1.0)
                self.left_finger_pos[i] = 1.0
                self.right_finger_pos[i] = 1.0
            else:
                self._lf_pos_sl[i].set(0.0)
                self._rf_pos_sl[i].set(0.0)
                self.left_finger_pos[i] = 0.0
                self.right_finger_pos[i] = 0.0

            self._lf_vel_sl[i].set(1.0)
            self._rf_vel_sl[i].set(1.0)
            self.left_finger_vel[i] = 1.0
            self.right_finger_vel[i] = 1.0

    def _capture_current_position(self):
        return {
            'leg_mode': self.leg_mode,
            'arm_mode': self.arm_mode,
            'left_leg_pos': list(self.left_leg_pos),
            'right_leg_pos': list(self.right_leg_pos),
            'left_arm_pos': list(self.left_arm_pos),
            'right_arm_pos': list(self.right_arm_pos),
            'leg_profile_speed': float(self._leg_pspd[0]),
            'leg_position_current': float(self._leg_pcur[0]),
            'leg_speed_current': float(self._leg_scur[0]),
            'arm_profile_speed': float(self._arm_pspd[0]),
            'arm_position_current': float(self._arm_pcur[0]),
            'arm_speed_current': float(self._arm_scur[0]),
            'waist_pos': list(self.waist_pos),
            'waist_speed': list(self.waist_speed),
            'head_pos': list(self.head_pos),
            'head_speed': list(self.head_speed),
            'left_finger_pos': list(self.left_finger_pos),
            'right_finger_pos': list(self.right_finger_pos),
            'left_finger_vel': list(self.left_finger_vel),
            'right_finger_vel': list(self.right_finger_vel),
            'hand_effort': list(self.finger_effort),
        }

    def _apply_saved_position(self, data):
        leg_mode = data.get('leg_mode', MODE_POSITION)
        if leg_mode not in (MODE_MIT, MODE_POSITION, MODE_SPEED):
            leg_mode = MODE_POSITION
        self._leg_mode_var.set(leg_mode)
        self._on_leg_mode_change()
        arm_mode = data.get('arm_mode', MODE_POSITION)
        if arm_mode not in (MODE_MIT, MODE_POSITION, MODE_SPEED):
            arm_mode = MODE_POSITION
        self._arm_mode_var.set(arm_mode)
        self._on_arm_mode_change()

        if 'leg_profile_speed' in data:
            v = float(data['leg_profile_speed'])
            self._leg_pspd_sl.set(v)
            self._leg_pspd[0] = v
        if 'leg_position_current' in data:
            v = float(data['leg_position_current'])
            self._leg_pcur_sl.set(v)
            self._leg_pcur[0] = v
        if 'leg_speed_current' in data:
            v = float(data['leg_speed_current'])
            self._leg_scur_sl.set(v)
            self._leg_scur[0] = v

        if 'arm_profile_speed' in data:
            v = float(data['arm_profile_speed'])
            self._arm_pspd_sl.set(v)
            self._arm_pspd[0] = v
        if 'arm_position_current' in data:
            v = float(data['arm_position_current'])
            self._arm_pcur_sl.set(v)
            self._arm_pcur[0] = v
        if 'arm_speed_current' in data:
            v = float(data['arm_speed_current'])
            self._arm_scur_sl.set(v)
            self._arm_scur[0] = v

        # Legs
        for i, v in enumerate(data.get('left_leg_pos', [])):
            if i < len(self._ll_pos_sl):
                self._ll_pos_sl[i].set(float(v))
                self.left_leg_pos[i] = float(v)
        for i, v in enumerate(data.get('right_leg_pos', [])):
            if i < len(self._rl_pos_sl):
                self._rl_pos_sl[i].set(float(v))
                self.right_leg_pos[i] = float(v)

        # Arms
        for i, v in enumerate(data.get('left_arm_pos', [])):
            if i < len(self._la_pos_sl):
                self._la_pos_sl[i].set(float(v))
                self.left_arm_pos[i] = float(v)
        for i, v in enumerate(data.get('right_arm_pos', [])):
            if i < len(self._ra_pos_sl):
                self._ra_pos_sl[i].set(float(v))
                self.right_arm_pos[i] = float(v)

        # Waist + head
        waist_vals = data.get('waist_pos', [])
        if waist_vals and len(self._waist_ids) > 0:
            self._waist_slider.set(float(waist_vals[0]))
            self.waist_pos[0] = float(waist_vals[0])
        waist_speed_vals = data.get('waist_speed', [])
        if waist_speed_vals:
            self._waist_spd_slider.set(float(waist_speed_vals[0]))
            self.waist_speed[0] = float(waist_speed_vals[0])
        for i, v in enumerate(data.get('head_pos', [])):
            if i < len(self._head_sliders):
                self._head_sliders[i].set(float(v))
                self.head_pos[i] = float(v)
        head_speed_vals = data.get('head_speed', [])
        if head_speed_vals:
            self._head_spd_slider.set(float(head_speed_vals[0]))
            self.head_speed[0] = float(head_speed_vals[0])

        # Hands (finger 5 remains fixed at 1.0)
        for i, v in enumerate(data.get('left_finger_pos', [])):
            if i < len(self._lf_pos_sl):
                vv = 1.0 if i == 4 else float(v)
                self._lf_pos_sl[i].set(vv)
                self.left_finger_pos[i] = vv
        for i, v in enumerate(data.get('right_finger_pos', [])):
            if i < len(self._rf_pos_sl):
                vv = 1.0 if i == 4 else float(v)
                self._rf_pos_sl[i].set(vv)
                self.right_finger_pos[i] = vv

        for i, v in enumerate(data.get('left_finger_vel', [])):
            if i < len(self._lf_vel_sl):
                vv = float(v)
                self._lf_vel_sl[i].set(vv)
                self.left_finger_vel[i] = vv
        for i, v in enumerate(data.get('right_finger_vel', [])):
            if i < len(self._rf_vel_sl):
                vv = float(v)
                self._rf_vel_sl[i].set(vv)
                self.right_finger_vel[i] = vv

        hand_eff_vals = data.get('hand_effort', [])
        if hand_eff_vals:
            vv = float(hand_eff_vals[0])
            self._finger_eff_sl.set(vv)
            self.finger_effort[0] = vv

    def _read_saved_positions(self):
        if not os.path.exists(self._positions_file):
            return {}

        saved = {}
        try:
            with open(self._positions_file, 'r', newline='', encoding='utf-8') as f:
                reader = csv.DictReader(f)
                for row in reader:
                    name = (row.get('name') or '').strip()
                    payload = row.get('payload')
                    if not name or not payload:
                        continue
                    try:
                        saved[name] = json.loads(payload)
                    except json.JSONDecodeError:
                        continue
        except OSError as exc:
            messagebox.showerror('Load Position', f'Failed to read positions file:\n{exc}')
            return {}
        return saved

    def _write_saved_positions(self, saved):
        try:
            with open(self._positions_file, 'w', newline='', encoding='utf-8') as f:
                writer = csv.DictWriter(f, fieldnames=['name', 'payload'])
                writer.writeheader()
                for name in sorted(saved.keys()):
                    writer.writerow({'name': name, 'payload': json.dumps(saved[name])})
            return True
        except OSError as exc:
            messagebox.showerror('Save Position', f'Failed to write positions file:\n{exc}')
            return False

    def _save_named_position(self):
        name = simpledialog.askstring('Save Position', 'Enter a name for this position:', parent=self.root)
        if name is None:
            return
        name = name.strip()
        if not name:
            messagebox.showwarning('Save Position', 'Position name cannot be empty.')
            return

        saved = self._read_saved_positions()
        if name in saved:
            overwrite = messagebox.askyesno('Save Position', f'"{name}" already exists. Overwrite?')
            if not overwrite:
                return

        saved[name] = self._capture_current_position()
        if self._write_saved_positions(saved):
            self._refresh_positions_tab()

    def _build_positions_tab(self, parent):
        top = tk.Frame(parent)
        top.pack(fill='x', padx=8, pady=(8, 4))

        tk.Label(top, text='Saved positions', font=('Arial', 11, 'bold')).pack(side='left')
        tk.Button(top, text='Refresh', command=self._refresh_positions_tab).pack(side='right')

        self._positions_note_var = tk.StringVar(value='')
        tk.Label(parent, textvariable=self._positions_note_var, anchor='w').pack(fill='x', padx=8, pady=(0, 4))

        self._positions_buttons_frame = tk.Frame(parent)
        self._positions_buttons_frame.pack(fill='both', expand=True, padx=8, pady=8)

        self._refresh_positions_tab()

    def _refresh_positions_tab(self):
        frame = getattr(self, '_positions_buttons_frame', None)
        if frame is None:
            return

        for child in frame.winfo_children():
            child.destroy()

        saved = self._read_saved_positions()
        names = sorted(saved.keys())
        if not names:
            self._positions_note_var.set('No saved positions found. Use SAVE POSITION to add one.')
            tk.Label(frame, text='No saved positions yet.', fg='#666').pack(anchor='w')
            return

        self._positions_note_var.set(f'{len(names)} saved position(s). Click a button to execute.')
        for i, name in enumerate(names):
            btn = tk.Button(
                frame,
                text=name,
                width=36,
                command=lambda n=name: self._execute_saved_position(n),
            )
            btn.grid(row=i // 3, column=i % 3, padx=6, pady=6, sticky='ew')

        for col in range(3):
            frame.grid_columnconfigure(col, weight=1)

    def _execute_saved_position(self, name):
        saved = self._read_saved_positions()
        data = saved.get(name)
        if data is None:
            messagebox.showwarning('Positions', f'Position "{name}" was not found.')
            self._refresh_positions_tab()
            return

        self._apply_saved_position(data)

    def _exit_app(self):
        self._shutdown_requested = True
        self._random_mode = False
        if self._random_timer_id:
            self.root.after_cancel(self._random_timer_id)
            self._random_timer_id = None

        if self._motion_client.service_is_ready():
            self._stop_motion()

        try:
            self.root.destroy()
        except tk.TclError:
            pass

        if rclpy.ok():
            rclpy.shutdown()

    # ── Hand tab ──────────────────────────────────────────────────────────────

    def _build_hand_tab(self, parent):
        main = tk.Frame(parent)
        main.pack(padx=8, pady=8)

        lhf = tk.LabelFrame(main, text="LEFT HAND", font=('Arial', 11, 'bold'),
                             relief=tk.RIDGE, borderwidth=2)
        lhf.grid(row=0, column=0, padx=8, pady=4)

        rhf = tk.LabelFrame(main, text="RIGHT HAND", font=('Arial', 11, 'bold'),
                             relief=tk.RIDGE, borderwidth=2)
        rhf.grid(row=0, column=1, padx=8, pady=4)

        self._lf_pos_sl, self._lf_vel_sl = self._build_finger_sliders(
            lhf, 'left')
        self._rf_pos_sl, self._rf_vel_sl = self._build_finger_sliders(
            rhf, 'right')

        # left buttons
        lbf = tk.Frame(lhf)
        lbf.pack(pady=6)
        tk.Button(lbf, text="OPEN",  width=8,
                  command=lambda: self._open_hand('left')).pack(side='left', padx=4)
        tk.Button(lbf, text="CLOSE", width=8,
                  command=lambda: self._close_hand('left')).pack(side='left', padx=4)

        # right buttons
        rbf = tk.Frame(rhf)
        rbf.pack(pady=6)
        tk.Button(rbf, text="OPEN",  width=8,
                  command=lambda: self._open_hand('right')).pack(side='left', padx=4)
        tk.Button(rbf, text="CLOSE", width=8,
                  command=lambda: self._close_hand('right')).pack(side='left', padx=4)

        # global controls (effort, random period, random toggle)
        gf = tk.LabelFrame(main, text="Global hand controls")
        gf.grid(row=1, column=0, columnspan=2, padx=8, pady=8, sticky='ew')

        tk.Label(gf, text="Effort (all fingers)").pack(pady=(4, 0))
        eff_sl = tk.Scale(gf, from_=0.0, to=2.0, resolution=0.1,
                          orient=tk.HORIZONTAL, length=400,
                          command=lambda v: self.finger_effort.__setitem__(0, float(v)))
        eff_sl.set(self.finger_effort[0])
        eff_sl.pack()
        self._finger_eff_sl = eff_sl

        tk.Label(gf, text="Random update period  (s)").pack(pady=(8, 0))
        rp_sl = tk.Scale(gf, from_=0.05, to=2.0, resolution=0.05,
                         orient=tk.HORIZONTAL, length=400,
                         command=lambda v: self._random_period.__setitem__(0, float(v)))
        rp_sl.set(self._random_period[0])
        rp_sl.pack()

        self._random_btn = tk.Button(gf, text="START RANDOM",
                                     bg='lightgreen', width=16,
                                     command=self._toggle_random)
        self._random_btn.pack(pady=8)

    def _build_finger_sliders(self, parent, hand):
        pos_sliders, vel_sliders = [], []
        for i, name in enumerate(FINGER_NAMES):
            row = tk.Frame(parent)
            row.pack(fill='x', padx=4, pady=2)
            tk.Label(row, text=f"Finger {name}", width=8).pack(side='left')

            ps = tk.Scale(row, from_=0.0, to=1.0, resolution=0.01,
                          orient=tk.HORIZONTAL, length=180,
                          command=lambda v, h=hand, idx=i: self._set_finger_pos(h, idx, v))
            if i == 4:
                ps.set(1.0)
                ps.config(state='disabled')
            pos_sliders.append(ps)
            ps.pack(side='left')

            tk.Label(row, text="vel:", width=4).pack(side='left')
            vs = tk.Scale(row, from_=0.0, to=2.0, resolution=0.1,
                          orient=tk.HORIZONTAL, length=80,
                          command=lambda v, h=hand, idx=i: self._set_finger_vel(h, idx, v))
            vs.set(1.0)
            vs.pack(side='left')
            vel_sliders.append(vs)

        return pos_sliders, vel_sliders

    def _set_finger_pos(self, hand, i, v):
        if i == 4:
            return
        if hand == 'left':
            self.left_finger_pos[i] = float(v)
        else:
            self.right_finger_pos[i] = float(v)

    def _set_finger_vel(self, hand, i, v):
        if hand == 'left':
            self.left_finger_vel[i] = float(v)
        else:
            self.right_finger_vel[i] = float(v)

    def _open_hand(self, hand):
        sl = self._lf_pos_sl if hand == 'left' else self._rf_pos_sl
        pos = self.left_finger_pos if hand == 'left' else self.right_finger_pos
        for i in range(4):
            sl[i].set(1.0)
            pos[i] = 1.0

    def _close_hand(self, hand):
        sl = self._lf_pos_sl if hand == 'left' else self._rf_pos_sl
        pos = self.left_finger_pos if hand == 'left' else self.right_finger_pos
        for i in range(6):
            if i != 4:
                sl[i].set(0.0)
                pos[i] = 0.0

    def _toggle_random(self):
        self._random_mode = not self._random_mode
        if self._random_mode:
            self._random_btn.config(text="STOP RANDOM", bg='orange')
            self._apply_random_fingers()
        else:
            self._random_btn.config(text="START RANDOM", bg='lightgreen')
            if self._random_timer_id:
                self.root.after_cancel(self._random_timer_id)
                self._random_timer_id = None

    def _apply_random_fingers(self):
        for i in range(6):
            if i == 4:
                continue
            v = round(random.uniform(0.0, 1.0), 2)
            self._lf_pos_sl[i].set(v)
            self.left_finger_pos[i] = v
            v = round(random.uniform(0.0, 1.0), 2)
            self._rf_pos_sl[i].set(v)
            self.right_finger_pos[i] = v
        if self._random_mode:
            delay = int(self._random_period[0] * 1000)
            self._random_timer_id = self.root.after(delay, self._apply_random_fingers)

    # =========================================================================
    # Generic helpers
    # =========================================================================

    @staticmethod
    def _set_pos(arr, i, v):
        arr[i] = float(v)

    @staticmethod
    def _set_spd(arr, i, v):
        arr[i] = float(v)

    @staticmethod
    def _zero_limb(pos_sliders, spd_sliders, pos_arr, spd_arr):
        for i, s in enumerate(pos_sliders):
            s.set(0.0)
            pos_arr[i] = 0.0
        for i, s in enumerate(spd_sliders):
            s.set(0.0)
            spd_arr[i] = 0.0

    # =========================================================================
    # Publishing
    # =========================================================================

    def _publish_all(self):
        self._publish_legs()
        self._publish_arms()
        self._publish_waist()
        self._publish_head()
        self._publish_hands()

    # ── leg ───────────────────────────────────────────────────────────────────

    def _publish_legs(self):
        if not (all(self._left_leg_init) and all(self._right_leg_init)):
            return
        mode = self.leg_mode
        if mode == MODE_MIT:
            msg = CmdMotorCtrl()
            msg.cmds = []
            for ids, pos_arr in ((self._left_leg_ids, self.left_leg_pos),
                                 (self._right_leg_ids, self.right_leg_pos)):
                for i, mid in enumerate(ids):
                    c = MotorCtrl()
                    c.name = mid
                    c.kp   = float(self._leg_kp[i][0])
                    c.kd   = float(self._leg_kd[i][0])
                    c.pos  = math.radians(float(pos_arr[i]))
                    c.spd  = 0.0
                    c.tor  = 0.0
                    msg.cmds.append(c)
            self._leg_mit_pub.publish(msg)

        elif mode == MODE_POSITION:
            msg = CmdSetMotorPosition()
            msg.cmds = []
            for ids, pos_arr in ((self._left_leg_ids, self.left_leg_pos),
                                 (self._right_leg_ids, self.right_leg_pos)):
                for i, mid in enumerate(ids):
                    c = SetMotorPosition()
                    c.name = mid
                    c.pos  = math.radians(float(pos_arr[i]))
                    c.spd  = float(self._leg_pspd[0])
                    c.cur  = float(self._leg_pcur[0])
                    msg.cmds.append(c)
            self._leg_pos_pub.publish(msg)

        else:  # SPEED
            msg = CmdSetMotorSpeed()
            msg.cmds = []
            for ids, spd_arr in ((self._left_leg_ids, self.left_leg_spd),
                                 (self._right_leg_ids, self.right_leg_spd)):
                for i, mid in enumerate(ids):
                    c = SetMotorSpeed()
                    c.name = mid
                    c.spd  = float(spd_arr[i])
                    c.cur  = float(self._leg_scur[0])
                    msg.cmds.append(c)
            self._leg_spd_pub.publish(msg)

    # ── arm ───────────────────────────────────────────────────────────────────

    def _publish_arms(self):
        if not (all(self._left_arm_init) and all(self._right_arm_init)):
            return
        mode = self.arm_mode
        if mode == MODE_MIT:
            msg = CmdMotorCtrl()
            msg.cmds = []
            for ids, pos_arr in ((self._left_arm_ids, self.left_arm_pos),
                                 (self._right_arm_ids, self.right_arm_pos)):
                for i, mid in enumerate(ids):
                    c = MotorCtrl()
                    c.name = mid
                    c.kp   = float(self._arm_kp[i][0])
                    c.kd   = float(self._arm_kd[i][0])
                    c.pos  = math.radians(float(pos_arr[i]))
                    c.spd  = 0.0
                    c.tor  = 0.0
                    msg.cmds.append(c)
            self._arm_mit_pub.publish(msg)

        elif mode == MODE_POSITION:
            msg = CmdSetMotorPosition()
            msg.cmds = []
            for ids, pos_arr in ((self._left_arm_ids, self.left_arm_pos),
                                 (self._right_arm_ids, self.right_arm_pos)):
                for i, mid in enumerate(ids):
                    c = SetMotorPosition()
                    c.name = mid
                    c.pos  = math.radians(float(pos_arr[i]))
                    c.spd  = float(self._arm_pspd[0])
                    c.cur  = float(self._arm_pcur[0])
                    msg.cmds.append(c)
            self._arm_pos_pub.publish(msg)

        else:  # SPEED
            msg = CmdSetMotorSpeed()
            msg.cmds = []
            for ids, spd_arr in ((self._left_arm_ids, self.left_arm_spd),
                                 (self._right_arm_ids, self.right_arm_spd)):
                for i, mid in enumerate(ids):
                    c = SetMotorSpeed()
                    c.name = mid
                    c.spd  = float(spd_arr[i])
                    c.cur  = float(self._arm_scur[0])
                    msg.cmds.append(c)
            self._arm_spd_pub.publish(msg)

    # ── waist ─────────────────────────────────────────────────────────────────

    def _publish_waist(self):
        if not self._waist_init[0]:
            return
        msg = CmdSetMotorPosition()
        c = SetMotorPosition()
        c.name = self._waist_ids[0]
        c.pos  = math.radians(float(self.waist_pos[0]))
        c.spd  = float(self.waist_speed[0])
        c.cur  = 8.0
        msg.cmds = [c]
        self._waist_pub.publish(msg)

    # ── head ──────────────────────────────────────────────────────────────────

    def _publish_head(self):
        msg = CmdSetMotorPosition()
        msg.cmds = []
        for i, mid in enumerate(self._head_ids):
            c = SetMotorPosition()
            c.name = mid
            c.pos  = math.radians(float(self.head_pos[i]))
            c.spd  = float(self.head_speed[0])
            c.cur  = 8.0
            msg.cmds.append(c)
        self._head_pub.publish(msg)

    # ── hands ─────────────────────────────────────────────────────────────────

    def _publish_hands(self):
        self.left_finger_pos[4]  = 1.0
        self.right_finger_pos[4] = 1.0

        lmsg = JointState()
        lmsg.header.stamp = self.get_clock().now().to_msg()
        lmsg.name     = FINGER_NAMES
        lmsg.position = list(self.left_finger_pos)
        lmsg.velocity = list(self.left_finger_vel)
        lmsg.effort   = [self.finger_effort[0]] * 6
        self._hand_left_pub.publish(lmsg)

        rmsg = JointState()
        rmsg.header.stamp = self.get_clock().now().to_msg()
        rmsg.name     = FINGER_NAMES
        rmsg.position = list(self.right_finger_pos)
        rmsg.velocity = list(self.right_finger_vel)
        rmsg.effort   = [self.finger_effort[0]] * 6
        self._hand_right_pub.publish(rmsg)

    # =========================================================================
    # Status callbacks
    # =========================================================================

    def _leg_status_cb(self, msg):
        for st in msg.status:
            pos_deg = math.degrees(st.pos)
            text = _status_text(st, pos_deg)
            if st.name in self._left_leg_ids:
                i = self._left_leg_ids.index(st.name)
                if not self._left_leg_init[i]:
                    self._ll_pos_sl[i].set(pos_deg)
                    self.left_leg_pos[i] = pos_deg
                    self._left_leg_init[i] = True
                self._ll_status[i].config(text=text)
            elif st.name in self._right_leg_ids:
                i = self._right_leg_ids.index(st.name)
                if not self._right_leg_init[i]:
                    self._rl_pos_sl[i].set(pos_deg)
                    self.right_leg_pos[i] = pos_deg
                    self._right_leg_init[i] = True
                self._rl_status[i].config(text=text)

    def _arm_status_cb(self, msg):
        for st in msg.status:
            pos_deg = math.degrees(st.pos)
            text = _status_text(st, pos_deg)
            if st.name in self._left_arm_ids:
                i = self._left_arm_ids.index(st.name)
                if not self._left_arm_init[i]:
                    self._la_pos_sl[i].set(pos_deg)
                    self.left_arm_pos[i] = pos_deg
                    self._left_arm_init[i] = True
                self._la_status[i].config(text=text)
            elif st.name in self._right_arm_ids:
                i = self._right_arm_ids.index(st.name)
                if not self._right_arm_init[i]:
                    self._ra_pos_sl[i].set(pos_deg)
                    self.right_arm_pos[i] = pos_deg
                    self._right_arm_init[i] = True
                self._ra_status[i].config(text=text)

    def _waist_status_cb(self, msg):
        for st in msg.status:
            if st.name in self._waist_ids:
                pos_deg = math.degrees(st.pos)
                if not self._waist_init[0]:
                    self._waist_slider.set(pos_deg)
                    self.waist_pos[0] = pos_deg
                    self._waist_init[0] = True
                self._waist_status_lbl.config(text=_status_text(st, pos_deg))

    def _head_status_cb(self, msg):
        for st in msg.status:
            if st.name in self._head_ids:
                i = self._head_ids.index(st.name)
                self._head_status_lbls[i].config(text=_status_text(st, math.degrees(st.pos)))

    # =========================================================================
    # Motion service
    # =========================================================================

    def _stop_motion(self):
        if not self._motion_client.service_is_ready():
            self._motion_status_var.set('motion: service not available')
            return
        self._motion_status_var.set('motion: stopping…')
        req = SetMotionMode.Request()
        req.walk_mode_request = SetMotionMode.Request.STOP
        req.is_need_swing_arm = False
        threading.Thread(target=self._do_stop_motion, args=(req,), daemon=True).start()

    def _do_stop_motion(self, req):
        future = self._motion_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.done() and future.result() is not None:
            resp = future.result()
            result = ('motion: STOPPED' if resp.success
                      else f'motion: STOP failed (err={resp.error_code})')
        else:
            result = 'motion: STOP timeout'
        self.root.after(0, lambda: self._motion_status_var.set(result))

    # =========================================================================
    # Main loop
    # =========================================================================

    def spin(self):
        while rclpy.ok() and not self._shutdown_requested:
            self.root.update()
            rclpy.spin_once(self, timeout_sec=0.0)


def main():
    rclpy.init()
    node = MotionControlGUI()
    try:
        node.spin()
    except tk.TclError:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
