// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from monitor_msgs:msg/ProcCpuData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "monitor_msgs/msg/detail/proc_cpu_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace monitor_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ProcCpuData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) monitor_msgs::msg::ProcCpuData(_init);
}

void ProcCpuData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<monitor_msgs::msg::ProcCpuData *>(message_memory);
  typed_message->~ProcCpuData();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ProcCpuData_message_member_array[2] = {
  {
    "num",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs::msg::ProcCpuData, num),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "used",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs::msg::ProcCpuData, used),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ProcCpuData_message_members = {
  "monitor_msgs::msg",  // message namespace
  "ProcCpuData",  // message name
  2,  // number of fields
  sizeof(monitor_msgs::msg::ProcCpuData),
  ProcCpuData_message_member_array,  // message members
  ProcCpuData_init_function,  // function to initialize message memory (memory has to be allocated)
  ProcCpuData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ProcCpuData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ProcCpuData_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace monitor_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<monitor_msgs::msg::ProcCpuData>()
{
  return &::monitor_msgs::msg::rosidl_typesupport_introspection_cpp::ProcCpuData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, monitor_msgs, msg, ProcCpuData)() {
  return &::monitor_msgs::msg::rosidl_typesupport_introspection_cpp::ProcCpuData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
