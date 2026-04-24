#!/usr/bin/env python3
"""
Interactive ROS2 Remote Explorer
Connects to remote ROS2 robot and provides TUI for exploring topics, nodes, and services.
"""

import curses
import subprocess
import threading
import queue
import sys
import time
import argparse
from typing import List, Tuple, Optional

# SSH Configuration
SSH_HOST = "192.168.41.1"
SSH_USER = "ubuntu"
SSH_PASS = "123"

# Nvidia target (set by command line args)
NVIDIA_HOST = None
NVIDIA_USER = "nvidia"

class ROS2RemoteExplorer:
    def __init__(self):
        self.current_view = "topics"  # topics, nodes, services
        self.topics = []
        self.nodes = []
        self.services = []
        self.current_index = 0
        self.echo_running = False
        self.echo_queue = queue.Queue()
        self.echo_thread = None
        self.echo_process = None
        
    def execute_ssh_command(self, command: str) -> List[str]:
        """Execute command on remote machine via SSH"""
        # Build the ROS2 command
        ros_cmd = f"bash -c 'source /opt/ros/humble/setup.bash 2>/dev/null || source /opt/ros/foxy/setup.bash 2>/dev/null || true; {command}'"
        
        # If nvidia host is specified, tunnel through ubuntu to nvidia
        if NVIDIA_HOST:
            inner_ssh = f"ssh -o StrictHostKeyChecking=no {NVIDIA_USER}@{NVIDIA_HOST} \"{ros_cmd}\""
            ssh_cmd = [
                "sshpass", "-p", SSH_PASS,
                "ssh", "-o", "StrictHostKeyChecking=no",
                f"{SSH_USER}@{SSH_HOST}",
                inner_ssh
            ]
        else:
            ssh_cmd = [
                "sshpass", "-p", SSH_PASS,
                "ssh", "-o", "StrictHostKeyChecking=no",
                f"{SSH_USER}@{SSH_HOST}",
                ros_cmd
            ]
        
        try:
            result = subprocess.run(
                ssh_cmd,
                capture_output=True,
                text=True,
                timeout=10
            )
            if result.returncode == 0:
                return [line.strip() for line in result.stdout.strip().split('\n') if line.strip()]
            return []
        except subprocess.TimeoutExpired:
            return ["Error: Command timeout"]
        except Exception as e:
            return [f"Error: {str(e)}"]
    
    def refresh_topics(self):
        """Fetch list of topics from remote"""
        self.topics = self.execute_ssh_command("ros2 topic list")
        if not self.topics:
            self.topics = ["No topics found"]
    
    def refresh_nodes(self):
        """Fetch list of nodes from remote"""
        self.nodes = self.execute_ssh_command("ros2 node list")
        if not self.nodes:
            self.nodes = ["No nodes found"]
    
    def refresh_services(self):
        """Fetch list of services from remote"""
        self.services = self.execute_ssh_command("ros2 service list")
        if not self.services:
            self.services = ["No services found"]
    
    def get_current_list(self) -> List[str]:
        """Get the current list based on view"""
        if self.current_view == "topics":
            return self.topics
        elif self.current_view == "nodes":
            return self.nodes
        else:
            return self.services
    
    def get_current_item(self) -> Optional[str]:
        """Get currently selected item"""
        items = self.get_current_list()
        if 0 <= self.current_index < len(items):
            return items[self.current_index]
        return None
    
    def echo_topic_thread(self, topic: str):
        """Thread function to echo topic messages"""
        # Build the ROS2 command
        ros_cmd = f"bash -c 'source /opt/ros/humble/setup.bash 2>/dev/null || source /opt/ros/foxy/setup.bash 2>/dev/null || true; ros2 topic echo {topic}'"
        
        # If nvidia host is specified, tunnel through ubuntu to nvidia
        if NVIDIA_HOST:
            inner_ssh = f"ssh -o StrictHostKeyChecking=no {NVIDIA_USER}@{NVIDIA_HOST} \"{ros_cmd}\""
            ssh_cmd = [
                "sshpass", "-p", SSH_PASS,
                "ssh", "-o", "StrictHostKeyChecking=no",
                f"{SSH_USER}@{SSH_HOST}",
                inner_ssh
            ]
        else:
            ssh_cmd = [
                "sshpass", "-p", SSH_PASS,
                "ssh", "-o", "StrictHostKeyChecking=no",
                f"{SSH_USER}@{SSH_HOST}",
                ros_cmd
            ]
        
        try:
            self.echo_process = subprocess.Popen(
                ssh_cmd,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                bufsize=1
            )
            
            while self.echo_running and self.echo_process:
                line = self.echo_process.stdout.readline()
                if line:
                    self.echo_queue.put(line.rstrip())
                elif self.echo_process.poll() is not None:
                    break
            
            if self.echo_process:
                self.echo_process.terminate()
                try:
                    self.echo_process.wait(timeout=2)
                except subprocess.TimeoutExpired:
                    self.echo_process.kill()
                self.echo_process = None
        except Exception as e:
            self.echo_queue.put(f"Error: {str(e)}")
            self.echo_process = None
    
    def get_topic_info(self, topic: str) -> List[str]:
        """Get topic info"""
        return self.execute_ssh_command(f"ros2 topic info {topic}")
    
    def get_topic_type(self, topic: str) -> List[str]:
        """Get topic type"""
        result = self.execute_ssh_command(f"ros2 topic info -t {topic}")
        return result
    
    def get_node_info(self, node: str) -> List[str]:
        """Get node info"""
        return self.execute_ssh_command(f"ros2 node info {node}")
    
    def get_service_type(self, service: str) -> List[str]:
        """Get service type"""
        return self.execute_ssh_command(f"ros2 service type {service}")
    
    def call_service(self, service: str) -> List[str]:
        """Call service (empty request)"""
        return self.execute_ssh_command(f"ros2 service call {service} '{{}}'")


