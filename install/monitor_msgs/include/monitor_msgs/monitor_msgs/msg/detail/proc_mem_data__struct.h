// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from monitor_msgs:msg/ProcMemData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__STRUCT_H_
#define MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ProcMemData in the package monitor_msgs.
typedef struct monitor_msgs__msg__ProcMemData
{
  uint32_t vmsize;
  uint32_t vmrss;
  uint32_t vmshared;
  uint32_t vmexe;
  uint32_t vmdata;
} monitor_msgs__msg__ProcMemData;

// Struct for a sequence of monitor_msgs__msg__ProcMemData.
typedef struct monitor_msgs__msg__ProcMemData__Sequence
{
  monitor_msgs__msg__ProcMemData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} monitor_msgs__msg__ProcMemData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__STRUCT_H_
