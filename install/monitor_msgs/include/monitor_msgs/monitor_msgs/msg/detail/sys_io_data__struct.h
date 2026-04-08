// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from monitor_msgs:msg/SysIoData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__STRUCT_H_
#define MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__STRUCT_H_

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

/// Struct defined in msg/SysIoData in the package monitor_msgs.
typedef struct monitor_msgs__msg__SysIoData
{
  builtin_interfaces__msg__Time timestamp;
  double disk_read;
  double disk_write;
} monitor_msgs__msg__SysIoData;

// Struct for a sequence of monitor_msgs__msg__SysIoData.
typedef struct monitor_msgs__msg__SysIoData__Sequence
{
  monitor_msgs__msg__SysIoData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} monitor_msgs__msg__SysIoData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__STRUCT_H_
