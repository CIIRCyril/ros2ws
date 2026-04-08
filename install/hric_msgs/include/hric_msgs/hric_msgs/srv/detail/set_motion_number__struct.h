// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:srv/SetMotionNumber.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__STRUCT_H_
#define HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetMotionNumber in the package hric_msgs.
typedef struct hric_msgs__srv__SetMotionNumber_Request
{
  bool is_motion;
  int32_t motion_number;
} hric_msgs__srv__SetMotionNumber_Request;

// Struct for a sequence of hric_msgs__srv__SetMotionNumber_Request.
typedef struct hric_msgs__srv__SetMotionNumber_Request__Sequence
{
  hric_msgs__srv__SetMotionNumber_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__SetMotionNumber_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetMotionNumber in the package hric_msgs.
typedef struct hric_msgs__srv__SetMotionNumber_Response
{
  bool success;
} hric_msgs__srv__SetMotionNumber_Response;

// Struct for a sequence of hric_msgs__srv__SetMotionNumber_Response.
typedef struct hric_msgs__srv__SetMotionNumber_Response__Sequence
{
  hric_msgs__srv__SetMotionNumber_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__srv__SetMotionNumber_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__STRUCT_H_
