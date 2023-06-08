// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from example_interfaces:srv/Comimagen.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__BUILDER_HPP_
#define EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "example_interfaces/srv/detail/comimagen__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace example_interfaces
{

namespace srv
{

namespace builder
{

class Init_Comimagen_Request_banner
{
public:
  explicit Init_Comimagen_Request_banner(::example_interfaces::srv::Comimagen_Request & msg)
  : msg_(msg)
  {}
  ::example_interfaces::srv::Comimagen_Request banner(::example_interfaces::srv::Comimagen_Request::_banner_type arg)
  {
    msg_.banner = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_interfaces::srv::Comimagen_Request msg_;
};

class Init_Comimagen_Request_imagen
{
public:
  Init_Comimagen_Request_imagen()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Comimagen_Request_banner imagen(::example_interfaces::srv::Comimagen_Request::_imagen_type arg)
  {
    msg_.imagen = std::move(arg);
    return Init_Comimagen_Request_banner(msg_);
  }

private:
  ::example_interfaces::srv::Comimagen_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_interfaces::srv::Comimagen_Request>()
{
  return example_interfaces::srv::builder::Init_Comimagen_Request_imagen();
}

}  // namespace example_interfaces


namespace example_interfaces
{

namespace srv
{

namespace builder
{

class Init_Comimagen_Response_finalizo
{
public:
  Init_Comimagen_Response_finalizo()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::example_interfaces::srv::Comimagen_Response finalizo(::example_interfaces::srv::Comimagen_Response::_finalizo_type arg)
  {
    msg_.finalizo = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_interfaces::srv::Comimagen_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_interfaces::srv::Comimagen_Response>()
{
  return example_interfaces::srv::builder::Init_Comimagen_Response_finalizo();
}

}  // namespace example_interfaces

#endif  // EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__BUILDER_HPP_
