// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from monitor_msgs:msg/SysCpuData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__STRUCT_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__monitor_msgs__msg__SysCpuData __attribute__((deprecated))
#else
# define DEPRECATED__monitor_msgs__msg__SysCpuData __declspec(deprecated)
#endif

namespace monitor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SysCpuData_
{
  using Type = SysCpuData_<ContainerAllocator>;

  explicit SysCpuData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cpu_num = 0;
      this->cpu_used = 0.0f;
      this->proc_num = 0ul;
    }
  }

  explicit SysCpuData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cpu_num = 0;
      this->cpu_used = 0.0f;
      this->proc_num = 0ul;
    }
  }

  // field types and members
  using _cpu_num_type =
    uint8_t;
  _cpu_num_type cpu_num;
  using _cpu_used_type =
    float;
  _cpu_used_type cpu_used;
  using _proc_num_type =
    uint32_t;
  _proc_num_type proc_num;
  using _proc_array_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _proc_array_type proc_array;

  // setters for named parameter idiom
  Type & set__cpu_num(
    const uint8_t & _arg)
  {
    this->cpu_num = _arg;
    return *this;
  }
  Type & set__cpu_used(
    const float & _arg)
  {
    this->cpu_used = _arg;
    return *this;
  }
  Type & set__proc_num(
    const uint32_t & _arg)
  {
    this->proc_num = _arg;
    return *this;
  }
  Type & set__proc_array(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->proc_array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    monitor_msgs::msg::SysCpuData_<ContainerAllocator> *;
  using ConstRawPtr =
    const monitor_msgs::msg::SysCpuData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<monitor_msgs::msg::SysCpuData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<monitor_msgs::msg::SysCpuData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::SysCpuData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::SysCpuData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::SysCpuData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::SysCpuData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<monitor_msgs::msg::SysCpuData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<monitor_msgs::msg::SysCpuData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__monitor_msgs__msg__SysCpuData
    std::shared_ptr<monitor_msgs::msg::SysCpuData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__monitor_msgs__msg__SysCpuData
    std::shared_ptr<monitor_msgs::msg::SysCpuData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SysCpuData_ & other) const
  {
    if (this->cpu_num != other.cpu_num) {
      return false;
    }
    if (this->cpu_used != other.cpu_used) {
      return false;
    }
    if (this->proc_num != other.proc_num) {
      return false;
    }
    if (this->proc_array != other.proc_array) {
      return false;
    }
    return true;
  }
  bool operator!=(const SysCpuData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SysCpuData_

// alias to use template instance with default allocator
using SysCpuData =
  monitor_msgs::msg::SysCpuData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__STRUCT_HPP_
