// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from monitor_msgs:msg/ProcDatas.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "monitor_msgs/msg/detail/proc_datas__struct.hpp"
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

void ProcDatas_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) monitor_msgs::msg::ProcDatas(_init);
}

void ProcDatas_fini_function(void * message_memory)
{
  auto typed_message = static_cast<monitor_msgs::msg::ProcDatas *>(message_memory);
  typed_message->~ProcDatas();
}

size_t size_function__ProcDatas__proc_datas(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<monitor_msgs::msg::ProcData> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ProcDatas__proc_datas(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<monitor_msgs::msg::ProcData> *>(untyped_member);
  return &member[index];
}

void * get_function__ProcDatas__proc_datas(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<monitor_msgs::msg::ProcData> *>(untyped_member);
  return &member[index];
}

void fetch_function__ProcDatas__proc_datas(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const monitor_msgs::msg::ProcData *>(
    get_const_function__ProcDatas__proc_datas(untyped_member, index));
  auto & value = *reinterpret_cast<monitor_msgs::msg::ProcData *>(untyped_value);
  value = item;
}

void assign_function__ProcDatas__proc_datas(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<monitor_msgs::msg::ProcData *>(
    get_function__ProcDatas__proc_datas(untyped_member, index));
  const auto & value = *reinterpret_cast<const monitor_msgs::msg::ProcData *>(untyped_value);
  item = value;
}

void resize_function__ProcDatas__proc_datas(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<monitor_msgs::msg::ProcData> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ProcDatas_message_member_array[2] = {
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs::msg::ProcDatas, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "proc_datas",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<monitor_msgs::msg::ProcData>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(monitor_msgs::msg::ProcDatas, proc_datas),  // bytes offset in struct
    nullptr,  // default value
    size_function__ProcDatas__proc_datas,  // size() function pointer
    get_const_function__ProcDatas__proc_datas,  // get_const(index) function pointer
    get_function__ProcDatas__proc_datas,  // get(index) function pointer
    fetch_function__ProcDatas__proc_datas,  // fetch(index, &value) function pointer
    assign_function__ProcDatas__proc_datas,  // assign(index, value) function pointer
    resize_function__ProcDatas__proc_datas  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ProcDatas_message_members = {
  "monitor_msgs::msg",  // message namespace
  "ProcDatas",  // message name
  2,  // number of fields
  sizeof(monitor_msgs::msg::ProcDatas),
  ProcDatas_message_member_array,  // message members
  ProcDatas_init_function,  // function to initialize message memory (memory has to be allocated)
  ProcDatas_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ProcDatas_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ProcDatas_message_members,
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
get_message_type_support_handle<monitor_msgs::msg::ProcDatas>()
{
  return &::monitor_msgs::msg::rosidl_typesupport_introspection_cpp::ProcDatas_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, monitor_msgs, msg, ProcDatas)() {
  return &::monitor_msgs::msg::rosidl_typesupport_introspection_cpp::ProcDatas_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
