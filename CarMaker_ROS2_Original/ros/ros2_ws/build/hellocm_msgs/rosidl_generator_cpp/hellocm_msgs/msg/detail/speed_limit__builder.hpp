// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/SpeedLimit.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__SPEED_LIMIT__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__SPEED_LIMIT__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/speed_limit__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_SpeedLimit_speed_limit
{
public:
  explicit Init_SpeedLimit_speed_limit(::hellocm_msgs::msg::SpeedLimit & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::SpeedLimit speed_limit(::hellocm_msgs::msg::SpeedLimit::_speed_limit_type arg)
  {
    msg_.speed_limit = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::SpeedLimit msg_;
};

class Init_SpeedLimit_distance
{
public:
  explicit Init_SpeedLimit_distance(::hellocm_msgs::msg::SpeedLimit & msg)
  : msg_(msg)
  {}
  Init_SpeedLimit_speed_limit distance(::hellocm_msgs::msg::SpeedLimit::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_SpeedLimit_speed_limit(msg_);
  }

private:
  ::hellocm_msgs::msg::SpeedLimit msg_;
};

class Init_SpeedLimit_synthdelay
{
public:
  explicit Init_SpeedLimit_synthdelay(::hellocm_msgs::msg::SpeedLimit & msg)
  : msg_(msg)
  {}
  Init_SpeedLimit_distance synthdelay(::hellocm_msgs::msg::SpeedLimit::_synthdelay_type arg)
  {
    msg_.synthdelay = std::move(arg);
    return Init_SpeedLimit_distance(msg_);
  }

private:
  ::hellocm_msgs::msg::SpeedLimit msg_;
};

class Init_SpeedLimit_cycleno
{
public:
  explicit Init_SpeedLimit_cycleno(::hellocm_msgs::msg::SpeedLimit & msg)
  : msg_(msg)
  {}
  Init_SpeedLimit_synthdelay cycleno(::hellocm_msgs::msg::SpeedLimit::_cycleno_type arg)
  {
    msg_.cycleno = std::move(arg);
    return Init_SpeedLimit_synthdelay(msg_);
  }

private:
  ::hellocm_msgs::msg::SpeedLimit msg_;
};

class Init_SpeedLimit_time
{
public:
  explicit Init_SpeedLimit_time(::hellocm_msgs::msg::SpeedLimit & msg)
  : msg_(msg)
  {}
  Init_SpeedLimit_cycleno time(::hellocm_msgs::msg::SpeedLimit::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_SpeedLimit_cycleno(msg_);
  }

private:
  ::hellocm_msgs::msg::SpeedLimit msg_;
};

class Init_SpeedLimit_header
{
public:
  Init_SpeedLimit_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpeedLimit_time header(::hellocm_msgs::msg::SpeedLimit::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SpeedLimit_time(msg_);
  }

private:
  ::hellocm_msgs::msg::SpeedLimit msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::SpeedLimit>()
{
  return hellocm_msgs::msg::builder::Init_SpeedLimit_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__SPEED_LIMIT__BUILDER_HPP_
