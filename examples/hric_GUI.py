#!/usr/bin/env python3
"""
hric_GUI.py — Tkinter GUI for HRIC system monitoring and control.

Displays live status for:
  - Motion (walk mode, velocity, errors)
  - Localization / LiDAR (status, confidence, errors)
  - Navigation (status, errors)
  - Map markers (list, create, delete)

And provides buttons to:
  - Change motion mode (Stop / Zero / Stand / Walk / Run)
  - Trigger relocalization (local / global)
  - Send navigation goals
  - Create / delete markers

Usage:
    source ~/ros2ws/install/setup.bash
    python3 examples/hric_GUI.py
"""

import threading
import tkinter as tk
from tkinter import ttk, messagebox, simpledialog
import math

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from hric_msgs.msg import MotionStatus, LocStatus, NavStatus, MarkerInfo
from hric_msgs.srv import (
    SetMotionMode,
    SetMotionNumber,
    SetGoal,
    Relocate,
    MarkHere,
    MarkAtPose,
    OperateMarker,
    ListMarkers,
    SetVisualLocMode,
)
from hric_msgs.action import NavToPose
from geometry_msgs.msg import PoseStamped, Pose2D


# ---------------------------------------------------------------------------
# Constants / mappings
# ---------------------------------------------------------------------------

WALK_MODE_NAMES = {
    0: 'stop',
    1: 'zero',
    2: 'Z→Stand',
    3: 'stand',
    4: 'Stand→Walk',
    5: 'walk',
    6: 'start',
    7: 'run',
}

LOC_STATUS_NAMES = {
    100: 'IDLE',
    101: 'INITIALIZING',
    102: 'RUNNING',
    103: 'WEAK',
    104: 'LOST',
    105: 'BLOCKED',
}

LOC_STATUS_COLORS = {
    100: '#888888',
    101: '#e6a817',
    102: '#27ae60',
    103: '#e67e22',
    104: '#e74c3c',
    105: '#c0392b',
}

NAV_STATUS_NAMES = {
    0: 'IDLE',
    1: 'NAVIGATING',
    2: 'CANCELED',
    3: 'FAILED',
    4: 'GOAL REACHED',
}

NAV_STATUS_COLORS = {
    0: '#888888',
    1: '#2980b9',
    2: '#e67e22',
    3: '#e74c3c',
    4: '#27ae60',
}

WALK_MODE_COLORS = {
    0: '#888888',   # stop
    1: '#888888',   # zero
    2: '#e6a817',   # Z→Stand
    3: '#27ae60',   # stand
    4: '#e6a817',   # Stand→Walk
    5: '#2980b9',   # walk
    6: '#e6a817',   # start
    7: '#9b59b6',   # run
}

LOC_ERROR_NAMES = {
    0:   'None',
    200: 'Unknown',
    201: 'TF error',
    202: 'Sensor error',
    203: 'Reloc failed',
}

NAV_ERROR_NAMES = {
    0:   'None',
    100: 'Unknown',
    101: 'Goal occupied',
    102: 'Timeout',
    103: 'No valid path',
}


# ---------------------------------------------------------------------------
# ROS node
# ---------------------------------------------------------------------------

