// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from example_interfaces:msg/Banner.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__MSG__DETAIL__BANNER__STRUCT_H_
#define EXAMPLE_INTERFACES__MSG__DETAIL__BANNER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'figure'
// Member 'word'
// Member 'color'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Banner in the package example_interfaces.
typedef struct example_interfaces__msg__Banner
{
  int32_t banner;
  rosidl_runtime_c__String figure;
  rosidl_runtime_c__String word;
  rosidl_runtime_c__String color;
} example_interfaces__msg__Banner;

// Struct for a sequence of example_interfaces__msg__Banner.
typedef struct example_interfaces__msg__Banner__Sequence
{
  example_interfaces__msg__Banner * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} example_interfaces__msg__Banner__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EXAMPLE_INTERFACES__MSG__DETAIL__BANNER__STRUCT_H_
