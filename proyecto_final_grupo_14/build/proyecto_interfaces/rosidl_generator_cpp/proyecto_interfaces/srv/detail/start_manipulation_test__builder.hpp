// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from proyecto_interfaces:srv/StartManipulationTest.idl
// generated code does not contain a copyright notice

#ifndef PROYECTO_INTERFACES__SRV__DETAIL__START_MANIPULATION_TEST__BUILDER_HPP_
#define PROYECTO_INTERFACES__SRV__DETAIL__START_MANIPULATION_TEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "proyecto_interfaces/srv/detail/start_manipulation_test__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace proyecto_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartManipulationTest_Request_x
{
public:
  explicit Init_StartManipulationTest_Request_x(::proyecto_interfaces::srv::StartManipulationTest_Request & msg)
  : msg_(msg)
  {}
  ::proyecto_interfaces::srv::StartManipulationTest_Request x(::proyecto_interfaces::srv::StartManipulationTest_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proyecto_interfaces::srv::StartManipulationTest_Request msg_;
};

class Init_StartManipulationTest_Request_platform
{
public:
  Init_StartManipulationTest_Request_platform()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartManipulationTest_Request_x platform(::proyecto_interfaces::srv::StartManipulationTest_Request::_platform_type arg)
  {
    msg_.platform = std::move(arg);
    return Init_StartManipulationTest_Request_x(msg_);
  }

private:
  ::proyecto_interfaces::srv::StartManipulationTest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::proyecto_interfaces::srv::StartManipulationTest_Request>()
{
  return proyecto_interfaces::srv::builder::Init_StartManipulationTest_Request_platform();
}

}  // namespace proyecto_interfaces


namespace proyecto_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartManipulationTest_Response_answer
{
public:
  Init_StartManipulationTest_Response_answer()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::proyecto_interfaces::srv::StartManipulationTest_Response answer(::proyecto_interfaces::srv::StartManipulationTest_Response::_answer_type arg)
  {
    msg_.answer = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proyecto_interfaces::srv::StartManipulationTest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::proyecto_interfaces::srv::StartManipulationTest_Response>()
{
  return proyecto_interfaces::srv::builder::Init_StartManipulationTest_Response_answer();
}

}  // namespace proyecto_interfaces

#endif  // PROYECTO_INTERFACES__SRV__DETAIL__START_MANIPULATION_TEST__BUILDER_HPP_
