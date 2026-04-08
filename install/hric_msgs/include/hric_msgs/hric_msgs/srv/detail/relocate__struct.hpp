// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:srv/Relocate.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__RELOCATE__STRUCT_HPP_
#define HRIC_MSGS__SRV__DETAIL__RELOCATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose_robot'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__Relocate_Request __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__Relocate_Request __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Relocate_Request_
{
  using Type = Relocate_Request_<ContainerAllocator>;

  explicit Relocate_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_robot(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->match_type = 0;
    }
  }

  explicit Relocate_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_robot(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->match_type = 0;
    }
  }

  // field types and members
  using _pose_robot_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_robot_type pose_robot;
  using _match_type_type =
    uint8_t;
  _match_type_type match_type;

  // setters for named parameter idiom
  Type & set__pose_robot(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose_robot = _arg;
    return *this;
  }
  Type & set__match_type(
    const uint8_t & _arg)
  {
    this->match_type = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t LOCAL_MATCH =
    1u;
  static constexpr uint8_t GLOBAL_MATCH =
    2u;

  // pointer types
  using RawPtr =
    hric_msgs::srv::Relocate_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::Relocate_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::Relocate_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::Relocate_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::Relocate_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::Relocate_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::Relocate_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::Relocate_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::Relocate_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::Relocate_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__Relocate_Request
    std::shared_ptr<hric_msgs::srv::Relocate_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__Relocate_Request
    std::shared_ptr<hric_msgs::srv::Relocate_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Relocate_Request_ & other) const
  {
    if (this->pose_robot != other.pose_robot) {
      return false;
    }
    if (this->match_type != other.match_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const Relocate_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Relocate_Request_

// alias to use template instance with default allocator
using Relocate_Request =
  hric_msgs::srv::Relocate_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Relocate_Request_<ContainerAllocator>::LOCAL_MATCH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Relocate_Request_<ContainerAllocator>::GLOBAL_MATCH;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace hric_msgs


#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__Relocate_Response __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__Relocate_Response __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Relocate_Response_
{
  using Type = Relocate_Response_<ContainerAllocator>;

  explicit Relocate_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0ul;
      this->message = "";
    }
  }

  explicit Relocate_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0ul;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _error_code_type =
    uint32_t;
  _error_code_type error_code;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

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
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t NONE =
    0u;
  static constexpr uint32_t UNKNOWN =
    200u;
  static constexpr uint32_t TF_ERROR =
    201u;
  static constexpr uint32_t SENSOR_ERROR =
    202u;
  static constexpr uint32_t LOW_CONFIDENCE =
    203u;

  // pointer types
  using RawPtr =
    hric_msgs::srv::Relocate_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::Relocate_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::Relocate_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::Relocate_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::Relocate_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::Relocate_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::Relocate_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::Relocate_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::Relocate_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::Relocate_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__Relocate_Response
    std::shared_ptr<hric_msgs::srv::Relocate_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__Relocate_Response
    std::shared_ptr<hric_msgs::srv::Relocate_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Relocate_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const Relocate_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Relocate_Response_

// alias to use template instance with default allocator
using Relocate_Response =
  hric_msgs::srv::Relocate_Response_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t Relocate_Response_<ContainerAllocator>::NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t Relocate_Response_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t Relocate_Response_<ContainerAllocator>::TF_ERROR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t Relocate_Response_<ContainerAllocator>::SENSOR_ERROR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t Relocate_Response_<ContainerAllocator>::LOW_CONFIDENCE;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace hric_msgs

namespace hric_msgs
{

namespace srv
{

struct Relocate
{
  using Request = hric_msgs::srv::Relocate_Request;
  using Response = hric_msgs::srv::Relocate_Response;
};

}  // namespace srv

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__RELOCATE__STRUCT_HPP_
