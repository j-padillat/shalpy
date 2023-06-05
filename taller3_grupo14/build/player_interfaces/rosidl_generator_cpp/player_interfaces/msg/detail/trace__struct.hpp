// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from player_interfaces:msg/Trace.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__MSG__DETAIL__TRACE__STRUCT_HPP_
#define PLAYER_INTERFACES__MSG__DETAIL__TRACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__player_interfaces__msg__Trace __attribute__((deprecated))
#else
# define DEPRECATED__player_interfaces__msg__Trace __declspec(deprecated)
#endif

namespace player_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Trace_
{
  using Type = Trace_<ContainerAllocator>;

  explicit Trace_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->x = 0.0;
      this->y = 0.0;
      this->th = 0.0;
      this->time = 0.0;
    }
  }

  explicit Trace_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : key(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->x = 0.0;
      this->y = 0.0;
      this->th = 0.0;
      this->time = 0.0;
    }
  }

  // field types and members
  using _key_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _key_type key;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _th_type =
    double;
  _th_type th;
  using _time_type =
    double;
  _time_type time;

  // setters for named parameter idiom
  Type & set__key(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->key = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__th(
    const double & _arg)
  {
    this->th = _arg;
    return *this;
  }
  Type & set__time(
    const double & _arg)
  {
    this->time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    player_interfaces::msg::Trace_<ContainerAllocator> *;
  using ConstRawPtr =
    const player_interfaces::msg::Trace_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<player_interfaces::msg::Trace_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<player_interfaces::msg::Trace_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      player_interfaces::msg::Trace_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::msg::Trace_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      player_interfaces::msg::Trace_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::msg::Trace_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<player_interfaces::msg::Trace_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<player_interfaces::msg::Trace_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__player_interfaces__msg__Trace
    std::shared_ptr<player_interfaces::msg::Trace_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__player_interfaces__msg__Trace
    std::shared_ptr<player_interfaces::msg::Trace_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Trace_ & other) const
  {
    if (this->key != other.key) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->th != other.th) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    return true;
  }
  bool operator!=(const Trace_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Trace_

// alias to use template instance with default allocator
using Trace =
  player_interfaces::msg::Trace_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace player_interfaces

#endif  // PLAYER_INTERFACES__MSG__DETAIL__TRACE__STRUCT_HPP_
