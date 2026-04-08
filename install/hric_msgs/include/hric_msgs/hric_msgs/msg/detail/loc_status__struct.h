// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:msg/LocStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__LOC_STATUS__STRUCT_H_
#define HRIC_MSGS__MSG__DETAIL__LOC_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'IDLE'.
/**
  * 状态码
  * 空闲状态， 不能导航
 */
enum
{
  hric_msgs__msg__LocStatus__IDLE = 100
};

/// Constant 'INITIALIZING'.
/**
  * 初始化中， 不能导航
 */
enum
{
  hric_msgs__msg__LocStatus__INITIALIZING = 101
};

/// Constant 'RUNNING'.
/**
  * 正常状态
 */
enum
{
  hric_msgs__msg__LocStatus__RUNNING = 102
};

/// Constant 'WEAK'.
enum
{
  hric_msgs__msg__LocStatus__WEAK = 103
};

/// Constant 'LOST'.
/**
  * （不能导航）
 */
enum
{
  hric_msgs__msg__LocStatus__LOST = 104
};

/// Constant 'BLOCKED'.
/**
  * （传感器数据异常、初始化失败，不能导航）
 */
enum
{
  hric_msgs__msg__LocStatus__BLOCKED = 105
};

/// Constant 'NONE'.
/**
  * 错误码
 */
enum
{
  hric_msgs__msg__LocStatus__NONE = 0ul
};

/// Constant 'UNKNOWN'.
enum
{
  hric_msgs__msg__LocStatus__UNKNOWN = 200ul
};

/// Constant 'TF_ERROR'.
/**
  * TF错误
 */
enum
{
  hric_msgs__msg__LocStatus__TF_ERROR = 201ul
};

/// Constant 'SENSOR_ERROR'.
/**
  * 传感器异常
 */
enum
{
  hric_msgs__msg__LocStatus__SENSOR_ERROR = 202ul
};

/// Constant 'RELOCALIZATION_ERROR'.
/**
  * 重定位失败
 */
enum
{
  hric_msgs__msg__LocStatus__RELOCALIZATION_ERROR = 203ul
};

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in msg/LocStatus in the package hric_msgs.
typedef struct hric_msgs__msg__LocStatus
{
  uint8_t status;
  double confidence;
  uint32_t error_code;
  geometry_msgs__msg__PoseStamped pose;
} hric_msgs__msg__LocStatus;

// Struct for a sequence of hric_msgs__msg__LocStatus.
typedef struct hric_msgs__msg__LocStatus__Sequence
{
  hric_msgs__msg__LocStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__msg__LocStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__MSG__DETAIL__LOC_STATUS__STRUCT_H_
