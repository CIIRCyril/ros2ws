// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from monitor_msgs:msg/SysCpuDatas.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__STRUCT_H_
#define MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'cpu_datas'
#include "monitor_msgs/msg/detail/sys_cpu_data__struct.h"

/// Struct defined in msg/SysCpuDatas in the package monitor_msgs.
typedef struct monitor_msgs__msg__SysCpuDatas
{
  builtin_interfaces__msg__Time timestamp;
  monitor_msgs__msg__SysCpuData__Sequence cpu_datas;
} monitor_msgs__msg__SysCpuDatas;

// Struct for a sequence of monitor_msgs__msg__SysCpuDatas.
typedef struct monitor_msgs__msg__SysCpuDatas__Sequence
{
  monitor_msgs__msg__SysCpuDatas * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} monitor_msgs__msg__SysCpuDatas__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__STRUCT_H_
