#!/bin/bash

####################
## version: 0.0.1 ##
####################

CURRENT_DIR=$(dirname $(readlink -f "$0"))
cd "${CURRENT_DIR}" || exit 1

service_file=$(find . -name "*.service" | head -n 1)
if [ -z "$service_file" ]; then
  echo "No service file found."
  exit 1
fi

service_file=$(basename "$service_file")
service_name=${service_file%.*}
echo "Deploying service: $service_name"

USER_HOME="/home/$(echo "$CURRENT_DIR" | cut -d/ -f3)"
USER=${USER_HOME##*/}
echo "USER: '$USER'"

target=$(grep -E "User=" ${service_file} | head -n 1 | xargs)
replacement="User=${USER}"
sed -i "s|$target|$replacement|g" ${service_file}

target=$(grep -E "ExecStart=" ${service_file} | head -n 1 | cut -d '=' -f 2 | xargs)
target=${target#* }
target=${target%/*}
replacement="${CURRENT_DIR}"

escaped_target=$(echo "$target" | sed 's/\//\\\//g')
escaped_replacement=$(echo "$replacement" | sed 's/\//\\\//g')

sed -i "s|$escaped_target|$escaped_replacement|g" ${service_file}
cat ${service_file}

sudo systemctl stop ${service_name}
sudo cp ${service_file} /etc/systemd/system
sudo systemctl daemon-reload
sudo systemctl enable ${service_name}
