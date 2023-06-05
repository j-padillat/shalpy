// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from player_interfaces:srv/PlayerHardware.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "player_interfaces/srv/detail/player_hardware__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace player_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void PlayerHardware_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) player_interfaces::srv::PlayerHardware_Request(_init);
}

void PlayerHardware_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<player_interfaces::srv::PlayerHardware_Request *>(message_memory);
  typed_message->~PlayerHardware_Request();
}

size_t size_function__PlayerHardware_Request__posiciones(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PlayerHardware_Request__posiciones(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  return &member[index];
}

void * get_function__PlayerHardware_Request__posiciones(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  return &member[index];
}

void fetch_function__PlayerHardware_Request__posiciones(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Twist *>(
    get_const_function__PlayerHardware_Request__posiciones(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Twist *>(untyped_value);
  value = item;
}

void assign_function__PlayerHardware_Request__posiciones(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Twist *>(
    get_function__PlayerHardware_Request__posiciones(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Twist *>(untyped_value);
  item = value;
}

void resize_function__PlayerHardware_Request__posiciones(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PlayerHardware_Request__keys(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PlayerHardware_Request__keys(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__PlayerHardware_Request__keys(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__PlayerHardware_Request__keys(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__PlayerHardware_Request__keys(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__PlayerHardware_Request__keys(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__PlayerHardware_Request__keys(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__PlayerHardware_Request__keys(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PlayerHardware_Request__times(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PlayerHardware_Request__times(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__PlayerHardware_Request__times(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__PlayerHardware_Request__times(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__PlayerHardware_Request__times(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__PlayerHardware_Request__times(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__PlayerHardware_Request__times(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__PlayerHardware_Request__times(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PlayerHardware_Request_message_member_array[4] = {
  {
    "nombre",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces::srv::PlayerHardware_Request, nombre),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "posiciones",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Twist>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces::srv::PlayerHardware_Request, posiciones),  // bytes offset in struct
    nullptr,  // default value
    size_function__PlayerHardware_Request__posiciones,  // size() function pointer
    get_const_function__PlayerHardware_Request__posiciones,  // get_const(index) function pointer
    get_function__PlayerHardware_Request__posiciones,  // get(index) function pointer
    fetch_function__PlayerHardware_Request__posiciones,  // fetch(index, &value) function pointer
    assign_function__PlayerHardware_Request__posiciones,  // assign(index, value) function pointer
    resize_function__PlayerHardware_Request__posiciones  // resize(index) function pointer
  },
  {
    "keys",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces::srv::PlayerHardware_Request, keys),  // bytes offset in struct
    nullptr,  // default value
    size_function__PlayerHardware_Request__keys,  // size() function pointer
    get_const_function__PlayerHardware_Request__keys,  // get_const(index) function pointer
    get_function__PlayerHardware_Request__keys,  // get(index) function pointer
    fetch_function__PlayerHardware_Request__keys,  // fetch(index, &value) function pointer
    assign_function__PlayerHardware_Request__keys,  // assign(index, value) function pointer
    resize_function__PlayerHardware_Request__keys  // resize(index) function pointer
  },
  {
    "times",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces::srv::PlayerHardware_Request, times),  // bytes offset in struct
    nullptr,  // default value
    size_function__PlayerHardware_Request__times,  // size() function pointer
    get_const_function__PlayerHardware_Request__times,  // get_const(index) function pointer
    get_function__PlayerHardware_Request__times,  // get(index) function pointer
    fetch_function__PlayerHardware_Request__times,  // fetch(index, &value) function pointer
    assign_function__PlayerHardware_Request__times,  // assign(index, value) function pointer
    resize_function__PlayerHardware_Request__times  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PlayerHardware_Request_message_members = {
  "player_interfaces::srv",  // message namespace
  "PlayerHardware_Request",  // message name
  4,  // number of fields
  sizeof(player_interfaces::srv::PlayerHardware_Request),
  PlayerHardware_Request_message_member_array,  // message members
  PlayerHardware_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  PlayerHardware_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PlayerHardware_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PlayerHardware_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace player_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<player_interfaces::srv::PlayerHardware_Request>()
{
  return &::player_interfaces::srv::rosidl_typesupport_introspection_cpp::PlayerHardware_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, player_interfaces, srv, PlayerHardware_Request)() {
  return &::player_interfaces::srv::rosidl_typesupport_introspection_cpp::PlayerHardware_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "player_interfaces/srv/detail/player_hardware__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace player_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void PlayerHardware_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) player_interfaces::srv::PlayerHardware_Response(_init);
}

void PlayerHardware_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<player_interfaces::srv::PlayerHardware_Response *>(message_memory);
  typed_message->~PlayerHardware_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PlayerHardware_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(player_interfaces::srv::PlayerHardware_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PlayerHardware_Response_message_members = {
  "player_interfaces::srv",  // message namespace
  "PlayerHardware_Response",  // message name
  1,  // number of fields
  sizeof(player_interfaces::srv::PlayerHardware_Response),
  PlayerHardware_Response_message_member_array,  // message members
  PlayerHardware_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  PlayerHardware_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PlayerHardware_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PlayerHardware_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace player_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<player_interfaces::srv::PlayerHardware_Response>()
{
  return &::player_interfaces::srv::rosidl_typesupport_introspection_cpp::PlayerHardware_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, player_interfaces, srv, PlayerHardware_Response)() {
  return &::player_interfaces::srv::rosidl_typesupport_introspection_cpp::PlayerHardware_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "player_interfaces/srv/detail/player_hardware__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace player_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers PlayerHardware_service_members = {
  "player_interfaces::srv",  // service namespace
  "PlayerHardware",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<player_interfaces::srv::PlayerHardware>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t PlayerHardware_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PlayerHardware_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace player_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<player_interfaces::srv::PlayerHardware>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::player_interfaces::srv::rosidl_typesupport_introspection_cpp::PlayerHardware_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::player_interfaces::srv::PlayerHardware_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::player_interfaces::srv::PlayerHardware_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, player_interfaces, srv, PlayerHardware)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<player_interfaces::srv::PlayerHardware>();
}

#ifdef __cplusplus
}
#endif
