// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from proyecto_interfaces:msg/Banner.idl
// generated code does not contain a copyright notice
#include "proyecto_interfaces/msg/detail/banner__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `figure`
// Member `word`
// Member `color`
#include "rosidl_runtime_c/string_functions.h"

bool
proyecto_interfaces__msg__Banner__init(proyecto_interfaces__msg__Banner * msg)
{
  if (!msg) {
    return false;
  }
  // banner
  // figure
  if (!rosidl_runtime_c__String__init(&msg->figure)) {
    proyecto_interfaces__msg__Banner__fini(msg);
    return false;
  }
  // word
  if (!rosidl_runtime_c__String__init(&msg->word)) {
    proyecto_interfaces__msg__Banner__fini(msg);
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__init(&msg->color)) {
    proyecto_interfaces__msg__Banner__fini(msg);
    return false;
  }
  return true;
}

void
proyecto_interfaces__msg__Banner__fini(proyecto_interfaces__msg__Banner * msg)
{
  if (!msg) {
    return;
  }
  // banner
  // figure
  rosidl_runtime_c__String__fini(&msg->figure);
  // word
  rosidl_runtime_c__String__fini(&msg->word);
  // color
  rosidl_runtime_c__String__fini(&msg->color);
}

bool
proyecto_interfaces__msg__Banner__are_equal(const proyecto_interfaces__msg__Banner * lhs, const proyecto_interfaces__msg__Banner * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // banner
  if (lhs->banner != rhs->banner) {
    return false;
  }
  // figure
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->figure), &(rhs->figure)))
  {
    return false;
  }
  // word
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->word), &(rhs->word)))
  {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->color), &(rhs->color)))
  {
    return false;
  }
  return true;
}

bool
proyecto_interfaces__msg__Banner__copy(
  const proyecto_interfaces__msg__Banner * input,
  proyecto_interfaces__msg__Banner * output)
{
  if (!input || !output) {
    return false;
  }
  // banner
  output->banner = input->banner;
  // figure
  if (!rosidl_runtime_c__String__copy(
      &(input->figure), &(output->figure)))
  {
    return false;
  }
  // word
  if (!rosidl_runtime_c__String__copy(
      &(input->word), &(output->word)))
  {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__copy(
      &(input->color), &(output->color)))
  {
    return false;
  }
  return true;
}

proyecto_interfaces__msg__Banner *
proyecto_interfaces__msg__Banner__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  proyecto_interfaces__msg__Banner * msg = (proyecto_interfaces__msg__Banner *)allocator.allocate(sizeof(proyecto_interfaces__msg__Banner), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(proyecto_interfaces__msg__Banner));
  bool success = proyecto_interfaces__msg__Banner__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
proyecto_interfaces__msg__Banner__destroy(proyecto_interfaces__msg__Banner * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    proyecto_interfaces__msg__Banner__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
proyecto_interfaces__msg__Banner__Sequence__init(proyecto_interfaces__msg__Banner__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  proyecto_interfaces__msg__Banner * data = NULL;

  if (size) {
    data = (proyecto_interfaces__msg__Banner *)allocator.zero_allocate(size, sizeof(proyecto_interfaces__msg__Banner), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = proyecto_interfaces__msg__Banner__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        proyecto_interfaces__msg__Banner__fini(&data[i - 1]);
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
proyecto_interfaces__msg__Banner__Sequence__fini(proyecto_interfaces__msg__Banner__Sequence * array)
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
      proyecto_interfaces__msg__Banner__fini(&array->data[i]);
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

proyecto_interfaces__msg__Banner__Sequence *
proyecto_interfaces__msg__Banner__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  proyecto_interfaces__msg__Banner__Sequence * array = (proyecto_interfaces__msg__Banner__Sequence *)allocator.allocate(sizeof(proyecto_interfaces__msg__Banner__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = proyecto_interfaces__msg__Banner__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
proyecto_interfaces__msg__Banner__Sequence__destroy(proyecto_interfaces__msg__Banner__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    proyecto_interfaces__msg__Banner__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
proyecto_interfaces__msg__Banner__Sequence__are_equal(const proyecto_interfaces__msg__Banner__Sequence * lhs, const proyecto_interfaces__msg__Banner__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!proyecto_interfaces__msg__Banner__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
proyecto_interfaces__msg__Banner__Sequence__copy(
  const proyecto_interfaces__msg__Banner__Sequence * input,
  proyecto_interfaces__msg__Banner__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(proyecto_interfaces__msg__Banner);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    proyecto_interfaces__msg__Banner * data =
      (proyecto_interfaces__msg__Banner *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!proyecto_interfaces__msg__Banner__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          proyecto_interfaces__msg__Banner__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!proyecto_interfaces__msg__Banner__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
