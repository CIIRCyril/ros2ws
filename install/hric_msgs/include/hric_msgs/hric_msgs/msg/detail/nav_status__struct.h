// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:msg/NavStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_H_
#define HRIC_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_H_

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
  hric_msgs__msg__NavStatus__NONE = 0ul
};

/// Constant 'UNKNOWN'.
enum
{
  hric_msgs__msg__NavStatus__UNKNOWN = 100ul
};

/// Constant 'GOAL_OCCUPIED'.
/**
  * 目标点被占用
 */
enum
{
  hric_msgs__msg__NavStatus__GOAL_OCCUPIED = 101ul
};

/// Constant 'TIMEOUT'.
/**
  * 规划超时
 */
enum
{
  hric_msgs__msg__NavStatus__TIMEOUT = 102ul
};

/// Constant 'NO_VALID_PATH'.
/**
  * 无可通行路线
 */
enum
{
  hric_msgs__msg__NavStatus__NO_VALID_PATH = 103ul
};

/// Constant 'IDLE'.
/**
  * 导航状态码
  *  空闲状态
 */
enum
{
  hric_msgs__msg__NavStatus__IDLE = 0
};

/// Constant 'EXECUTE_TASK'.
/**
  * 执行导航任务，去往目标点
 */
enum
{
  hric_msgs__msg__NavStatus__EXECUTE_TASK = 1
};

/// Constant 'CANCELED'.
/**
  * 导航任务被取消
 */
enum
{
  hric_msgs__msg__NavStatus__CANCELED = 2
};

/// Constant 'FAILED'.
/**
  * 导航任务失败
 */
enum
{
  hric_msgs__msg__NavStatus__FAILED = 3
};

/// Constant 'REACHED_GOAL'.
/**
  * 已到达目标位置，导航任务完成
 */
enum
{
  hric_msgs__msg__NavStatus__REACHED_GOAL = 4
};

/// Struct defined in msg/NavStatus in the package hric_msgs.
/**
  * 导航错误码
 */
typedef struct hric_msgs__msg__NavStatus
{
  /// 导航状态
  uint8_t status;
  /// 错误码
  uint32_t error_code;
} hric_msgs__msg__NavStatus;

// Struct for a sequence of hric_msgs__msg__NavStatus.
typedef struct hric_msgs__msg__NavStatus__Sequence
{
  hric_msgs__msg__NavStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__msg__NavStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_H_
