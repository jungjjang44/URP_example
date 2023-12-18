// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/VehicleControlIn.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__VEHICLE_CONTROL_IN__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__VEHICLE_CONTROL_IN__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/vehicle_control_in__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleControlIn_gear_no
{
public:
  explicit Init_VehicleControlIn_gear_no(::hellocm_msgs::msg::VehicleControlIn & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::VehicleControlIn gear_no(::hellocm_msgs::msg::VehicleControlIn::_gear_no_type arg)
  {
    msg_.gear_no = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleControlIn msg_;
};

class Init_VehicleControlIn_steer_ang
{
public:
  explicit Init_VehicleControlIn_steer_ang(::hellocm_msgs::msg::VehicleControlIn & msg)
  : msg_(msg)
  {}
  Init_VehicleControlIn_gear_no steer_ang(::hellocm_msgs::msg::VehicleControlIn::_steer_ang_type arg)
  {
    msg_.steer_ang = std::move(arg);
    return Init_VehicleControlIn_gear_no(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleControlIn msg_;
};

class Init_VehicleControlIn_ax
{
public:
  explicit Init_VehicleControlIn_ax(::hellocm_msgs::msg::VehicleControlIn & msg)
  : msg_(msg)
  {}
  Init_VehicleControlIn_steer_ang ax(::hellocm_msgs::msg::VehicleControlIn::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_VehicleControlIn_steer_ang(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleControlIn msg_;
};

class Init_VehicleControlIn_sw
{
public:
  explicit Init_VehicleControlIn_sw(::hellocm_msgs::msg::VehicleControlIn & msg)
  : msg_(msg)
  {}
  Init_VehicleControlIn_ax sw(::hellocm_msgs::msg::VehicleControlIn::_sw_type arg)
  {
    msg_.sw = std::move(arg);
    return Init_VehicleControlIn_ax(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleControlIn msg_;
};

class Init_VehicleControlIn_time
{
public:
  explicit Init_VehicleControlIn_time(::hellocm_msgs::msg::VehicleControlIn & msg)
  : msg_(msg)
  {}
  Init_VehicleControlIn_sw time(::hellocm_msgs::msg::VehicleControlIn::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_VehicleControlIn_sw(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleControlIn msg_;
};

class Init_VehicleControlIn_header
{
public:
  Init_VehicleControlIn_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleControlIn_time header(::hellocm_msgs::msg::VehicleControlIn::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleControlIn_time(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleControlIn msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::VehicleControlIn>()
{
  return hellocm_msgs::msg::builder::Init_VehicleControlIn_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__VEHICLE_CONTROL_IN__BUILDER_HPP_
