#!/bin/bash

CURRENT_DIR=$(dirname $(readlink -f "$0"))
cd "${CURRENT_DIR}" || exit 1

service=$(find . -name "*.service" | head -n 1)
if [ -z "$service" ]; then
  echo "No service file found."
  exit 1
fi

service=$(basename "$service")
service=${service%.*}
echo "Deploying service: $service"

target=$(grep -E "ExecStart=" ${service}.service | head -n 1 | cut -d '=' -f 2 | xargs)
target=${target#* }
target=${target%/*}
replacement="${CURRENT_DIR}"

escaped_target=$(echo "$target" | sed 's/\//\\\//g')
escaped_replacement=$(echo "$replacement" | sed 's/\//\\\//g')

sed -i "s|$escaped_target|$escaped_replacement|g" ${service}.service
cat ${service}.service

sudo systemctl stop ${service}
sudo cp ${service}.service /etc/systemd/system
sudo systemctl daemon-reload
sudo systemctl enable ${service}
