// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:srv/Relocate.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__RELOCATE__TRAITS_HPP_
#define HRIC_MSGS__SRV__DETAIL__RELOCATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/srv/detail/relocate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose_robot'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Relocate_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose_robot
  {
    out << "pose_robot: ";
    to_flow_style_yaml(msg.pose_robot, out);
    out << ", ";
  }

  // member: match_type
  {
    out << "match_type: ";
    rosidl_generator_traits::value_to_yaml(msg.match_type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Relocate_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose_robot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_robot:\n";
    to_block_style_yaml(msg.pose_robot, out, indentation + 2);
  }

  // member: match_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "match_type: ";
    rosidl_generator_traits::value_to_yaml(msg.match_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Relocate_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hric_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hric_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hric_msgs::srv::Relocate_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::Relocate_Request & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::Relocate_Request>()
{
  return "hric_msgs::srv::Relocate_Request";
}

template<>
inline const char * name<hric_msgs::srv::Relocate_Request>()
{
  return "hric_msgs/srv/Relocate_Request";
}

template<>
struct has_fixed_size<hric_msgs::srv::Relocate_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<hric_msgs::srv::Relocate_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<hric_msgs::srv::Relocate_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Relocate_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Relocate_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
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

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Relocate_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hric_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hric_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hric_msgs::srv::Relocate_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::Relocate_Response & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::Relocate_Response>()
{
  return "hric_msgs::srv::Relocate_Response";
}

template<>
inline const char * name<hric_msgs::srv::Relocate_Response>()
{
  return "hric_msgs/srv/Relocate_Response";
}

template<>
struct has_fixed_size<hric_msgs::srv::Relocate_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hric_msgs::srv::Relocate_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hric_msgs::srv::Relocate_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hric_msgs::srv::Relocate>()
{
  return "hric_msgs::srv::Relocate";
}

template<>
inline const char * name<hric_msgs::srv::Relocate>()
{
  return "hric_msgs/srv/Relocate";
}

template<>
struct has_fixed_size<hric_msgs::srv::Relocate>
  : std::integral_constant<
    bool,
    has_fixed_size<hric_msgs::srv::Relocate_Request>::value &&
    has_fixed_size<hric_msgs::srv::Relocate_Response>::value
  >
{
};

template<>
struct has_bounded_size<hric_msgs::srv::Relocate>
  : std::integral_constant<
    bool,
    has_bounded_size<hric_msgs::srv::Relocate_Request>::value &&
    has_bounded_size<hric_msgs::srv::Relocate_Response>::value
  >
{
};

template<>
struct is_service<hric_msgs::srv::Relocate>
  : std::true_type
{
};

template<>
struct is_service_request<hric_msgs::srv::Relocate_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hric_msgs::srv::Relocate_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__SRV__DETAIL__RELOCATE__TRAITS_HPP_