class HricNode(Node):
    """Thin ROS node: subscriptions + service clients."""

    def __init__(self):
        super().__init__('hric_gui')

        # ── Status snapshots (updated from callbacks, read by GUI) ──────────
        self.motion_status: MotionStatus | None = None
        self.loc_status:    LocStatus    | None = None
        self.nav_status:    NavStatus    | None = None
        self.markers:       list[MarkerInfo]    = []

        # ── Subscriptions ────────────────────────────────────────────────────
        self.create_subscription(
            MotionStatus, '/hric/motion/motion_status', self._cb_motion, 10
        )
        self.create_subscription(
            LocStatus, '/hric/loc/loc_status', self._cb_loc, 10
        )
        self.create_subscription(
            NavStatus, '/hric/nav/nav_status', self._cb_nav, 10
        )

        # ── Service clients ──────────────────────────────────────────────────
        self.cli_motion_mode = self.create_client(
            SetMotionMode, '/hric/motion/set_motion_mode'
        )
        self.cli_motion_number = self.create_client(
            SetMotionNumber, '/hric/motion/set_motion_number'
        )
        self.cli_set_goal = self.create_client(
            SetGoal, '/hric/nav/set_goal'
        )
        self.cli_relocate = self.create_client(
            Relocate, '/hric/loc/relocate'
        )
        self.cli_visual_loc = self.create_client(
            SetVisualLocMode, '/hric/loc/set_visual_loc_mode'
        )
        self.cli_mark_here = self.create_client(
            MarkHere, '/hric/map/mark_here'
        )
        self.cli_mark_at = self.create_client(
            MarkAtPose, '/hric/map/mark_at_pose'
        )
        self.cli_operate_marker = self.create_client(
            OperateMarker, '/hric/map/operate_marker'
        )
        self.cli_list_markers = self.create_client(
            ListMarkers, '/hric/map/list_markers'
        )

        self._nav_action = ActionClient(self, NavToPose, '/hric/nav/nav_to_pose')

    # ── Callbacks ────────────────────────────────────────────────────────────

    def _cb_motion(self, msg: MotionStatus):
        self.motion_status = msg

    def _cb_loc(self, msg: LocStatus):
        self.loc_status = msg

    def _cb_nav(self, msg: NavStatus):
        self.nav_status = msg

    # ── Service call helpers (blocking, intended to be called from a thread) ─

    def call_set_motion_mode(self, mode: int, swing_arm: bool = False):
        if not self.cli_motion_mode.wait_for_service(timeout_sec=2.0):
            return None, 'service unavailable'
        req = SetMotionMode.Request()
        req.walk_mode_request = mode
        req.is_need_swing_arm = swing_arm
        future = self.cli_motion_mode.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.result() is None:
            return None, 'timeout'
        return future.result(), None

    def call_set_motion_number(self, number: int, enable: bool = True):
        if not self.cli_motion_number.wait_for_service(timeout_sec=2.0):
            return None, 'service unavailable'
        req = SetMotionNumber.Request()
        req.is_motion = enable
        req.motion_number = number
        future = self.cli_motion_number.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.result() is None:
            return None, 'timeout'
        return future.result(), None

    def call_relocate(self, match_type: int, pose: PoseStamped | None = None):
        if not self.cli_relocate.wait_for_service(timeout_sec=2.0):
            return None, 'service unavailable'
        req = Relocate.Request()
        req.match_type = match_type
        if pose is not None:
            req.pose_robot = pose
        future = self.cli_relocate.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=10.0)
        if future.result() is None:
            return None, 'timeout'
        return future.result(), None

    def call_set_visual_loc_mode(self, mode: int):
        if not self.cli_visual_loc.wait_for_service(timeout_sec=2.0):
            return None, 'service unavailable'
        req = SetVisualLocMode.Request()
        req.loc_mode = mode
        future = self.cli_visual_loc.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.result() is None:
            return None, 'timeout'
        return future.result(), None

    def call_set_goal(self, x: float, y: float, yaw: float = 0.0,
                      frame_id: str = 'map'):
        if not self.cli_set_goal.wait_for_service(timeout_sec=2.0):
            return None, 'service unavailable'
        req = SetGoal.Request()
        req.goal = PoseStamped()
        req.goal.header.frame_id = frame_id
        req.goal.pose.position.x = x
        req.goal.pose.position.y = y
        req.goal.pose.orientation.z = math.sin(yaw / 2.0)
        req.goal.pose.orientation.w = math.cos(yaw / 2.0)
        future = self.cli_set_goal.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.result() is None:
            return None, 'timeout'
        return future.result(), None

    def call_mark_here(self, name: str, map_id: str = '', floor: str = ''):
        if not self.cli_mark_here.wait_for_service(timeout_sec=2.0):
            return None, 'service unavailable'
        req = MarkHere.Request()
        req.name = name
        req.map_id = map_id
        req.floor = floor
        future = self.cli_mark_here.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.result() is None:
            return None, 'timeout'
        return future.result(), None

    def call_mark_at_pose(self, name: str, x: float, y: float,
                          theta: float, map_id: str = '', floor: str = ''):
        if not self.cli_mark_at.wait_for_service(timeout_sec=2.0):
            return None, 'service unavailable'
        req = MarkAtPose.Request()
        req.name = name
        req.map_id = map_id
        req.floor = floor
        req.pose = Pose2D()
        req.pose.x = x
        req.pose.y = y
        req.pose.theta = theta
        future = self.cli_mark_at.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.result() is None:
            return None, 'timeout'
        return future.result(), None

    def call_operate_marker(self, name: str):
        if not self.cli_operate_marker.wait_for_service(timeout_sec=2.0):
            return None, 'service unavailable'
        req = OperateMarker.Request()
        req.name = name
        future = self.cli_operate_marker.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.result() is None:
            return None, 'timeout'
        return future.result(), None

    def call_list_markers(self):
        if not self.cli_list_markers.wait_for_service(timeout_sec=2.0):
            return None, 'service unavailable'
        future = self.cli_list_markers.call_async(ListMarkers.Request())
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.result() is None:
            return None, 'timeout'
        self.markers = list(future.result().markers)
        return future.result(), None


# ---------------------------------------------------------------------------
# GUI helpers
# ---------------------------------------------------------------------------

def _status_dot(parent, color: str = '#888888') -> tk.Canvas:
    """Small coloured circle used as a status indicator."""
    try:
        bg = parent.winfo_background()
    except Exception:
        bg = 'white'
    c = tk.Canvas(parent, width=14, height=14, highlightthickness=0, bg=bg)
    c.create_oval(2, 2, 12, 12, fill=color, outline='')
    return c


