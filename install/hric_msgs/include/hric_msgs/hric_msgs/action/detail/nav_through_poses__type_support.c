// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hric_msgs:action/NavThroughPoses.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
#include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hric_msgs/action/detail/nav_through_poses__functions.h"
#include "hric_msgs/action/detail/nav_through_poses__struct.h"


// Include directives for member types
// Member `poses`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `poses`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__action__NavThroughPoses_Goal__init(message_memory);
}

void hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_fini_function(void * message_memory)
{
  hric_msgs__action__NavThroughPoses_Goal__fini(message_memory);
}

size_t hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__size_function__NavThroughPoses_Goal__poses(
  const void * untyped_member)
{
  const geometry_msgs__msg__PoseStamped__Sequence * member =
    (const geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  return member->size;
}

const void * hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__get_const_function__NavThroughPoses_Goal__poses(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__PoseStamped__Sequence * member =
    (const geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void * hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__get_function__NavThroughPoses_Goal__poses(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__PoseStamped__Sequence * member =
    (geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__fetch_function__NavThroughPoses_Goal__poses(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__PoseStamped * item =
    ((const geometry_msgs__msg__PoseStamped *)
    hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__get_const_function__NavThroughPoses_Goal__poses(untyped_member, index));
  geometry_msgs__msg__PoseStamped * value =
    (geometry_msgs__msg__PoseStamped *)(untyped_value);
  *value = *item;
}

void hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__assign_function__NavThroughPoses_Goal__poses(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__PoseStamped * item =
    ((geometry_msgs__msg__PoseStamped *)
    hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__get_function__NavThroughPoses_Goal__poses(untyped_member, index));
  const geometry_msgs__msg__PoseStamped * value =
    (const geometry_msgs__msg__PoseStamped *)(untyped_value);
  *item = *value;
}

bool hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__resize_function__NavThroughPoses_Goal__poses(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__PoseStamped__Sequence * member =
    (geometry_msgs__msg__PoseStamped__Sequence *)(untyped_member);
  geometry_msgs__msg__PoseStamped__Sequence__fini(member);
  return geometry_msgs__msg__PoseStamped__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_message_member_array[1] = {
  {
    "poses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_Goal, poses),  // bytes offset in struct
    NULL,  // default value
    hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__size_function__NavThroughPoses_Goal__poses,  // size() function pointer
    hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__get_const_function__NavThroughPoses_Goal__poses,  // get_const(index) function pointer
    hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__get_function__NavThroughPoses_Goal__poses,  // get(index) function pointer
    hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__fetch_function__NavThroughPoses_Goal__poses,  // fetch(index, &value) function pointer
    hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__assign_function__NavThroughPoses_Goal__poses,  // assign(index, value) function pointer
    hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__resize_function__NavThroughPoses_Goal__poses  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_message_members = {
  "hric_msgs__action",  // message namespace
  "NavThroughPoses_Goal",  // message name
  1,  // number of fields
  sizeof(hric_msgs__action__NavThroughPoses_Goal),
  hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_message_member_array,  // message members
  hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_message_type_support_handle = {
  0,
  &hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_Goal)() {
  hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_message_type_support_handle.typesupport_identifier) {
    hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__action__NavThroughPoses_Goal__rosidl_typesupport_introspection_c__NavThroughPoses_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__functions.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__action__NavThroughPoses_Result__init(message_memory);
}

void hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_fini_function(void * message_memory)
{
  hric_msgs__action__NavThroughPoses_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_message_member_array[1] = {
  {
    "error_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_Result, error_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_message_members = {
  "hric_msgs__action",  // message namespace
  "NavThroughPoses_Result",  // message name
  1,  // number of fields
  sizeof(hric_msgs__action__NavThroughPoses_Result),
  hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_message_member_array,  // message members
  hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_message_type_support_handle = {
  0,
  &hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_Result)() {
  if (!hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_message_type_support_handle.typesupport_identifier) {
    hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__action__NavThroughPoses_Result__rosidl_typesupport_introspection_c__NavThroughPoses_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__functions.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__action__NavThroughPoses_Feedback__init(message_memory);
}

void hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_fini_function(void * message_memory)
{
  hric_msgs__action__NavThroughPoses_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_Feedback, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_message_members = {
  "hric_msgs__action",  // message namespace
  "NavThroughPoses_Feedback",  // message name
  1,  // number of fields
  sizeof(hric_msgs__action__NavThroughPoses_Feedback),
  hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_message_member_array,  // message members
  hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_message_type_support_handle = {
  0,
  &hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_Feedback)() {
  if (!hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_message_type_support_handle.typesupport_identifier) {
    hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__action__NavThroughPoses_Feedback__rosidl_typesupport_introspection_c__NavThroughPoses_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__functions.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "hric_msgs/action/nav_through_poses.h"
// Member `goal`
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__action__NavThroughPoses_SendGoal_Request__init(message_memory);
}

void hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_fini_function(void * message_memory)
{
  hric_msgs__action__NavThroughPoses_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_members = {
  "hric_msgs__action",  // message namespace
  "NavThroughPoses_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(hric_msgs__action__NavThroughPoses_SendGoal_Request),
  hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_member_array,  // message members
  hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_type_support_handle = {
  0,
  &hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_SendGoal_Request)() {
  hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_Goal)();
  if (!hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__action__NavThroughPoses_SendGoal_Request__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__functions.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__action__NavThroughPoses_SendGoal_Response__init(message_memory);
}

void hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_fini_function(void * message_memory)
{
  hric_msgs__action__NavThroughPoses_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_members = {
  "hric_msgs__action",  // message namespace
  "NavThroughPoses_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(hric_msgs__action__NavThroughPoses_SendGoal_Response),
  hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_member_array,  // message members
  hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_type_support_handle = {
  0,
  &hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_SendGoal_Response)() {
  hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__action__NavThroughPoses_SendGoal_Response__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_service_members = {
  "hric_msgs__action",  // service namespace
  "NavThroughPoses_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_service_type_support_handle = {
  0,
  &hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_SendGoal)() {
  if (!hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_service_type_support_handle.typesupport_identifier) {
    hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_SendGoal_Response)()->data;
  }

  return &hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__functions.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__action__NavThroughPoses_GetResult_Request__init(message_memory);
}

void hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_fini_function(void * message_memory)
{
  hric_msgs__action__NavThroughPoses_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_members = {
  "hric_msgs__action",  // message namespace
  "NavThroughPoses_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(hric_msgs__action__NavThroughPoses_GetResult_Request),
  hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_member_array,  // message members
  hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_type_support_handle = {
  0,
  &hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_GetResult_Request)() {
  hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__action__NavThroughPoses_GetResult_Request__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__functions.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "hric_msgs/action/nav_through_poses.h"
// Member `result`
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__action__NavThroughPoses_GetResult_Response__init(message_memory);
}

void hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_fini_function(void * message_memory)
{
  hric_msgs__action__NavThroughPoses_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_members = {
  "hric_msgs__action",  // message namespace
  "NavThroughPoses_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(hric_msgs__action__NavThroughPoses_GetResult_Response),
  hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_member_array,  // message members
  hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_type_support_handle = {
  0,
  &hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_GetResult_Response)() {
  hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_Result)();
  if (!hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__action__NavThroughPoses_GetResult_Response__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_service_members = {
  "hric_msgs__action",  // service namespace
  "NavThroughPoses_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_service_type_support_handle = {
  0,
  &hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_GetResult)() {
  if (!hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_service_type_support_handle.typesupport_identifier) {
    hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_GetResult_Response)()->data;
  }

  return &hric_msgs__action__detail__nav_through_poses__rosidl_typesupport_introspection_c__NavThroughPoses_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hric_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__functions.h"
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "hric_msgs/action/nav_through_poses.h"
// Member `feedback`
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hric_msgs__action__NavThroughPoses_FeedbackMessage__init(message_memory);
}

void hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_fini_function(void * message_memory)
{
  hric_msgs__action__NavThroughPoses_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hric_msgs__action__NavThroughPoses_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_members = {
  "hric_msgs__action",  // message namespace
  "NavThroughPoses_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(hric_msgs__action__NavThroughPoses_FeedbackMessage),
  hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_member_array,  // message members
  hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_type_support_handle = {
  0,
  &hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hric_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_FeedbackMessage)() {
  hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hric_msgs, action, NavThroughPoses_Feedback)();
  if (!hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hric_msgs__action__NavThroughPoses_FeedbackMessage__rosidl_typesupport_introspection_c__NavThroughPoses_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
