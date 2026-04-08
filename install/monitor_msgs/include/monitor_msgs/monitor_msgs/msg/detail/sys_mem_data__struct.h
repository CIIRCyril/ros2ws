// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from monitor_msgs:msg/SysMemData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__STRUCT_H_
#define MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__STRUCT_H_

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

/// Struct defined in msg/SysMemData in the package monitor_msgs.
typedef struct monitor_msgs__msg__SysMemData
{
  builtin_interfaces__msg__Time timestamp;
  /// 系统总物理内存
  uint64_t total;
  /// 系统总物理使用内存
  uint64_t used;
  /// 完全空闲的物理内存（未被任何进程/缓存使用）
  uint64_t free;
  uint64_t shared;
  /// 实际可被新进程使用的内存（含可回收缓存）
  uint64_t available;
  /// 用于块设备（如磁盘）的临时缓存
  uint64_t buffers;
  /// 用于文件系统的页缓存（可回收）
  uint64_t cached;
  uint64_t sreclaimable;
  /// 交换分区总大小
  uint64_t swap_total;
  /// 空闲交换分区大小
  uint64_t swap_free;
} monitor_msgs__msg__SysMemData;

// Struct for a sequence of monitor_msgs__msg__SysMemData.
typedef struct monitor_msgs__msg__SysMemData__Sequence
{
  monitor_msgs__msg__SysMemData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} monitor_msgs__msg__SysMemData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__STRUCT_H_
