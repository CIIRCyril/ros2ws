// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:msg/MotionStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__TRAITS_HPP_
#define HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/msg/detail/motion_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace hric_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotionStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: walk_mode
  {
    out << "walk_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.walk_mode, out);
    out << ", ";
  }

  // member: is_console_control
  {
    out << "is_console_control: ";
    rosidl_generator_traits::value_to_yaml(msg.is_console_control, out);
    out << ", ";
  }

  // member: is_swing_arm
  {
    out << "is_swing_arm: ";
    rosidl_generator_traits::value_to_yaml(msg.is_swing_arm, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotionStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: walk_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "walk_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.walk_mode, out);
    out << "\n";
  }

  // member: is_console_control
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_console_control: ";
    rosidl_generator_traits::value_to_yaml(msg.is_console_control, out);
    out << "\n";
  }

  // member: is_swing_arm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_swing_arm: ";
    rosidl_generator_traits::value_to_yaml(msg.is_swing_arm, out);
    out << "\n";
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotionStatus & msg, bool use_flow_style = false)
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
  const hric_msgs::msg::MotionStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::msg::MotionStatus & msg)
{
  return hric_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::msg::MotionStatus>()
{
  return "hric_msgs::msg::MotionStatus";
}

template<>
inline const char * name<hric_msgs::msg::MotionStatus>()
{
  return "hric_msgs/msg/MotionStatus";
}

template<>
struct has_fixed_size<hric_msgs::msg::MotionStatus>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Twist>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<hric_msgs::msg::MotionStatus>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Twist>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<hric_msgs::msg::MotionStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__TRAITS_HPP_
