// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hellocm_msgs:msg/ObjectInfoOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__STRUCT_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__STRUCT_HPP_

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
# define DEPRECATED__hellocm_msgs__msg__ObjectInfoOut __attribute__((deprecated))
#else
# define DEPRECATED__hellocm_msgs__msg__ObjectInfoOut __declspec(deprecated)
#endif

namespace hellocm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectInfoOut_
{
  using Type = ObjectInfoOut_<ContainerAllocator>;

  explicit ObjectInfoOut_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycleno = 0ll;
      this->synthdelay = 0.0;
      this->num = 0;
      std::fill<typename std::array<double, 50>::iterator, double>(this->id.begin(), this->id.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->x.begin(), this->x.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->y.begin(), this->y.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->w.begin(), this->w.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->h.begin(), this->h.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->vx.begin(), this->vx.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->vy.begin(), this->vy.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->alpha.begin(), this->alpha.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->global_vx.begin(), this->global_vx.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->global_vy.begin(), this->global_vy.end(), 0.0);
    }
  }

  explicit ObjectInfoOut_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    time(_alloc, _init),
    id(_alloc),
    x(_alloc),
    y(_alloc),
    w(_alloc),
    h(_alloc),
    vx(_alloc),
    vy(_alloc),
    alpha(_alloc),
    global_vx(_alloc),
    global_vy(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycleno = 0ll;
      this->synthdelay = 0.0;
      this->num = 0;
      std::fill<typename std::array<double, 50>::iterator, double>(this->id.begin(), this->id.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->x.begin(), this->x.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->y.begin(), this->y.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->w.begin(), this->w.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->h.begin(), this->h.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->vx.begin(), this->vx.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->vy.begin(), this->vy.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->alpha.begin(), this->alpha.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->global_vx.begin(), this->global_vx.end(), 0.0);
      std::fill<typename std::array<double, 50>::iterator, double>(this->global_vy.begin(), this->global_vy.end(), 0.0);
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
  using _num_type =
    int16_t;
  _num_type num;
  using _id_type =
    std::array<double, 50>;
  _id_type id;
  using _x_type =
    std::array<double, 50>;
  _x_type x;
  using _y_type =
    std::array<double, 50>;
  _y_type y;
  using _w_type =
    std::array<double, 50>;
  _w_type w;
  using _h_type =
    std::array<double, 50>;
  _h_type h;
  using _vx_type =
    std::array<double, 50>;
  _vx_type vx;
  using _vy_type =
    std::array<double, 50>;
  _vy_type vy;
  using _alpha_type =
    std::array<double, 50>;
  _alpha_type alpha;
  using _global_vx_type =
    std::array<double, 50>;
  _global_vx_type global_vx;
  using _global_vy_type =
    std::array<double, 50>;
  _global_vy_type global_vy;

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
  Type & set__num(
    const int16_t & _arg)
  {
    this->num = _arg;
    return *this;
  }
  Type & set__id(
    const std::array<double, 50> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__x(
    const std::array<double, 50> & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const std::array<double, 50> & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__w(
    const std::array<double, 50> & _arg)
  {
    this->w = _arg;
    return *this;
  }
  Type & set__h(
    const std::array<double, 50> & _arg)
  {
    this->h = _arg;
    return *this;
  }
  Type & set__vx(
    const std::array<double, 50> & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const std::array<double, 50> & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__alpha(
    const std::array<double, 50> & _arg)
  {
    this->alpha = _arg;
    return *this;
  }
  Type & set__global_vx(
    const std::array<double, 50> & _arg)
  {
    this->global_vx = _arg;
    return *this;
  }
  Type & set__global_vy(
    const std::array<double, 50> & _arg)
  {
    this->global_vy = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator> *;
  using ConstRawPtr =
    const hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hellocm_msgs__msg__ObjectInfoOut
    std::shared_ptr<hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hellocm_msgs__msg__ObjectInfoOut
    std::shared_ptr<hellocm_msgs::msg::ObjectInfoOut_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectInfoOut_ & other) const
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
    if (this->num != other.num) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->w != other.w) {
      return false;
    }
    if (this->h != other.h) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->alpha != other.alpha) {
      return false;
    }
    if (this->global_vx != other.global_vx) {
      return false;
    }
    if (this->global_vy != other.global_vy) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectInfoOut_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectInfoOut_

// alias to use template instance with default allocator
using ObjectInfoOut =
  hellocm_msgs::msg::ObjectInfoOut_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__STRUCT_HPP_
