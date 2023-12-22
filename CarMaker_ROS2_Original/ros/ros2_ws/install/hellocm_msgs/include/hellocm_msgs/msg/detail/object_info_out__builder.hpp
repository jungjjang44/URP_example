// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/ObjectInfoOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/object_info_out__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_ObjectInfoOut_global_vy
{
public:
  explicit Init_ObjectInfoOut_global_vy(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::ObjectInfoOut global_vy(::hellocm_msgs::msg::ObjectInfoOut::_global_vy_type arg)
  {
    msg_.global_vy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_global_vx
{
public:
  explicit Init_ObjectInfoOut_global_vx(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_global_vy global_vx(::hellocm_msgs::msg::ObjectInfoOut::_global_vx_type arg)
  {
    msg_.global_vx = std::move(arg);
    return Init_ObjectInfoOut_global_vy(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_alpha
{
public:
  explicit Init_ObjectInfoOut_alpha(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_global_vx alpha(::hellocm_msgs::msg::ObjectInfoOut::_alpha_type arg)
  {
    msg_.alpha = std::move(arg);
    return Init_ObjectInfoOut_global_vx(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_vy
{
public:
  explicit Init_ObjectInfoOut_vy(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_alpha vy(::hellocm_msgs::msg::ObjectInfoOut::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_ObjectInfoOut_alpha(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_vx
{
public:
  explicit Init_ObjectInfoOut_vx(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_vy vx(::hellocm_msgs::msg::ObjectInfoOut::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_ObjectInfoOut_vy(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_h
{
public:
  explicit Init_ObjectInfoOut_h(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_vx h(::hellocm_msgs::msg::ObjectInfoOut::_h_type arg)
  {
    msg_.h = std::move(arg);
    return Init_ObjectInfoOut_vx(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_w
{
public:
  explicit Init_ObjectInfoOut_w(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_h w(::hellocm_msgs::msg::ObjectInfoOut::_w_type arg)
  {
    msg_.w = std::move(arg);
    return Init_ObjectInfoOut_h(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_y
{
public:
  explicit Init_ObjectInfoOut_y(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_w y(::hellocm_msgs::msg::ObjectInfoOut::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ObjectInfoOut_w(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_x
{
public:
  explicit Init_ObjectInfoOut_x(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_y x(::hellocm_msgs::msg::ObjectInfoOut::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ObjectInfoOut_y(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_id
{
public:
  explicit Init_ObjectInfoOut_id(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_x id(::hellocm_msgs::msg::ObjectInfoOut::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ObjectInfoOut_x(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_num
{
public:
  explicit Init_ObjectInfoOut_num(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_id num(::hellocm_msgs::msg::ObjectInfoOut::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_ObjectInfoOut_id(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_synthdelay
{
public:
  explicit Init_ObjectInfoOut_synthdelay(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_num synthdelay(::hellocm_msgs::msg::ObjectInfoOut::_synthdelay_type arg)
  {
    msg_.synthdelay = std::move(arg);
    return Init_ObjectInfoOut_num(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_cycleno
{
public:
  explicit Init_ObjectInfoOut_cycleno(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_synthdelay cycleno(::hellocm_msgs::msg::ObjectInfoOut::_cycleno_type arg)
  {
    msg_.cycleno = std::move(arg);
    return Init_ObjectInfoOut_synthdelay(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_time
{
public:
  explicit Init_ObjectInfoOut_time(::hellocm_msgs::msg::ObjectInfoOut & msg)
  : msg_(msg)
  {}
  Init_ObjectInfoOut_cycleno time(::hellocm_msgs::msg::ObjectInfoOut::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_ObjectInfoOut_cycleno(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

class Init_ObjectInfoOut_header
{
public:
  Init_ObjectInfoOut_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectInfoOut_time header(::hellocm_msgs::msg::ObjectInfoOut::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ObjectInfoOut_time(msg_);
  }

private:
  ::hellocm_msgs::msg::ObjectInfoOut msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::ObjectInfoOut>()
{
  return hellocm_msgs::msg::builder::Init_ObjectInfoOut_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__BUILDER_HPP_
