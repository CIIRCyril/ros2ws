#!/bin/bash
cur=$(dirname $(realpath $0))

export CLOUD_SERVICE_LOG_DIR=/home/ubuntu/logs/glogs
mkdir -p ${CLOUD_SERVICE_LOG_DIR}

source /opt/ros/humble/setup.bash
cd $cur/../bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib
./system_monitor -c ../config/monitor.json >/dev/null 2>&1

echo "end"
