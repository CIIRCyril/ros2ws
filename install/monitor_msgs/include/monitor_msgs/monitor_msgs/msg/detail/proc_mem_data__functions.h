// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from monitor_msgs:msg/ProcMemData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__FUNCTIONS_H_
#define MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "monitor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "monitor_msgs/msg/detail/proc_mem_data__struct.h"

/// Initialize msg/ProcMemData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * monitor_msgs__msg__ProcMemData
 * )) before or use
 * monitor_msgs__msg__ProcMemData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcMemData__init(monitor_msgs__msg__ProcMemData * msg);

/// Finalize msg/ProcMemData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
void
monitor_msgs__msg__ProcMemData__fini(monitor_msgs__msg__ProcMemData * msg);

/// Create msg/ProcMemData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * monitor_msgs__msg__ProcMemData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
monitor_msgs__msg__ProcMemData *
monitor_msgs__msg__ProcMemData__create();

/// Destroy msg/ProcMemData message.
/**
 * It calls
 * monitor_msgs__msg__ProcMemData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
void
monitor_msgs__msg__ProcMemData__destroy(monitor_msgs__msg__ProcMemData * msg);

/// Check for msg/ProcMemData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcMemData__are_equal(const monitor_msgs__msg__ProcMemData * lhs, const monitor_msgs__msg__ProcMemData * rhs);

/// Copy a msg/ProcMemData message.
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
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcMemData__copy(
  const monitor_msgs__msg__ProcMemData * input,
  monitor_msgs__msg__ProcMemData * output);

/// Initialize array of msg/ProcMemData messages.
/**
 * It allocates the memory for the number of elements and calls
 * monitor_msgs__msg__ProcMemData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcMemData__Sequence__init(monitor_msgs__msg__ProcMemData__Sequence * array, size_t size);

/// Finalize array of msg/ProcMemData messages.
/**
 * It calls
 * monitor_msgs__msg__ProcMemData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
void
monitor_msgs__msg__ProcMemData__Sequence__fini(monitor_msgs__msg__ProcMemData__Sequence * array);

/// Create array of msg/ProcMemData messages.
/**
 * It allocates the memory for the array and calls
 * monitor_msgs__msg__ProcMemData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
monitor_msgs__msg__ProcMemData__Sequence *
monitor_msgs__msg__ProcMemData__Sequence__create(size_t size);

/// Destroy array of msg/ProcMemData messages.
/**
 * It calls
 * monitor_msgs__msg__ProcMemData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
void
monitor_msgs__msg__ProcMemData__Sequence__destroy(monitor_msgs__msg__ProcMemData__Sequence * array);

/// Check for msg/ProcMemData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcMemData__Sequence__are_equal(const monitor_msgs__msg__ProcMemData__Sequence * lhs, const monitor_msgs__msg__ProcMemData__Sequence * rhs);

/// Copy an array of msg/ProcMemData messages.
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
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcMemData__Sequence__copy(
  const monitor_msgs__msg__ProcMemData__Sequence * input,
  monitor_msgs__msg__ProcMemData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__FUNCTIONS_H_
