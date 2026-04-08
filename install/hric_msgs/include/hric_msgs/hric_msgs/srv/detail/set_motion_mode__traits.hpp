// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:srv/SetMotionMode.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__TRAITS_HPP_
#define HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/srv/detail/set_motion_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMotionMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: walk_mode_request
  {
    out << "walk_mode_request: ";
    rosidl_generator_traits::value_to_yaml(msg.walk_mode_request, out);
    out << ", ";
  }

  // member: is_need_swing_arm
  {
    out << "is_need_swing_arm: ";
    rosidl_generator_traits::value_to_yaml(msg.is_need_swing_arm, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMotionMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: walk_mode_request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "walk_mode_request: ";
    rosidl_generator_traits::value_to_yaml(msg.walk_mode_request, out);
    out << "\n";
  }

  // member: is_need_swing_arm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_need_swing_arm: ";
    rosidl_generator_traits::value_to_yaml(msg.is_need_swing_arm, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMotionMode_Request & msg, bool use_flow_style = false)
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
  const hric_msgs::srv::SetMotionMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::SetMotionMode_Request & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::SetMotionMode_Request>()
{
  return "hric_msgs::srv::SetMotionMode_Request";
}

template<>
inline const char * name<hric_msgs::srv::SetMotionMode_Request>()
{
  return "hric_msgs/srv/SetMotionMode_Request";
}

template<>
struct has_fixed_size<hric_msgs::srv::SetMotionMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::srv::SetMotionMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::srv::SetMotionMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMotionMode_Response & msg,
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMotionMode_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMotionMode_Response & msg, bool use_flow_style = false)
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
  const hric_msgs::srv::SetMotionMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::SetMotionMode_Response & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::SetMotionMode_Response>()
{
  return "hric_msgs::srv::SetMotionMode_Response";
}

template<>
inline const char * name<hric_msgs::srv::SetMotionMode_Response>()
{
  return "hric_msgs/srv/SetMotionMode_Response";
}

template<>
struct has_fixed_size<hric_msgs::srv::SetMotionMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::srv::SetMotionMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::srv::SetMotionMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hric_msgs::srv::SetMotionMode>()
{
  return "hric_msgs::srv::SetMotionMode";
}

template<>
inline const char * name<hric_msgs::srv::SetMotionMode>()
{
  return "hric_msgs/srv/SetMotionMode";
}

template<>
struct has_fixed_size<hric_msgs::srv::SetMotionMode>
  : std::integral_constant<
    bool,
    has_fixed_size<hric_msgs::srv::SetMotionMode_Request>::value &&
    has_fixed_size<hric_msgs::srv::SetMotionMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<hric_msgs::srv::SetMotionMode>
  : std::integral_constant<
    bool,
    has_bounded_size<hric_msgs::srv::SetMotionMode_Request>::value &&
    has_bounded_size<hric_msgs::srv::SetMotionMode_Response>::value
  >
{
};

template<>
struct is_service<hric_msgs::srv::SetMotionMode>
  : std::true_type
{
};

template<>
struct is_service_request<hric_msgs::srv::SetMotionMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hric_msgs::srv::SetMotionMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__TRAITS_HPP_
