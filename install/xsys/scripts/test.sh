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

echo "Current directory: ${CURRENT_DIR}"

echo "==== env ===="
printenv | grep ROS_
printenv | grep RMW_
echo "==== env ===="

source install/setup.bash 
ros2 service call /xsys/get_serial_number xsys_msgs/srv/GetSerialNumber
