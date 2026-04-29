#!/usr/bin/env python3
"""
remoty.py — Tkinter GUI remote control for Walker Tienkung robot.
Publishes SbusData messages to /sbus_data/event topic at 20 Hz.

Layout:
  - Push Buttons A-D  (press-and-hold)
  - Toggle Keys E-H   (3-way radio buttons)
  - Left / Right joystick canvas widgets
  - Status bar showing current values
"""
import tkinter as tk
from tkinter import ttk

import threading

import rclpy
from rclpy.node import Node
from bodyctrl_msgs.msg import SbusData
from std_msgs.msg import Header
from hric_msgs.srv import SetMotionMode, SetMotionNumber


# ---------------------------------------------------------------------------
# Key-event constants (mirror SbusData message constants)
# ---------------------------------------------------------------------------
KEY_NONE   = 0
KEY_A_UP   = 1;  KEY_A_DOWN  = 2
KEY_B_UP   = 3;  KEY_B_DOWN  = 4
KEY_C_UP   = 5;  KEY_C_DOWN  = 6
KEY_D_UP   = 7;  KEY_D_DOWN  = 8
KEY_E_UP   = 9;  KEY_E_MID   = 10; KEY_E_DOWN  = 11
KEY_F_UP   = 12; KEY_F_MID   = 13; KEY_F_DOWN  = 14
KEY_G_LEFT = 15; KEY_G_MID   = 16; KEY_G_RIGHT = 17
KEY_H_LEFT = 18; KEY_H_MID   = 19; KEY_H_RIGHT = 20

# int8 value (-1 / 0 / 1) → key-event constant for 3-way keys
# E / F:  -1=up,    0=mid, +1=down
# G:      -1=left,  0=mid, +1=right
# H:      -1=right, 0=mid, +1=left   (H axis is reversed per spec)
_E_KEY = {-1: KEY_E_UP,    0: KEY_E_MID,  1: KEY_E_DOWN}
_F_KEY = {-1: KEY_F_UP,    0: KEY_F_MID,  1: KEY_F_DOWN}
_G_KEY = {-1: KEY_G_LEFT,  0: KEY_G_MID,  1: KEY_G_RIGHT}
_H_KEY = {-1: KEY_H_RIGHT, 0: KEY_H_MID,  1: KEY_H_LEFT}


# ---------------------------------------------------------------------------
# Joystick canvas widget
# ---------------------------------------------------------------------------
class JoystickCanvas(tk.Canvas):
    """Click-and-drag 2-D joystick.  Snaps back to centre on release."""

    RADIUS = 70
    HANDLE_R = 12

    def __init__(self, parent, label: str, on_change, **kwargs):
        size = self.RADIUS * 2 + 10
        super().__init__(parent, width=size, height=size + 22, **kwargs)
        self._on_change = on_change
        self._cx = self.RADIUS + 5
        self._cy = self.RADIUS + 5
        self._dragging = False

        # Background circle
        self.create_oval(
            self._cx - self.RADIUS, self._cy - self.RADIUS,
            self._cx + self.RADIUS, self._cy + self.RADIUS,
            fill='#e8e8e8', outline='#999', width=2,
        )
        # Cross-hairs
        self.create_line(
            self._cx - self.RADIUS, self._cy,
            self._cx + self.RADIUS, self._cy, fill='#bbb',
        )
        self.create_line(
            self._cx, self._cy - self.RADIUS,
            self._cx, self._cy + self.RADIUS, fill='#bbb',
        )
        # Label
        self.create_text(self._cx, size + 11, text=label, font=('Arial', 9))
        # Draggable handle
        self._handle = self.create_oval(
            self._cx - self.HANDLE_R, self._cy - self.HANDLE_R,
            self._cx + self.HANDLE_R, self._cy + self.HANDLE_R,
            fill='#4488ff', outline='#2266cc', width=2,
        )

        self.bind('<ButtonPress-1>',   self._on_press)
        self.bind('<B1-Motion>',       self._on_drag)
        self.bind('<ButtonRelease-1>', self._on_release)

    def _clamp(self, dx: float, dy: float):
        dist = (dx ** 2 + dy ** 2) ** 0.5
        if dist > self.RADIUS:
            scale = self.RADIUS / dist
            dx *= scale
            dy *= scale
        return dx, dy

    def _move_handle(self, x: float, y: float):
        dx, dy = self._clamp(x - self._cx, y - self._cy)
        hx = self._cx + dx
        hy = self._cy + dy
        self.coords(
            self._handle,
            hx - self.HANDLE_R, hy - self.HANDLE_R,
            hx + self.HANDLE_R, hy + self.HANDLE_R,
        )
        vx =  dx / self.RADIUS          # right = +1
        vy = -dy / self.RADIUS          # up    = +1  (canvas Y is inverted)
        self._on_change(vx, vy)

    def _on_press(self, event):
        self._dragging = True
        self._move_handle(event.x, event.y)

    def _on_drag(self, event):
        if self._dragging:
            self._move_handle(event.x, event.y)

    def _on_release(self, event):
        self._dragging = False
        self._move_handle(self._cx, self._cy)   # snap to centre


