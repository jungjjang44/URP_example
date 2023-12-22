// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hellocm_msgs:msg/SpeedLimit.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__SPEED_LIMIT__STRUCT_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__SPEED_LIMIT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'time'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hellocm_msgs__msg__SpeedLimit __attribute__((deprecated))
#else
# define DEPRECATED__hellocm_msgs__msg__SpeedLimit __declspec(deprecated)
#endif

namespace hellocm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SpeedLimit_
{
  using Type = SpeedLimit_<ContainerAllocator>;

  explicit SpeedLimit_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycleno = 0ll;
      this->synthdelay = 0.0;
      this->distance = 0.0;
      this->speed_limit = 0.0;
    }
  }

  explicit SpeedLimit_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    time(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycleno = 0ll;
      this->synthdelay = 0.0;
      this->distance = 0.0;
      this->speed_limit = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _time_type time;
  using _cycleno_type =
    int64_t;
  _cycleno_type cycleno;
  using _synthdelay_type =
    double;
  _synthdelay_type synthdelay;
  using _distance_type =
    double;
  _distance_type distance;
  using _speed_limit_type =
    double;
  _speed_limit_type speed_limit;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__cycleno(
    const int64_t & _arg)
  {
    this->cycleno = _arg;
    return *this;
  }
  Type & set__synthdelay(
    const double & _arg)
  {
    this->synthdelay = _arg;
    return *this;
  }
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__speed_limit(
    const double & _arg)
  {
    this->speed_limit = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hellocm_msgs::msg::SpeedLimit_<ContainerAllocator> *;
  using ConstRawPtr =
    const hellocm_msgs::msg::SpeedLimit_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hellocm_msgs::msg::SpeedLimit_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hellocm_msgs::msg::SpeedLimit_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::SpeedLimit_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::SpeedLimit_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::SpeedLimit_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::SpeedLimit_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hellocm_msgs::msg::SpeedLimit_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hellocm_msgs::msg::SpeedLimit_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hellocm_msgs__msg__SpeedLimit
    std::shared_ptr<hellocm_msgs::msg::SpeedLimit_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hellocm_msgs__msg__SpeedLimit
    std::shared_ptr<hellocm_msgs::msg::SpeedLimit_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SpeedLimit_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    if (this->cycleno != other.cycleno) {
      return false;
    }
    if (this->synthdelay != other.synthdelay) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->speed_limit != other.speed_limit) {
      return false;
    }
    return true;
  }
  bool operator!=(const SpeedLimit_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SpeedLimit_

// alias to use template instance with default allocator
using SpeedLimit =
  hellocm_msgs::msg::SpeedLimit_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__SPEED_LIMIT__STRUCT_HPP_
