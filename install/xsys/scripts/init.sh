#!/bin/bash

CURRENT_DIR=$(dirname $(readlink -f "$0"))
cd "${CURRENT_DIR}" || exit 1

# go back to the parent folder of 'install'.
while [ "${CURRENT_DIR}" != "/" ]; do
  if [ -f install/setup.bash ]; then
    break
  fi

  CURRENT_DIR=$(dirname "${CURRENT_DIR}")
  cd ${CURRENT_DIR} || exit 1
done

if [ "${CURRENT_DIR}" == "/" ]; then
  echo "Error: install/setup.bash not found in the directory hierarchy."
  exit 1
fi

USER_HOME="/home/$(echo "$CURRENT_DIR" | cut -d/ -f3)"
echo "USER: '$USER'"
echo "USER_HOME: '$USER_HOME'"
echo "Current directory: ${CURRENT_DIR}"

source /opt/ros/humble/setup.bash

startup_script="${HOME}/data/param/ros2_setup.bash"
if [ -f "${startup_script}" ]; then
  echo "source ${startup_script}"
  source "${startup_script}"
fi
unset startup_script

source install/setup.bash 

echo "==== env ===="
printenv | grep ROS_
printenv | grep RMW_
echo "==== env ===="

ros2 launch xsys xsys.launch.py
