#!/bin/bash

CURRENT_DIR=$(dirname $(readlink -f "$0"))
cd "${CURRENT_DIR}" || exit 1

ps -ef | grep "audio.launch.py" | grep -v grep | awk '{print $2}' | xargs kill -9
