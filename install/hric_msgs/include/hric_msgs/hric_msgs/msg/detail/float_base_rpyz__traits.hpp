// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:msg/FloatBaseRPYZ.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__TRAITS_HPP_
#define HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/msg/detail/float_base_rpyz__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hric_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FloatBaseRPYZ & msg,
  std::ostream & out)
{
  out << "{";
  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FloatBaseRPYZ & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FloatBaseRPYZ & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace hric_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hric_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hric_msgs::msg::FloatBaseRPYZ & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::msg::FloatBaseRPYZ & msg)
{
  return hric_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::msg::FloatBaseRPYZ>()
{
  return "hric_msgs::msg::FloatBaseRPYZ";
}

template<>
inline const char * name<hric_msgs::msg::FloatBaseRPYZ>()
{
  return "hric_msgs/msg/FloatBaseRPYZ";
}

template<>
struct has_fixed_size<hric_msgs::msg::FloatBaseRPYZ>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::msg::FloatBaseRPYZ>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::msg::FloatBaseRPYZ>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__TRAITS_HPP_
