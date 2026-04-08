// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from monitor_msgs:msg/ProcDatas.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__STRUCT_H_
#define MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__STRUCT_H_

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
// Member 'proc_datas'
#include "monitor_msgs/msg/detail/proc_data__struct.h"

/// Struct defined in msg/ProcDatas in the package monitor_msgs.
typedef struct monitor_msgs__msg__ProcDatas
{
  builtin_interfaces__msg__Time timestamp;
  monitor_msgs__msg__ProcData__Sequence proc_datas;
} monitor_msgs__msg__ProcDatas;

// Struct for a sequence of monitor_msgs__msg__ProcDatas.
typedef struct monitor_msgs__msg__ProcDatas__Sequence
{
  monitor_msgs__msg__ProcDatas * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} monitor_msgs__msg__ProcDatas__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__STRUCT_H_
