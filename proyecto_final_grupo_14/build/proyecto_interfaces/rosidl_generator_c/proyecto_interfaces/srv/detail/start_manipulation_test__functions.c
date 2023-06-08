// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from proyecto_interfaces:srv/StartManipulationTest.idl
// generated code does not contain a copyright notice
#include "proyecto_interfaces/srv/detail/start_manipulation_test__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `platform`
#include "rosidl_runtime_c/string_functions.h"

bool
proyecto_interfaces__srv__StartManipulationTest_Request__init(proyecto_interfaces__srv__StartManipulationTest_Request * msg)
{
  if (!msg) {
    return false;
  }
  // platform
  if (!rosidl_runtime_c__String__init(&msg->platform)) {
    proyecto_interfaces__srv__StartManipulationTest_Request__fini(msg);
    return false;
  }
  // x
  return true;
}

void
proyecto_interfaces__srv__StartManipulationTest_Request__fini(proyecto_interfaces__srv__StartManipulationTest_Request * msg)
{
  if (!msg) {
    return;
  }
  // platform
  rosidl_runtime_c__String__fini(&msg->platform);
  // x
}

bool
proyecto_interfaces__srv__StartManipulationTest_Request__are_equal(const proyecto_interfaces__srv__StartManipulationTest_Request * lhs, const proyecto_interfaces__srv__StartManipulationTest_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // platform
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->platform), &(rhs->platform)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  return true;
}

bool
proyecto_interfaces__srv__StartManipulationTest_Request__copy(
  const proyecto_interfaces__srv__StartManipulationTest_Request * input,
  proyecto_interfaces__srv__StartManipulationTest_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // platform
  if (!rosidl_runtime_c__String__copy(
      &(input->platform), &(output->platform)))
  {
    return false;
  }
  // x
  output->x = input->x;
  return true;
}

