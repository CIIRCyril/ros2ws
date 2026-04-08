// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hric_msgs:srv/MarkHere.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hric_msgs/srv/detail/mark_here__rosidl_typesupport_introspection_c.h"
#include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hric_msgs/srv/detail/mark_here__functions.h"
#include "hric_msgs/srv/detail/mark_here__struct.h"


// Include directives for member types
// Member `name`
// Member `map_id`
// Member `floor`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__srv__MarkHere_Request__init(message_memory);
}

void hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_fini_function(void * message_memory)
{
  hric_msgs__srv__MarkHere_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_message_member_array[3] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__MarkHere_Request, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "map_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__MarkHere_Request, map_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "floor",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__MarkHere_Request, floor),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_message_members = {
  "hric_msgs__srv",  // message namespace
  "MarkHere_Request",  // message name
  3,  // number of fields
  sizeof(hric_msgs__srv__MarkHere_Request),
  hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_message_member_array,  // message members
  hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_message_type_support_handle = {
  0,
  &hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, MarkHere_Request)() {
  if (!hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_message_type_support_handle.typesupport_identifier) {
    hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__srv__MarkHere_Request__rosidl_typesupport_introspection_c__MarkHere_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/srv/detail/mark_here__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/srv/detail/mark_here__functions.h"
// already included above
// #include "hric_msgs/srv/detail/mark_here__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `marker`
#include "hric_msgs/msg/marker_info.h"
// Member `marker`
#include "hric_msgs/msg/detail/marker_info__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__srv__MarkHere_Response__init(message_memory);
}

void hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_fini_function(void * message_memory)
{
  hric_msgs__srv__MarkHere_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_message_member_array[3] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__MarkHere_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__MarkHere_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "marker",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__MarkHere_Response, marker),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_message_members = {
  "hric_msgs__srv",  // message namespace
  "MarkHere_Response",  // message name
  3,  // number of fields
  sizeof(hric_msgs__srv__MarkHere_Response),
  hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_message_member_array,  // message members
  hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_message_type_support_handle = {
  0,
  &hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, MarkHere_Response)() {
  hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, msg, MarkerInfo)();
  if (!hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_message_type_support_handle.typesupport_identifier) {
    hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__srv__MarkHere_Response__rosidl_typesupport_introspection_c__MarkHere_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hric_msgs/srv/detail/mark_here__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hric_msgs__srv__detail__mark_here__rosidl_typesupport_introspection_c__MarkHere_service_members = {
  "hric_msgs__srv",  // service namespace
  "MarkHere",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hric_msgs__srv__detail__mark_here__rosidl_typesupport_introspection_c__MarkHere_Request_message_type_support_handle,
  NULL  // response message
  // hric_msgs__srv__detail__mark_here__rosidl_typesupport_introspection_c__MarkHere_Response_message_type_support_handle
};

static rosidl_service_type_support_t hric_msgs__srv__detail__mark_here__rosidl_typesupport_introspection_c__MarkHere_service_type_support_handle = {
  0,
  &hric_msgs__srv__detail__mark_here__rosidl_typesupport_introspection_c__MarkHere_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, MarkHere_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, MarkHere_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, MarkHere)() {
  if (!hric_msgs__srv__detail__mark_here__rosidl_typesupport_introspection_c__MarkHere_service_type_support_handle.typesupport_identifier) {
    hric_msgs__srv__detail__mark_here__rosidl_typesupport_introspection_c__MarkHere_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hric_msgs__srv__detail__mark_here__rosidl_typesupport_introspection_c__MarkHere_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, MarkHere_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, MarkHere_Response)()->data;
  }

  return &hric_msgs__srv__detail__mark_here__rosidl_typesupport_introspection_c__MarkHere_service_type_support_handle;
}
