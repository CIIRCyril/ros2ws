// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xsys_msgs:srv/GetSerialNumber.idl
// generated code does not contain a copyright notice

#ifndef XSYS_MSGS__SRV__DETAIL__GET_SERIAL_NUMBER__TRAITS_HPP_
#define XSYS_MSGS__SRV__DETAIL__GET_SERIAL_NUMBER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xsys_msgs/srv/detail/get_serial_number__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace xsys_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSerialNumber_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSerialNumber_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSerialNumber_Request & msg, bool use_flow_style = false)
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

}  // namespace xsys_msgs

namespace rosidl_generator_traits
{

[[deprecated("use xsys_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xsys_msgs::srv::GetSerialNumber_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  xsys_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xsys_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const xsys_msgs::srv::GetSerialNumber_Request & msg)
{
  return xsys_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<xsys_msgs::srv::GetSerialNumber_Request>()
{
  return "xsys_msgs::srv::GetSerialNumber_Request";
}

template<>
inline const char * name<xsys_msgs::srv::GetSerialNumber_Request>()
{
  return "xsys_msgs/srv/GetSerialNumber_Request";
}

template<>
struct has_fixed_size<xsys_msgs::srv::GetSerialNumber_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xsys_msgs::srv::GetSerialNumber_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xsys_msgs::srv::GetSerialNumber_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace xsys_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSerialNumber_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: serial_number
  {
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSerialNumber_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: serial_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSerialNumber_Response & msg, bool use_flow_style = false)
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

}  // namespace xsys_msgs

namespace rosidl_generator_traits
{

[[deprecated("use xsys_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xsys_msgs::srv::GetSerialNumber_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  xsys_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xsys_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const xsys_msgs::srv::GetSerialNumber_Response & msg)
{
  return xsys_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<xsys_msgs::srv::GetSerialNumber_Response>()
{
  return "xsys_msgs::srv::GetSerialNumber_Response";
}

template<>
inline const char * name<xsys_msgs::srv::GetSerialNumber_Response>()
{
  return "xsys_msgs/srv/GetSerialNumber_Response";
}

template<>
struct has_fixed_size<xsys_msgs::srv::GetSerialNumber_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<xsys_msgs::srv::GetSerialNumber_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<xsys_msgs::srv::GetSerialNumber_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<xsys_msgs::srv::GetSerialNumber>()
{
  return "xsys_msgs::srv::GetSerialNumber";
}

template<>
inline const char * name<xsys_msgs::srv::GetSerialNumber>()
{
  return "xsys_msgs/srv/GetSerialNumber";
}

template<>
struct has_fixed_size<xsys_msgs::srv::GetSerialNumber>
  : std::integral_constant<
    bool,
    has_fixed_size<xsys_msgs::srv::GetSerialNumber_Request>::value &&
    has_fixed_size<xsys_msgs::srv::GetSerialNumber_Response>::value
  >
{
};

template<>
struct has_bounded_size<xsys_msgs::srv::GetSerialNumber>
  : std::integral_constant<
    bool,
    has_bounded_size<xsys_msgs::srv::GetSerialNumber_Request>::value &&
    has_bounded_size<xsys_msgs::srv::GetSerialNumber_Response>::value
  >
{
};

template<>
struct is_service<xsys_msgs::srv::GetSerialNumber>
  : std::true_type
{
};

template<>
struct is_service_request<xsys_msgs::srv::GetSerialNumber_Request>
  : std::true_type
{
};

template<>
struct is_service_response<xsys_msgs::srv::GetSerialNumber_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // XSYS_MSGS__SRV__DETAIL__GET_SERIAL_NUMBER__TRAITS_HPP_