class StatusCard(ttk.LabelFrame):
    """A labelled card that holds key-value rows."""

    def __init__(self, parent, title: str, **kwargs):
        super().__init__(parent, text=f'  {title}  ', padding=8, **kwargs)
        self._rows: dict[str, tk.StringVar] = {}
        self._dots: dict[str, tk.Canvas]    = {}
        self._row_idx = 0

    def add_row(self, key: str, initial: str = '—', with_dot: bool = False):
        lbl = ttk.Label(self, text=key + ':', width=18, anchor='e')
        lbl.grid(row=self._row_idx, column=0, sticky='e', padx=(0, 4), pady=1)

        var = tk.StringVar(value=initial)
        self._rows[key] = var

        if with_dot:
            dot = _status_dot(self)
            dot.grid(row=self._row_idx, column=1, sticky='w', padx=(0, 4))
            self._dots[key] = dot
            val_lbl = ttk.Label(self, textvariable=var, anchor='w')
            val_lbl.grid(row=self._row_idx, column=2, sticky='w')
        else:
            val_lbl = ttk.Label(self, textvariable=var, anchor='w')
            val_lbl.grid(row=self._row_idx, column=1, columnspan=2, sticky='w')

        self._row_idx += 1

    def set(self, key: str, value: str, dot_color: str | None = None):
        if key in self._rows:
            self._rows[key].set(value)
        if dot_color and key in self._dots:
            self._dots[key].itemconfig(1, fill=dot_color)


# ---------------------------------------------------------------------------
# Dialog helpers
# ---------------------------------------------------------------------------

class GoalDialog(tk.Toplevel):
    """Simple dialog to input a navigation goal pose."""

    def __init__(self, parent):
        super().__init__(parent)
        self.title('Send Navigation Goal')
        self.resizable(False, False)
        self.result = None

        ttk.Label(self, text='X (m):').grid(row=0, column=0, padx=8, pady=4, sticky='e')
        ttk.Label(self, text='Y (m):').grid(row=1, column=0, padx=8, pady=4, sticky='e')
        ttk.Label(self, text='Yaw (deg):').grid(row=2, column=0, padx=8, pady=4, sticky='e')
        ttk.Label(self, text='Frame:').grid(row=3, column=0, padx=8, pady=4, sticky='e')

        self._x   = ttk.Entry(self, width=12); self._x.insert(0, '0.0')
        self._y   = ttk.Entry(self, width=12); self._y.insert(0, '0.0')
        self._yaw = ttk.Entry(self, width=12); self._yaw.insert(0, '0.0')
        self._frame = ttk.Combobox(self, values=['map', 'base_link'], width=10,
                                   state='readonly')
        self._frame.set('map')

        self._x.grid(row=0, column=1, padx=8, pady=4)
        self._y.grid(row=1, column=1, padx=8, pady=4)
        self._yaw.grid(row=2, column=1, padx=8, pady=4)
        self._frame.grid(row=3, column=1, padx=8, pady=4)

        btn_frame = ttk.Frame(self)
        btn_frame.grid(row=4, column=0, columnspan=2, pady=8)
        ttk.Button(btn_frame, text='Send', command=self._ok).pack(side='left', padx=4)
        ttk.Button(btn_frame, text='Cancel', command=self.destroy).pack(side='left', padx=4)

        self.grab_set()
        self.wait_window()

    def _ok(self):
        try:
            x     = float(self._x.get())
            y     = float(self._y.get())
            yaw   = math.radians(float(self._yaw.get()))
            frame = self._frame.get()
            self.result = (x, y, yaw, frame)
        except ValueError:
            messagebox.showerror('Input error', 'Please enter valid numbers.',
                                 parent=self)
            return
        self.destroy()


class MarkAtPoseDialog(tk.Toplevel):
    """Dialog to input a named pose for mark_at_pose."""

    def __init__(self, parent):
        super().__init__(parent)
        self.title('Mark at Pose')
        self.resizable(False, False)
        self.result = None

        labels = ['Name:', 'X (m):', 'Y (m):', 'Theta (deg):']
        defaults = ['waypoint', '0.0', '0.0', '0.0']
        self._entries = []
        for i, (lbl, val) in enumerate(zip(labels, defaults)):
            ttk.Label(self, text=lbl).grid(row=i, column=0, padx=8, pady=4, sticky='e')
            e = ttk.Entry(self, width=14)
            e.insert(0, val)
            e.grid(row=i, column=1, padx=8, pady=4)
            self._entries.append(e)

        btn_frame = ttk.Frame(self)
        btn_frame.grid(row=len(labels), column=0, columnspan=2, pady=8)
        ttk.Button(btn_frame, text='Create', command=self._ok).pack(side='left', padx=4)
        ttk.Button(btn_frame, text='Cancel', command=self.destroy).pack(side='left', padx=4)

        self.grab_set()
        self.wait_window()

    def _ok(self):
        try:
            name  = self._entries[0].get().strip()
            x     = float(self._entries[1].get())
            y     = float(self._entries[2].get())
            theta = math.radians(float(self._entries[3].get()))
            if not name:
                raise ValueError('Name is empty')
            self.result = (name, x, y, theta)
        except ValueError as e:
            messagebox.showerror('Input error', str(e), parent=self)
            return
        self.destroy()


