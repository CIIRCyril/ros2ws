// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:msg/MotionStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__STRUCT_HPP_
#define HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__msg__MotionStatus __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__msg__MotionStatus __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotionStatus_
{
  using Type = MotionStatus_<ContainerAllocator>;

  explicit MotionStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    velocity(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->walk_mode = 0;
      this->is_console_control = false;
      this->is_swing_arm = false;
      this->error_code = 0ul;
    }
  }

  explicit MotionStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    velocity(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->walk_mode = 0;
      this->is_console_control = false;
      this->is_swing_arm = false;
      this->error_code = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _velocity_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _velocity_type velocity;
  using _walk_mode_type =
    uint8_t;
  _walk_mode_type walk_mode;
  using _is_console_control_type =
    bool;
  _is_console_control_type is_console_control;
  using _is_swing_arm_type =
    bool;
  _is_swing_arm_type is_swing_arm;
  using _error_code_type =
    uint32_t;
  _error_code_type error_code;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__walk_mode(
    const uint8_t & _arg)
  {
    this->walk_mode = _arg;
    return *this;
  }
  Type & set__is_console_control(
    const bool & _arg)
  {
    this->is_console_control = _arg;
    return *this;
  }
  Type & set__is_swing_arm(
    const bool & _arg)
  {
    this->is_swing_arm = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint32_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t NONE =
    0u;
  static constexpr uint32_t UNKNOWN =
    400u;

  // pointer types
  using RawPtr =
    hric_msgs::msg::MotionStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::msg::MotionStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::msg::MotionStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::msg::MotionStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::MotionStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::MotionStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::MotionStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::MotionStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::msg::MotionStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::msg::MotionStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__msg__MotionStatus
    std::shared_ptr<hric_msgs::msg::MotionStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__msg__MotionStatus
    std::shared_ptr<hric_msgs::msg::MotionStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotionStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->walk_mode != other.walk_mode) {
      return false;
    }
    if (this->is_console_control != other.is_console_control) {
      return false;
    }
    if (this->is_swing_arm != other.is_swing_arm) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotionStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotionStatus_

// alias to use template instance with default allocator
using MotionStatus =
  hric_msgs::msg::MotionStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t MotionStatus_<ContainerAllocator>::NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t MotionStatus_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__STRUCT_HPP_
