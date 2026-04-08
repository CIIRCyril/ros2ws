// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from monitor_msgs:msg/SysCpuData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "monitor_msgs/msg/detail/sys_cpu_data__rosidl_typesupport_introspection_c.h"
#include "monitor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "monitor_msgs/msg/detail/sys_cpu_data__functions.h"
#include "monitor_msgs/msg/detail/sys_cpu_data__struct.h"


// Include directives for member types
// Member `proc_array`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  monitor_msgs__msg__SysCpuData__init(message_memory);
}

void monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_fini_function(void * message_memory)
{
  monitor_msgs__msg__SysCpuData__fini(message_memory);
}

size_t monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__size_function__SysCpuData__proc_array(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__get_const_function__SysCpuData__proc_array(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__get_function__SysCpuData__proc_array(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__fetch_function__SysCpuData__proc_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__get_const_function__SysCpuData__proc_array(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__assign_function__SysCpuData__proc_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__get_function__SysCpuData__proc_array(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__resize_function__SysCpuData__proc_array(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_message_member_array[4] = {
  {
    "cpu_num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__SysCpuData, cpu_num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cpu_used",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__SysCpuData, cpu_used),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "proc_num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__SysCpuData, proc_num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "proc_array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__SysCpuData, proc_array),  // bytes offset in struct
    NULL,  // default value
    monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__size_function__SysCpuData__proc_array,  // size() function pointer
    monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__get_const_function__SysCpuData__proc_array,  // get_const(index) function pointer
    monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__get_function__SysCpuData__proc_array,  // get(index) function pointer
    monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__fetch_function__SysCpuData__proc_array,  // fetch(index, &value) function pointer
    monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__assign_function__SysCpuData__proc_array,  // assign(index, value) function pointer
    monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__resize_function__SysCpuData__proc_array  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_message_members = {
  "monitor_msgs__msg",  // message namespace
  "SysCpuData",  // message name
  4,  // number of fields
  sizeof(monitor_msgs__msg__SysCpuData),
  monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_message_member_array,  // message members
  monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_init_function,  // function to initialize message memory (memory has to be allocated)
  monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_message_type_support_handle = {
  0,
  &monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_monitor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, monitor_msgs, msg, SysCpuData)() {
  if (!monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_message_type_support_handle.typesupport_identifier) {
    monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &monitor_msgs__msg__SysCpuData__rosidl_typesupport_introspection_c__SysCpuData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
