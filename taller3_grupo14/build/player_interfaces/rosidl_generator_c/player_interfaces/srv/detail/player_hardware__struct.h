// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from player_interfaces:srv/PlayerHardware.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__SRV__DETAIL__PLAYER_HARDWARE__STRUCT_H_
#define PLAYER_INTERFACES__SRV__DETAIL__PLAYER_HARDWARE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'nombre'
// Member 'keys'
#include "rosidl_runtime_c/string.h"
// Member 'posiciones'
#include "geometry_msgs/msg/detail/twist__struct.h"
// Member 'times'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/PlayerHardware in the package player_interfaces.
typedef struct player_interfaces__srv__PlayerHardware_Request
{
  rosidl_runtime_c__String nombre;
  geometry_msgs__msg__Twist__Sequence posiciones;
  rosidl_runtime_c__String__Sequence keys;
  rosidl_runtime_c__double__Sequence times;
} player_interfaces__srv__PlayerHardware_Request;

// Struct for a sequence of player_interfaces__srv__PlayerHardware_Request.
typedef struct player_interfaces__srv__PlayerHardware_Request__Sequence
{
  player_interfaces__srv__PlayerHardware_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} player_interfaces__srv__PlayerHardware_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/PlayerHardware in the package player_interfaces.
typedef struct player_interfaces__srv__PlayerHardware_Response
{
  uint8_t structure_needs_at_least_one_member;
} player_interfaces__srv__PlayerHardware_Response;

// Struct for a sequence of player_interfaces__srv__PlayerHardware_Response.
typedef struct player_interfaces__srv__PlayerHardware_Response__Sequence
{
  player_interfaces__srv__PlayerHardware_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} player_interfaces__srv__PlayerHardware_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PLAYER_INTERFACES__SRV__DETAIL__PLAYER_HARDWARE__STRUCT_H_
