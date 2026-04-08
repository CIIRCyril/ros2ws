// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from monitor_msgs:msg/ProcData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "monitor_msgs/msg/detail/proc_data__rosidl_typesupport_introspection_c.h"
#include "monitor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "monitor_msgs/msg/detail/proc_data__functions.h"
#include "monitor_msgs/msg/detail/proc_data__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `cpu_data`
#include "monitor_msgs/msg/proc_cpu_data.h"
// Member `cpu_data`
#include "monitor_msgs/msg/detail/proc_cpu_data__rosidl_typesupport_introspection_c.h"
// Member `io_data`
#include "monitor_msgs/msg/proc_io_data.h"
// Member `io_data`
#include "monitor_msgs/msg/detail/proc_io_data__rosidl_typesupport_introspection_c.h"
// Member `mem_data`
#include "monitor_msgs/msg/proc_mem_data.h"
// Member `mem_data`
#include "monitor_msgs/msg/detail/proc_mem_data__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  monitor_msgs__msg__ProcData__init(message_memory);
}

void monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_fini_function(void * message_memory)
{
  monitor_msgs__msg__ProcData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_member_array[6] = {
  {
    "pid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__ProcData, pid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__ProcData, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "active",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__ProcData, active),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cpu_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__ProcData, cpu_data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "io_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__ProcData, io_data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mem_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__ProcData, mem_data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_members = {
  "monitor_msgs__msg",  // message namespace
  "ProcData",  // message name
  6,  // number of fields
  sizeof(monitor_msgs__msg__ProcData),
  monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_member_array,  // message members
  monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_init_function,  // function to initialize message memory (memory has to be allocated)
  monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_type_support_handle = {
  0,
  &monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_monitor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, monitor_msgs, msg, ProcData)() {
  monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, monitor_msgs, msg, ProcCpuData)();
  monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, monitor_msgs, msg, ProcIoData)();
  monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, monitor_msgs, msg, ProcMemData)();
  if (!monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_type_support_handle.typesupport_identifier) {
    monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &monitor_msgs__msg__ProcData__rosidl_typesupport_introspection_c__ProcData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
