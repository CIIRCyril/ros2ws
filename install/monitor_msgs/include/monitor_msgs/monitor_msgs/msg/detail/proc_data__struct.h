// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from monitor_msgs:msg/ProcData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_DATA__STRUCT_H_
#define MONITOR_MSGS__MSG__DETAIL__PROC_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'cpu_data'
#include "monitor_msgs/msg/detail/proc_cpu_data__struct.h"
// Member 'io_data'
#include "monitor_msgs/msg/detail/proc_io_data__struct.h"
// Member 'mem_data'
#include "monitor_msgs/msg/detail/proc_mem_data__struct.h"

/// Struct defined in msg/ProcData in the package monitor_msgs.
typedef struct monitor_msgs__msg__ProcData
{
  uint32_t pid;
  rosidl_runtime_c__String name;
  bool active;
  monitor_msgs__msg__ProcCpuData cpu_data;
  monitor_msgs__msg__ProcIoData io_data;
  monitor_msgs__msg__ProcMemData mem_data;
} monitor_msgs__msg__ProcData;

// Struct for a sequence of monitor_msgs__msg__ProcData.
typedef struct monitor_msgs__msg__ProcData__Sequence
{
  monitor_msgs__msg__ProcData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} monitor_msgs__msg__ProcData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_DATA__STRUCT_H_
