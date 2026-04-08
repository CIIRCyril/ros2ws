// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:srv/SetVisualLocMode.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_VISUAL_LOC_MODE__STRUCT_H_
#define HRIC_MSGS__SRV__DETAIL__SET_VISUAL_LOC_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'IDLE_MODE'.
enum
{
  hric_msgs__srv__SetVisualLocMode_Request__IDLE_MODE = 0
};

/// Constant 'ODOM_MODE'.
enum
{
  hric_msgs__srv__SetVisualLocMode_Request__ODOM_MODE = 1
};

/// Constant 'MAP_REFINE_MODE'.
enum
{
  hric_msgs__srv__SetVisualLocMode_Request__MAP_REFINE_MODE = 2
};

/// Constant 'MAP_LOC_MODE'.
enum
{
  hric_msgs__srv__SetVisualLocMode_Request__MAP_LOC_MODE = 3
};

/// Struct defined in srv/SetVisualLocMode in the package hric_msgs.
typedef struct hric_msgs__srv__SetVisualLocMode_Request
{
  uint8_t loc_mode;
} hric_msgs__srv__SetVisualLocMode_Request;

// Struct for a sequence of hric_msgs__srv__SetVisualLocMode_Request.
typedef struct hric_msgs__srv__SetVisualLocMode_Request__Sequence
{
  hric_msgs__srv__SetVisualLocMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__SetVisualLocMode_Request__Sequence;


// Constants defined in the message

/// Constant 'NONE'.
/**
  * 错误码
 */
enum
{
  hric_msgs__srv__SetVisualLocMode_Response__NONE = 0ul
};

/// Constant 'UNKNOWN'.
enum
{
  hric_msgs__srv__SetVisualLocMode_Response__UNKNOWN = 200ul
};

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetVisualLocMode in the package hric_msgs.
typedef struct hric_msgs__srv__SetVisualLocMode_Response
{
  /// 表示服务调用是否成功
  bool success;
  /// 错误码
  uint32_t error_code;
  /// 失败原因
  rosidl_runtime_c__String message;
} hric_msgs__srv__SetVisualLocMode_Response;

// Struct for a sequence of hric_msgs__srv__SetVisualLocMode_Response.
typedef struct hric_msgs__srv__SetVisualLocMode_Response__Sequence
{
  hric_msgs__srv__SetVisualLocMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__SetVisualLocMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__SRV__DETAIL__SET_VISUAL_LOC_MODE__STRUCT_H_
