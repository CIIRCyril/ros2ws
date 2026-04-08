// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from monitor_msgs:msg/SysCpuDatas.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "monitor_msgs/msg/detail/sys_cpu_datas__rosidl_typesupport_introspection_c.h"
#include "monitor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "monitor_msgs/msg/detail/sys_cpu_datas__functions.h"
#include "monitor_msgs/msg/detail/sys_cpu_datas__struct.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/time.h"
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `cpu_datas`
#include "monitor_msgs/msg/sys_cpu_data.h"
// Member `cpu_datas`
#include "monitor_msgs/msg/detail/sys_cpu_data__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  monitor_msgs__msg__SysCpuDatas__init(message_memory);
}

void monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_fini_function(void * message_memory)
{
  monitor_msgs__msg__SysCpuDatas__fini(message_memory);
}

size_t monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__size_function__SysCpuDatas__cpu_datas(
  const void * untyped_member)
{
  const monitor_msgs__msg__SysCpuData__Sequence * member =
    (const monitor_msgs__msg__SysCpuData__Sequence *)(untyped_member);
  return member->size;
}

const void * monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__get_const_function__SysCpuDatas__cpu_datas(
  const void * untyped_member, size_t index)
{
  const monitor_msgs__msg__SysCpuData__Sequence * member =
    (const monitor_msgs__msg__SysCpuData__Sequence *)(untyped_member);
  return &member->data[index];
}

void * monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__get_function__SysCpuDatas__cpu_datas(
  void * untyped_member, size_t index)
{
  monitor_msgs__msg__SysCpuData__Sequence * member =
    (monitor_msgs__msg__SysCpuData__Sequence *)(untyped_member);
  return &member->data[index];
}

void monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__fetch_function__SysCpuDatas__cpu_datas(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const monitor_msgs__msg__SysCpuData * item =
    ((const monitor_msgs__msg__SysCpuData *)
    monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__get_const_function__SysCpuDatas__cpu_datas(untyped_member, index));
  monitor_msgs__msg__SysCpuData * value =
    (monitor_msgs__msg__SysCpuData *)(untyped_value);
  *value = *item;
}

void monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__assign_function__SysCpuDatas__cpu_datas(
  void * untyped_member, size_t index, const void * untyped_value)
{
  monitor_msgs__msg__SysCpuData * item =
    ((monitor_msgs__msg__SysCpuData *)
    monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__get_function__SysCpuDatas__cpu_datas(untyped_member, index));
  const monitor_msgs__msg__SysCpuData * value =
    (const monitor_msgs__msg__SysCpuData *)(untyped_value);
  *item = *value;
}

bool monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__resize_function__SysCpuDatas__cpu_datas(
  void * untyped_member, size_t size)
{
  monitor_msgs__msg__SysCpuData__Sequence * member =
    (monitor_msgs__msg__SysCpuData__Sequence *)(untyped_member);
  monitor_msgs__msg__SysCpuData__Sequence__fini(member);
  return monitor_msgs__msg__SysCpuData__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_member_array[2] = {
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__SysCpuDatas, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cpu_datas",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs__msg__SysCpuDatas, cpu_datas),  // bytes offset in struct
    NULL,  // default value
    monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__size_function__SysCpuDatas__cpu_datas,  // size() function pointer
    monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__get_const_function__SysCpuDatas__cpu_datas,  // get_const(index) function pointer
    monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__get_function__SysCpuDatas__cpu_datas,  // get(index) function pointer
    monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__fetch_function__SysCpuDatas__cpu_datas,  // fetch(index, &value) function pointer
    monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__assign_function__SysCpuDatas__cpu_datas,  // assign(index, value) function pointer
    monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__resize_function__SysCpuDatas__cpu_datas  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_members = {
  "monitor_msgs__msg",  // message namespace
  "SysCpuDatas",  // message name
  2,  // number of fields
  sizeof(monitor_msgs__msg__SysCpuDatas),
  monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_member_array,  // message members
  monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_init_function,  // function to initialize message memory (memory has to be allocated)
  monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_type_support_handle = {
  0,
  &monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_monitor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, monitor_msgs, msg, SysCpuDatas)() {
  monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, monitor_msgs, msg, SysCpuData)();
  if (!monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_type_support_handle.typesupport_identifier) {
    monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &monitor_msgs__msg__SysCpuDatas__rosidl_typesupport_introspection_c__SysCpuDatas_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
