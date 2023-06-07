// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from player_interfaces:msg/Trace.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__MSG__DETAIL__TRACE__STRUCT_H_
#define PLAYER_INTERFACES__MSG__DETAIL__TRACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'key'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Trace in the package player_interfaces.
typedef struct player_interfaces__msg__Trace
{
  rosidl_runtime_c__String key;
  double x;
  double y;
  double th;
  double time;
} player_interfaces__msg__Trace;

// Struct for a sequence of player_interfaces__msg__Trace.
typedef struct player_interfaces__msg__Trace__Sequence
{
  player_interfaces__msg__Trace * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} player_interfaces__msg__Trace__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PLAYER_INTERFACES__MSG__DETAIL__TRACE__STRUCT_H_
