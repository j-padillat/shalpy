// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from player_interfaces:msg/Trace.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "player_interfaces/msg/detail/trace__rosidl_typesupport_introspection_c.h"
#include "player_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "player_interfaces/msg/detail/trace__functions.h"
#include "player_interfaces/msg/detail/trace__struct.h"


// Include directives for member types
// Member `key`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  player_interfaces__msg__Trace__init(message_memory);
}

void player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_fini_function(void * message_memory)
{
  player_interfaces__msg__Trace__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_message_member_array[5] = {
  {
    "key",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces__msg__Trace, key),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces__msg__Trace, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces__msg__Trace, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "th",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces__msg__Trace, th),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces__msg__Trace, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_message_members = {
  "player_interfaces__msg",  // message namespace
  "Trace",  // message name
  5,  // number of fields
  sizeof(player_interfaces__msg__Trace),
  player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_message_member_array,  // message members
  player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_init_function,  // function to initialize message memory (memory has to be allocated)
  player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_message_type_support_handle = {
  0,
  &player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_player_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, player_interfaces, msg, Trace)() {
  if (!player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_message_type_support_handle.typesupport_identifier) {
    player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &player_interfaces__msg__Trace__rosidl_typesupport_introspection_c__Trace_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
