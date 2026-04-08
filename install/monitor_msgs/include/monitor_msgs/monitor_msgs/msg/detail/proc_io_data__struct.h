// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from monitor_msgs:msg/ProcIoData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__STRUCT_H_
#define MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ProcIoData in the package monitor_msgs.
typedef struct monitor_msgs__msg__ProcIoData
{
  double read;
  double write;
  double total_read;
  double total_write;
} monitor_msgs__msg__ProcIoData;

// Struct for a sequence of monitor_msgs__msg__ProcIoData.
typedef struct monitor_msgs__msg__ProcIoData__Sequence
{
  monitor_msgs__msg__ProcIoData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} monitor_msgs__msg__ProcIoData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__STRUCT_H_
