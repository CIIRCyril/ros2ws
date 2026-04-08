// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:srv/UpdateMarker.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__UPDATE_MARKER__STRUCT_H_
#define HRIC_MSGS__SRV__DETAIL__UPDATE_MARKER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'map_id'
// Member 'floor'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__struct.h"

/// Struct defined in srv/UpdateMarker in the package hric_msgs.
typedef struct hric_msgs__srv__UpdateMarker_Request
{
  /// marker名字（名字唯一，重名返回失败）
  rosidl_runtime_c__String name;
  /// 地图id，置空默认为当前地图。
  rosidl_runtime_c__String map_id;
  /// 楼层名字，置空默认为当前楼层。
  rosidl_runtime_c__String floor;
  /// marker的位置,theta取值范围[-pi,pi)
  geometry_msgs__msg__Pose2D pose;
} hric_msgs__srv__UpdateMarker_Request;

// Struct for a sequence of hric_msgs__srv__UpdateMarker_Request.
typedef struct hric_msgs__srv__UpdateMarker_Request__Sequence
{
  hric_msgs__srv__UpdateMarker_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__UpdateMarker_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'marker_old'
// Member 'marker_new'
#include "hric_msgs/msg/detail/marker_info__struct.h"

/// Struct defined in srv/UpdateMarker in the package hric_msgs.
typedef struct hric_msgs__srv__UpdateMarker_Response
{
  /// 表示服务调用是否成功
  bool success;
  /// 调用失败原因
  rosidl_runtime_c__String message;
  /// 返回的marker信息
  hric_msgs__msg__MarkerInfo marker_old;
  /// 返回的marker信息
  hric_msgs__msg__MarkerInfo marker_new;
} hric_msgs__srv__UpdateMarker_Response;

// Struct for a sequence of hric_msgs__srv__UpdateMarker_Response.
typedef struct hric_msgs__srv__UpdateMarker_Response__Sequence
{
  hric_msgs__srv__UpdateMarker_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__UpdateMarker_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__SRV__DETAIL__UPDATE_MARKER__STRUCT_H_
