// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from player_interfaces:msg/Trace.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__MSG__DETAIL__TRACE__BUILDER_HPP_
#define PLAYER_INTERFACES__MSG__DETAIL__TRACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "player_interfaces/msg/detail/trace__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace player_interfaces
{

namespace msg
{

namespace builder
{

class Init_Trace_time
{
public:
  explicit Init_Trace_time(::player_interfaces::msg::Trace & msg)
  : msg_(msg)
  {}
  ::player_interfaces::msg::Trace time(::player_interfaces::msg::Trace::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::player_interfaces::msg::Trace msg_;
};

class Init_Trace_th
{
public:
  explicit Init_Trace_th(::player_interfaces::msg::Trace & msg)
  : msg_(msg)
  {}
  Init_Trace_time th(::player_interfaces::msg::Trace::_th_type arg)
  {
    msg_.th = std::move(arg);
    return Init_Trace_time(msg_);
  }

private:
  ::player_interfaces::msg::Trace msg_;
};

class Init_Trace_y
{
public:
  explicit Init_Trace_y(::player_interfaces::msg::Trace & msg)
  : msg_(msg)
  {}
  Init_Trace_th y(::player_interfaces::msg::Trace::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Trace_th(msg_);
  }

private:
  ::player_interfaces::msg::Trace msg_;
};

class Init_Trace_x
{
public:
  explicit Init_Trace_x(::player_interfaces::msg::Trace & msg)
  : msg_(msg)
  {}
  Init_Trace_y x(::player_interfaces::msg::Trace::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Trace_y(msg_);
  }

private:
  ::player_interfaces::msg::Trace msg_;
};

class Init_Trace_key
{
public:
  Init_Trace_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trace_x key(::player_interfaces::msg::Trace::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_Trace_x(msg_);
  }

private:
  ::player_interfaces::msg::Trace msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::player_interfaces::msg::Trace>()
{
  return player_interfaces::msg::builder::Init_Trace_key();
}

}  // namespace player_interfaces

#endif  // PLAYER_INTERFACES__MSG__DETAIL__TRACE__BUILDER_HPP_
