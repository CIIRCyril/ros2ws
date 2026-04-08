// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:srv/ListMarkers.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__STRUCT_H_
#define HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ListMarkers in the package hric_msgs.
typedef struct hric_msgs__srv__ListMarkers_Request
{
  uint8_t structure_needs_at_least_one_member;
} hric_msgs__srv__ListMarkers_Request;

// Struct for a sequence of hric_msgs__srv__ListMarkers_Request.
typedef struct hric_msgs__srv__ListMarkers_Request__Sequence
{
  hric_msgs__srv__ListMarkers_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__ListMarkers_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'markers'
#include "hric_msgs/msg/detail/marker_info__struct.h"

/// Struct defined in srv/ListMarkers in the package hric_msgs.
typedef struct hric_msgs__srv__ListMarkers_Response
{
  /// 返回的marker信息列表
  hric_msgs__msg__MarkerInfo__Sequence markers;
} hric_msgs__srv__ListMarkers_Response;

// Struct for a sequence of hric_msgs__srv__ListMarkers_Response.
typedef struct hric_msgs__srv__ListMarkers_Response__Sequence
{
  hric_msgs__srv__ListMarkers_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__ListMarkers_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__STRUCT_H_
