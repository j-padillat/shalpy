// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from proyecto_interfaces:msg/Banner.idl
// generated code does not contain a copyright notice

#ifndef PROYECTO_INTERFACES__MSG__DETAIL__BANNER__BUILDER_HPP_
#define PROYECTO_INTERFACES__MSG__DETAIL__BANNER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "proyecto_interfaces/msg/detail/banner__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace proyecto_interfaces
{

namespace msg
{

namespace builder
{

class Init_Banner_color
{
public:
  explicit Init_Banner_color(::proyecto_interfaces::msg::Banner & msg)
  : msg_(msg)
  {}
  ::proyecto_interfaces::msg::Banner color(::proyecto_interfaces::msg::Banner::_color_type arg)
  {
    msg_.color = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proyecto_interfaces::msg::Banner msg_;
};

class Init_Banner_word
{
public:
  explicit Init_Banner_word(::proyecto_interfaces::msg::Banner & msg)
  : msg_(msg)
  {}
  Init_Banner_color word(::proyecto_interfaces::msg::Banner::_word_type arg)
  {
    msg_.word = std::move(arg);
    return Init_Banner_color(msg_);
  }

private:
  ::proyecto_interfaces::msg::Banner msg_;
};

class Init_Banner_figure
{
public:
  explicit Init_Banner_figure(::proyecto_interfaces::msg::Banner & msg)
  : msg_(msg)
  {}
  Init_Banner_word figure(::proyecto_interfaces::msg::Banner::_figure_type arg)
  {
    msg_.figure = std::move(arg);
    return Init_Banner_word(msg_);
  }

private:
  ::proyecto_interfaces::msg::Banner msg_;
};

class Init_Banner_banner
{
public:
  Init_Banner_banner()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Banner_figure banner(::proyecto_interfaces::msg::Banner::_banner_type arg)
  {
    msg_.banner = std::move(arg);
    return Init_Banner_figure(msg_);
  }

private:
  ::proyecto_interfaces::msg::Banner msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::proyecto_interfaces::msg::Banner>()
{
  return proyecto_interfaces::msg::builder::Init_Banner_banner();
}

}  // namespace proyecto_interfaces

#endif  // PROYECTO_INTERFACES__MSG__DETAIL__BANNER__BUILDER_HPP_