def draw_header(stdscr, explorer: ROS2RemoteExplorer, height: int, width: int):
    """Draw header with view tabs"""
    stdscr.attron(curses.color_pair(1))
    stdscr.addstr(0, 0, " " * width)
    
    if NVIDIA_HOST:
        title = f" ROS2 Remote Explorer - {SSH_USER}@{SSH_HOST} -> {NVIDIA_USER}@{NVIDIA_HOST} "
    else:
        title = f" ROS2 Remote Explorer - {SSH_USER}@{SSH_HOST} "
    stdscr.addstr(0, 2, title[:width-4], curses.color_pair(1) | curses.A_BOLD)
    
    # View tabs
    tab_y = 1
    tabs = ["Topics", "Nodes", "Services"]
    views = ["topics", "nodes", "services"]
    x_pos = 2
    
    stdscr.addstr(tab_y, 0, " " * width)
    for tab, view in zip(tabs, views):
        if explorer.current_view == view:
            stdscr.addstr(tab_y, x_pos, f"[{tab}]", curses.color_pair(2) | curses.A_BOLD)
        else:
            stdscr.addstr(tab_y, x_pos, f" {tab} ", curses.color_pair(1))
        x_pos += len(tab) + 4
    
    stdscr.attroff(curses.color_pair(1))


def draw_list(stdscr, explorer: ROS2RemoteExplorer, start_y: int, height: int, width: int):
    """Draw the list of items"""
    items = explorer.get_current_list()
    visible_height = height - start_y - 4
    
    # Calculate scroll offset
    scroll_offset = max(0, explorer.current_index - visible_height + 1)
    
    for i, item in enumerate(items[scroll_offset:scroll_offset + visible_height]):
        actual_index = i + scroll_offset
        y_pos = start_y + i
        
        if y_pos >= height - 4:
            break
        
        # Truncate if too long
        display_text = item[:width - 4] if len(item) > width - 4 else item
        
        if actual_index == explorer.current_index:
            stdscr.attron(curses.color_pair(3))
            stdscr.addstr(y_pos, 2, f"> {display_text}")
            stdscr.attroff(curses.color_pair(3))
        else:
            stdscr.addstr(y_pos, 2, f"  {display_text}")


def draw_help(stdscr, height: int, width: int, in_echo_mode: bool = False):
    """Draw help line at bottom"""
    help_y = height - 2
    
    if in_echo_mode:
        help_text = "q: Stop echo | Any key: Continue"
    else:
        help_text = "↑↓: Navigate | Enter: Echo/Info | 1-3: Switch view | i: Info | t: Type | r: Refresh | q: Quit"
    
    stdscr.attron(curses.color_pair(1))
    stdscr.addstr(help_y, 0, " " * width)
    if len(help_text) < width - 2:
        stdscr.addstr(help_y, 2, help_text[:width-4])
    stdscr.attroff(curses.color_pair(1))


