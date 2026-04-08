// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:srv/VisualRelocate.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__VISUAL_RELOCATE__STRUCT_H_
#define HRIC_MSGS__SRV__DETAIL__VISUAL_RELOCATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'LOCAL_MATCH'.
/**
  * 局部重定位位姿(需要提供pose_robot)
 */
enum
{
  hric_msgs__srv__VisualRelocate_Request__LOCAL_MATCH = 1
};

/// Constant 'GLOBAL_MATCH'.
/**
  * 全局重定位位姿(不需要提供pose_ref，定位算法进行自动匹配)
 */
enum
{
  hric_msgs__srv__VisualRelocate_Request__GLOBAL_MATCH = 2
};

// Include directives for member types
// Member 'pose_ref'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/VisualRelocate in the package hric_msgs.
typedef struct hric_msgs__srv__VisualRelocate_Request
{
  /// goal definition
  /// 初始参考位姿
  geometry_msgs__msg__PoseStamped pose_ref;
  /// 匹配类型（LOCAL_MATCH、GLOBAL_MATCH）
  uint8_t match_type;
} hric_msgs__srv__VisualRelocate_Request;

// Struct for a sequence of hric_msgs__srv__VisualRelocate_Request.
typedef struct hric_msgs__srv__VisualRelocate_Request__Sequence
{
  hric_msgs__srv__VisualRelocate_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__VisualRelocate_Request__Sequence;


// Constants defined in the message

/// Constant 'NONE'.
/**
  * 错误码
 */
enum
{
  hric_msgs__srv__VisualRelocate_Response__NONE = 0ul
};

/// Constant 'UNKNOWN'.
enum
{
  hric_msgs__srv__VisualRelocate_Response__UNKNOWN = 200ul
};

/// Constant 'TF_ERROR'.
/**
  * TF错误
 */
enum
{
  hric_msgs__srv__VisualRelocate_Response__TF_ERROR = 201ul
};

/// Constant 'SENSOR_ERROR'.
/**
  * 传感器异常
 */
enum
{
  hric_msgs__srv__VisualRelocate_Response__SENSOR_ERROR = 202ul
};

/// Constant 'LOW_CONFIDENCE'.
/**
  * 低置信度
 */
enum
{
  hric_msgs__srv__VisualRelocate_Response__LOW_CONFIDENCE = 203ul
};

// Include directives for member types
// Member 'pose_robot'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/VisualRelocate in the package hric_msgs.
typedef struct hric_msgs__srv__VisualRelocate_Response
{
  /// 机器人位姿
  geometry_msgs__msg__PoseStamped pose_robot;
  /// 结果
  bool success;
  /// 错误码
  uint32_t error_code;
  /// 失败原因
  rosidl_runtime_c__String message;
} hric_msgs__srv__VisualRelocate_Response;

// Struct for a sequence of hric_msgs__srv__VisualRelocate_Response.
typedef struct hric_msgs__srv__VisualRelocate_Response__Sequence
{
  hric_msgs__srv__VisualRelocate_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__VisualRelocate_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__SRV__DETAIL__VISUAL_RELOCATE__STRUCT_H_
