// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from player_interfaces:srv/Player.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "player_interfaces/srv/detail/player__rosidl_typesupport_introspection_c.h"
#include "player_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "player_interfaces/srv/detail/player__functions.h"
#include "player_interfaces/srv/detail/player__struct.h"


// Include directives for member types
// Member `nombre`
#include "rosidl_runtime_c/string_functions.h"
// Member `posiciones`
#include "geometry_msgs/msg/twist.h"
// Member `posiciones`
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  player_interfaces__srv__Player_Request__init(message_memory);
}

void player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_fini_function(void * message_memory)
{
  player_interfaces__srv__Player_Request__fini(message_memory);
}

size_t player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__size_function__Player_Request__posiciones(
  const void * untyped_member)
{
  const geometry_msgs__msg__Twist__Sequence * member =
    (const geometry_msgs__msg__Twist__Sequence *)(untyped_member);
  return member->size;
}

const void * player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__get_const_function__Player_Request__posiciones(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Twist__Sequence * member =
    (const geometry_msgs__msg__Twist__Sequence *)(untyped_member);
  return &member->data[index];
}

void * player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__get_function__Player_Request__posiciones(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Twist__Sequence * member =
    (geometry_msgs__msg__Twist__Sequence *)(untyped_member);
  return &member->data[index];
}

void player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__fetch_function__Player_Request__posiciones(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Twist * item =
    ((const geometry_msgs__msg__Twist *)
    player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__get_const_function__Player_Request__posiciones(untyped_member, index));
  geometry_msgs__msg__Twist * value =
    (geometry_msgs__msg__Twist *)(untyped_value);
  *value = *item;
}

void player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__assign_function__Player_Request__posiciones(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Twist * item =
    ((geometry_msgs__msg__Twist *)
    player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__get_function__Player_Request__posiciones(untyped_member, index));
  const geometry_msgs__msg__Twist * value =
    (const geometry_msgs__msg__Twist *)(untyped_value);
  *item = *value;
}

bool player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__resize_function__Player_Request__posiciones(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Twist__Sequence * member =
    (geometry_msgs__msg__Twist__Sequence *)(untyped_member);
  geometry_msgs__msg__Twist__Sequence__fini(member);
  return geometry_msgs__msg__Twist__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_message_member_array[2] = {
  {
    "nombre",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces__srv__Player_Request, nombre),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "posiciones",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces__srv__Player_Request, posiciones),  // bytes offset in struct
    NULL,  // default value
    player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__size_function__Player_Request__posiciones,  // size() function pointer
    player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__get_const_function__Player_Request__posiciones,  // get_const(index) function pointer
    player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__get_function__Player_Request__posiciones,  // get(index) function pointer
    player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__fetch_function__Player_Request__posiciones,  // fetch(index, &value) function pointer
    player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__assign_function__Player_Request__posiciones,  // assign(index, value) function pointer
    player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__resize_function__Player_Request__posiciones  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_message_members = {
  "player_interfaces__srv",  // message namespace
  "Player_Request",  // message name
  2,  // number of fields
  sizeof(player_interfaces__srv__Player_Request),
  player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_message_member_array,  // message members
  player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_message_type_support_handle = {
  0,
  &player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_player_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, player_interfaces, srv, Player_Request)() {
  player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Twist)();
  if (!player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_message_type_support_handle.typesupport_identifier) {
    player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &player_interfaces__srv__Player_Request__rosidl_typesupport_introspection_c__Player_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "player_interfaces/srv/detail/player__rosidl_typesupport_introspection_c.h"
// already included above
// #include "player_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "player_interfaces/srv/detail/player__functions.h"
// already included above
// #include "player_interfaces/srv/detail/player__struct.h"


// Include directives for member types
// Member `respuesta`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  player_interfaces__srv__Player_Response__init(message_memory);
}

void player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_fini_function(void * message_memory)
{
  player_interfaces__srv__Player_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_message_member_array[1] = {
  {
    "respuesta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces__srv__Player_Response, respuesta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_message_members = {
  "player_interfaces__srv",  // message namespace
  "Player_Response",  // message name
  1,  // number of fields
  sizeof(player_interfaces__srv__Player_Response),
  player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_message_member_array,  // message members
  player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_message_type_support_handle = {
  0,
  &player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_player_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, player_interfaces, srv, Player_Response)() {
  if (!player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_message_type_support_handle.typesupport_identifier) {
    player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &player_interfaces__srv__Player_Response__rosidl_typesupport_introspection_c__Player_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "player_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "player_interfaces/srv/detail/player__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers player_interfaces__srv__detail__player__rosidl_typesupport_introspection_c__Player_service_members = {
  "player_interfaces__srv",  // service namespace
  "Player",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // player_interfaces__srv__detail__player__rosidl_typesupport_introspection_c__Player_Request_message_type_support_handle,
  NULL  // response message
  // player_interfaces__srv__detail__player__rosidl_typesupport_introspection_c__Player_Response_message_type_support_handle
};

static rosidl_service_type_support_t player_interfaces__srv__detail__player__rosidl_typesupport_introspection_c__Player_service_type_support_handle = {
  0,
  &player_interfaces__srv__detail__player__rosidl_typesupport_introspection_c__Player_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, player_interfaces, srv, Player_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, player_interfaces, srv, Player_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_player_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, player_interfaces, srv, Player)() {
  if (!player_interfaces__srv__detail__player__rosidl_typesupport_introspection_c__Player_service_type_support_handle.typesupport_identifier) {
    player_interfaces__srv__detail__player__rosidl_typesupport_introspection_c__Player_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)player_interfaces__srv__detail__player__rosidl_typesupport_introspection_c__Player_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, player_interfaces, srv, Player_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, player_interfaces, srv, Player_Response)()->data;
  }

  return &player_interfaces__srv__detail__player__rosidl_typesupport_introspection_c__Player_service_type_support_handle;
}