def show_echo_mode(stdscr, explorer: ROS2RemoteExplorer, topic: str):
    """Show topic echo in full screen"""
    height, width = stdscr.getmaxyx()
    
    # Start echo thread
    explorer.echo_running = True
    explorer.echo_thread = threading.Thread(target=explorer.echo_topic_thread, args=(topic,))
    explorer.echo_thread.start()
    
    # Clear queue
    while not explorer.echo_queue.empty():
        try:
            explorer.echo_queue.get_nowait()
        except queue.Empty:
            break
    
    messages = []
    stdscr.nodelay(True)
    
    while True:
        stdscr.clear()
        
        # Header
        stdscr.attron(curses.color_pair(1))
        stdscr.addstr(0, 0, " " * width)
        header = f" Echoing: {topic} "
        stdscr.addstr(0, 2, header[:width-4], curses.color_pair(1) | curses.A_BOLD)
        stdscr.attroff(curses.color_pair(1))
        
        # Get new messages
        try:
            while True:
                msg = explorer.echo_queue.get_nowait()
                messages.append(msg)
        except queue.Empty:
            pass
        
        # Display messages (last N lines)
        visible_lines = height - 4
        display_messages = messages[-visible_lines:] if len(messages) > visible_lines else messages
        
        for i, msg in enumerate(display_messages):
            y_pos = i + 2
            if y_pos < height - 2:
                stdscr.addstr(y_pos, 0, msg[:width-1])
        
        # Help
        draw_help(stdscr, height, width, in_echo_mode=True)
        
        stdscr.refresh()
        
        # Check for quit
        try:
            key = stdscr.getch()
            if key == ord('q') or key == ord('Q'):
                break
        except:
            pass
        
        time.sleep(0.05)
    
    # Stop echo
    explorer.echo_running = False
    
    # Terminate the process first to unblock readline()
    if explorer.echo_process:
        try:
            explorer.echo_process.terminate()
            explorer.echo_process.wait(timeout=1)
        except:
            if explorer.echo_process:
                explorer.echo_process.kill()
    
    if explorer.echo_thread:
        explorer.echo_thread.join(timeout=2)
    
    stdscr.nodelay(False)


