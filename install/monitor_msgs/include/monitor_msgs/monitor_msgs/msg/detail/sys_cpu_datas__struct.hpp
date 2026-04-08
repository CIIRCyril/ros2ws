// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from monitor_msgs:msg/SysCpuDatas.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__STRUCT_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__STRUCT_HPP_

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
// Member 'cpu_datas'
#include "monitor_msgs/msg/detail/sys_cpu_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__monitor_msgs__msg__SysCpuDatas __attribute__((deprecated))
#else
# define DEPRECATED__monitor_msgs__msg__SysCpuDatas __declspec(deprecated)
#endif

namespace monitor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SysCpuDatas_
{
  using Type = SysCpuDatas_<ContainerAllocator>;

  explicit SysCpuDatas_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    (void)_init;
  }

  explicit SysCpuDatas_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _cpu_datas_type =
    std::vector<monitor_msgs::msg::SysCpuData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<monitor_msgs::msg::SysCpuData_<ContainerAllocator>>>;
  _cpu_datas_type cpu_datas;

  // setters for named parameter idiom
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__cpu_datas(
    const std::vector<monitor_msgs::msg::SysCpuData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<monitor_msgs::msg::SysCpuData_<ContainerAllocator>>> & _arg)
  {
    this->cpu_datas = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    monitor_msgs::msg::SysCpuDatas_<ContainerAllocator> *;
  using ConstRawPtr =
    const monitor_msgs::msg::SysCpuDatas_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<monitor_msgs::msg::SysCpuDatas_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<monitor_msgs::msg::SysCpuDatas_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::SysCpuDatas_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::SysCpuDatas_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::SysCpuDatas_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::SysCpuDatas_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<monitor_msgs::msg::SysCpuDatas_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<monitor_msgs::msg::SysCpuDatas_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__monitor_msgs__msg__SysCpuDatas
    std::shared_ptr<monitor_msgs::msg::SysCpuDatas_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__monitor_msgs__msg__SysCpuDatas
    std::shared_ptr<monitor_msgs::msg::SysCpuDatas_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SysCpuDatas_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->cpu_datas != other.cpu_datas) {
      return false;
    }
    return true;
  }
  bool operator!=(const SysCpuDatas_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SysCpuDatas_

// alias to use template instance with default allocator
using SysCpuDatas =
  monitor_msgs::msg::SysCpuDatas_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__STRUCT_HPP_
