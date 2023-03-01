// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from player_interfaces:srv/Player.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__SRV__DETAIL__PLAYER__STRUCT_H_
#define PLAYER_INTERFACES__SRV__DETAIL__PLAYER__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"
// Member 'posiciones'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in srv/Player in the package player_interfaces.
typedef struct player_interfaces__srv__Player_Request
{
  rosidl_runtime_c__String nombre;
  geometry_msgs__msg__Twist__Sequence posiciones;
} player_interfaces__srv__Player_Request;

// Struct for a sequence of player_interfaces__srv__Player_Request.
typedef struct player_interfaces__srv__Player_Request__Sequence
{
  player_interfaces__srv__Player_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} player_interfaces__srv__Player_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Player in the package player_interfaces.
typedef struct player_interfaces__srv__Player_Response
{
  uint8_t structure_needs_at_least_one_member;
} player_interfaces__srv__Player_Response;

// Struct for a sequence of player_interfaces__srv__Player_Response.
typedef struct player_interfaces__srv__Player_Response__Sequence
{
  player_interfaces__srv__Player_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} player_interfaces__srv__Player_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PLAYER_INTERFACES__SRV__DETAIL__PLAYER__STRUCT_H_