# ---------------------------------------------------------------------------
# Main application
# ---------------------------------------------------------------------------

class HricGUI:

    REFRESH_MS = 500   # UI refresh interval

    def __init__(self, root: tk.Tk, node: HricNode):
        self.root  = root
        self.node  = node
        self._busy = False   # prevent overlapping service calls

        root.title('HRIC Robot Control Panel')
        root.resizable(True, True)

        style = ttk.Style()
        style.theme_use('clam')
        style.configure('TLabelframe.Label', font=('Arial', 10, 'bold'))
        style.configure('Header.TLabel', font=('Arial', 11, 'bold'))
        style.configure('Big.TButton', padding=6)
        style.configure('Mode.TButton', padding=4, width=8)

        self._build_ui()
        self._schedule_refresh()

    # ── UI construction ───────────────────────────────────────────────────

    def _build_ui(self):
        # Top-level notebook
        nb = ttk.Notebook(self.root)
        nb.pack(fill='both', expand=True, padx=8, pady=8)

        # ── Tab 1: Overview ───────────────────────────────────────────────
        tab_overview = ttk.Frame(nb, padding=6)
        nb.add(tab_overview, text='  Overview  ')
        self._build_overview(tab_overview)

        # ── Tab 2: Motion ─────────────────────────────────────────────────
        tab_motion = ttk.Frame(nb, padding=6)
        nb.add(tab_motion, text='  Motion  ')
        self._build_motion(tab_motion)

        # ── Tab 3: Navigation ─────────────────────────────────────────────
        tab_nav = ttk.Frame(nb, padding=6)
        nb.add(tab_nav, text='  Navigation  ')
        self._build_navigation(tab_nav)

        # ── Tab 4: Localization ───────────────────────────────────────────
        tab_loc = ttk.Frame(nb, padding=6)
        nb.add(tab_loc, text='  Localization  ')
        self._build_localization(tab_loc)

        # ── Tab 5: Markers ────────────────────────────────────────────────
        tab_markers = ttk.Frame(nb, padding=6)
        nb.add(tab_markers, text='  Markers  ')
        self._build_markers(tab_markers)

        # ── Status bar ────────────────────────────────────────────────────
        self._status_bar = tk.StringVar(value='Ready')
        bar = ttk.Label(self.root, textvariable=self._status_bar,
                        relief='sunken', anchor='w', padding=(6, 2))
        bar.pack(fill='x', side='bottom')

    # ── Overview tab ──────────────────────────────────────────────────────

    def _build_overview(self, parent):
        parent.columnconfigure(0, weight=1)
        parent.columnconfigure(1, weight=1)

        # Motion card
        self._ov_motion = StatusCard(parent, 'Motion')
        self._ov_motion.grid(row=0, column=0, sticky='nsew', padx=4, pady=4)
        self._ov_motion.add_row('Walk mode',   with_dot=True)
        self._ov_motion.add_row('Console ctrl')
        self._ov_motion.add_row('Arm swing')
        self._ov_motion.add_row('Vel X (m/s)')
        self._ov_motion.add_row('Vel Y (m/s)')
        self._ov_motion.add_row('Yaw rate')
        self._ov_motion.add_row('Error code')

        # Localization card
        self._ov_loc = StatusCard(parent, 'Localization (LiDAR)')
        self._ov_loc.grid(row=0, column=1, sticky='nsew', padx=4, pady=4)
        self._ov_loc.add_row('Status',      with_dot=True)
        self._ov_loc.add_row('Confidence')
        self._ov_loc.add_row('Error code')
        self._ov_loc.add_row('Pose X (m)')
        self._ov_loc.add_row('Pose Y (m)')
        self._ov_loc.add_row('Pose Z (m)')

        # Navigation card
        self._ov_nav = StatusCard(parent, 'Navigation')
        self._ov_nav.grid(row=1, column=0, sticky='nsew', padx=4, pady=4)
        self._ov_nav.add_row('Status',     with_dot=True)
        self._ov_nav.add_row('Error code')

        # Quick actions card
        qa = ttk.LabelFrame(parent, text='  Quick Actions  ', padding=8)
        qa.grid(row=1, column=1, sticky='nsew', padx=4, pady=4)

        modes = [
            ('Stop',  1, '#e74c3c'),
            ('Zero',  2, '#888888'),
            ('Stand', 3, '#27ae60'),
            ('Walk',  5, '#2980b9'),
            ('Run',   7, '#9b59b6'),
        ]
        for col, (label, mode, color) in enumerate(modes):
            btn = tk.Button(
                qa, text=label, bg=color, fg='white',
                relief='raised', padx=8, pady=6, font=('Arial', 9, 'bold'),
                activebackground=color,
                command=lambda m=mode: self._set_motion_mode(m),
            )
            btn.grid(row=0, column=col, padx=3, pady=4)

        ttk.Button(qa, text='Reloc (global)',
                   command=lambda: self._relocate(2)).grid(
            row=1, column=0, columnspan=2, sticky='ew', padx=3, pady=2)
        ttk.Button(qa, text='Reloc (local)',
                   command=lambda: self._relocate(1)).grid(
            row=1, column=2, columnspan=3, sticky='ew', padx=3, pady=2)
        ttk.Button(qa, text='Send Nav Goal …',
                   command=self._send_nav_goal).grid(
            row=2, column=0, columnspan=5, sticky='ew', padx=3, pady=2)

    # ── Motion tab ────────────────────────────────────────────────────────

    def _build_motion(self, parent):
        parent.columnconfigure(0, weight=1)
        parent.columnconfigure(1, weight=1)

        # Status card
        self._mot_card = StatusCard(parent, 'Live Motion Status')
        self._mot_card.grid(row=0, column=0, columnspan=2, sticky='ew', padx=4, pady=4)
        self._mot_card.add_row('Walk mode',     with_dot=True)
        self._mot_card.add_row('Console ctrl')
        self._mot_card.add_row('Arm swing')
        self._mot_card.add_row('Lin. vel X')
        self._mot_card.add_row('Lin. vel Y')
        self._mot_card.add_row('Lin. vel Z')
        self._mot_card.add_row('Ang. vel X')
        self._mot_card.add_row('Ang. vel Y')
        self._mot_card.add_row('Yaw rate (Z)')
        self._mot_card.add_row('Error code')

        # Mode buttons
        mode_frame = ttk.LabelFrame(parent, text='  Set Motion Mode  ', padding=8)
        mode_frame.grid(row=1, column=0, sticky='nsew', padx=4, pady=4)

        modes = [
            ('START (0)',  0),
            ('STOP  (1)',  1),
            ('ZERO  (2)',  2),
            ('STAND (3)',  3),
            ('WALK  (4)',  4),
            ('RUN   (5)',  7),
        ]
        self._swing_var = tk.BooleanVar(value=False)
        for i, (label, mode) in enumerate(modes):
            ttk.Button(
                mode_frame, text=label, style='Mode.TButton',
                command=lambda m=mode: self._set_motion_mode(m),
            ).grid(row=i // 2, column=i % 2, padx=4, pady=3, sticky='ew')

        ttk.Checkbutton(
            mode_frame, text='Arm swing (walk)', variable=self._swing_var,
        ).grid(row=3, column=0, columnspan=2, pady=(6, 0), sticky='w')

        # Predefined motion
        pred_frame = ttk.LabelFrame(parent, text='  Predefined Motion  ', padding=8)
        pred_frame.grid(row=1, column=1, sticky='nsew', padx=4, pady=4)

        ttk.Label(pred_frame, text='Motion #:').grid(row=0, column=0, sticky='e', padx=4)
        self._motion_number = tk.IntVar(value=1)
        spin = ttk.Spinbox(pred_frame, from_=1, to=99, width=6,
                           textvariable=self._motion_number)
        spin.grid(row=0, column=1, sticky='w', padx=4, pady=4)

        ttk.Button(pred_frame, text='Trigger motion',
                   command=self._trigger_motion).grid(
            row=1, column=0, columnspan=2, sticky='ew', pady=4)
        ttk.Button(pred_frame, text='Stop motion',
                   command=lambda: self._trigger_motion(enable=False)).grid(
            row=2, column=0, columnspan=2, sticky='ew', pady=2)

    # ── Navigation tab ────────────────────────────────────────────────────

    def _build_navigation(self, parent):
        parent.columnconfigure(0, weight=1)
        parent.columnconfigure(1, weight=1)

        self._nav_card = StatusCard(parent, 'Live Navigation Status')
        self._nav_card.grid(row=0, column=0, columnspan=2, sticky='ew', padx=4, pady=4)
        self._nav_card.add_row('Status',     with_dot=True)
        self._nav_card.add_row('Error code')

        # Goal panel
        goal_frame = ttk.LabelFrame(parent, text='  Send Goal  ', padding=8)
        goal_frame.grid(row=1, column=0, sticky='nsew', padx=4, pady=4)

        fields = [('X (m)', '0.0'), ('Y (m)', '0.0'), ('Yaw (deg)', '0.0')]
        self._nav_entries: list[ttk.Entry] = []
        for i, (lbl, val) in enumerate(fields):
            ttk.Label(goal_frame, text=lbl + ':').grid(
                row=i, column=0, sticky='e', padx=4, pady=3)
            e = ttk.Entry(goal_frame, width=10)
            e.insert(0, val)
            e.grid(row=i, column=1, sticky='w', padx=4, pady=3)
            self._nav_entries.append(e)

        self._nav_frame_var = tk.StringVar(value='map')
        ttk.Label(goal_frame, text='Frame:').grid(row=3, column=0, sticky='e', padx=4)
        ttk.Combobox(goal_frame, textvariable=self._nav_frame_var,
                     values=['map', 'base_link'], width=9,
                     state='readonly').grid(row=3, column=1, sticky='w', padx=4, pady=3)

        ttk.Button(goal_frame, text='Send Goal',
                   command=self._send_nav_goal_inline).grid(
            row=4, column=0, columnspan=2, sticky='ew', pady=6)

        # Waypoints panel (simple list)
        wp_frame = ttk.LabelFrame(parent, text='  Saved Markers → Nav Goals  ',
                                  padding=8)
        wp_frame.grid(row=1, column=1, sticky='nsew', padx=4, pady=4)

        self._nav_marker_list = tk.Listbox(wp_frame, height=8, width=24,
                                            selectmode='single')
        self._nav_marker_list.pack(side='left', fill='both', expand=True)
        sb = ttk.Scrollbar(wp_frame, orient='vertical',
                           command=self._nav_marker_list.yview)
        sb.pack(side='left', fill='y')
        self._nav_marker_list.config(yscrollcommand=sb.set)

        ttk.Button(wp_frame, text='Navigate to selected',
                   command=self._nav_to_selected_marker).pack(
            fill='x', pady=(4, 0))
        ttk.Button(wp_frame, text='Refresh markers',
                   command=self._refresh_markers).pack(fill='x', pady=2)

    # ── Localization tab ──────────────────────────────────────────────────

    def _build_localization(self, parent):
        parent.columnconfigure(0, weight=1)
        parent.columnconfigure(1, weight=1)

        self._loc_card = StatusCard(parent, 'Live Localization Status')
        self._loc_card.grid(row=0, column=0, columnspan=2, sticky='ew', padx=4, pady=4)
        self._loc_card.add_row('Status',      with_dot=True)
        self._loc_card.add_row('Confidence')
        self._loc_card.add_row('Error code')
        self._loc_card.add_row('Pose X (m)')
        self._loc_card.add_row('Pose Y (m)')
        self._loc_card.add_row('Pose Z (m)')
        self._loc_card.add_row('Frame ID')

        # LiDAR relocalization
        reloc_frame = ttk.LabelFrame(parent, text='  LiDAR Relocalization  ',
                                     padding=8)
        reloc_frame.grid(row=1, column=0, sticky='nsew', padx=4, pady=4)

        ttk.Button(reloc_frame, text='Global Match (auto)',
                   command=lambda: self._relocate(2)).pack(
            fill='x', pady=3)
        ttk.Button(reloc_frame, text='Local Match (current pose hint)',
                   command=lambda: self._relocate(1)).pack(
            fill='x', pady=3)

        # Visual localization
        vis_frame = ttk.LabelFrame(parent, text='  Visual Localization Mode  ',
                                   padding=8)
        vis_frame.grid(row=1, column=1, sticky='nsew', padx=4, pady=4)

        modes = [
            ('Idle (0)',           0),
            ('Odometry only (1)',  1),
            ('Map refine (2)',     2),
            ('Map loc (3)',        3),
        ]
        for label, mode in modes:
            ttk.Button(
                vis_frame, text=label,
                command=lambda m=mode: self._set_visual_loc(m),
            ).pack(fill='x', pady=2)

    # ── Markers tab ───────────────────────────────────────────────────────

    def _build_markers(self, parent):
        parent.columnconfigure(0, weight=1)
        parent.columnconfigure(1, weight=1)

        # Markers list
        list_frame = ttk.LabelFrame(parent, text='  Stored Markers  ', padding=8)
        list_frame.grid(row=0, column=0, rowspan=2, sticky='nsew', padx=4, pady=4)
        list_frame.rowconfigure(0, weight=1)
        list_frame.columnconfigure(0, weight=1)

        cols = ('name', 'x', 'y', 'theta', 'map')
        self._marker_tree = ttk.Treeview(list_frame, columns=cols,
                                          show='headings', height=14)
        for col, hdr, w in zip(cols, ('Name', 'X', 'Y', 'Theta', 'Map'),
                               (120, 60, 60, 60, 80)):
            self._marker_tree.heading(col, text=hdr)
            self._marker_tree.column(col, width=w, anchor='center')
        self._marker_tree.grid(row=0, column=0, sticky='nsew')
        vsb = ttk.Scrollbar(list_frame, orient='vertical',
                            command=self._marker_tree.yview)
        vsb.grid(row=0, column=1, sticky='ns')
        self._marker_tree.configure(yscrollcommand=vsb.set)

        ttk.Button(list_frame, text='Refresh list',
                   command=self._refresh_markers).grid(
            row=1, column=0, columnspan=2, sticky='ew', pady=(4, 0))

        # Operations
        ops_frame = ttk.LabelFrame(parent, text='  Operations  ', padding=8)
        ops_frame.grid(row=0, column=1, sticky='nsew', padx=4, pady=4)

        ttk.Button(ops_frame, text='Mark HERE (current pose)',
                   command=self._mark_here).pack(fill='x', pady=3)
        ttk.Button(ops_frame, text='Mark at Pose …',
                   command=self._mark_at_pose).pack(fill='x', pady=3)
        ttk.Button(ops_frame, text='Delete selected marker',
                   command=self._delete_marker).pack(fill='x', pady=3)
        ttk.Separator(ops_frame, orient='horizontal').pack(fill='x', pady=6)
        ttk.Button(ops_frame, text='Navigate to selected',
                   command=self._nav_to_selected_marker).pack(fill='x', pady=3)

    # ── Periodic refresh ──────────────────────────────────────────────────

    def _schedule_refresh(self):
        self._refresh_status()
        self.root.after(self.REFRESH_MS, self._schedule_refresh)

    def _refresh_status(self):
        self._update_motion()
        self._update_loc()
        self._update_nav()

    def _update_motion(self):
        m = self.node.motion_status
        if m is None:
            return

        mode_name  = WALK_MODE_NAMES.get(m.walk_mode, str(m.walk_mode))
        mode_color = WALK_MODE_COLORS.get(m.walk_mode, '#888888')

        for card in (self._ov_motion, self._mot_card):
            card.set('Walk mode', mode_name, dot_color=mode_color)
            card.set('Console ctrl', 'yes' if m.is_console_control else 'no')
            card.set('Arm swing',    'yes' if m.is_swing_arm else 'no')
            card.set('Error code', str(m.error_code))

        self._ov_motion.set('Vel X (m/s)', f'{m.velocity.linear.x:.3f}')
        self._ov_motion.set('Vel Y (m/s)', f'{m.velocity.linear.y:.3f}')
        self._ov_motion.set('Yaw rate',    f'{m.velocity.angular.z:.3f}')

        self._mot_card.set('Lin. vel X',  f'{m.velocity.linear.x:.3f}')
        self._mot_card.set('Lin. vel Y',  f'{m.velocity.linear.y:.3f}')
        self._mot_card.set('Lin. vel Z',  f'{m.velocity.linear.z:.3f}')
        self._mot_card.set('Ang. vel X',  f'{m.velocity.angular.x:.3f}')
        self._mot_card.set('Ang. vel Y',  f'{m.velocity.angular.y:.3f}')
        self._mot_card.set('Yaw rate (Z)', f'{m.velocity.angular.z:.3f}')

    def _update_loc(self):
        l = self.node.loc_status
        if l is None:
            return

        st_name  = LOC_STATUS_NAMES.get(l.status, str(l.status))
        st_color = LOC_STATUS_COLORS.get(l.status, '#888888')
        err_name = LOC_ERROR_NAMES.get(l.error_code, str(l.error_code))

        for card in (self._ov_loc, self._loc_card):
            card.set('Status',      st_name, dot_color=st_color)
            card.set('Confidence',  f'{l.confidence:.3f}')
            card.set('Error code',  err_name)

        for card in (self._ov_loc, self._loc_card):
            try:
                pos = l.pose.pose.position
                card.set('Pose X (m)', f'{pos.x:.3f}')
                card.set('Pose Y (m)', f'{pos.y:.3f}')
                card.set('Pose Z (m)', f'{pos.z:.3f}')
            except Exception:
                pass

        try:
            self._loc_card.set('Frame ID', l.pose.header.frame_id or '—')
        except Exception:
            pass

    def _update_nav(self):
        n = self.node.nav_status
        if n is None:
            return

        st_name  = NAV_STATUS_NAMES.get(n.status, str(n.status))
        st_color = NAV_STATUS_COLORS.get(n.status, '#888888')
        err_name = NAV_ERROR_NAMES.get(n.error_code, str(n.error_code))

        for card in (self._ov_nav, self._nav_card):
            card.set('Status',     st_name, dot_color=st_color)
            card.set('Error code', err_name)

    # ── Action handlers ───────────────────────────────────────────────────

    def _run_async(self, fn, *args, success_msg: str = 'Done.',
                   on_done=None, **kwargs):
        """Run a blocking service call in a daemon thread."""
        if self._busy:
            self._set_status('Busy — please wait …')
            return
        self._busy = True
        self._set_status('Calling service …')

        def _worker():
            result, err = fn(*args, **kwargs)
            if err:
                self.root.after(0, lambda: self._set_status(f'Error: {err}'))
            elif result is not None and hasattr(result, 'success') \
                    and not result.success:
                msg = getattr(result, 'message', 'unknown reason')
                self.root.after(0, lambda: self._set_status(f'Failed: {msg}'))
            else:
                self.root.after(0, lambda: self._set_status(success_msg))
            if on_done:
                self.root.after(0, on_done)
            self._busy = False

        t = threading.Thread(target=_worker, daemon=True)
        t.start()

    def _set_status(self, msg: str):
        self._status_bar.set(msg)

    def _set_motion_mode(self, mode: int):
        swing = self._swing_var.get() if mode in (4, 5) else False
        name  = WALK_MODE_NAMES.get(mode, str(mode))
        self._run_async(
            self.node.call_set_motion_mode, mode, swing,
            success_msg=f'Motion mode → {name}',
        )

    def _trigger_motion(self, enable: bool = True):
        number = self._motion_number.get()
        self._run_async(
            self.node.call_set_motion_number, number, enable,
            success_msg=f'Motion #{number} {"started" if enable else "stopped"}',
        )

    def _relocate(self, match_type: int):
        label = 'global' if match_type == 2 else 'local'
        self._run_async(
            self.node.call_relocate, match_type,
            success_msg=f'Relocalization ({label}) triggered',
        )

    def _set_visual_loc(self, mode: int):
        modes = {0: 'Idle', 1: 'Odometry', 2: 'Map refine', 3: 'Map loc'}
        self._run_async(
            self.node.call_set_visual_loc_mode, mode,
            success_msg=f'Visual loc mode → {modes.get(mode, mode)}',
        )

    def _send_nav_goal(self):
        dlg = GoalDialog(self.root)
        if dlg.result is None:
            return
        x, y, yaw, frame = dlg.result
        self._run_async(
            self.node.call_set_goal, x, y, yaw, frame,
            success_msg=f'Goal sent: ({x:.2f}, {y:.2f}) [{frame}]',
        )

    def _send_nav_goal_inline(self):
        try:
            x     = float(self._nav_entries[0].get())
            y     = float(self._nav_entries[1].get())
            yaw   = math.radians(float(self._nav_entries[2].get()))
            frame = self._nav_frame_var.get()
        except ValueError:
            messagebox.showerror('Input error', 'Enter valid numbers.')
            return
        self._run_async(
            self.node.call_set_goal, x, y, yaw, frame,
            success_msg=f'Goal sent: ({x:.2f}, {y:.2f}) [{frame}]',
        )

    def _refresh_markers(self):
        def _done():
            self._populate_marker_tree()
            self._populate_nav_marker_list()
            self._set_status(f'Markers refreshed ({len(self.node.markers)} found)')

        self._run_async(
            self.node.call_list_markers,
            success_msg='',
            on_done=_done,
        )

    def _populate_marker_tree(self):
        for row in self._marker_tree.get_children():
            self._marker_tree.delete(row)
        for m in self.node.markers:
            self._marker_tree.insert(
                '', 'end',
                values=(m.name,
                        f'{m.pose.x:.2f}',
                        f'{m.pose.y:.2f}',
                        f'{math.degrees(m.pose.theta):.1f}°',
                        m.map_id or '—'),
            )

    def _populate_nav_marker_list(self):
        self._nav_marker_list.delete(0, 'end')
        for m in self.node.markers:
            self._nav_marker_list.insert(
                'end', f'{m.name}  ({m.pose.x:.1f}, {m.pose.y:.1f})'
            )

    def _mark_here(self):
        name = simpledialog.askstring(
            'Mark Here', 'Marker name:', parent=self.root
        )
        if not name:
            return
        self._run_async(
            self.node.call_mark_here, name.strip(),
            success_msg=f'Marker "{name}" created at current pose',
            on_done=self._refresh_markers,
        )

    def _mark_at_pose(self):
        dlg = MarkAtPoseDialog(self.root)
        if dlg.result is None:
            return
        name, x, y, theta = dlg.result
        self._run_async(
            self.node.call_mark_at_pose, name, x, y, theta,
            success_msg=f'Marker "{name}" created at ({x:.2f}, {y:.2f})',
            on_done=self._refresh_markers,
        )

    def _delete_marker(self):
        sel = self._marker_tree.selection()
        if not sel:
            messagebox.showinfo('No selection', 'Select a marker first.')
            return
        name = self._marker_tree.item(sel[0])['values'][0]
        if not messagebox.askyesno('Confirm delete',
                                   f'Delete marker "{name}"?'):
            return
        self._run_async(
            self.node.call_operate_marker, name,
            success_msg=f'Marker "{name}" deleted',
            on_done=self._refresh_markers,
        )

    def _nav_to_selected_marker(self):
        # Check marker tree first, then nav list
        sel_tree = self._marker_tree.selection()
        sel_nav  = self._nav_marker_list.curselection()

        marker: MarkerInfo | None = None
        if sel_tree:
            name = self._marker_tree.item(sel_tree[0])['values'][0]
            marker = next((m for m in self.node.markers if m.name == name), None)
        elif sel_nav:
            idx = sel_nav[0]
            if idx < len(self.node.markers):
                marker = self.node.markers[idx]

        if marker is None:
            messagebox.showinfo('No selection', 'Select a marker first.')
            return

        self._run_async(
            self.node.call_set_goal,
            float(marker.pose.x), float(marker.pose.y),
            float(marker.pose.theta), 'map',
            success_msg=f'Navigating to marker "{marker.name}"',
        )


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main():
    rclpy.init()
    node = HricNode()

    # Spin ROS in a background thread
    ros_thread = threading.Thread(
        target=rclpy.spin, args=(node,), daemon=True
    )
    ros_thread.start()

    root = tk.Tk()
    app = HricGUI(root, node)  # noqa: F841

    try:
        root.mainloop()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
