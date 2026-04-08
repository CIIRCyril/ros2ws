#!/bin/bash

if [ -f /opt/ros/humble/setup.bash ];then
  source /opt/ros/humble/setup.bash
fi

#local_ip=`ip addr show | grep -E 'inet [0-9]' | awk '{print $2}' | awk -F '/' '{print $1}' | grep 192.168.41`
#if [ "${local_ip}" != "" ];then
#  if [ -f /home/ubuntu/data/param/dds_profile.xml ];then
#    sed -i "s|\${local_ip}|${local_ip}|g" /home/ubuntu/data/param/dds_profile.xml
#  elif [ -f /home/nvidia/data/param/dds_profile.xml ];then
#    sed -i "s|\${local_ip}|${local_ip}|g" /home/nvidia/data/param/dds_profile.xml
#  fi
#fi


config_file=${config_file}
if [ -f ${config_file} ];then
  lines=`cat ${config_file}`
  for line in ${lines}
  do
    if [[ ${line} =~ ^# ]] || [ -z "${line}" ];then
      echo "ignore: ${line}" > /dev/null
    else
      export ${line}
    fi
  done
fi
