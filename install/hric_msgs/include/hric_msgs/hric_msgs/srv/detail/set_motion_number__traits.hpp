// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:srv/SetMotionNumber.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__TRAITS_HPP_
#define HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/srv/detail/set_motion_number__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMotionNumber_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_motion
  {
    out << "is_motion: ";
    rosidl_generator_traits::value_to_yaml(msg.is_motion, out);
    out << ", ";
  }

  // member: motion_number
  {
    out << "motion_number: ";
    rosidl_generator_traits::value_to_yaml(msg.motion_number, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMotionNumber_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_motion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_motion: ";
    rosidl_generator_traits::value_to_yaml(msg.is_motion, out);
    out << "\n";
  }

  // member: motion_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motion_number: ";
    rosidl_generator_traits::value_to_yaml(msg.motion_number, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMotionNumber_Request & msg, bool use_flow_style = false)
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
  const hric_msgs::srv::SetMotionNumber_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::SetMotionNumber_Request & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::SetMotionNumber_Request>()
{
  return "hric_msgs::srv::SetMotionNumber_Request";
}

template<>
inline const char * name<hric_msgs::srv::SetMotionNumber_Request>()
{
  return "hric_msgs/srv/SetMotionNumber_Request";
}

template<>
struct has_fixed_size<hric_msgs::srv::SetMotionNumber_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::srv::SetMotionNumber_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::srv::SetMotionNumber_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMotionNumber_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMotionNumber_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMotionNumber_Response & msg, bool use_flow_style = false)
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
  const hric_msgs::srv::SetMotionNumber_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::SetMotionNumber_Response & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::SetMotionNumber_Response>()
{
  return "hric_msgs::srv::SetMotionNumber_Response";
}

template<>
inline const char * name<hric_msgs::srv::SetMotionNumber_Response>()
{
  return "hric_msgs/srv/SetMotionNumber_Response";
}

template<>
struct has_fixed_size<hric_msgs::srv::SetMotionNumber_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::srv::SetMotionNumber_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::srv::SetMotionNumber_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hric_msgs::srv::SetMotionNumber>()
{
  return "hric_msgs::srv::SetMotionNumber";
}

template<>
inline const char * name<hric_msgs::srv::SetMotionNumber>()
{
  return "hric_msgs/srv/SetMotionNumber";
}

template<>
struct has_fixed_size<hric_msgs::srv::SetMotionNumber>
  : std::integral_constant<
    bool,
    has_fixed_size<hric_msgs::srv::SetMotionNumber_Request>::value &&
    has_fixed_size<hric_msgs::srv::SetMotionNumber_Response>::value
  >
{
};

template<>
struct has_bounded_size<hric_msgs::srv::SetMotionNumber>
  : std::integral_constant<
    bool,
    has_bounded_size<hric_msgs::srv::SetMotionNumber_Request>::value &&
    has_bounded_size<hric_msgs::srv::SetMotionNumber_Response>::value
  >
{
};

template<>
struct is_service<hric_msgs::srv::SetMotionNumber>
  : std::true_type
{
};

template<>
struct is_service_request<hric_msgs::srv::SetMotionNumber_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hric_msgs::srv::SetMotionNumber_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__TRAITS_HPP_
