// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from example_interfaces:srv/Comimagen.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__STRUCT_H_
#define EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'imagen'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in srv/Comimagen in the package example_interfaces.
typedef struct example_interfaces__srv__Comimagen_Request
{
  sensor_msgs__msg__Image imagen;
  int32_t banner;
} example_interfaces__srv__Comimagen_Request;

// Struct for a sequence of example_interfaces__srv__Comimagen_Request.
typedef struct example_interfaces__srv__Comimagen_Request__Sequence
{
  example_interfaces__srv__Comimagen_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} example_interfaces__srv__Comimagen_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'finalizo'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Comimagen in the package example_interfaces.
typedef struct example_interfaces__srv__Comimagen_Response
{
  rosidl_runtime_c__String finalizo;
} example_interfaces__srv__Comimagen_Response;

// Struct for a sequence of example_interfaces__srv__Comimagen_Response.
typedef struct example_interfaces__srv__Comimagen_Response__Sequence
{
  example_interfaces__srv__Comimagen_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} example_interfaces__srv__Comimagen_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__STRUCT_H_