def show_info_popup(stdscr, title: str, lines: List[str]):
    """Show information in a popup window"""
    height, width = stdscr.getmaxyx()
    
    # Calculate popup size
    popup_height = min(len(lines) + 4, height - 4)
    popup_width = min(max(len(line) for line in lines) + 4 if lines else 40, width - 4)
    
    popup_y = (height - popup_height) // 2
    popup_x = (width - popup_width) // 2
    
    # Create popup window
    popup = curses.newwin(popup_height, popup_width, popup_y, popup_x)
    popup.box()
    
    # Title
    popup.attron(curses.color_pair(2) | curses.A_BOLD)
    popup.addstr(0, 2, f" {title} ")
    popup.attroff(curses.color_pair(2) | curses.A_BOLD)
    
    # Content
    for i, line in enumerate(lines[:popup_height - 3]):
        if i + 1 < popup_height - 2:
            display_line = line[:popup_width - 4] if len(line) > popup_width - 4 else line
            popup.addstr(i + 1, 2, display_line)
    
    # Help
    help_text = "Press any key to close"
    popup.addstr(popup_height - 1, (popup_width - len(help_text)) // 2, help_text, curses.color_pair(1))
    
    popup.refresh()
    stdscr.getch()


def main(stdscr):
    """Main TUI loop"""
    # Initialize colors
    curses.curs_set(0)
    curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_CYAN)
    curses.init_pair(2, curses.COLOR_BLACK, curses.COLOR_GREEN)
    curses.init_pair(3, curses.COLOR_BLACK, curses.COLOR_YELLOW)
    
    explorer = ROS2RemoteExplorer()
    
    # Initial load
    stdscr.clear()
    stdscr.addstr(0, 0, "Loading topics...")
    stdscr.refresh()
    explorer.refresh_topics()
    
    while True:
        stdscr.clear()
        height, width = stdscr.getmaxyx()
        
        # Draw UI
        draw_header(stdscr, explorer, height, width)
        draw_list(stdscr, explorer, 3, height, width)
        draw_help(stdscr, height, width)
        
        stdscr.refresh()
        
        # Handle input
        key = stdscr.getch()
        
        items = explorer.get_current_list()
        
        if key == curses.KEY_UP:
            explorer.current_index = max(0, explorer.current_index - 1)
        
        elif key == curses.KEY_DOWN:
            explorer.current_index = min(len(items) - 1, explorer.current_index + 1)
        
        elif key == ord('1'):
            if explorer.current_view != "topics":
                explorer.current_view = "topics"
                explorer.current_index = 0
                if not explorer.topics:
                    explorer.refresh_topics()
        
        elif key == ord('2'):
            if explorer.current_view != "nodes":
                explorer.current_view = "nodes"
                explorer.current_index = 0
                if not explorer.nodes:
                    stdscr.addstr(height - 1, 0, "Loading nodes...")
                    stdscr.refresh()
                    explorer.refresh_nodes()
        
        elif key == ord('3'):
            if explorer.current_view != "services":
                explorer.current_view = "services"
                explorer.current_index = 0
                if not explorer.services:
                    stdscr.addstr(height - 1, 0, "Loading services...")
                    stdscr.refresh()
                    explorer.refresh_services()
        
        elif key == ord('r') or key == ord('R'):
            stdscr.addstr(height - 1, 0, "Refreshing...")
            stdscr.refresh()
            if explorer.current_view == "topics":
                explorer.refresh_topics()
            elif explorer.current_view == "nodes":
                explorer.refresh_nodes()
            else:
                explorer.refresh_services()
            explorer.current_index = 0
        
        elif key == ord('\n') or key == curses.KEY_ENTER or key == 10 or key == 13:
            item = explorer.get_current_item()
            if item and not item.startswith("No ") and not item.startswith("Error"):
                if explorer.current_view == "topics":
                    show_echo_mode(stdscr, explorer, item)
                elif explorer.current_view == "nodes":
                    stdscr.addstr(height - 1, 0, "Getting node info...")
                    stdscr.refresh()
                    info = explorer.get_node_info(item)
                    show_info_popup(stdscr, f"Node Info: {item}", info)
                else:  # services
                    stdscr.addstr(height - 1, 0, "Getting service info...")
                    stdscr.refresh()
                    info = explorer.get_service_type(item)
                    show_info_popup(stdscr, f"Service Type: {item}", info)
        
        elif key == ord('i') or key == ord('I'):
            item = explorer.get_current_item()
            if item and not item.startswith("No ") and not item.startswith("Error"):
                stdscr.addstr(height - 1, 0, "Getting info...")
                stdscr.refresh()
                if explorer.current_view == "topics":
                    info = explorer.get_topic_info(item)
                    show_info_popup(stdscr, f"Topic Info: {item}", info)
                elif explorer.current_view == "nodes":
                    info = explorer.get_node_info(item)
                    show_info_popup(stdscr, f"Node Info: {item}", info)
                else:
                    info = explorer.get_service_type(item)
                    show_info_popup(stdscr, f"Service Type: {item}", info)
        
        elif key == ord('t') or key == ord('T'):
            item = explorer.get_current_item()
            if item and not item.startswith("No ") and not item.startswith("Error"):
                stdscr.addstr(height - 1, 0, "Getting type...")
                stdscr.refresh()
                if explorer.current_view == "topics":
                    info = explorer.get_topic_type(item)
                    show_info_popup(stdscr, f"Topic Type: {item}", info)
                elif explorer.current_view == "services":
                    info = explorer.get_service_type(item)
                    show_info_popup(stdscr, f"Service Type: {item}", info)
        
        elif key == ord('q') or key == ord('Q'):
            break


if __name__ == "__main__":
    # Parse command line arguments
    parser = argparse.ArgumentParser(description='ROS2 Remote Explorer - Interactive TUI for remote ROS2 systems')
    parser.add_argument('-n1', action='store_true', help='Connect to nvidia@192.168.41.2 via ubuntu machine')
    parser.add_argument('-n2', action='store_true', help='Connect to nvidia@192.168.41.3 via ubuntu machine')
    args = parser.parse_args()
    
    # Set nvidia host based on parameters
    if args.n1:
        NVIDIA_HOST = "192.168.41.2"
    elif args.n2:
        NVIDIA_HOST = "192.168.41.3"
    
    # Check if sshpass is available
    try:
        subprocess.run(["which", "sshpass"], capture_output=True, check=True)
    except subprocess.CalledProcessError:
        print("Error: 'sshpass' is not installed.")
        print("Please install it with: sudo apt-get install sshpass")
        sys.exit(1)
    
    try:
        curses.wrapper(main)
    except KeyboardInterrupt:
        print("\nExiting...")
    except Exception as e:
        print(f"Error: {e}")
        import traceback
        traceback.print_exc()
