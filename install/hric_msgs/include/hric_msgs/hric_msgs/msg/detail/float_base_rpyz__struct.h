// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:msg/FloatBaseRPYZ.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__STRUCT_H_
#define HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FloatBaseRPYZ in the package hric_msgs.
typedef struct hric_msgs__msg__FloatBaseRPYZ
{
  double roll;
  double pitch;
  double yaw;
  double z;
} hric_msgs__msg__FloatBaseRPYZ;

// Struct for a sequence of hric_msgs__msg__FloatBaseRPYZ.
typedef struct hric_msgs__msg__FloatBaseRPYZ__Sequence
{
  hric_msgs__msg__FloatBaseRPYZ * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__msg__FloatBaseRPYZ__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__STRUCT_H_
