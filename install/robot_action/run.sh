#!/bin/bash
set -e

echo "录制文件存储在 ./bin/actions 目录下"
echo "访问 http://localhost:8080 或者  http://x.x.x.x(设备IP):8080 启动界面"


source /opt/ros/humble/setup.bash
source install/setup.bash


./bin/app.bin