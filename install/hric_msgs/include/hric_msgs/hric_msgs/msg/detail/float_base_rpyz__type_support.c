// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hric_msgs:msg/FloatBaseRPYZ.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hric_msgs/msg/detail/float_base_rpyz__rosidl_typesupport_introspection_c.h"
#include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hric_msgs/msg/detail/float_base_rpyz__functions.h"
#include "hric_msgs/msg/detail/float_base_rpyz__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__msg__FloatBaseRPYZ__init(message_memory);
}

void hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_fini_function(void * message_memory)
{
  hric_msgs__msg__FloatBaseRPYZ__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_message_member_array[4] = {
  {
    "roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__msg__FloatBaseRPYZ, roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__msg__FloatBaseRPYZ, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__msg__FloatBaseRPYZ, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__msg__FloatBaseRPYZ, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_message_members = {
  "hric_msgs__msg",  // message namespace
  "FloatBaseRPYZ",  // message name
  4,  // number of fields
  sizeof(hric_msgs__msg__FloatBaseRPYZ),
  hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_message_member_array,  // message members
  hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_message_type_support_handle = {
  0,
  &hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, msg, FloatBaseRPYZ)() {
  if (!hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_message_type_support_handle.typesupport_identifier) {
    hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__msg__FloatBaseRPYZ__rosidl_typesupport_introspection_c__FloatBaseRPYZ_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
