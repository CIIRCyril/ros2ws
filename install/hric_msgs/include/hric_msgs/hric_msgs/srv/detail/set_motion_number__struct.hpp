// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:srv/SetMotionNumber.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__STRUCT_HPP_
#define HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__SetMotionNumber_Request __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__SetMotionNumber_Request __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetMotionNumber_Request_
{
  using Type = SetMotionNumber_Request_<ContainerAllocator>;

  explicit SetMotionNumber_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_motion = false;
      this->motion_number = 0l;
    }
  }

  explicit SetMotionNumber_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_motion = false;
      this->motion_number = 0l;
    }
  }

  // field types and members
  using _is_motion_type =
    bool;
  _is_motion_type is_motion;
  using _motion_number_type =
    int32_t;
  _motion_number_type motion_number;

  // setters for named parameter idiom
  Type & set__is_motion(
    const bool & _arg)
  {
    this->is_motion = _arg;
    return *this;
  }
  Type & set__motion_number(
    const int32_t & _arg)
  {
    this->motion_number = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__SetMotionNumber_Request
    std::shared_ptr<hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__SetMotionNumber_Request
    std::shared_ptr<hric_msgs::srv::SetMotionNumber_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetMotionNumber_Request_ & other) const
  {
    if (this->is_motion != other.is_motion) {
      return false;
    }
    if (this->motion_number != other.motion_number) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetMotionNumber_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetMotionNumber_Request_

// alias to use template instance with default allocator
using SetMotionNumber_Request =
  hric_msgs::srv::SetMotionNumber_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hric_msgs


#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__SetMotionNumber_Response __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__SetMotionNumber_Response __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetMotionNumber_Response_
{
  using Type = SetMotionNumber_Response_<ContainerAllocator>;

  explicit SetMotionNumber_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SetMotionNumber_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__SetMotionNumber_Response
    std::shared_ptr<hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__SetMotionNumber_Response
    std::shared_ptr<hric_msgs::srv::SetMotionNumber_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetMotionNumber_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetMotionNumber_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetMotionNumber_Response_

// alias to use template instance with default allocator
using SetMotionNumber_Response =
  hric_msgs::srv::SetMotionNumber_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hric_msgs

namespace hric_msgs
{

namespace srv
{

struct SetMotionNumber
{
  using Request = hric_msgs::srv::SetMotionNumber_Request;
  using Response = hric_msgs::srv::SetMotionNumber_Response;
};

}  // namespace srv

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__STRUCT_HPP_