# ---------------------------------------------------------------------------
# Main application / ROS node
# ---------------------------------------------------------------------------
class RemoteControlGUI(Node):

    def __init__(self):
        super().__init__('remoty')

        self.pub = self.create_publisher(SbusData, '/sbus_data/event', 10)

        # Current output state
        self._button_a: int   = -1   # -1=release, 1=press
        self._button_b: int   = -1
        self._button_c: int   = -1
        self._button_d: int   = -1
        self._button_e: int   =  0   # -1=up,    0=mid, 1=down
        self._button_f: int   =  0
        self._button_g: int   =  0   # -1=left,  0=mid, 1=right
        self._button_h: int   =  0   # -1=right, 0=mid, 1=left
        self._x1: float       =  0.0
        self._y1: float       =  0.0
        self._x2: float       =  0.0
        self._y2: float       =  0.0
        self._key_event_new: int = KEY_NONE
        self._key_event_old: int = KEY_NONE

        self.timer = self.create_timer(0.05, self._publish)   # 20 Hz

        self._motion_client = self.create_client(
            SetMotionMode, '/hric/motion/set_motion_mode'
        )
        self._action_client = self.create_client(
            SetMotionNumber, '/hric/motion/set_motion_number'
        )

        self._build_gui()

    # ------------------------------------------------------------------
    # GUI construction
    # ------------------------------------------------------------------
    def _build_gui(self):
        self.root = tk.Tk()
        self.root.title('Robot Remote Control — remoty')
        self.root.resizable(False, False)

        pad = dict(padx=8, pady=4)

        # ── Push Buttons A-D ───────────────────────────────────────────
        btn_frame = ttk.LabelFrame(self.root, text='Push Buttons')
        btn_frame.grid(row=0, column=0, columnspan=2, sticky='ew', **pad)

        self._btn_widgets: dict[str, tk.Button] = {}
        for col, name in enumerate('ABCD'):
            btn = tk.Button(
                btn_frame, text=f'  {name}  ', width=6,
                bg='#cccccc', relief='raised',
            )
            btn.grid(row=0, column=col, padx=10, pady=8)
            btn.bind('<ButtonPress-1>',   lambda e, n=name: self._btn_press(n))
            btn.bind('<ButtonRelease-1>', lambda e, n=name: self._btn_release(n))
            self._btn_widgets[name] = btn

        # ── 3-way Toggle Keys E-H ──────────────────────────────────────
        tog_frame = ttk.LabelFrame(self.root, text='Toggle Keys')
        tog_frame.grid(row=1, column=0, columnspan=2, sticky='ew', **pad)

        self._e_var = tk.IntVar(value=0)
        self._f_var = tk.IntVar(value=0)
        self._g_var = tk.IntVar(value=0)
        self._h_var = tk.IntVar(value=0)

        self._add_3way(tog_frame, 'E', self._e_var,
                       ('Up', 'Mid', 'Down'), (-1, 0, 1), self._on_e_change, col=0)
        self._add_3way(tog_frame, 'F', self._f_var,
                       ('Up', 'Mid', 'Down'), (-1, 0, 1), self._on_f_change, col=1)
        self._add_3way(tog_frame, 'G', self._g_var,
                       ('Left', 'Mid', 'Right'), (-1, 0, 1), self._on_g_change, col=2)
        self._add_3way(tog_frame, 'H', self._h_var,
                       ('Right', 'Mid', 'Left'), (-1, 0, 1), self._on_h_change, col=3)

        # ── Joysticks ──────────────────────────────────────────────────
        joy_frame = ttk.LabelFrame(self.root, text='Joysticks')
        joy_frame.grid(row=2, column=0, columnspan=2, sticky='ew', **pad)

        self._joy_left = JoystickCanvas(
            joy_frame, 'Left  (x1, y1)', self._on_left_joy, bg='#f4f4f4')
        self._joy_left.grid(row=0, column=0, padx=24, pady=10)

        self._joy_right = JoystickCanvas(
            joy_frame, 'Right (x2, y2)', self._on_right_joy, bg='#f4f4f4')
        self._joy_right.grid(row=0, column=1, padx=24, pady=10)

        # ── Motion Control ─────────────────────────────────────────────
        motion_frame = ttk.LabelFrame(self.root, text='Motion Control')
        motion_frame.grid(row=3, column=0, columnspan=2, sticky='ew', **pad)

        motion_modes = [
            ('Stop',  1, '#e05555'),
            ('Zero',  2, '#e09955'),
            ('Stand', 3, '#5599e0'),
            ('Walk',  4, '#55aa55'),
            ('Run',   5, '#aa55cc'),
        ]
        self._motion_status_var = tk.StringVar(value='motion: —')
        for col, (label, mode, colour) in enumerate(motion_modes):
            btn = tk.Button(
                motion_frame, text=label, width=7,
                bg=colour, fg='white', font=('Arial', 9, 'bold'),
                relief='raised', activebackground=colour,
                command=lambda m=mode, l=label: self._call_motion_mode(m, l),
            )
            btn.grid(row=0, column=col, padx=6, pady=8)
        tk.Label(
            motion_frame, textvariable=self._motion_status_var,
            font=('Courier', 8), anchor='w',
        ).grid(row=1, column=0, columnspan=5, sticky='w', padx=6, pady=(0, 4))

        # ── Custom Actions ─────────────────────────────────────────────
        action_frame = ttk.LabelFrame(self.root, text='Custom Actions (stand + E-up required)')
        action_frame.grid(row=4, column=0, columnspan=2, sticky='ew', **pad)

        action_labels = ['Wave', 'Action 2', 'Action 3', 'Action 4', 'Action 5']
        self._action_status_var = tk.StringVar(value='action: —')
        for col, label in enumerate(action_labels):
            btn = tk.Button(
                action_frame, text=label, width=8,
                bg='#557788', fg='white', font=('Arial', 9, 'bold'),
                relief='raised', activebackground='#557788',
                command=lambda n=col + 1, l=label: self._call_motion_number(n, l),
            )
            btn.grid(row=0, column=col, padx=6, pady=8)
        tk.Label(
            action_frame, textvariable=self._action_status_var,
            font=('Courier', 8), anchor='w',
        ).grid(row=1, column=0, columnspan=5, sticky='w', padx=6, pady=(0, 4))

        # ── Status bar ─────────────────────────────────────────────────
        self._status_var = tk.StringVar(value='')
        tk.Label(
            self.root, textvariable=self._status_var,
            font=('Courier', 8), anchor='w', bg='#e8e8e8', relief='sunken',
        ).grid(row=5, column=0, columnspan=2, sticky='ew', padx=4, pady=(0, 4))

        self.root.after(200, self._refresh_status)

    def _add_3way(self, parent, label, var, texts, values, callback, col):
        f = tk.Frame(parent)
        f.grid(row=0, column=col, padx=12, pady=6)
        tk.Label(f, text=f'Key {label}', font=('Arial', 9, 'bold')).pack()
        for text, val in zip(texts, values):
            tk.Radiobutton(
                f, text=text, variable=var, value=val,
                command=lambda v=val: callback(v),
            ).pack(anchor='w')

    def _refresh_status(self):
        self._status_var.set(
            f'A={self._button_a:+d} B={self._button_b:+d} '
            f'C={self._button_c:+d} D={self._button_d:+d}   '
            f'E={self._button_e:+d} F={self._button_f:+d} '
            f'G={self._button_g:+d} H={self._button_h:+d}   '
            f'L({self._x1:+.2f},{self._y1:+.2f}) '
            f'R({self._x2:+.2f},{self._y2:+.2f})'
        )
        self.root.after(200, self._refresh_status)

    # ------------------------------------------------------------------
    # Button A-D handlers
    # ------------------------------------------------------------------
    _KEY_UP   = (KEY_A_UP,   KEY_B_UP,   KEY_C_UP,   KEY_D_UP)
    _KEY_DOWN = (KEY_A_DOWN, KEY_B_DOWN, KEY_C_DOWN, KEY_D_DOWN)

    def _btn_press(self, name: str):
        idx = 'ABCD'.index(name)
        self._key_event_old = self._KEY_UP[idx]
        self._key_event_new = self._KEY_DOWN[idx]
        setattr(self, f'_button_{name.lower()}', 1)
        self._btn_widgets[name].config(bg='#4488ff', relief='sunken')

    def _btn_release(self, name: str):
        idx = 'ABCD'.index(name)
        self._key_event_old = self._KEY_DOWN[idx]
        self._key_event_new = self._KEY_UP[idx]
        setattr(self, f'_button_{name.lower()}', -1)
        self._btn_widgets[name].config(bg='#cccccc', relief='raised')

    # ------------------------------------------------------------------
    # Toggle E-H handlers
    # ------------------------------------------------------------------
    def _on_e_change(self, val: int):
        self._key_event_old = _E_KEY[self._button_e]
        self._button_e = val
        self._key_event_new = _E_KEY[val]

    def _on_f_change(self, val: int):
        self._key_event_old = _F_KEY[self._button_f]
        self._button_f = val
        self._key_event_new = _F_KEY[val]

    def _on_g_change(self, val: int):
        self._key_event_old = _G_KEY[self._button_g]
        self._button_g = val
        self._key_event_new = _G_KEY[val]

    def _on_h_change(self, val: int):
        self._key_event_old = _H_KEY[self._button_h]
        self._button_h = val
        self._key_event_new = _H_KEY[val]

    # ------------------------------------------------------------------
    # Joystick handlers
    # ------------------------------------------------------------------
    def _on_left_joy(self, x: float, y: float):
        self._x1 = round(x, 4)
        self._y1 = round(y, 4)

    def _on_right_joy(self, x: float, y: float):
        self._x2 = round(x, 4)
        self._y2 = round(y, 4)

    # ------------------------------------------------------------------
    # Motion mode service call
    # ------------------------------------------------------------------
    def _call_motion_mode(self, mode: int, label: str):
        if not self._motion_client.service_is_ready():
            self._motion_status_var.set(f'motion: service not available')
            return
        self._motion_status_var.set(f'motion: calling {label}…')
        req = SetMotionMode.Request()
        req.walk_mode_request = mode
        req.is_need_swing_arm = False
        # Call in a background thread so the GUI/spin loop is not blocked
        threading.Thread(target=self._do_service_call,
                         args=(req, label), daemon=True).start()

    def _do_service_call(self, req: SetMotionMode.Request, label: str):
        future = self._motion_client.call_async(req)
        # Spin until done (runs in background thread, safe)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.done():
            resp = future.result()
            if resp is not None and resp.sucess:
                result_text = f'motion: {label} OK'
            elif resp is not None:
                result_text = f'motion: {label} failed (err={resp.error_code})'
            else:
                result_text = f'motion: {label} timeout'
        else:
            result_text = f'motion: {label} timeout'
        # Update the label from the main thread
        self.root.after(0, lambda: self._motion_status_var.set(result_text))

    # ------------------------------------------------------------------
    # Custom action service call
    # ------------------------------------------------------------------
    def _call_motion_number(self, number: int, label: str):
        if not self._action_client.service_is_ready():
            self._action_status_var.set('action: service not available')
            return
        self._action_status_var.set(f'action: calling {label}…')
        req = SetMotionNumber.Request()
        req.is_motion = True
        req.motion_number = number
        threading.Thread(target=self._do_action_call,
                         args=(req, label), daemon=True).start()

    def _do_action_call(self, req: SetMotionNumber.Request, label: str):
        future = self._action_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.done():
            resp = future.result()
            if resp is not None and resp.sucess:
                result_text = f'action: {label} OK'
            elif resp is not None:
                result_text = f'action: {label} failed'
            else:
                result_text = f'action: {label} timeout'
        else:
            result_text = f'action: {label} timeout'
        self.root.after(0, lambda: self._action_status_var.set(result_text))

    # ------------------------------------------------------------------
    # ROS publishing
    # ------------------------------------------------------------------
    def _publish(self):
        msg = SbusData()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.key_event_new = self._key_event_new
        msg.key_event_old = self._key_event_old
        msg.button_a = self._button_a
        msg.button_b = self._button_b
        msg.button_c = self._button_c
        msg.button_d = self._button_d
        msg.button_e = self._button_e
        msg.button_f = self._button_f
        msg.button_g = self._button_g
        msg.button_h = self._button_h
        msg.x1 = self._x1
        msg.y1 = self._y1
        msg.x2 = self._x2
        msg.y2 = self._y2
        self.pub.publish(msg)
        # Key events are edge-triggered; reset to NONE after each publish cycle
        self._key_event_new = KEY_NONE
        self._key_event_old = KEY_NONE

    # ------------------------------------------------------------------
    # Main loop
    # ------------------------------------------------------------------
    def spin(self):
        while rclpy.ok():
            self.root.update()
            rclpy.spin_once(self, timeout_sec=0.0)


def main():
    rclpy.init()
    node = RemoteControlGUI()
    try:
        node.spin()
    except tk.TclError:
        pass   # window was closed
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
