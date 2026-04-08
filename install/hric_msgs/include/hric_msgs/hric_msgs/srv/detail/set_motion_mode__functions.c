// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hric_msgs:srv/SetMotionMode.idl
// generated code does not contain a copyright notice
#include "hric_msgs/srv/detail/set_motion_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
hric_msgs__srv__SetMotionMode_Request__init(hric_msgs__srv__SetMotionMode_Request * msg)
{
  if (!msg) {
    return false;
  }
  // walk_mode_request
  // is_need_swing_arm
  return true;
}

void
hric_msgs__srv__SetMotionMode_Request__fini(hric_msgs__srv__SetMotionMode_Request * msg)
{
  if (!msg) {
    return;
  }
  // walk_mode_request
  // is_need_swing_arm
}

bool
hric_msgs__srv__SetMotionMode_Request__are_equal(const hric_msgs__srv__SetMotionMode_Request * lhs, const hric_msgs__srv__SetMotionMode_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // walk_mode_request
  if (lhs->walk_mode_request != rhs->walk_mode_request) {
    return false;
  }
  // is_need_swing_arm
  if (lhs->is_need_swing_arm != rhs->is_need_swing_arm) {
    return false;
  }
  return true;
}

bool
hric_msgs__srv__SetMotionMode_Request__copy(
  const hric_msgs__srv__SetMotionMode_Request * input,
  hric_msgs__srv__SetMotionMode_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // walk_mode_request
  output->walk_mode_request = input->walk_mode_request;
  // is_need_swing_arm
  output->is_need_swing_arm = input->is_need_swing_arm;
  return true;
}

hric_msgs__srv__SetMotionMode_Request *
hric_msgs__srv__SetMotionMode_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__srv__SetMotionMode_Request * msg = (hric_msgs__srv__SetMotionMode_Request *)allocator.allocate(sizeof(hric_msgs__srv__SetMotionMode_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hric_msgs__srv__SetMotionMode_Request));
  bool success = hric_msgs__srv__SetMotionMode_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hric_msgs__srv__SetMotionMode_Request__destroy(hric_msgs__srv__SetMotionMode_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hric_msgs__srv__SetMotionMode_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hric_msgs__srv__SetMotionMode_Request__Sequence__init(hric_msgs__srv__SetMotionMode_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__srv__SetMotionMode_Request * data = NULL;

  if (size) {
    data = (hric_msgs__srv__SetMotionMode_Request *)allocator.zero_allocate(size, sizeof(hric_msgs__srv__SetMotionMode_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hric_msgs__srv__SetMotionMode_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hric_msgs__srv__SetMotionMode_Request__fini(&data[i - 1]);
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
hric_msgs__srv__SetMotionMode_Request__Sequence__fini(hric_msgs__srv__SetMotionMode_Request__Sequence * array)
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
      hric_msgs__srv__SetMotionMode_Request__fini(&array->data[i]);
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

hric_msgs__srv__SetMotionMode_Request__Sequence *
hric_msgs__srv__SetMotionMode_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__srv__SetMotionMode_Request__Sequence * array = (hric_msgs__srv__SetMotionMode_Request__Sequence *)allocator.allocate(sizeof(hric_msgs__srv__SetMotionMode_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hric_msgs__srv__SetMotionMode_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hric_msgs__srv__SetMotionMode_Request__Sequence__destroy(hric_msgs__srv__SetMotionMode_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hric_msgs__srv__SetMotionMode_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hric_msgs__srv__SetMotionMode_Request__Sequence__are_equal(const hric_msgs__srv__SetMotionMode_Request__Sequence * lhs, const hric_msgs__srv__SetMotionMode_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hric_msgs__srv__SetMotionMode_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hric_msgs__srv__SetMotionMode_Request__Sequence__copy(
  const hric_msgs__srv__SetMotionMode_Request__Sequence * input,
  hric_msgs__srv__SetMotionMode_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hric_msgs__srv__SetMotionMode_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hric_msgs__srv__SetMotionMode_Request * data =
      (hric_msgs__srv__SetMotionMode_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hric_msgs__srv__SetMotionMode_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hric_msgs__srv__SetMotionMode_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hric_msgs__srv__SetMotionMode_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
hric_msgs__srv__SetMotionMode_Response__init(hric_msgs__srv__SetMotionMode_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_code
  return true;
}

void
hric_msgs__srv__SetMotionMode_Response__fini(hric_msgs__srv__SetMotionMode_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_code
}

bool
hric_msgs__srv__SetMotionMode_Response__are_equal(const hric_msgs__srv__SetMotionMode_Response * lhs, const hric_msgs__srv__SetMotionMode_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // error_code
  if (lhs->error_code != rhs->error_code) {
    return false;
  }
  return true;
}

bool
hric_msgs__srv__SetMotionMode_Response__copy(
  const hric_msgs__srv__SetMotionMode_Response * input,
  hric_msgs__srv__SetMotionMode_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // error_code
  output->error_code = input->error_code;
  return true;
}

hric_msgs__srv__SetMotionMode_Response *
hric_msgs__srv__SetMotionMode_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__srv__SetMotionMode_Response * msg = (hric_msgs__srv__SetMotionMode_Response *)allocator.allocate(sizeof(hric_msgs__srv__SetMotionMode_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hric_msgs__srv__SetMotionMode_Response));
  bool success = hric_msgs__srv__SetMotionMode_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hric_msgs__srv__SetMotionMode_Response__destroy(hric_msgs__srv__SetMotionMode_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hric_msgs__srv__SetMotionMode_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hric_msgs__srv__SetMotionMode_Response__Sequence__init(hric_msgs__srv__SetMotionMode_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__srv__SetMotionMode_Response * data = NULL;

  if (size) {
    data = (hric_msgs__srv__SetMotionMode_Response *)allocator.zero_allocate(size, sizeof(hric_msgs__srv__SetMotionMode_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hric_msgs__srv__SetMotionMode_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hric_msgs__srv__SetMotionMode_Response__fini(&data[i - 1]);
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
hric_msgs__srv__SetMotionMode_Response__Sequence__fini(hric_msgs__srv__SetMotionMode_Response__Sequence * array)
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
      hric_msgs__srv__SetMotionMode_Response__fini(&array->data[i]);
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

hric_msgs__srv__SetMotionMode_Response__Sequence *
hric_msgs__srv__SetMotionMode_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__srv__SetMotionMode_Response__Sequence * array = (hric_msgs__srv__SetMotionMode_Response__Sequence *)allocator.allocate(sizeof(hric_msgs__srv__SetMotionMode_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hric_msgs__srv__SetMotionMode_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hric_msgs__srv__SetMotionMode_Response__Sequence__destroy(hric_msgs__srv__SetMotionMode_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hric_msgs__srv__SetMotionMode_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hric_msgs__srv__SetMotionMode_Response__Sequence__are_equal(const hric_msgs__srv__SetMotionMode_Response__Sequence * lhs, const hric_msgs__srv__SetMotionMode_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hric_msgs__srv__SetMotionMode_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hric_msgs__srv__SetMotionMode_Response__Sequence__copy(
  const hric_msgs__srv__SetMotionMode_Response__Sequence * input,
  hric_msgs__srv__SetMotionMode_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hric_msgs__srv__SetMotionMode_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hric_msgs__srv__SetMotionMode_Response * data =
      (hric_msgs__srv__SetMotionMode_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hric_msgs__srv__SetMotionMode_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hric_msgs__srv__SetMotionMode_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hric_msgs__srv__SetMotionMode_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
