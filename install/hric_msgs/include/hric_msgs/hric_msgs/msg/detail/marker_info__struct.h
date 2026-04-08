// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:msg/MarkerInfo.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__MARKER_INFO__STRUCT_H_
#define HRIC_MSGS__MSG__DETAIL__MARKER_INFO__STRUCT_H_

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

/// Struct defined in msg/MarkerInfo in the package hric_msgs.
typedef struct hric_msgs__msg__MarkerInfo
{
  /// marker的名称，名称唯一
  rosidl_runtime_c__String name;
  /// 地图ID
  rosidl_runtime_c__String map_id;
  /// 楼层名称
  rosidl_runtime_c__String floor;
  /// marker的位置
  geometry_msgs__msg__Pose2D pose;
} hric_msgs__msg__MarkerInfo;

// Struct for a sequence of hric_msgs__msg__MarkerInfo.
typedef struct hric_msgs__msg__MarkerInfo__Sequence
{
  hric_msgs__msg__MarkerInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__msg__MarkerInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__MSG__DETAIL__MARKER_INFO__STRUCT_H_
