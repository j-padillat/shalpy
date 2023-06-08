// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from proyecto_interfaces:srv/StartNavigationTest.idl
// generated code does not contain a copyright notice

#ifndef PROYECTO_INTERFACES__SRV__DETAIL__START_NAVIGATION_TEST__BUILDER_HPP_
#define PROYECTO_INTERFACES__SRV__DETAIL__START_NAVIGATION_TEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "proyecto_interfaces/srv/detail/start_navigation_test__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace proyecto_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartNavigationTest_Request_y
{
public:
  explicit Init_StartNavigationTest_Request_y(::proyecto_interfaces::srv::StartNavigationTest_Request & msg)
  : msg_(msg)
  {}
  ::proyecto_interfaces::srv::StartNavigationTest_Request y(::proyecto_interfaces::srv::StartNavigationTest_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proyecto_interfaces::srv::StartNavigationTest_Request msg_;
};

class Init_StartNavigationTest_Request_x
{
public:
  Init_StartNavigationTest_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartNavigationTest_Request_y x(::proyecto_interfaces::srv::StartNavigationTest_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_StartNavigationTest_Request_y(msg_);
  }

private:
  ::proyecto_interfaces::srv::StartNavigationTest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::proyecto_interfaces::srv::StartNavigationTest_Request>()
{
  return proyecto_interfaces::srv::builder::Init_StartNavigationTest_Request_x();
}

}  // namespace proyecto_interfaces


namespace proyecto_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartNavigationTest_Response_answer
{
public:
  Init_StartNavigationTest_Response_answer()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::proyecto_interfaces::srv::StartNavigationTest_Response answer(::proyecto_interfaces::srv::StartNavigationTest_Response::_answer_type arg)
  {
    msg_.answer = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proyecto_interfaces::srv::StartNavigationTest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::proyecto_interfaces::srv::StartNavigationTest_Response>()
{
  return proyecto_interfaces::srv::builder::Init_StartNavigationTest_Response_answer();
}

}  // namespace proyecto_interfaces

#endif  // PROYECTO_INTERFACES__SRV__DETAIL__START_NAVIGATION_TEST__BUILDER_HPP_
