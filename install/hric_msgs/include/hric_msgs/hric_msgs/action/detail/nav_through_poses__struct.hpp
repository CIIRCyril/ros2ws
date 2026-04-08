// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:action/NavThroughPoses.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__ACTION__DETAIL__NAV_THROUGH_POSES__STRUCT_HPP_
#define HRIC_MSGS__ACTION__DETAIL__NAV_THROUGH_POSES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'poses'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__action__NavThroughPoses_Goal __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__action__NavThroughPoses_Goal __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct NavThroughPoses_Goal_
{
  using Type = NavThroughPoses_Goal_<ContainerAllocator>;

  explicit NavThroughPoses_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit NavThroughPoses_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _poses_type =
    std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>>;
  _poses_type poses;

  // setters for named parameter idiom
  Type & set__poses(
    const std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>> & _arg)
  {
    this->poses = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_Goal
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_Goal
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavThroughPoses_Goal_ & other) const
  {
    if (this->poses != other.poses) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavThroughPoses_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavThroughPoses_Goal_

// alias to use template instance with default allocator
using NavThroughPoses_Goal =
  hric_msgs::action::NavThroughPoses_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hric_msgs


#ifndef _WIN32
# define DEPRECATED__hric_msgs__action__NavThroughPoses_Result __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__action__NavThroughPoses_Result __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct NavThroughPoses_Result_
{
  using Type = NavThroughPoses_Result_<ContainerAllocator>;

  explicit NavThroughPoses_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error_code = 0ul;
    }
  }

  explicit NavThroughPoses_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error_code = 0ul;
    }
  }

  // field types and members
  using _error_code_type =
    uint32_t;
  _error_code_type error_code;

  // setters for named parameter idiom
  Type & set__error_code(
    const uint32_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t NONE =
    0u;
  static constexpr uint32_t GOAL_OCCUPIED =
    101u;
  static constexpr uint32_t TIMEOUT =
    102u;
  static constexpr uint32_t NO_VALID_PATH =
    103u;

  // pointer types
  using RawPtr =
    hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_Result
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_Result
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavThroughPoses_Result_ & other) const
  {
    if (this->error_code != other.error_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavThroughPoses_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavThroughPoses_Result_

// alias to use template instance with default allocator
using NavThroughPoses_Result =
  hric_msgs::action::NavThroughPoses_Result_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavThroughPoses_Result_<ContainerAllocator>::NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavThroughPoses_Result_<ContainerAllocator>::GOAL_OCCUPIED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavThroughPoses_Result_<ContainerAllocator>::TIMEOUT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavThroughPoses_Result_<ContainerAllocator>::NO_VALID_PATH;
#endif  // __cplusplus < 201703L

}  // namespace action

}  // namespace hric_msgs


