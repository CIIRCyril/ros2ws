// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from monitor_msgs:msg/ProcCpuData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__FUNCTIONS_H_
#define MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "monitor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "monitor_msgs/msg/detail/proc_cpu_data__struct.h"

/// Initialize msg/ProcCpuData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * monitor_msgs__msg__ProcCpuData
 * )) before or use
 * monitor_msgs__msg__ProcCpuData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcCpuData__init(monitor_msgs__msg__ProcCpuData * msg);

/// Finalize msg/ProcCpuData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
void
monitor_msgs__msg__ProcCpuData__fini(monitor_msgs__msg__ProcCpuData * msg);

/// Create msg/ProcCpuData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * monitor_msgs__msg__ProcCpuData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
monitor_msgs__msg__ProcCpuData *
monitor_msgs__msg__ProcCpuData__create();

/// Destroy msg/ProcCpuData message.
/**
 * It calls
 * monitor_msgs__msg__ProcCpuData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
void
monitor_msgs__msg__ProcCpuData__destroy(monitor_msgs__msg__ProcCpuData * msg);

/// Check for msg/ProcCpuData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcCpuData__are_equal(const monitor_msgs__msg__ProcCpuData * lhs, const monitor_msgs__msg__ProcCpuData * rhs);

/// Copy a msg/ProcCpuData message.
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
monitor_msgs__msg__ProcCpuData__copy(
  const monitor_msgs__msg__ProcCpuData * input,
  monitor_msgs__msg__ProcCpuData * output);

/// Initialize array of msg/ProcCpuData messages.
/**
 * It allocates the memory for the number of elements and calls
 * monitor_msgs__msg__ProcCpuData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcCpuData__Sequence__init(monitor_msgs__msg__ProcCpuData__Sequence * array, size_t size);

/// Finalize array of msg/ProcCpuData messages.
/**
 * It calls
 * monitor_msgs__msg__ProcCpuData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
void
monitor_msgs__msg__ProcCpuData__Sequence__fini(monitor_msgs__msg__ProcCpuData__Sequence * array);

/// Create array of msg/ProcCpuData messages.
/**
 * It allocates the memory for the array and calls
 * monitor_msgs__msg__ProcCpuData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
monitor_msgs__msg__ProcCpuData__Sequence *
monitor_msgs__msg__ProcCpuData__Sequence__create(size_t size);

/// Destroy array of msg/ProcCpuData messages.
/**
 * It calls
 * monitor_msgs__msg__ProcCpuData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
void
monitor_msgs__msg__ProcCpuData__Sequence__destroy(monitor_msgs__msg__ProcCpuData__Sequence * array);

/// Check for msg/ProcCpuData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_monitor_msgs
bool
monitor_msgs__msg__ProcCpuData__Sequence__are_equal(const monitor_msgs__msg__ProcCpuData__Sequence * lhs, const monitor_msgs__msg__ProcCpuData__Sequence * rhs);

/// Copy an array of msg/ProcCpuData messages.
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
monitor_msgs__msg__ProcCpuData__Sequence__copy(
  const monitor_msgs__msg__ProcCpuData__Sequence * input,
  monitor_msgs__msg__ProcCpuData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__FUNCTIONS_H_
