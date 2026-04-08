#!/bin/bash

ps -ef | grep "sys_monitor" | grep -v grep | awk '{print $2}' | xargs kill -9