#ifndef _WIN32
# define DEPRECATED__hric_msgs__action__NavThroughPoses_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__action__NavThroughPoses_Feedback __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct NavThroughPoses_Feedback_
{
  using Type = NavThroughPoses_Feedback_<ContainerAllocator>;

  explicit NavThroughPoses_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit NavThroughPoses_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_Feedback
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_Feedback
    std::shared_ptr<hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavThroughPoses_Feedback_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavThroughPoses_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavThroughPoses_Feedback_

// alias to use template instance with default allocator
using NavThroughPoses_Feedback =
  hric_msgs::action::NavThroughPoses_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hric_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "hric_msgs/action/detail/nav_through_poses__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__action__NavThroughPoses_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__action__NavThroughPoses_SendGoal_Request __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct NavThroughPoses_SendGoal_Request_
{
  using Type = NavThroughPoses_SendGoal_Request_<ContainerAllocator>;

  explicit NavThroughPoses_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit NavThroughPoses_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const hric_msgs::action::NavThroughPoses_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_SendGoal_Request
    std::shared_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_SendGoal_Request
    std::shared_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavThroughPoses_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavThroughPoses_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavThroughPoses_SendGoal_Request_

// alias to use template instance with default allocator
using NavThroughPoses_SendGoal_Request =
  hric_msgs::action::NavThroughPoses_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hric_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__action__NavThroughPoses_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__action__NavThroughPoses_SendGoal_Response __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct NavThroughPoses_SendGoal_Response_
{
  using Type = NavThroughPoses_SendGoal_Response_<ContainerAllocator>;

  explicit NavThroughPoses_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit NavThroughPoses_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_SendGoal_Response
    std::shared_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_SendGoal_Response
    std::shared_ptr<hric_msgs::action::NavThroughPoses_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavThroughPoses_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavThroughPoses_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavThroughPoses_SendGoal_Response_

// alias to use template instance with default allocator
using NavThroughPoses_SendGoal_Response =
  hric_msgs::action::NavThroughPoses_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hric_msgs

namespace hric_msgs
{

namespace action
{

struct NavThroughPoses_SendGoal
{
  using Request = hric_msgs::action::NavThroughPoses_SendGoal_Request;
  using Response = hric_msgs::action::NavThroughPoses_SendGoal_Response;
};

}  // namespace action

}  // namespace hric_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__action__NavThroughPoses_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__action__NavThroughPoses_GetResult_Request __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct NavThroughPoses_GetResult_Request_
{
  using Type = NavThroughPoses_GetResult_Request_<ContainerAllocator>;

  explicit NavThroughPoses_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit NavThroughPoses_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_GetResult_Request
    std::shared_ptr<hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_GetResult_Request
    std::shared_ptr<hric_msgs::action::NavThroughPoses_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavThroughPoses_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavThroughPoses_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavThroughPoses_GetResult_Request_

// alias to use template instance with default allocator
using NavThroughPoses_GetResult_Request =
  hric_msgs::action::NavThroughPoses_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hric_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__action__NavThroughPoses_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__action__NavThroughPoses_GetResult_Response __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct NavThroughPoses_GetResult_Response_
{
  using Type = NavThroughPoses_GetResult_Response_<ContainerAllocator>;

  explicit NavThroughPoses_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit NavThroughPoses_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const hric_msgs::action::NavThroughPoses_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_GetResult_Response
    std::shared_ptr<hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_GetResult_Response
    std::shared_ptr<hric_msgs::action::NavThroughPoses_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavThroughPoses_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavThroughPoses_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavThroughPoses_GetResult_Response_

// alias to use template instance with default allocator
using NavThroughPoses_GetResult_Response =
  hric_msgs::action::NavThroughPoses_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hric_msgs

namespace hric_msgs
{

namespace action
{

struct NavThroughPoses_GetResult
{
  using Request = hric_msgs::action::NavThroughPoses_GetResult_Request;
  using Response = hric_msgs::action::NavThroughPoses_GetResult_Response;
};

}  // namespace action

}  // namespace hric_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "hric_msgs/action/detail/nav_through_poses__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__action__NavThroughPoses_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__action__NavThroughPoses_FeedbackMessage __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct NavThroughPoses_FeedbackMessage_
{
  using Type = NavThroughPoses_FeedbackMessage_<ContainerAllocator>;

  explicit NavThroughPoses_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit NavThroughPoses_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const hric_msgs::action::NavThroughPoses_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_FeedbackMessage
    std::shared_ptr<hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__action__NavThroughPoses_FeedbackMessage
    std::shared_ptr<hric_msgs::action::NavThroughPoses_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavThroughPoses_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavThroughPoses_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavThroughPoses_FeedbackMessage_

// alias to use template instance with default allocator
using NavThroughPoses_FeedbackMessage =
  hric_msgs::action::NavThroughPoses_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hric_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace hric_msgs
{

namespace action
{

struct NavThroughPoses
{
  /// The goal message defined in the action definition.
  using Goal = hric_msgs::action::NavThroughPoses_Goal;
  /// The result message defined in the action definition.
  using Result = hric_msgs::action::NavThroughPoses_Result;
  /// The feedback message defined in the action definition.
  using Feedback = hric_msgs::action::NavThroughPoses_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = hric_msgs::action::NavThroughPoses_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = hric_msgs::action::NavThroughPoses_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = hric_msgs::action::NavThroughPoses_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct NavThroughPoses NavThroughPoses;

}  // namespace action

}  // namespace hric_msgs

#endif  // HRIC_MSGS__ACTION__DETAIL__NAV_THROUGH_POSES__STRUCT_HPP_
