# ROS 2 Humble — Full Installation Guide (Ubuntu 22.04)

## 1. Set Locale

```bash
sudo apt install locales -y
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
locale
```

## 2. Add the ROS 2 Repository

```bash
sudo apt install software-properties-common -y
sudo add-apt-repository universe -y
sudo apt update
sudo apt install curl gnupg lsb-release -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
  -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] \
http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" \
  | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
sudo apt update
sudo apt upgrade -y
```

## 3. Install ROS 2 Humble Desktop

```bash
sudo apt install ros-humble-desktop
```

## 4. Install Optional Core Packages

```bash
sudo apt install ros-humble-moveit
sudo apt install ros-humble-rviz2
sudo apt install ros-humble-ros-gz
```

## 5. Install Robot State / Visualisation Stack

```bash
sudo apt install \
  ros-humble-desktop \
  ros-humble-robot-state-publisher \
  ros-humble-joint-state-publisher-gui \
  ros-humble-xacro \
  ros-humble-tf2-tools \
  ros-humble-rviz2
```

## 6. Install ros2_control Stack

```bash
sudo apt install \
  ros-humble-ros2-control \
  ros-humble-ros2-controllers \
  ros-humble-controller-manager \
  ros-humble-joint-trajectory-controller \
  ros-humble-position-controllers \
  ros-humble-effort-controllers
```

## 7. Install Navigation Stack

```bash
sudo apt install \
  ros-humble-navigation2 \
  ros-humble-nav2-bringup \
  ros-humble-slam-toolbox
```

## 8. Install Vision / Perception Stack

```bash
sudo apt install \
  ros-humble-image-transport \
  ros-humble-cv-bridge \
  ros-humble-depth-image-proc \
  ros-humble-pcl-ros \
  ros-humble-vision-msgs
```

## 9. Install Kinematics Libraries

```bash
sudo apt install \
  ros-humble-kdl-parser \
  ros-humble-pinocchio
```

## 10. Source the Environment

Add to `~/.bashrc` (or `~/.zshrc`):

```bash
source /opt/ros/humble/setup.bash
```

Then reload:

```bash
source ~/.bashrc
```
