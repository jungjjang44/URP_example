// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hellocm_msgs:msg/SignalLightIn.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__SIGNAL_LIGHT_IN__STRUCT_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__SIGNAL_LIGHT_IN__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__hellocm_msgs__msg__SignalLightIn __attribute__((deprecated))
#else
# define DEPRECATED__hellocm_msgs__msg__SignalLightIn __declspec(deprecated)
#endif

namespace hellocm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SignalLightIn_
{
  using Type = SignalLightIn_<ContainerAllocator>;

  explicit SignalLightIn_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->signal_light = 0;
      this->hazard = false;
    }
  }

  explicit SignalLightIn_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->signal_light = 0;
      this->hazard = false;
    }
  }

  // field types and members
  using _signal_light_type =
    int8_t;
  _signal_light_type signal_light;
  using _hazard_type =
    bool;
  _hazard_type hazard;

  // setters for named parameter idiom
  Type & set__signal_light(
    const int8_t & _arg)
  {
    this->signal_light = _arg;
    return *this;
  }
  Type & set__hazard(
    const bool & _arg)
  {
    this->hazard = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hellocm_msgs::msg::SignalLightIn_<ContainerAllocator> *;
  using ConstRawPtr =
    const hellocm_msgs::msg::SignalLightIn_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hellocm_msgs::msg::SignalLightIn_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hellocm_msgs::msg::SignalLightIn_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::SignalLightIn_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::SignalLightIn_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::SignalLightIn_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::SignalLightIn_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hellocm_msgs::msg::SignalLightIn_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hellocm_msgs::msg::SignalLightIn_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hellocm_msgs__msg__SignalLightIn
    std::shared_ptr<hellocm_msgs::msg::SignalLightIn_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hellocm_msgs__msg__SignalLightIn
    std::shared_ptr<hellocm_msgs::msg::SignalLightIn_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SignalLightIn_ & other) const
  {
    if (this->signal_light != other.signal_light) {
      return false;
    }
    if (this->hazard != other.hazard) {
      return false;
    }
    return true;
  }
  bool operator!=(const SignalLightIn_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SignalLightIn_

// alias to use template instance with default allocator
using SignalLightIn =
  hellocm_msgs::msg::SignalLightIn_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__SIGNAL_LIGHT_IN__STRUCT_HPP_
