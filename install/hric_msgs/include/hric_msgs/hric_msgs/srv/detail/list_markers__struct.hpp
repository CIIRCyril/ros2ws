// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:srv/ListMarkers.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__STRUCT_HPP_
#define HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__ListMarkers_Request __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__ListMarkers_Request __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ListMarkers_Request_
{
  using Type = ListMarkers_Request_<ContainerAllocator>;

  explicit ListMarkers_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit ListMarkers_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::srv::ListMarkers_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::ListMarkers_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::ListMarkers_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::ListMarkers_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::ListMarkers_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::ListMarkers_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::ListMarkers_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::ListMarkers_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::ListMarkers_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::ListMarkers_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__ListMarkers_Request
    std::shared_ptr<hric_msgs::srv::ListMarkers_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__ListMarkers_Request
    std::shared_ptr<hric_msgs::srv::ListMarkers_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ListMarkers_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const ListMarkers_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ListMarkers_Request_

// alias to use template instance with default allocator
using ListMarkers_Request =
  hric_msgs::srv::ListMarkers_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hric_msgs


// Include directives for member types
// Member 'markers'
#include "hric_msgs/msg/detail/marker_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__ListMarkers_Response __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__ListMarkers_Response __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ListMarkers_Response_
{
  using Type = ListMarkers_Response_<ContainerAllocator>;

  explicit ListMarkers_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ListMarkers_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _markers_type =
    std::vector<hric_msgs::msg::MarkerInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hric_msgs::msg::MarkerInfo_<ContainerAllocator>>>;
  _markers_type markers;

  // setters for named parameter idiom
  Type & set__markers(
    const std::vector<hric_msgs::msg::MarkerInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hric_msgs::msg::MarkerInfo_<ContainerAllocator>>> & _arg)
  {
    this->markers = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::srv::ListMarkers_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::ListMarkers_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::ListMarkers_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::ListMarkers_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::ListMarkers_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::ListMarkers_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::ListMarkers_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::ListMarkers_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::ListMarkers_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::ListMarkers_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__ListMarkers_Response
    std::shared_ptr<hric_msgs::srv::ListMarkers_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__ListMarkers_Response
    std::shared_ptr<hric_msgs::srv::ListMarkers_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ListMarkers_Response_ & other) const
  {
    if (this->markers != other.markers) {
      return false;
    }
    return true;
  }
  bool operator!=(const ListMarkers_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ListMarkers_Response_

// alias to use template instance with default allocator
using ListMarkers_Response =
  hric_msgs::srv::ListMarkers_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hric_msgs

namespace hric_msgs
{

namespace srv
{

struct ListMarkers
{
  using Request = hric_msgs::srv::ListMarkers_Request;
  using Response = hric_msgs::srv::ListMarkers_Response;
};

}  // namespace srv

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__STRUCT_HPP_
