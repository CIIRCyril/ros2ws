// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:msg/MotionStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__STRUCT_H_
#define HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'NONE'.
/**
  * 无异常
 */
enum
{
  hric_msgs__msg__MotionStatus__NONE = 0ul
};

/// Constant 'UNKNOWN'.
enum
{
  hric_msgs__msg__MotionStatus__UNKNOWN = 400ul
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/MotionStatus in the package hric_msgs.
/**
  * 运控错误码
 */
typedef struct hric_msgs__msg__MotionStatus
{
  /// 时间戳和坐标系
  std_msgs__msg__Header header;
  /// 机器人腰部坐标系速度
  geometry_msgs__msg__Twist velocity;
  /// 行走状态 0: stop , 1: zero, 2: Z2S, 3: stand, 4: S2W, 5: walk, 6: start, 7: run
  uint8_t walk_mode;
  /// 是否为遥控器操控 true:遥控器操纵false：导航操控
  bool is_console_control;
  /// 是否为walk摆臂状态
  bool is_swing_arm;
  /// 错误码
  uint32_t error_code;
} hric_msgs__msg__MotionStatus;

// Struct for a sequence of hric_msgs__msg__MotionStatus.
typedef struct hric_msgs__msg__MotionStatus__Sequence
{
  hric_msgs__msg__MotionStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__msg__MotionStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__STRUCT_H_
