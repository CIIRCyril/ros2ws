// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hric_msgs:msg/FloatBaseRPYZ.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__FUNCTIONS_H_
#define HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hric_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "hric_msgs/msg/detail/float_base_rpyz__struct.h"

/// Initialize msg/FloatBaseRPYZ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hric_msgs__msg__FloatBaseRPYZ
 * )) before or use
 * hric_msgs__msg__FloatBaseRPYZ__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__FloatBaseRPYZ__init(hric_msgs__msg__FloatBaseRPYZ * msg);

/// Finalize msg/FloatBaseRPYZ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__msg__FloatBaseRPYZ__fini(hric_msgs__msg__FloatBaseRPYZ * msg);

/// Create msg/FloatBaseRPYZ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hric_msgs__msg__FloatBaseRPYZ__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__msg__FloatBaseRPYZ *
hric_msgs__msg__FloatBaseRPYZ__create();

/// Destroy msg/FloatBaseRPYZ message.
/**
 * It calls
 * hric_msgs__msg__FloatBaseRPYZ__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__msg__FloatBaseRPYZ__destroy(hric_msgs__msg__FloatBaseRPYZ * msg);

/// Check for msg/FloatBaseRPYZ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__FloatBaseRPYZ__are_equal(const hric_msgs__msg__FloatBaseRPYZ * lhs, const hric_msgs__msg__FloatBaseRPYZ * rhs);

/// Copy a msg/FloatBaseRPYZ message.
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
hric_msgs__msg__FloatBaseRPYZ__copy(
  const hric_msgs__msg__FloatBaseRPYZ * input,
  hric_msgs__msg__FloatBaseRPYZ * output);

/// Initialize array of msg/FloatBaseRPYZ messages.
/**
 * It allocates the memory for the number of elements and calls
 * hric_msgs__msg__FloatBaseRPYZ__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__FloatBaseRPYZ__Sequence__init(hric_msgs__msg__FloatBaseRPYZ__Sequence * array, size_t size);

/// Finalize array of msg/FloatBaseRPYZ messages.
/**
 * It calls
 * hric_msgs__msg__FloatBaseRPYZ__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__msg__FloatBaseRPYZ__Sequence__fini(hric_msgs__msg__FloatBaseRPYZ__Sequence * array);

/// Create array of msg/FloatBaseRPYZ messages.
/**
 * It allocates the memory for the array and calls
 * hric_msgs__msg__FloatBaseRPYZ__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
hric_msgs__msg__FloatBaseRPYZ__Sequence *
hric_msgs__msg__FloatBaseRPYZ__Sequence__create(size_t size);

/// Destroy array of msg/FloatBaseRPYZ messages.
/**
 * It calls
 * hric_msgs__msg__FloatBaseRPYZ__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
void
hric_msgs__msg__FloatBaseRPYZ__Sequence__destroy(hric_msgs__msg__FloatBaseRPYZ__Sequence * array);

/// Check for msg/FloatBaseRPYZ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hric_msgs
bool
hric_msgs__msg__FloatBaseRPYZ__Sequence__are_equal(const hric_msgs__msg__FloatBaseRPYZ__Sequence * lhs, const hric_msgs__msg__FloatBaseRPYZ__Sequence * rhs);

/// Copy an array of msg/FloatBaseRPYZ messages.
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
hric_msgs__msg__FloatBaseRPYZ__Sequence__copy(
  const hric_msgs__msg__FloatBaseRPYZ__Sequence * input,
  hric_msgs__msg__FloatBaseRPYZ__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__FUNCTIONS_H_
