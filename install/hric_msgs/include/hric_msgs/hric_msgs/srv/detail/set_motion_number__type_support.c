// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hric_msgs:srv/SetMotionNumber.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hric_msgs/srv/detail/set_motion_number__rosidl_typesupport_introspection_c.h"
#include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hric_msgs/srv/detail/set_motion_number__functions.h"
#include "hric_msgs/srv/detail/set_motion_number__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__srv__SetMotionNumber_Request__init(message_memory);
}

void hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_fini_function(void * message_memory)
{
  hric_msgs__srv__SetMotionNumber_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_message_member_array[2] = {
  {
    "is_motion",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__SetMotionNumber_Request, is_motion),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motion_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__SetMotionNumber_Request, motion_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_message_members = {
  "hric_msgs__srv",  // message namespace
  "SetMotionNumber_Request",  // message name
  2,  // number of fields
  sizeof(hric_msgs__srv__SetMotionNumber_Request),
  hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_message_member_array,  // message members
  hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_message_type_support_handle = {
  0,
  &hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, SetMotionNumber_Request)() {
  if (!hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_message_type_support_handle.typesupport_identifier) {
    hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__srv__SetMotionNumber_Request__rosidl_typesupport_introspection_c__SetMotionNumber_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/srv/detail/set_motion_number__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/srv/detail/set_motion_number__functions.h"
// already included above
// #include "hric_msgs/srv/detail/set_motion_number__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__srv__SetMotionNumber_Response__init(message_memory);
}

void hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_fini_function(void * message_memory)
{
  hric_msgs__srv__SetMotionNumber_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__SetMotionNumber_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_message_members = {
  "hric_msgs__srv",  // message namespace
  "SetMotionNumber_Response",  // message name
  1,  // number of fields
  sizeof(hric_msgs__srv__SetMotionNumber_Response),
  hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_message_member_array,  // message members
  hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_message_type_support_handle = {
  0,
  &hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, SetMotionNumber_Response)() {
  if (!hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_message_type_support_handle.typesupport_identifier) {
    hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__srv__SetMotionNumber_Response__rosidl_typesupport_introspection_c__SetMotionNumber_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hric_msgs/srv/detail/set_motion_number__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hric_msgs__srv__detail__set_motion_number__rosidl_typesupport_introspection_c__SetMotionNumber_service_members = {
  "hric_msgs__srv",  // service namespace
  "SetMotionNumber",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hric_msgs__srv__detail__set_motion_number__rosidl_typesupport_introspection_c__SetMotionNumber_Request_message_type_support_handle,
  NULL  // response message
  // hric_msgs__srv__detail__set_motion_number__rosidl_typesupport_introspection_c__SetMotionNumber_Response_message_type_support_handle
};

static rosidl_service_type_support_t hric_msgs__srv__detail__set_motion_number__rosidl_typesupport_introspection_c__SetMotionNumber_service_type_support_handle = {
  0,
  &hric_msgs__srv__detail__set_motion_number__rosidl_typesupport_introspection_c__SetMotionNumber_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, SetMotionNumber_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, SetMotionNumber_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, SetMotionNumber)() {
  if (!hric_msgs__srv__detail__set_motion_number__rosidl_typesupport_introspection_c__SetMotionNumber_service_type_support_handle.typesupport_identifier) {
    hric_msgs__srv__detail__set_motion_number__rosidl_typesupport_introspection_c__SetMotionNumber_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hric_msgs__srv__detail__set_motion_number__rosidl_typesupport_introspection_c__SetMotionNumber_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, SetMotionNumber_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, SetMotionNumber_Response)()->data;
  }

  return &hric_msgs__srv__detail__set_motion_number__rosidl_typesupport_introspection_c__SetMotionNumber_service_type_support_handle;
}
