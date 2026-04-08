// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:srv/SetMotionMode.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__STRUCT_H_
#define HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'START'.
enum
{
  hric_msgs__srv__SetMotionMode_Request__START = 0
};

/// Constant 'STOP'.
enum
{
  hric_msgs__srv__SetMotionMode_Request__STOP = 1
};

/// Constant 'ZERO'.
enum
{
  hric_msgs__srv__SetMotionMode_Request__ZERO = 2
};

/// Constant 'STAND'.
enum
{
  hric_msgs__srv__SetMotionMode_Request__STAND = 3
};

/// Constant 'WALK'.
enum
{
  hric_msgs__srv__SetMotionMode_Request__WALK = 4
};

/// Constant 'RUN'.
enum
{
  hric_msgs__srv__SetMotionMode_Request__RUN = 5
};

/// Struct defined in srv/SetMotionMode in the package hric_msgs.
typedef struct hric_msgs__srv__SetMotionMode_Request
{
  /// 导航之前请求walk模式，导航结束请求stand模式
  /// 请求切换的运动模式-> 0: start, 1: stop, 2: zero, 3: stand, 4: walk, 5: run
  uint8_t walk_mode_request;
  /// walk是否需要摆臂
  bool is_need_swing_arm;
} hric_msgs__srv__SetMotionMode_Request;

// Struct for a sequence of hric_msgs__srv__SetMotionMode_Request.
typedef struct hric_msgs__srv__SetMotionMode_Request__Sequence
{
  hric_msgs__srv__SetMotionMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__SetMotionMode_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetMotionMode in the package hric_msgs.
typedef struct hric_msgs__srv__SetMotionMode_Response
{
  /// 表示服务调用是否成功
  bool success;
  /// 错误码
  uint32_t error_code;
} hric_msgs__srv__SetMotionMode_Response;

// Struct for a sequence of hric_msgs__srv__SetMotionMode_Response.
typedef struct hric_msgs__srv__SetMotionMode_Response__Sequence
{
  hric_msgs__srv__SetMotionMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__SetMotionMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__STRUCT_H_
