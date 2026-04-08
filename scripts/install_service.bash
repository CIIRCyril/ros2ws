#!/bin/bash

output_dir=
dst_dir=
home_dir=

for arg in "$@";do
  key=${arg%=*}
  val=${arg#*=}
  echo "${key}: ${val}"
  if [ ${key} = "--output_dir" ];then
    output_dir=${val}
    dst_dir=${val}
  elif [ ${key} = "--home_dir" ];then
    home_dir=${val}
  fi
done

if [ "${output_dir}" = "" ];then
  echo "output dir empty, exit"
  exit 1
fi

echo 'SUBSYSTEM=="tty", ATTRS{idVendor}=="1a86", ATTRS{idProduct}=="7523", SYMLINK+="ttySBUS0"' | sudo tee /etc/udev/rules.d/50-usb_sbus.rules
echo 'SUBSYSTEM=="tty", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6015", SYMLINK+="ttyUSB10"' | sudo tee /etc/udev/rules.d/51-robotiq.rules
echo "reload udev rules"
sudo udevadm control --reload-rules && sudo udevadm trigger
echo "udev rules reload done"

if [ ! -f /home/ubuntu/data/param/yaml/parameters.yaml ];then
  mkdir -p /home/ubuntu/data/param/yaml
  if [ -f ${dst_dir}/install_isolated/share/motion_control/src/plugins/mpcWbc_lib/config/yaml/parameters.yaml ];then
    cp ${dst_dir}/install_isolated/share/motion_control/src/plugins/mpcWbc_lib/config/yaml/parameters.yaml /home/ubuntu/data/param/yaml
  fi
fi

# install/motioncontrol_component/share/motioncontrol_component/config/yaml/parameters.yaml
if [ ! -f /home/ubuntu/data/param/yaml/parameters.yaml ];then
  mkdir -p /home/ubuntu/data/param/yaml
  if [ -f ${dst_dir}/install/motioncontrol_component/share/motioncontrol_component/config/yaml/parameters.yaml ];then
    cp ${dst_dir}/install/motioncontrol_component/share/motioncontrol_component/config/yaml/parameters.yaml /home/ubuntu/data/param/yaml
  fi
fi

# ./install/motioncontrol_component_joint/share/motioncontrol_component_joint/config/yaml/parameters.yaml
if [ ! -f /home/ubuntu/data/param/motion_control_joint/yaml/parameters.yaml ];then
  mkdir -p /home/ubuntu/data/param/motion_control_joint/yaml
  if [ -f ${dst_dir}/install/motioncontrol_component_joint/share/motioncontrol_component_joint/config/yaml/parameters.yaml ];then
    cp ${dst_dir}/install/motioncontrol_component_joint/share/motioncontrol_component_joint/config/yaml/parameters.yaml /home/ubuntu/data/param/motion_control_joint/yaml
  fi
fi

mkdir -p ${home_dir}/data/param/python_scripts/traced
if [ -d ${dst_dir}/install_isolated/share/rl_control/python_scripts/traced ];then
  cp -r ${dst_dir}/install_isolated/share/rl_control/python_scripts/traced/* ${home_dir}/data/param/python_scripts/traced
  if [ ! -f ${home_dir}/data/param/rl_control_new.txt ] && [ -f ${dst_dir}/install_isolated/share/rl_control/python_scripts/traced/rl_control_new.txt ];then
    cp ${dst_dir}/install_isolated/share/rl_control/python_scripts/traced/rl_control_new.txt ${home_dir}/data/param/rl_control_new.txt
  fi
  mkdir -p ${home_dir}/.ros/python_scripts/traced
  cp -r ${dst_dir}/install_isolated/share/rl_control/python_scripts/traced/* ${home_dir}/.ros/python_scripts/traced
fi

mkdir -p ${home_dir}/data/param/python_scripts/traced
if [ -d ${dst_dir}/install/rl_control_new/share/python_scripts/traced ];then
  cp -r ${dst_dir}/install/rl_control_new/share/python_scripts/traced/* ${home_dir}/data/param/python_scripts/traced
  if [ ! -f ${home_dir}/data/param/rl_control_new.txt ] && [ -f ${dst_dir}/install/rl_control_new/share/python_scripts/traced/rl_control_new.txt ];then
    cp ${dst_dir}/install/rl_control_new/share/python_scripts/traced/rl_control_new.txt ${home_dir}/data/param/rl_control_new.txt
  fi
  mkdir -p ${home_dir}/.ros/python_scripts/traced
  cp -r ${dst_dir}/install/rl_control_new/share/python_scripts/traced/* ${home_dir}/.ros/python_scripts/traced
fi

mkdir -p ${home_dir}/data/param/python_scripts/traced
if [ -d ${dst_dir}/install/rl_control/share/python_scripts/traced ];then
  cp -r ${dst_dir}/install/rl_control/share/python_scripts/traced/* ${home_dir}/data/param/python_scripts/traced
  if [ ! -f ${home_dir}/data/param/rl_control.txt ] && [ -f ${dst_dir}/install/rl_control/share/python_scripts/traced/rl_control.txt ];then
    cp ${dst_dir}/install/rl_control/share/python_scripts/traced/rl_control.txt ${home_dir}/data/param/rl_control.txt
  fi
  mkdir -p ${home_dir}/.ros/python_scripts/traced
  cp -r ${dst_dir}/install/rl_control/share/python_scripts/traced/* ${home_dir}/.ros/python_scripts/traced
fi

if [ ! -f /home/ubuntu/data/param/yaml/parameters.yaml ];then
  mkdir -p /home/ubuntu/data/param/yaml
  if [ -f ${dst_dir}/install/motion_control/share/motion_control/config/yaml/parameters.yaml ];then
    cp ${dst_dir}/install/motion_control/share/motion_control/config/yaml/parameters.yaml /home/ubuntu/data/param/yaml
  fi
fi

if [ ! -f ${home_dir}/data/param/audio_config.txt ];then
  mkdir -p ${home_dir}/data/param
  if [ -f ${dst_dir}/scripts/audio_config.txt ];then
    cp ${dst_dir}/scripts/audio_config.txt ${home_dir}/data/param
  fi
fi

if [ ! -f ${home_dir}/data/param/proc_manager.txt ];then
  mkdir -p ${home_dir}/data/param
  if [ -f ${dst_dir}/scripts/proc_manager.txt ];then
    cp ${dst_dir}/scripts/proc_manager.txt ${home_dir}/data/param
  fi
fi

if [ -f ${dst_dir}/scripts/proc_manager.service ];then
  echo "install proc_manager service"
  mkdir -p ${home_dir}/data/scripts
  #if [ ! -f ${home_dir}/data/scripts/startup_proc_manager.bash ];then
    cp ${dst_dir}/scripts/startup_proc_manager.bash ${home_dir}/data/scripts
  #fi
  chmod +x ${dst_dir}/scripts/startup_proc_manager.bash
  if [ -f ${home_dir}/data/scripts/startup_proc_manager.bash ];then
    chmod +x ${home_dir}/data/scripts/startup_proc_manager.bash
  fi
  sudo cp ${dst_dir}/scripts/proc_manager.service /etc/systemd/system/proc_manager.service
  sudo systemctl daemon-reload
  echo "install proc_manager service finish, use: "
  echo "    sudo systemctl restart proc_manager.service "
  echo "    sudo systemctl stop proc_manager.service "
  echo "    sudo systemctl start proc_manager.service "
  echo "    sudo systemctl enable proc_manager.service "
  echo "    sudo systemctl disable proc_manager.service "
fi
