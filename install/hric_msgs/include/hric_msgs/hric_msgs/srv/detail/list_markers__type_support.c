// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hric_msgs:srv/ListMarkers.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hric_msgs/srv/detail/list_markers__rosidl_typesupport_introspection_c.h"
#include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hric_msgs/srv/detail/list_markers__functions.h"
#include "hric_msgs/srv/detail/list_markers__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__srv__ListMarkers_Request__init(message_memory);
}

void hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_fini_function(void * message_memory)
{
  hric_msgs__srv__ListMarkers_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__ListMarkers_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_message_members = {
  "hric_msgs__srv",  // message namespace
  "ListMarkers_Request",  // message name
  1,  // number of fields
  sizeof(hric_msgs__srv__ListMarkers_Request),
  hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_message_member_array,  // message members
  hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_message_type_support_handle = {
  0,
  &hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, ListMarkers_Request)() {
  if (!hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_message_type_support_handle.typesupport_identifier) {
    hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__srv__ListMarkers_Request__rosidl_typesupport_introspection_c__ListMarkers_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/srv/detail/list_markers__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/srv/detail/list_markers__functions.h"
// already included above
// #include "hric_msgs/srv/detail/list_markers__struct.h"


// Include directives for member types
// Member `markers`
#include "hric_msgs/msg/marker_info.h"
// Member `markers`
#include "hric_msgs/msg/detail/marker_info__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__srv__ListMarkers_Response__init(message_memory);
}

void hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_fini_function(void * message_memory)
{
  hric_msgs__srv__ListMarkers_Response__fini(message_memory);
}

size_t hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__size_function__ListMarkers_Response__markers(
  const void * untyped_member)
{
  const hric_msgs__msg__MarkerInfo__Sequence * member =
    (const hric_msgs__msg__MarkerInfo__Sequence *)(untyped_member);
  return member->size;
}

const void * hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__get_const_function__ListMarkers_Response__markers(
  const void * untyped_member, size_t index)
{
  const hric_msgs__msg__MarkerInfo__Sequence * member =
    (const hric_msgs__msg__MarkerInfo__Sequence *)(untyped_member);
  return &member->data[index];
}

void * hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__get_function__ListMarkers_Response__markers(
  void * untyped_member, size_t index)
{
  hric_msgs__msg__MarkerInfo__Sequence * member =
    (hric_msgs__msg__MarkerInfo__Sequence *)(untyped_member);
  return &member->data[index];
}

void hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__fetch_function__ListMarkers_Response__markers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const hric_msgs__msg__MarkerInfo * item =
    ((const hric_msgs__msg__MarkerInfo *)
    hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__get_const_function__ListMarkers_Response__markers(untyped_member, index));
  hric_msgs__msg__MarkerInfo * value =
    (hric_msgs__msg__MarkerInfo *)(untyped_value);
  *value = *item;
}

void hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__assign_function__ListMarkers_Response__markers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  hric_msgs__msg__MarkerInfo * item =
    ((hric_msgs__msg__MarkerInfo *)
    hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__get_function__ListMarkers_Response__markers(untyped_member, index));
  const hric_msgs__msg__MarkerInfo * value =
    (const hric_msgs__msg__MarkerInfo *)(untyped_value);
  *item = *value;
}

bool hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__resize_function__ListMarkers_Response__markers(
  void * untyped_member, size_t size)
{
  hric_msgs__msg__MarkerInfo__Sequence * member =
    (hric_msgs__msg__MarkerInfo__Sequence *)(untyped_member);
  hric_msgs__msg__MarkerInfo__Sequence__fini(member);
  return hric_msgs__msg__MarkerInfo__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_message_member_array[1] = {
  {
    "markers",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__srv__ListMarkers_Response, markers),  // bytes offset in struct
    NULL,  // default value
    hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__size_function__ListMarkers_Response__markers,  // size() function pointer
    hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__get_const_function__ListMarkers_Response__markers,  // get_const(index) function pointer
    hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__get_function__ListMarkers_Response__markers,  // get(index) function pointer
    hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__fetch_function__ListMarkers_Response__markers,  // fetch(index, &value) function pointer
    hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__assign_function__ListMarkers_Response__markers,  // assign(index, value) function pointer
    hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__resize_function__ListMarkers_Response__markers  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_message_members = {
  "hric_msgs__srv",  // message namespace
  "ListMarkers_Response",  // message name
  1,  // number of fields
  sizeof(hric_msgs__srv__ListMarkers_Response),
  hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_message_member_array,  // message members
  hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_message_type_support_handle = {
  0,
  &hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, ListMarkers_Response)() {
  hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, msg, MarkerInfo)();
  if (!hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_message_type_support_handle.typesupport_identifier) {
    hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__srv__ListMarkers_Response__rosidl_typesupport_introspection_c__ListMarkers_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hric_msgs/srv/detail/list_markers__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hric_msgs__srv__detail__list_markers__rosidl_typesupport_introspection_c__ListMarkers_service_members = {
  "hric_msgs__srv",  // service namespace
  "ListMarkers",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hric_msgs__srv__detail__list_markers__rosidl_typesupport_introspection_c__ListMarkers_Request_message_type_support_handle,
  NULL  // response message
  // hric_msgs__srv__detail__list_markers__rosidl_typesupport_introspection_c__ListMarkers_Response_message_type_support_handle
};

static rosidl_service_type_support_t hric_msgs__srv__detail__list_markers__rosidl_typesupport_introspection_c__ListMarkers_service_type_support_handle = {
  0,
  &hric_msgs__srv__detail__list_markers__rosidl_typesupport_introspection_c__ListMarkers_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, ListMarkers_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, ListMarkers_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, ListMarkers)() {
  if (!hric_msgs__srv__detail__list_markers__rosidl_typesupport_introspection_c__ListMarkers_service_type_support_handle.typesupport_identifier) {
    hric_msgs__srv__detail__list_markers__rosidl_typesupport_introspection_c__ListMarkers_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hric_msgs__srv__detail__list_markers__rosidl_typesupport_introspection_c__ListMarkers_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, ListMarkers_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, srv, ListMarkers_Response)()->data;
  }

  return &hric_msgs__srv__detail__list_markers__rosidl_typesupport_introspection_c__ListMarkers_service_type_support_handle;
}
