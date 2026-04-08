// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hric_msgs:msg/FloatBaseRPYZ.idl
// generated code does not contain a copyright notice
#include "hric_msgs/msg/detail/float_base_rpyz__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hric_msgs__msg__FloatBaseRPYZ__init(hric_msgs__msg__FloatBaseRPYZ * msg)
{
  if (!msg) {
    return false;
  }
  // roll
  // pitch
  // yaw
  // z
  return true;
}

void
hric_msgs__msg__FloatBaseRPYZ__fini(hric_msgs__msg__FloatBaseRPYZ * msg)
{
  if (!msg) {
    return;
  }
  // roll
  // pitch
  // yaw
  // z
}

bool
hric_msgs__msg__FloatBaseRPYZ__are_equal(const hric_msgs__msg__FloatBaseRPYZ * lhs, const hric_msgs__msg__FloatBaseRPYZ * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
hric_msgs__msg__FloatBaseRPYZ__copy(
  const hric_msgs__msg__FloatBaseRPYZ * input,
  hric_msgs__msg__FloatBaseRPYZ * output)
{
  if (!input || !output) {
    return false;
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  // z
  output->z = input->z;
  return true;
}

hric_msgs__msg__FloatBaseRPYZ *
hric_msgs__msg__FloatBaseRPYZ__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__FloatBaseRPYZ * msg = (hric_msgs__msg__FloatBaseRPYZ *)allocator.allocate(sizeof(hric_msgs__msg__FloatBaseRPYZ), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hric_msgs__msg__FloatBaseRPYZ));
  bool success = hric_msgs__msg__FloatBaseRPYZ__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hric_msgs__msg__FloatBaseRPYZ__destroy(hric_msgs__msg__FloatBaseRPYZ * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hric_msgs__msg__FloatBaseRPYZ__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hric_msgs__msg__FloatBaseRPYZ__Sequence__init(hric_msgs__msg__FloatBaseRPYZ__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__FloatBaseRPYZ * data = NULL;

  if (size) {
    data = (hric_msgs__msg__FloatBaseRPYZ *)allocator.zero_allocate(size, sizeof(hric_msgs__msg__FloatBaseRPYZ), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hric_msgs__msg__FloatBaseRPYZ__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hric_msgs__msg__FloatBaseRPYZ__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hric_msgs__msg__FloatBaseRPYZ__Sequence__fini(hric_msgs__msg__FloatBaseRPYZ__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hric_msgs__msg__FloatBaseRPYZ__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hric_msgs__msg__FloatBaseRPYZ__Sequence *
hric_msgs__msg__FloatBaseRPYZ__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__FloatBaseRPYZ__Sequence * array = (hric_msgs__msg__FloatBaseRPYZ__Sequence *)allocator.allocate(sizeof(hric_msgs__msg__FloatBaseRPYZ__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hric_msgs__msg__FloatBaseRPYZ__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hric_msgs__msg__FloatBaseRPYZ__Sequence__destroy(hric_msgs__msg__FloatBaseRPYZ__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hric_msgs__msg__FloatBaseRPYZ__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hric_msgs__msg__FloatBaseRPYZ__Sequence__are_equal(const hric_msgs__msg__FloatBaseRPYZ__Sequence * lhs, const hric_msgs__msg__FloatBaseRPYZ__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hric_msgs__msg__FloatBaseRPYZ__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hric_msgs__msg__FloatBaseRPYZ__Sequence__copy(
  const hric_msgs__msg__FloatBaseRPYZ__Sequence * input,
  hric_msgs__msg__FloatBaseRPYZ__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hric_msgs__msg__FloatBaseRPYZ);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hric_msgs__msg__FloatBaseRPYZ * data =
      (hric_msgs__msg__FloatBaseRPYZ *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hric_msgs__msg__FloatBaseRPYZ__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hric_msgs__msg__FloatBaseRPYZ__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hric_msgs__msg__FloatBaseRPYZ__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
