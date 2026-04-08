#!/bin/bash

CURRENT_DIR=$(dirname $(readlink -f "$0"))
cd "${CURRENT_DIR}" || exit 1

while [ "${CURRENT_DIR}" != "/" ]; do
  if [ -f install/setup.bash ]; then
    break
  else
    CURRENT_DIR=$(dirname "${CURRENT_DIR}")
    cd ${CURRENT_DIR} || exit 1
  fi
done

if [ "${CURRENT_DIR}" == "/" ]; then
  echo "Error: install/setup.bash not found in the directory hierarchy."
  exit 1
fi

echo "Current directory: ${CURRENT_DIR}"

source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 launch audio audio.launch.py

echo "end"
