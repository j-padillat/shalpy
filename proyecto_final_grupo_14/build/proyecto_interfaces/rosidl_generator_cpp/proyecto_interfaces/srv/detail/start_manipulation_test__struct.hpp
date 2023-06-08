// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from proyecto_interfaces:srv/StartManipulationTest.idl
// generated code does not contain a copyright notice

#ifndef PROYECTO_INTERFACES__SRV__DETAIL__START_MANIPULATION_TEST__STRUCT_HPP_
#define PROYECTO_INTERFACES__SRV__DETAIL__START_MANIPULATION_TEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__proyecto_interfaces__srv__StartManipulationTest_Request __attribute__((deprecated))
#else
# define DEPRECATED__proyecto_interfaces__srv__StartManipulationTest_Request __declspec(deprecated)
#endif

namespace proyecto_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartManipulationTest_Request_
{
  using Type = StartManipulationTest_Request_<ContainerAllocator>;

  explicit StartManipulationTest_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->platform = "";
      this->x = 0l;
    }
  }

  explicit StartManipulationTest_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : platform(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->platform = "";
      this->x = 0l;
    }
  }

  // field types and members
  using _platform_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _platform_type platform;
  using _x_type =
    int32_t;
  _x_type x;

  // setters for named parameter idiom
  Type & set__platform(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->platform = _arg;
    return *this;
  }
  Type & set__x(
    const int32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__proyecto_interfaces__srv__StartManipulationTest_Request
    std::shared_ptr<proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__proyecto_interfaces__srv__StartManipulationTest_Request
    std::shared_ptr<proyecto_interfaces::srv::StartManipulationTest_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartManipulationTest_Request_ & other) const
  {
    if (this->platform != other.platform) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartManipulationTest_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartManipulationTest_Request_

// alias to use template instance with default allocator
using StartManipulationTest_Request =
  proyecto_interfaces::srv::StartManipulationTest_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace proyecto_interfaces


#ifndef _WIN32
# define DEPRECATED__proyecto_interfaces__srv__StartManipulationTest_Response __attribute__((deprecated))
#else
# define DEPRECATED__proyecto_interfaces__srv__StartManipulationTest_Response __declspec(deprecated)
#endif

namespace proyecto_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartManipulationTest_Response_
{
  using Type = StartManipulationTest_Response_<ContainerAllocator>;

  explicit StartManipulationTest_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->answer = "";
    }
  }

  explicit StartManipulationTest_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : answer(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->answer = "";
    }
  }

  // field types and members
  using _answer_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _answer_type answer;

  // setters for named parameter idiom
  Type & set__answer(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->answer = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__proyecto_interfaces__srv__StartManipulationTest_Response
    std::shared_ptr<proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__proyecto_interfaces__srv__StartManipulationTest_Response
    std::shared_ptr<proyecto_interfaces::srv::StartManipulationTest_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartManipulationTest_Response_ & other) const
  {
    if (this->answer != other.answer) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartManipulationTest_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartManipulationTest_Response_

// alias to use template instance with default allocator
using StartManipulationTest_Response =
  proyecto_interfaces::srv::StartManipulationTest_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace proyecto_interfaces

namespace proyecto_interfaces
{

namespace srv
{

struct StartManipulationTest
{
  using Request = proyecto_interfaces::srv::StartManipulationTest_Request;
  using Response = proyecto_interfaces::srv::StartManipulationTest_Response;
};

}  // namespace srv

}  // namespace proyecto_interfaces

#endif  // PROYECTO_INTERFACES__SRV__DETAIL__START_MANIPULATION_TEST__STRUCT_HPP_
