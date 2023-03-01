// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from player_interfaces:srv/Player.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__SRV__DETAIL__PLAYER__BUILDER_HPP_
#define PLAYER_INTERFACES__SRV__DETAIL__PLAYER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "player_interfaces/srv/detail/player__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace player_interfaces
{

namespace srv
{

namespace builder
{

class Init_Player_Request_posiciones
{
public:
  explicit Init_Player_Request_posiciones(::player_interfaces::srv::Player_Request & msg)
  : msg_(msg)
  {}
  ::player_interfaces::srv::Player_Request posiciones(::player_interfaces::srv::Player_Request::_posiciones_type arg)
  {
    msg_.posiciones = std::move(arg);
    return std::move(msg_);
  }

private:
  ::player_interfaces::srv::Player_Request msg_;
};

class Init_Player_Request_nombre
{
public:
  Init_Player_Request_nombre()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Player_Request_posiciones nombre(::player_interfaces::srv::Player_Request::_nombre_type arg)
  {
    msg_.nombre = std::move(arg);
    return Init_Player_Request_posiciones(msg_);
  }

private:
  ::player_interfaces::srv::Player_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::player_interfaces::srv::Player_Request>()
{
  return player_interfaces::srv::builder::Init_Player_Request_nombre();
}

}  // namespace player_interfaces


namespace player_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::player_interfaces::srv::Player_Response>()
{
  return ::player_interfaces::srv::Player_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace player_interfaces

#endif  // PLAYER_INTERFACES__SRV__DETAIL__PLAYER__BUILDER_HPP_
