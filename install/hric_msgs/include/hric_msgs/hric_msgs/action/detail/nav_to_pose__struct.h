// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hric_msgs:action/NavToPose.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__ACTION__DETAIL__NAV_TO_POSE__STRUCT_H_
#define HRIC_MSGS__ACTION__DETAIL__NAV_TO_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in action/NavToPose in the package hric_msgs.
typedef struct hric_msgs__action__NavToPose_Goal
{
  geometry_msgs__msg__PoseStamped pose;
} hric_msgs__action__NavToPose_Goal;

// Struct for a sequence of hric_msgs__action__NavToPose_Goal.
typedef struct hric_msgs__action__NavToPose_Goal__Sequence
{
  hric_msgs__action__NavToPose_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__action__NavToPose_Goal__Sequence;


// Constants defined in the message

/// Constant 'NONE'.
/**
  * Error codes
 */
enum
{
  hric_msgs__action__NavToPose_Result__NONE = 0ul
};

/// Constant 'GOAL_OCCUPIED'.
/**
  * 目标点被占用
 */
enum
{
  hric_msgs__action__NavToPose_Result__GOAL_OCCUPIED = 101ul
};

/// Constant 'TIMEOUT'.
/**
  * 规划超时
 */
enum
{
  hric_msgs__action__NavToPose_Result__TIMEOUT = 102ul
};

/// Constant 'NO_VALID_PATH'.
/**
  * 无可通行路线
 */
enum
{
  hric_msgs__action__NavToPose_Result__NO_VALID_PATH = 103ul
};

/// Struct defined in action/NavToPose in the package hric_msgs.
typedef struct hric_msgs__action__NavToPose_Result
{
  uint32_t error_code;
} hric_msgs__action__NavToPose_Result;

// Struct for a sequence of hric_msgs__action__NavToPose_Result.
typedef struct hric_msgs__action__NavToPose_Result__Sequence
{
  hric_msgs__action__NavToPose_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__action__NavToPose_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/NavToPose in the package hric_msgs.
typedef struct hric_msgs__action__NavToPose_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} hric_msgs__action__NavToPose_Feedback;

// Struct for a sequence of hric_msgs__action__NavToPose_Feedback.
typedef struct hric_msgs__action__NavToPose_Feedback__Sequence
{
  hric_msgs__action__NavToPose_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__action__NavToPose_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "hric_msgs/action/detail/nav_to_pose__struct.h"

/// Struct defined in action/NavToPose in the package hric_msgs.
typedef struct hric_msgs__action__NavToPose_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  hric_msgs__action__NavToPose_Goal goal;
} hric_msgs__action__NavToPose_SendGoal_Request;

// Struct for a sequence of hric_msgs__action__NavToPose_SendGoal_Request.
typedef struct hric_msgs__action__NavToPose_SendGoal_Request__Sequence
{
  hric_msgs__action__NavToPose_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__action__NavToPose_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/NavToPose in the package hric_msgs.
typedef struct hric_msgs__action__NavToPose_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} hric_msgs__action__NavToPose_SendGoal_Response;

// Struct for a sequence of hric_msgs__action__NavToPose_SendGoal_Response.
typedef struct hric_msgs__action__NavToPose_SendGoal_Response__Sequence
{
  hric_msgs__action__NavToPose_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__action__NavToPose_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/NavToPose in the package hric_msgs.
typedef struct hric_msgs__action__NavToPose_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} hric_msgs__action__NavToPose_GetResult_Request;

// Struct for a sequence of hric_msgs__action__NavToPose_GetResult_Request.
typedef struct hric_msgs__action__NavToPose_GetResult_Request__Sequence
{
  hric_msgs__action__NavToPose_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__action__NavToPose_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "hric_msgs/action/detail/nav_to_pose__struct.h"

/// Struct defined in action/NavToPose in the package hric_msgs.
typedef struct hric_msgs__action__NavToPose_GetResult_Response
{
  int8_t status;
  hric_msgs__action__NavToPose_Result result;
} hric_msgs__action__NavToPose_GetResult_Response;

// Struct for a sequence of hric_msgs__action__NavToPose_GetResult_Response.
typedef struct hric_msgs__action__NavToPose_GetResult_Response__Sequence
{
  hric_msgs__action__NavToPose_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__action__NavToPose_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "hric_msgs/action/detail/nav_to_pose__struct.h"

/// Struct defined in action/NavToPose in the package hric_msgs.
typedef struct hric_msgs__action__NavToPose_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  hric_msgs__action__NavToPose_Feedback feedback;
} hric_msgs__action__NavToPose_FeedbackMessage;

// Struct for a sequence of hric_msgs__action__NavToPose_FeedbackMessage.
typedef struct hric_msgs__action__NavToPose_FeedbackMessage__Sequence
{
  hric_msgs__action__NavToPose_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hric_msgs__action__NavToPose_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__ACTION__DETAIL__NAV_TO_POSE__STRUCT_H_
