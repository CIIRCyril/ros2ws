// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hric_msgs:action/NavToPose.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__ACTION__DETAIL__NAV_TO_POSE__FUNCTIONS_H_
#define HRIC_MSGS__ACTION__DETAIL__NAV_TO_POSE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hric_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "hric_msgs/action/detail/nav_to_pose__struct.h"

/// Initialize action/NavToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__action__NavToPose_Goal
 * )) before or use
 * hric_msgs__action__NavToPose_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Goal__init(hric_msgs__action__NavToPose_Goal * msg);

/// Finalize action/NavToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Goal__fini(hric_msgs__action__NavToPose_Goal * msg);

/// Create action/NavToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__action__NavToPose_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_Goal *
hric_msgs__action__NavToPose_Goal__create();

/// Destroy action/NavToPose message.
/**
 * It calls
 * hric_msgs__action__NavToPose_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Goal__destroy(hric_msgs__action__NavToPose_Goal * msg);

/// Check for action/NavToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Goal__are_equal(const hric_msgs__action__NavToPose_Goal * lhs, const hric_msgs__action__NavToPose_Goal * rhs);

/// Copy a action/NavToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Goal__copy(
  const hric_msgs__action__NavToPose_Goal * input,
  hric_msgs__action__NavToPose_Goal * output);

/// Initialize array of action/NavToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__action__NavToPose_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Goal__Sequence__init(hric_msgs__action__NavToPose_Goal__Sequence * array, size_t size);

/// Finalize array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Goal__Sequence__fini(hric_msgs__action__NavToPose_Goal__Sequence * array);

/// Create array of action/NavToPose messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__action__NavToPose_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_Goal__Sequence *
hric_msgs__action__NavToPose_Goal__Sequence__create(size_t size);

/// Destroy array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Goal__Sequence__destroy(hric_msgs__action__NavToPose_Goal__Sequence * array);

/// Check for action/NavToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Goal__Sequence__are_equal(const hric_msgs__action__NavToPose_Goal__Sequence * lhs, const hric_msgs__action__NavToPose_Goal__Sequence * rhs);

/// Copy an array of action/NavToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Goal__Sequence__copy(
  const hric_msgs__action__NavToPose_Goal__Sequence * input,
  hric_msgs__action__NavToPose_Goal__Sequence * output);

/// Initialize action/NavToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__action__NavToPose_Result
 * )) before or use
 * hric_msgs__action__NavToPose_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Result__init(hric_msgs__action__NavToPose_Result * msg);

/// Finalize action/NavToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Result__fini(hric_msgs__action__NavToPose_Result * msg);

/// Create action/NavToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__action__NavToPose_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_Result *
hric_msgs__action__NavToPose_Result__create();

/// Destroy action/NavToPose message.
/**
 * It calls
 * hric_msgs__action__NavToPose_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Result__destroy(hric_msgs__action__NavToPose_Result * msg);

/// Check for action/NavToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Result__are_equal(const hric_msgs__action__NavToPose_Result * lhs, const hric_msgs__action__NavToPose_Result * rhs);

/// Copy a action/NavToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Result__copy(
  const hric_msgs__action__NavToPose_Result * input,
  hric_msgs__action__NavToPose_Result * output);

/// Initialize array of action/NavToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__action__NavToPose_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Result__Sequence__init(hric_msgs__action__NavToPose_Result__Sequence * array, size_t size);

/// Finalize array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Result__Sequence__fini(hric_msgs__action__NavToPose_Result__Sequence * array);

/// Create array of action/NavToPose messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__action__NavToPose_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_Result__Sequence *
hric_msgs__action__NavToPose_Result__Sequence__create(size_t size);

/// Destroy array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Result__Sequence__destroy(hric_msgs__action__NavToPose_Result__Sequence * array);

/// Check for action/NavToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Result__Sequence__are_equal(const hric_msgs__action__NavToPose_Result__Sequence * lhs, const hric_msgs__action__NavToPose_Result__Sequence * rhs);

/// Copy an array of action/NavToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Result__Sequence__copy(
  const hric_msgs__action__NavToPose_Result__Sequence * input,
  hric_msgs__action__NavToPose_Result__Sequence * output);

/// Initialize action/NavToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__action__NavToPose_Feedback
 * )) before or use
 * hric_msgs__action__NavToPose_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Feedback__init(hric_msgs__action__NavToPose_Feedback * msg);

/// Finalize action/NavToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Feedback__fini(hric_msgs__action__NavToPose_Feedback * msg);

/// Create action/NavToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__action__NavToPose_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_Feedback *
hric_msgs__action__NavToPose_Feedback__create();

/// Destroy action/NavToPose message.
/**
 * It calls
 * hric_msgs__action__NavToPose_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Feedback__destroy(hric_msgs__action__NavToPose_Feedback * msg);

/// Check for action/NavToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Feedback__are_equal(const hric_msgs__action__NavToPose_Feedback * lhs, const hric_msgs__action__NavToPose_Feedback * rhs);

/// Copy a action/NavToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Feedback__copy(
  const hric_msgs__action__NavToPose_Feedback * input,
  hric_msgs__action__NavToPose_Feedback * output);

/// Initialize array of action/NavToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__action__NavToPose_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Feedback__Sequence__init(hric_msgs__action__NavToPose_Feedback__Sequence * array, size_t size);

/// Finalize array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Feedback__Sequence__fini(hric_msgs__action__NavToPose_Feedback__Sequence * array);

/// Create array of action/NavToPose messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__action__NavToPose_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_Feedback__Sequence *
hric_msgs__action__NavToPose_Feedback__Sequence__create(size_t size);

/// Destroy array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_Feedback__Sequence__destroy(hric_msgs__action__NavToPose_Feedback__Sequence * array);

/// Check for action/NavToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Feedback__Sequence__are_equal(const hric_msgs__action__NavToPose_Feedback__Sequence * lhs, const hric_msgs__action__NavToPose_Feedback__Sequence * rhs);

/// Copy an array of action/NavToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_Feedback__Sequence__copy(
  const hric_msgs__action__NavToPose_Feedback__Sequence * input,
  hric_msgs__action__NavToPose_Feedback__Sequence * output);

/// Initialize action/NavToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__action__NavToPose_SendGoal_Request
 * )) before or use
 * hric_msgs__action__NavToPose_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Request__init(hric_msgs__action__NavToPose_SendGoal_Request * msg);

/// Finalize action/NavToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_SendGoal_Request__fini(hric_msgs__action__NavToPose_SendGoal_Request * msg);

/// Create action/NavToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__action__NavToPose_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_SendGoal_Request *
hric_msgs__action__NavToPose_SendGoal_Request__create();

/// Destroy action/NavToPose message.
/**
 * It calls
 * hric_msgs__action__NavToPose_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_SendGoal_Request__destroy(hric_msgs__action__NavToPose_SendGoal_Request * msg);

/// Check for action/NavToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Request__are_equal(const hric_msgs__action__NavToPose_SendGoal_Request * lhs, const hric_msgs__action__NavToPose_SendGoal_Request * rhs);

/// Copy a action/NavToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Request__copy(
  const hric_msgs__action__NavToPose_SendGoal_Request * input,
  hric_msgs__action__NavToPose_SendGoal_Request * output);

/// Initialize array of action/NavToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__action__NavToPose_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Request__Sequence__init(hric_msgs__action__NavToPose_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_SendGoal_Request__Sequence__fini(hric_msgs__action__NavToPose_SendGoal_Request__Sequence * array);

/// Create array of action/NavToPose messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__action__NavToPose_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_SendGoal_Request__Sequence *
hric_msgs__action__NavToPose_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_SendGoal_Request__Sequence__destroy(hric_msgs__action__NavToPose_SendGoal_Request__Sequence * array);

/// Check for action/NavToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Request__Sequence__are_equal(const hric_msgs__action__NavToPose_SendGoal_Request__Sequence * lhs, const hric_msgs__action__NavToPose_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/NavToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Request__Sequence__copy(
  const hric_msgs__action__NavToPose_SendGoal_Request__Sequence * input,
  hric_msgs__action__NavToPose_SendGoal_Request__Sequence * output);

/// Initialize action/NavToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__action__NavToPose_SendGoal_Response
 * )) before or use
 * hric_msgs__action__NavToPose_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Response__init(hric_msgs__action__NavToPose_SendGoal_Response * msg);

/// Finalize action/NavToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_SendGoal_Response__fini(hric_msgs__action__NavToPose_SendGoal_Response * msg);

/// Create action/NavToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__action__NavToPose_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_SendGoal_Response *
hric_msgs__action__NavToPose_SendGoal_Response__create();

/// Destroy action/NavToPose message.
/**
 * It calls
 * hric_msgs__action__NavToPose_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_SendGoal_Response__destroy(hric_msgs__action__NavToPose_SendGoal_Response * msg);

/// Check for action/NavToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Response__are_equal(const hric_msgs__action__NavToPose_SendGoal_Response * lhs, const hric_msgs__action__NavToPose_SendGoal_Response * rhs);

/// Copy a action/NavToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Response__copy(
  const hric_msgs__action__NavToPose_SendGoal_Response * input,
  hric_msgs__action__NavToPose_SendGoal_Response * output);

/// Initialize array of action/NavToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__action__NavToPose_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Response__Sequence__init(hric_msgs__action__NavToPose_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_SendGoal_Response__Sequence__fini(hric_msgs__action__NavToPose_SendGoal_Response__Sequence * array);

/// Create array of action/NavToPose messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__action__NavToPose_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_SendGoal_Response__Sequence *
hric_msgs__action__NavToPose_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_SendGoal_Response__Sequence__destroy(hric_msgs__action__NavToPose_SendGoal_Response__Sequence * array);

/// Check for action/NavToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Response__Sequence__are_equal(const hric_msgs__action__NavToPose_SendGoal_Response__Sequence * lhs, const hric_msgs__action__NavToPose_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/NavToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_SendGoal_Response__Sequence__copy(
  const hric_msgs__action__NavToPose_SendGoal_Response__Sequence * input,
  hric_msgs__action__NavToPose_SendGoal_Response__Sequence * output);

/// Initialize action/NavToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__action__NavToPose_GetResult_Request
 * )) before or use
 * hric_msgs__action__NavToPose_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Request__init(hric_msgs__action__NavToPose_GetResult_Request * msg);

/// Finalize action/NavToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_GetResult_Request__fini(hric_msgs__action__NavToPose_GetResult_Request * msg);

/// Create action/NavToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__action__NavToPose_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_GetResult_Request *
hric_msgs__action__NavToPose_GetResult_Request__create();

/// Destroy action/NavToPose message.
/**
 * It calls
 * hric_msgs__action__NavToPose_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_GetResult_Request__destroy(hric_msgs__action__NavToPose_GetResult_Request * msg);

/// Check for action/NavToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Request__are_equal(const hric_msgs__action__NavToPose_GetResult_Request * lhs, const hric_msgs__action__NavToPose_GetResult_Request * rhs);

/// Copy a action/NavToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Request__copy(
  const hric_msgs__action__NavToPose_GetResult_Request * input,
  hric_msgs__action__NavToPose_GetResult_Request * output);

/// Initialize array of action/NavToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__action__NavToPose_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Request__Sequence__init(hric_msgs__action__NavToPose_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_GetResult_Request__Sequence__fini(hric_msgs__action__NavToPose_GetResult_Request__Sequence * array);

/// Create array of action/NavToPose messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__action__NavToPose_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_GetResult_Request__Sequence *
hric_msgs__action__NavToPose_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_GetResult_Request__Sequence__destroy(hric_msgs__action__NavToPose_GetResult_Request__Sequence * array);

/// Check for action/NavToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Request__Sequence__are_equal(const hric_msgs__action__NavToPose_GetResult_Request__Sequence * lhs, const hric_msgs__action__NavToPose_GetResult_Request__Sequence * rhs);

/// Copy an array of action/NavToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Request__Sequence__copy(
  const hric_msgs__action__NavToPose_GetResult_Request__Sequence * input,
  hric_msgs__action__NavToPose_GetResult_Request__Sequence * output);

/// Initialize action/NavToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__action__NavToPose_GetResult_Response
 * )) before or use
 * hric_msgs__action__NavToPose_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Response__init(hric_msgs__action__NavToPose_GetResult_Response * msg);

/// Finalize action/NavToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_GetResult_Response__fini(hric_msgs__action__NavToPose_GetResult_Response * msg);

/// Create action/NavToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__action__NavToPose_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_GetResult_Response *
hric_msgs__action__NavToPose_GetResult_Response__create();

/// Destroy action/NavToPose message.
/**
 * It calls
 * hric_msgs__action__NavToPose_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_GetResult_Response__destroy(hric_msgs__action__NavToPose_GetResult_Response * msg);

/// Check for action/NavToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Response__are_equal(const hric_msgs__action__NavToPose_GetResult_Response * lhs, const hric_msgs__action__NavToPose_GetResult_Response * rhs);

/// Copy a action/NavToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Response__copy(
  const hric_msgs__action__NavToPose_GetResult_Response * input,
  hric_msgs__action__NavToPose_GetResult_Response * output);

/// Initialize array of action/NavToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__action__NavToPose_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Response__Sequence__init(hric_msgs__action__NavToPose_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_GetResult_Response__Sequence__fini(hric_msgs__action__NavToPose_GetResult_Response__Sequence * array);

/// Create array of action/NavToPose messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__action__NavToPose_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_GetResult_Response__Sequence *
hric_msgs__action__NavToPose_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_GetResult_Response__Sequence__destroy(hric_msgs__action__NavToPose_GetResult_Response__Sequence * array);

/// Check for action/NavToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Response__Sequence__are_equal(const hric_msgs__action__NavToPose_GetResult_Response__Sequence * lhs, const hric_msgs__action__NavToPose_GetResult_Response__Sequence * rhs);

/// Copy an array of action/NavToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_GetResult_Response__Sequence__copy(
  const hric_msgs__action__NavToPose_GetResult_Response__Sequence * input,
  hric_msgs__action__NavToPose_GetResult_Response__Sequence * output);

/// Initialize action/NavToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__action__NavToPose_FeedbackMessage
 * )) before or use
 * hric_msgs__action__NavToPose_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_FeedbackMessage__init(hric_msgs__action__NavToPose_FeedbackMessage * msg);

/// Finalize action/NavToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_FeedbackMessage__fini(hric_msgs__action__NavToPose_FeedbackMessage * msg);

/// Create action/NavToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__action__NavToPose_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_FeedbackMessage *
hric_msgs__action__NavToPose_FeedbackMessage__create();

/// Destroy action/NavToPose message.
/**
 * It calls
 * hric_msgs__action__NavToPose_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_FeedbackMessage__destroy(hric_msgs__action__NavToPose_FeedbackMessage * msg);

/// Check for action/NavToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_FeedbackMessage__are_equal(const hric_msgs__action__NavToPose_FeedbackMessage * lhs, const hric_msgs__action__NavToPose_FeedbackMessage * rhs);

/// Copy a action/NavToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_FeedbackMessage__copy(
  const hric_msgs__action__NavToPose_FeedbackMessage * input,
  hric_msgs__action__NavToPose_FeedbackMessage * output);

/// Initialize array of action/NavToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__action__NavToPose_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_FeedbackMessage__Sequence__init(hric_msgs__action__NavToPose_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_FeedbackMessage__Sequence__fini(hric_msgs__action__NavToPose_FeedbackMessage__Sequence * array);

/// Create array of action/NavToPose messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__action__NavToPose_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__action__NavToPose_FeedbackMessage__Sequence *
hric_msgs__action__NavToPose_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/NavToPose messages.
/**
 * It calls
 * hric_msgs__action__NavToPose_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__action__NavToPose_FeedbackMessage__Sequence__destroy(hric_msgs__action__NavToPose_FeedbackMessage__Sequence * array);

/// Check for action/NavToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_FeedbackMessage__Sequence__are_equal(const hric_msgs__action__NavToPose_FeedbackMessage__Sequence * lhs, const hric_msgs__action__NavToPose_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/NavToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__action__NavToPose_FeedbackMessage__Sequence__copy(
  const hric_msgs__action__NavToPose_FeedbackMessage__Sequence * input,
  hric_msgs__action__NavToPose_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__ACTION__DETAIL__NAV_TO_POSE__FUNCTIONS_H_