proyecto_interfaces__srv__StartManipulationTest_Request *
proyecto_interfaces__srv__StartManipulationTest_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  proyecto_interfaces__srv__StartManipulationTest_Request * msg = (proyecto_interfaces__srv__StartManipulationTest_Request *)allocator.allocate(sizeof(proyecto_interfaces__srv__StartManipulationTest_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(proyecto_interfaces__srv__StartManipulationTest_Request));
  bool success = proyecto_interfaces__srv__StartManipulationTest_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
proyecto_interfaces__srv__StartManipulationTest_Request__destroy(proyecto_interfaces__srv__StartManipulationTest_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    proyecto_interfaces__srv__StartManipulationTest_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
proyecto_interfaces__srv__StartManipulationTest_Request__Sequence__init(proyecto_interfaces__srv__StartManipulationTest_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  proyecto_interfaces__srv__StartManipulationTest_Request * data = NULL;

  if (size) {
    data = (proyecto_interfaces__srv__StartManipulationTest_Request *)allocator.zero_allocate(size, sizeof(proyecto_interfaces__srv__StartManipulationTest_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = proyecto_interfaces__srv__StartManipulationTest_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        proyecto_interfaces__srv__StartManipulationTest_Request__fini(&data[i - 1]);
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
proyecto_interfaces__srv__StartManipulationTest_Request__Sequence__fini(proyecto_interfaces__srv__StartManipulationTest_Request__Sequence * array)
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
      proyecto_interfaces__srv__StartManipulationTest_Request__fini(&array->data[i]);
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

proyecto_interfaces__srv__StartManipulationTest_Request__Sequence *
proyecto_interfaces__srv__StartManipulationTest_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  proyecto_interfaces__srv__StartManipulationTest_Request__Sequence * array = (proyecto_interfaces__srv__StartManipulationTest_Request__Sequence *)allocator.allocate(sizeof(proyecto_interfaces__srv__StartManipulationTest_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = proyecto_interfaces__srv__StartManipulationTest_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
proyecto_interfaces__srv__StartManipulationTest_Request__Sequence__destroy(proyecto_interfaces__srv__StartManipulationTest_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    proyecto_interfaces__srv__StartManipulationTest_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
proyecto_interfaces__srv__StartManipulationTest_Request__Sequence__are_equal(const proyecto_interfaces__srv__StartManipulationTest_Request__Sequence * lhs, const proyecto_interfaces__srv__StartManipulationTest_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!proyecto_interfaces__srv__StartManipulationTest_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
proyecto_interfaces__srv__StartManipulationTest_Request__Sequence__copy(
  const proyecto_interfaces__srv__StartManipulationTest_Request__Sequence * input,
  proyecto_interfaces__srv__StartManipulationTest_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(proyecto_interfaces__srv__StartManipulationTest_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    proyecto_interfaces__srv__StartManipulationTest_Request * data =
      (proyecto_interfaces__srv__StartManipulationTest_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!proyecto_interfaces__srv__StartManipulationTest_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          proyecto_interfaces__srv__StartManipulationTest_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!proyecto_interfaces__srv__StartManipulationTest_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `answer`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
proyecto_interfaces__srv__StartManipulationTest_Response__init(proyecto_interfaces__srv__StartManipulationTest_Response * msg)
{
  if (!msg) {
    return false;
  }
  // answer
  if (!rosidl_runtime_c__String__init(&msg->answer)) {
    proyecto_interfaces__srv__StartManipulationTest_Response__fini(msg);
    return false;
  }
  return true;
}

void
proyecto_interfaces__srv__StartManipulationTest_Response__fini(proyecto_interfaces__srv__StartManipulationTest_Response * msg)
{
  if (!msg) {
    return;
  }
  // answer
  rosidl_runtime_c__String__fini(&msg->answer);
}

bool
proyecto_interfaces__srv__StartManipulationTest_Response__are_equal(const proyecto_interfaces__srv__StartManipulationTest_Response * lhs, const proyecto_interfaces__srv__StartManipulationTest_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // answer
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->answer), &(rhs->answer)))
  {
    return false;
  }
  return true;
}

bool
proyecto_interfaces__srv__StartManipulationTest_Response__copy(
  const proyecto_interfaces__srv__StartManipulationTest_Response * input,
  proyecto_interfaces__srv__StartManipulationTest_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // answer
  if (!rosidl_runtime_c__String__copy(
      &(input->answer), &(output->answer)))
  {
    return false;
  }
  return true;
}

proyecto_interfaces__srv__StartManipulationTest_Response *
proyecto_interfaces__srv__StartManipulationTest_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  proyecto_interfaces__srv__StartManipulationTest_Response * msg = (proyecto_interfaces__srv__StartManipulationTest_Response *)allocator.allocate(sizeof(proyecto_interfaces__srv__StartManipulationTest_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(proyecto_interfaces__srv__StartManipulationTest_Response));
  bool success = proyecto_interfaces__srv__StartManipulationTest_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
proyecto_interfaces__srv__StartManipulationTest_Response__destroy(proyecto_interfaces__srv__StartManipulationTest_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    proyecto_interfaces__srv__StartManipulationTest_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
proyecto_interfaces__srv__StartManipulationTest_Response__Sequence__init(proyecto_interfaces__srv__StartManipulationTest_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  proyecto_interfaces__srv__StartManipulationTest_Response * data = NULL;

  if (size) {
    data = (proyecto_interfaces__srv__StartManipulationTest_Response *)allocator.zero_allocate(size, sizeof(proyecto_interfaces__srv__StartManipulationTest_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = proyecto_interfaces__srv__StartManipulationTest_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        proyecto_interfaces__srv__StartManipulationTest_Response__fini(&data[i - 1]);
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
proyecto_interfaces__srv__StartManipulationTest_Response__Sequence__fini(proyecto_interfaces__srv__StartManipulationTest_Response__Sequence * array)
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
      proyecto_interfaces__srv__StartManipulationTest_Response__fini(&array->data[i]);
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

proyecto_interfaces__srv__StartManipulationTest_Response__Sequence *
proyecto_interfaces__srv__StartManipulationTest_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  proyecto_interfaces__srv__StartManipulationTest_Response__Sequence * array = (proyecto_interfaces__srv__StartManipulationTest_Response__Sequence *)allocator.allocate(sizeof(proyecto_interfaces__srv__StartManipulationTest_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = proyecto_interfaces__srv__StartManipulationTest_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
proyecto_interfaces__srv__StartManipulationTest_Response__Sequence__destroy(proyecto_interfaces__srv__StartManipulationTest_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    proyecto_interfaces__srv__StartManipulationTest_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
proyecto_interfaces__srv__StartManipulationTest_Response__Sequence__are_equal(const proyecto_interfaces__srv__StartManipulationTest_Response__Sequence * lhs, const proyecto_interfaces__srv__StartManipulationTest_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!proyecto_interfaces__srv__StartManipulationTest_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
proyecto_interfaces__srv__StartManipulationTest_Response__Sequence__copy(
  const proyecto_interfaces__srv__StartManipulationTest_Response__Sequence * input,
  proyecto_interfaces__srv__StartManipulationTest_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(proyecto_interfaces__srv__StartManipulationTest_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    proyecto_interfaces__srv__StartManipulationTest_Response * data =
      (proyecto_interfaces__srv__StartManipulationTest_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!proyecto_interfaces__srv__StartManipulationTest_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          proyecto_interfaces__srv__StartManipulationTest_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!proyecto_interfaces__srv__StartManipulationTest_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
