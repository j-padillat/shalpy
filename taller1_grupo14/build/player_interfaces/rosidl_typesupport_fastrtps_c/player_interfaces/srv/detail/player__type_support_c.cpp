// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from player_interfaces:srv/Player.idl
// generated code does not contain a copyright notice
#include "player_interfaces/srv/detail/player__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "player_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "player_interfaces/srv/detail/player__struct.h"
#include "player_interfaces/srv/detail/player__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // nombre
#include "rosidl_runtime_c/string_functions.h"  // nombre

// forward declare type support functions


using _Player_Request__ros_msg_type = player_interfaces__srv__Player_Request;

static bool _Player_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Player_Request__ros_msg_type * ros_message = static_cast<const _Player_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: nombre
  {
    const rosidl_runtime_c__String * str = &ros_message->nombre;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _Player_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Player_Request__ros_msg_type * ros_message = static_cast<_Player_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: nombre
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->nombre.data) {
      rosidl_runtime_c__String__init(&ros_message->nombre);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->nombre,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'nombre'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_player_interfaces
size_t get_serialized_size_player_interfaces__srv__Player_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Player_Request__ros_msg_type * ros_message = static_cast<const _Player_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name nombre
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->nombre.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Player_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_player_interfaces__srv__Player_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_player_interfaces
size_t max_serialized_size_player_interfaces__srv__Player_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: nombre
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Player_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_player_interfaces__srv__Player_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Player_Request = {
  "player_interfaces::srv",
  "Player_Request",
  _Player_Request__cdr_serialize,
  _Player_Request__cdr_deserialize,
  _Player_Request__get_serialized_size,
  _Player_Request__max_serialized_size
};

static rosidl_message_type_support_t _Player_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Player_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, Player_Request)() {
  return &_Player_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "player_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "player_interfaces/srv/detail/player__struct.h"
// already included above
// #include "player_interfaces/srv/detail/player__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // respuesta
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // respuesta

// forward declare type support functions


using _Player_Response__ros_msg_type = player_interfaces__srv__Player_Response;

static bool _Player_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Player_Response__ros_msg_type * ros_message = static_cast<const _Player_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: respuesta
  {
    const rosidl_runtime_c__String * str = &ros_message->respuesta;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _Player_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Player_Response__ros_msg_type * ros_message = static_cast<_Player_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: respuesta
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->respuesta.data) {
      rosidl_runtime_c__String__init(&ros_message->respuesta);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->respuesta,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'respuesta'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_player_interfaces
size_t get_serialized_size_player_interfaces__srv__Player_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Player_Response__ros_msg_type * ros_message = static_cast<const _Player_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name respuesta
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->respuesta.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Player_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_player_interfaces__srv__Player_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_player_interfaces
size_t max_serialized_size_player_interfaces__srv__Player_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: respuesta
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Player_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_player_interfaces__srv__Player_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Player_Response = {
  "player_interfaces::srv",
  "Player_Response",
  _Player_Response__cdr_serialize,
  _Player_Response__cdr_deserialize,
  _Player_Response__get_serialized_size,
  _Player_Response__max_serialized_size
};

static rosidl_message_type_support_t _Player_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Player_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, Player_Response)() {
  return &_Player_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "player_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "player_interfaces/srv/player.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Player__callbacks = {
  "player_interfaces::srv",
  "Player",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, Player_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, Player_Response)(),
};

static rosidl_service_type_support_t Player__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Player__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, Player)() {
  return &Player__handle;
}

#if defined(__cplusplus)
}
#endif
