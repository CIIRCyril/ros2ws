// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:srv/UpdateMarker.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__UPDATE_MARKER__STRUCT_HPP_
#define HRIC_MSGS__SRV__DETAIL__UPDATE_MARKER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__UpdateMarker_Request __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__UpdateMarker_Request __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UpdateMarker_Request_
{
  using Type = UpdateMarker_Request_<ContainerAllocator>;

  explicit UpdateMarker_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->map_id = "";
      this->floor = "";
    }
  }

  explicit UpdateMarker_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    map_id(_alloc),
    floor(_alloc),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->map_id = "";
      this->floor = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _map_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _map_id_type map_id;
  using _floor_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _floor_type floor;
  using _pose_type =
    geometry_msgs::msg::Pose2D_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__map_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->map_id = _arg;
    return *this;
  }
  Type & set__floor(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->floor = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose2D_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__UpdateMarker_Request
    std::shared_ptr<hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__UpdateMarker_Request
    std::shared_ptr<hric_msgs::srv::UpdateMarker_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpdateMarker_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->map_id != other.map_id) {
      return false;
    }
    if (this->floor != other.floor) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpdateMarker_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpdateMarker_Request_

// alias to use template instance with default allocator
using UpdateMarker_Request =
  hric_msgs::srv::UpdateMarker_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hric_msgs


// Include directives for member types
// Member 'marker_old'
// Member 'marker_new'
#include "hric_msgs/msg/detail/marker_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__UpdateMarker_Response __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__UpdateMarker_Response __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UpdateMarker_Response_
{
  using Type = UpdateMarker_Response_<ContainerAllocator>;

  explicit UpdateMarker_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : marker_old(_init),
    marker_new(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit UpdateMarker_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    marker_old(_alloc, _init),
    marker_new(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _marker_old_type =
    hric_msgs::msg::MarkerInfo_<ContainerAllocator>;
  _marker_old_type marker_old;
  using _marker_new_type =
    hric_msgs::msg::MarkerInfo_<ContainerAllocator>;
  _marker_new_type marker_new;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__marker_old(
    const hric_msgs::msg::MarkerInfo_<ContainerAllocator> & _arg)
  {
    this->marker_old = _arg;
    return *this;
  }
  Type & set__marker_new(
    const hric_msgs::msg::MarkerInfo_<ContainerAllocator> & _arg)
  {
    this->marker_new = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__UpdateMarker_Response
    std::shared_ptr<hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__UpdateMarker_Response
    std::shared_ptr<hric_msgs::srv::UpdateMarker_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpdateMarker_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->marker_old != other.marker_old) {
      return false;
    }
    if (this->marker_new != other.marker_new) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpdateMarker_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpdateMarker_Response_

// alias to use template instance with default allocator
using UpdateMarker_Response =
  hric_msgs::srv::UpdateMarker_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hric_msgs

namespace hric_msgs
{

namespace srv
{

struct UpdateMarker
{
  using Request = hric_msgs::srv::UpdateMarker_Request;
  using Response = hric_msgs::srv::UpdateMarker_Response;
};

}  // namespace srv

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__UPDATE_MARKER__STRUCT_HPP_
