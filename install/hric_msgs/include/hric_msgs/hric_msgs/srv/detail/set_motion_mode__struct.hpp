// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:srv/SetMotionMode.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__STRUCT_HPP_
#define HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__SetMotionMode_Request __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__SetMotionMode_Request __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetMotionMode_Request_
{
  using Type = SetMotionMode_Request_<ContainerAllocator>;

  explicit SetMotionMode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->walk_mode_request = 0;
      this->is_need_swing_arm = false;
    }
  }

  explicit SetMotionMode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->walk_mode_request = 0;
      this->is_need_swing_arm = false;
    }
  }

  // field types and members
  using _walk_mode_request_type =
    uint8_t;
  _walk_mode_request_type walk_mode_request;
  using _is_need_swing_arm_type =
    bool;
  _is_need_swing_arm_type is_need_swing_arm;

  // setters for named parameter idiom
  Type & set__walk_mode_request(
    const uint8_t & _arg)
  {
    this->walk_mode_request = _arg;
    return *this;
  }
  Type & set__is_need_swing_arm(
    const bool & _arg)
  {
    this->is_need_swing_arm = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t START =
    0u;
  static constexpr uint8_t STOP =
    1u;
  static constexpr uint8_t ZERO =
    2u;
  static constexpr uint8_t STAND =
    3u;
  static constexpr uint8_t WALK =
    4u;
  static constexpr uint8_t RUN =
    5u;

  // pointer types
  using RawPtr =
    hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__SetMotionMode_Request
    std::shared_ptr<hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__SetMotionMode_Request
    std::shared_ptr<hric_msgs::srv::SetMotionMode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetMotionMode_Request_ & other) const
  {
    if (this->walk_mode_request != other.walk_mode_request) {
      return false;
    }
    if (this->is_need_swing_arm != other.is_need_swing_arm) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetMotionMode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetMotionMode_Request_

// alias to use template instance with default allocator
using SetMotionMode_Request =
  hric_msgs::srv::SetMotionMode_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetMotionMode_Request_<ContainerAllocator>::START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetMotionMode_Request_<ContainerAllocator>::STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetMotionMode_Request_<ContainerAllocator>::ZERO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetMotionMode_Request_<ContainerAllocator>::STAND;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetMotionMode_Request_<ContainerAllocator>::WALK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetMotionMode_Request_<ContainerAllocator>::RUN;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace hric_msgs


#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__SetMotionMode_Response __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__SetMotionMode_Response __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetMotionMode_Response_
{
  using Type = SetMotionMode_Response_<ContainerAllocator>;

  explicit SetMotionMode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0ul;
    }
  }

  explicit SetMotionMode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0ul;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _error_code_type =
    uint32_t;
  _error_code_type error_code;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint32_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__SetMotionMode_Response
    std::shared_ptr<hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__SetMotionMode_Response
    std::shared_ptr<hric_msgs::srv::SetMotionMode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetMotionMode_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetMotionMode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetMotionMode_Response_

// alias to use template instance with default allocator
using SetMotionMode_Response =
  hric_msgs::srv::SetMotionMode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hric_msgs

namespace hric_msgs
{

namespace srv
{

struct SetMotionMode
{
  using Request = hric_msgs::srv::SetMotionMode_Request;
  using Response = hric_msgs::srv::SetMotionMode_Response;
};

}  // namespace srv

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__STRUCT_HPP_
