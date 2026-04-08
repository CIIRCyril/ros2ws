// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from monitor_msgs:msg/SysCpuData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__STRUCT_H_
#define MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'proc_array'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SysCpuData in the package monitor_msgs.
typedef struct monitor_msgs__msg__SysCpuData
{
  uint8_t cpu_num;
  float cpu_used;
  uint32_t proc_num;
  rosidl_runtime_c__String__Sequence proc_array;
} monitor_msgs__msg__SysCpuData;

// Struct for a sequence of monitor_msgs__msg__SysCpuData.
typedef struct monitor_msgs__msg__SysCpuData__Sequence
{
  monitor_msgs__msg__SysCpuData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} monitor_msgs__msg__SysCpuData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__STRUCT_H_
