// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:srv/SetGoal.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_GOAL__STRUCT_H_
#define HRIC_MSGS__SRV__DETAIL__SET_GOAL__STRUCT_H_

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
  hric_msgs__srv__SetGoal_Request__NONE = 0ul
};

/// Constant 'UNKNOWN'.
enum
{
  hric_msgs__srv__SetGoal_Request__UNKNOWN = 100ul
};

/// Constant 'GOAL_OCCUPIED'.
/**
  * 目标点被占用
 */
enum
{
  hric_msgs__srv__SetGoal_Request__GOAL_OCCUPIED = 101ul
};

/// Constant 'TIMEOUT'.
/**
  * 规划超时
 */
enum
{
  hric_msgs__srv__SetGoal_Request__TIMEOUT = 102ul
};

/// Constant 'NO_VALID_PATH'.
/**
  * 无可通行路线
 */
enum
{
  hric_msgs__srv__SetGoal_Request__NO_VALID_PATH = 103ul
};

// Include directives for member types
// Member 'goal'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/SetGoal in the package hric_msgs.
typedef struct hric_msgs__srv__SetGoal_Request
{
  /// 目标位姿。header中frame_id用于区分目标位姿是全局位姿还是局部位姿。若frame_id为"map"为全局目标位姿，为"base_link"为相对机器人的目标位姿。
  geometry_msgs__msg__PoseStamped goal;
} hric_msgs__srv__SetGoal_Request;

// Struct for a sequence of hric_msgs__srv__SetGoal_Request.
typedef struct hric_msgs__srv__SetGoal_Request__Sequence
{
  hric_msgs__srv__SetGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__SetGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetGoal in the package hric_msgs.
typedef struct hric_msgs__srv__SetGoal_Response
{
  /// 表示服务调用是否成功
  bool success;
  /// 失败原因
  rosidl_runtime_c__String message;
  /// 错误码
  uint32_t error_code;
} hric_msgs__srv__SetGoal_Response;

// Struct for a sequence of hric_msgs__srv__SetGoal_Response.
typedef struct hric_msgs__srv__SetGoal_Response__Sequence
{
  hric_msgs__srv__SetGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__SetGoal_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__SRV__DETAIL__SET_GOAL__STRUCT_H_
