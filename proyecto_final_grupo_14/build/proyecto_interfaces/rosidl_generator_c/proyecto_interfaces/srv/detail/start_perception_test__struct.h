// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from proyecto_interfaces:srv/StartPerceptionTest.idl
// generated code does not contain a copyright notice

#ifndef PROYECTO_INTERFACES__SRV__DETAIL__START_PERCEPTION_TEST__STRUCT_H_
#define PROYECTO_INTERFACES__SRV__DETAIL__START_PERCEPTION_TEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/StartPerceptionTest in the package proyecto_interfaces.
typedef struct proyecto_interfaces__srv__StartPerceptionTest_Request
{
  int32_t banner_a;
  int32_t banner_b;
} proyecto_interfaces__srv__StartPerceptionTest_Request;

// Struct for a sequence of proyecto_interfaces__srv__StartPerceptionTest_Request.
typedef struct proyecto_interfaces__srv__StartPerceptionTest_Request__Sequence
{
  proyecto_interfaces__srv__StartPerceptionTest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} proyecto_interfaces__srv__StartPerceptionTest_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'answer'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartPerceptionTest in the package proyecto_interfaces.
typedef struct proyecto_interfaces__srv__StartPerceptionTest_Response
{
  rosidl_runtime_c__String answer;
} proyecto_interfaces__srv__StartPerceptionTest_Response;

// Struct for a sequence of proyecto_interfaces__srv__StartPerceptionTest_Response.
typedef struct proyecto_interfaces__srv__StartPerceptionTest_Response__Sequence
{
  proyecto_interfaces__srv__StartPerceptionTest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} proyecto_interfaces__srv__StartPerceptionTest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROYECTO_INTERFACES__SRV__DETAIL__START_PERCEPTION_TEST__STRUCT_H_
