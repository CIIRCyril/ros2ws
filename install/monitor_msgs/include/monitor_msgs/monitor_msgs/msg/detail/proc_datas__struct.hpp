// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from monitor_msgs:msg/ProcDatas.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__STRUCT_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'proc_datas'
#include "monitor_msgs/msg/detail/proc_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__monitor_msgs__msg__ProcDatas __attribute__((deprecated))
#else
# define DEPRECATED__monitor_msgs__msg__ProcDatas __declspec(deprecated)
#endif

namespace monitor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProcDatas_
{
  using Type = ProcDatas_<ContainerAllocator>;

  explicit ProcDatas_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    (void)_init;
  }

  explicit ProcDatas_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _proc_datas_type =
    std::vector<monitor_msgs::msg::ProcData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<monitor_msgs::msg::ProcData_<ContainerAllocator>>>;
  _proc_datas_type proc_datas;

  // setters for named parameter idiom
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__proc_datas(
    const std::vector<monitor_msgs::msg::ProcData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<monitor_msgs::msg::ProcData_<ContainerAllocator>>> & _arg)
  {
    this->proc_datas = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    monitor_msgs::msg::ProcDatas_<ContainerAllocator> *;
  using ConstRawPtr =
    const monitor_msgs::msg::ProcDatas_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcDatas_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcDatas_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcDatas_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcDatas_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcDatas_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcDatas_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcDatas_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcDatas_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__monitor_msgs__msg__ProcDatas
    std::shared_ptr<monitor_msgs::msg::ProcDatas_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__monitor_msgs__msg__ProcDatas
    std::shared_ptr<monitor_msgs::msg::ProcDatas_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcDatas_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->proc_datas != other.proc_datas) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcDatas_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcDatas_

// alias to use template instance with default allocator
using ProcDatas =
  monitor_msgs::msg::ProcDatas_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__STRUCT_HPP_
