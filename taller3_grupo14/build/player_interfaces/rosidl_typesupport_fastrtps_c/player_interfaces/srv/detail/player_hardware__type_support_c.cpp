// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from player_interfaces:srv/PlayerHardware.idl
// generated code does not contain a copyright notice
#include "player_interfaces/srv/detail/player_hardware__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "player_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "player_interfaces/srv/detail/player_hardware__struct.h"
#include "player_interfaces/srv/detail/player_hardware__functions.h"
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

#include "geometry_msgs/msg/detail/twist__functions.h"  // posiciones
#include "rosidl_runtime_c/primitives_sequence.h"  // times
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // times
#include "rosidl_runtime_c/string.h"  // keys, nombre
#include "rosidl_runtime_c/string_functions.h"  // keys, nombre

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_player_interfaces
size_t get_serialized_size_geometry_msgs__msg__Twist(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_player_interfaces
size_t max_serialized_size_geometry_msgs__msg__Twist(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_player_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Twist)();


using _PlayerHardware_Request__ros_msg_type = player_interfaces__srv__PlayerHardware_Request;

static bool _PlayerHardware_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PlayerHardware_Request__ros_msg_type * ros_message = static_cast<const _PlayerHardware_Request__ros_msg_type *>(untyped_ros_message);
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

  // Field name: posiciones
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Twist
      )()->data);
    size_t size = ros_message->posiciones.size;
    auto array_ptr = ros_message->posiciones.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: keys
  {
    size_t size = ros_message->keys.size;
    auto array_ptr = ros_message->keys.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  // Field name: times
  {
    size_t size = ros_message->times.size;
    auto array_ptr = ros_message->times.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _PlayerHardware_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PlayerHardware_Request__ros_msg_type * ros_message = static_cast<_PlayerHardware_Request__ros_msg_type *>(untyped_ros_message);
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

  // Field name: posiciones
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Twist
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->posiciones.data) {
      geometry_msgs__msg__Twist__Sequence__fini(&ros_message->posiciones);
    }
    if (!geometry_msgs__msg__Twist__Sequence__init(&ros_message->posiciones, size)) {
      fprintf(stderr, "failed to create array for field 'posiciones'");
      return false;
    }
    auto array_ptr = ros_message->posiciones.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: keys
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->keys.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->keys);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->keys, size)) {
      fprintf(stderr, "failed to create array for field 'keys'");
      return false;
    }
    auto array_ptr = ros_message->keys.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'keys'\n");
        return false;
      }
    }
  }

  // Field name: times
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->times.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->times);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->times, size)) {
      fprintf(stderr, "failed to create array for field 'times'");
      return false;
    }
    auto array_ptr = ros_message->times.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_player_interfaces
size_t get_serialized_size_player_interfaces__srv__PlayerHardware_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PlayerHardware_Request__ros_msg_type * ros_message = static_cast<const _PlayerHardware_Request__ros_msg_type *>(untyped_ros_message);
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
  // field.name posiciones
  {
    size_t array_size = ros_message->posiciones.size;
    auto array_ptr = ros_message->posiciones.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_geometry_msgs__msg__Twist(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name keys
  {
    size_t array_size = ros_message->keys.size;
    auto array_ptr = ros_message->keys.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name times
  {
    size_t array_size = ros_message->times.size;
    auto array_ptr = ros_message->times.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PlayerHardware_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_player_interfaces__srv__PlayerHardware_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_player_interfaces
size_t max_serialized_size_player_interfaces__srv__PlayerHardware_Request(
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
  // member: posiciones
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Twist(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: keys
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: times
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _PlayerHardware_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_player_interfaces__srv__PlayerHardware_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PlayerHardware_Request = {
  "player_interfaces::srv",
  "PlayerHardware_Request",
  _PlayerHardware_Request__cdr_serialize,
  _PlayerHardware_Request__cdr_deserialize,
  _PlayerHardware_Request__get_serialized_size,
  _PlayerHardware_Request__max_serialized_size
};

static rosidl_message_type_support_t _PlayerHardware_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PlayerHardware_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, PlayerHardware_Request)() {
  return &_PlayerHardware_Request__type_support;
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
// #include "player_interfaces/srv/detail/player_hardware__struct.h"
// already included above
// #include "player_interfaces/srv/detail/player_hardware__functions.h"
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


// forward declare type support functions


using _PlayerHardware_Response__ros_msg_type = player_interfaces__srv__PlayerHardware_Response;

static bool _PlayerHardware_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PlayerHardware_Response__ros_msg_type * ros_message = static_cast<const _PlayerHardware_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

static bool _PlayerHardware_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PlayerHardware_Response__ros_msg_type * ros_message = static_cast<_PlayerHardware_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_player_interfaces
size_t get_serialized_size_player_interfaces__srv__PlayerHardware_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PlayerHardware_Response__ros_msg_type * ros_message = static_cast<const _PlayerHardware_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PlayerHardware_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_player_interfaces__srv__PlayerHardware_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_player_interfaces
size_t max_serialized_size_player_interfaces__srv__PlayerHardware_Response(
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

  // member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _PlayerHardware_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_player_interfaces__srv__PlayerHardware_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PlayerHardware_Response = {
  "player_interfaces::srv",
  "PlayerHardware_Response",
  _PlayerHardware_Response__cdr_serialize,
  _PlayerHardware_Response__cdr_deserialize,
  _PlayerHardware_Response__get_serialized_size,
  _PlayerHardware_Response__max_serialized_size
};

static rosidl_message_type_support_t _PlayerHardware_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PlayerHardware_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, PlayerHardware_Response)() {
  return &_PlayerHardware_Response__type_support;
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
#include "player_interfaces/srv/player_hardware.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t PlayerHardware__callbacks = {
  "player_interfaces::srv",
  "PlayerHardware",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, PlayerHardware_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, PlayerHardware_Response)(),
};

static rosidl_service_type_support_t PlayerHardware__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &PlayerHardware__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, player_interfaces, srv, PlayerHardware)() {
  return &PlayerHardware__handle;
}

#if defined(__cplusplus)
}
#endif
