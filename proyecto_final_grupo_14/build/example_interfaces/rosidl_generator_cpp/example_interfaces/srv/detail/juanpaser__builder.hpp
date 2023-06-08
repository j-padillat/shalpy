// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from example_interfaces:srv/Juanpaser.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__SRV__DETAIL__JUANPASER__BUILDER_HPP_
#define EXAMPLE_INTERFACES__SRV__DETAIL__JUANPASER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "example_interfaces/srv/detail/juanpaser__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace example_interfaces
{

namespace srv
{

namespace builder
{

class Init_Juanpaser_Request_empieza
{
public:
  explicit Init_Juanpaser_Request_empieza(::example_interfaces::srv::Juanpaser_Request & msg)
  : msg_(msg)
  {}
  ::example_interfaces::srv::Juanpaser_Request empieza(::example_interfaces::srv::Juanpaser_Request::_empieza_type arg)
  {
    msg_.empieza = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_interfaces::srv::Juanpaser_Request msg_;
};

class Init_Juanpaser_Request_banner
{
public:
  Init_Juanpaser_Request_banner()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Juanpaser_Request_empieza banner(::example_interfaces::srv::Juanpaser_Request::_banner_type arg)
  {
    msg_.banner = std::move(arg);
    return Init_Juanpaser_Request_empieza(msg_);
  }

private:
  ::example_interfaces::srv::Juanpaser_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_interfaces::srv::Juanpaser_Request>()
{
  return example_interfaces::srv::builder::Init_Juanpaser_Request_banner();
}

}  // namespace example_interfaces


namespace example_interfaces
{

namespace srv
{

namespace builder
{

class Init_Juanpaser_Response_termina
{
public:
  Init_Juanpaser_Response_termina()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::example_interfaces::srv::Juanpaser_Response termina(::example_interfaces::srv::Juanpaser_Response::_termina_type arg)
  {
    msg_.termina = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_interfaces::srv::Juanpaser_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_interfaces::srv::Juanpaser_Response>()
{
  return example_interfaces::srv::builder::Init_Juanpaser_Response_termina();
}

}  // namespace example_interfaces

#endif  // EXAMPLE_INTERFACES__SRV__DETAIL__JUANPASER__BUILDER_HPP_
