// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from proyecto_interfaces:srv/StartPerceptionTest.idl
// generated code does not contain a copyright notice

#ifndef PROYECTO_INTERFACES__SRV__DETAIL__START_PERCEPTION_TEST__BUILDER_HPP_
#define PROYECTO_INTERFACES__SRV__DETAIL__START_PERCEPTION_TEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "proyecto_interfaces/srv/detail/start_perception_test__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace proyecto_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartPerceptionTest_Request_banner_b
{
public:
  explicit Init_StartPerceptionTest_Request_banner_b(::proyecto_interfaces::srv::StartPerceptionTest_Request & msg)
  : msg_(msg)
  {}
  ::proyecto_interfaces::srv::StartPerceptionTest_Request banner_b(::proyecto_interfaces::srv::StartPerceptionTest_Request::_banner_b_type arg)
  {
    msg_.banner_b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proyecto_interfaces::srv::StartPerceptionTest_Request msg_;
};

class Init_StartPerceptionTest_Request_banner_a
{
public:
  Init_StartPerceptionTest_Request_banner_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartPerceptionTest_Request_banner_b banner_a(::proyecto_interfaces::srv::StartPerceptionTest_Request::_banner_a_type arg)
  {
    msg_.banner_a = std::move(arg);
    return Init_StartPerceptionTest_Request_banner_b(msg_);
  }

private:
  ::proyecto_interfaces::srv::StartPerceptionTest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::proyecto_interfaces::srv::StartPerceptionTest_Request>()
{
  return proyecto_interfaces::srv::builder::Init_StartPerceptionTest_Request_banner_a();
}

}  // namespace proyecto_interfaces


namespace proyecto_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartPerceptionTest_Response_answer
{
public:
  Init_StartPerceptionTest_Response_answer()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::proyecto_interfaces::srv::StartPerceptionTest_Response answer(::proyecto_interfaces::srv::StartPerceptionTest_Response::_answer_type arg)
  {
    msg_.answer = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proyecto_interfaces::srv::StartPerceptionTest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::proyecto_interfaces::srv::StartPerceptionTest_Response>()
{
  return proyecto_interfaces::srv::builder::Init_StartPerceptionTest_Response_answer();
}

}  // namespace proyecto_interfaces

#endif  // PROYECTO_INTERFACES__SRV__DETAIL__START_PERCEPTION_TEST__BUILDER_HPP_
