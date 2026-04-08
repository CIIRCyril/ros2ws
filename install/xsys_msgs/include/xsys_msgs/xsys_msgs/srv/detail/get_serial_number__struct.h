// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsys_msgs:srv/GetSerialNumber.idl
// generated code does not contain a copyright notice

#ifndef XSYS_MSGS__SRV__DETAIL__GET_SERIAL_NUMBER__STRUCT_H_
#define XSYS_MSGS__SRV__DETAIL__GET_SERIAL_NUMBER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SERVICE_NAME'.
static const char * const xsys_msgs__srv__GetSerialNumber_Request__SERVICE_NAME = "/xsys/get_serial_number";

/// Struct defined in srv/GetSerialNumber in the package xsys_msgs.
typedef struct xsys_msgs__srv__GetSerialNumber_Request
{
  uint8_t structure_needs_at_least_one_member;
} xsys_msgs__srv__GetSerialNumber_Request;

// Struct for a sequence of xsys_msgs__srv__GetSerialNumber_Request.
typedef struct xsys_msgs__srv__GetSerialNumber_Request__Sequence
{
  xsys_msgs__srv__GetSerialNumber_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsys_msgs__srv__GetSerialNumber_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'serial_number'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetSerialNumber in the package xsys_msgs.
typedef struct xsys_msgs__srv__GetSerialNumber_Response
{
  rosidl_runtime_c__String serial_number;
} xsys_msgs__srv__GetSerialNumber_Response;

// Struct for a sequence of xsys_msgs__srv__GetSerialNumber_Response.
typedef struct xsys_msgs__srv__GetSerialNumber_Response__Sequence
{
  xsys_msgs__srv__GetSerialNumber_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsys_msgs__srv__GetSerialNumber_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSYS_MSGS__SRV__DETAIL__GET_SERIAL_NUMBER__STRUCT_H_
