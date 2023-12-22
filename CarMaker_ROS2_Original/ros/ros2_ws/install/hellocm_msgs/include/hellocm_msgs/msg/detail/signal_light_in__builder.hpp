// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/SignalLightIn.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__SIGNAL_LIGHT_IN__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__SIGNAL_LIGHT_IN__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/signal_light_in__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_SignalLightIn_hazard
{
public:
  explicit Init_SignalLightIn_hazard(::hellocm_msgs::msg::SignalLightIn & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::SignalLightIn hazard(::hellocm_msgs::msg::SignalLightIn::_hazard_type arg)
  {
    msg_.hazard = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::SignalLightIn msg_;
};

class Init_SignalLightIn_signal_light
{
public:
  Init_SignalLightIn_signal_light()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SignalLightIn_hazard signal_light(::hellocm_msgs::msg::SignalLightIn::_signal_light_type arg)
  {
    msg_.signal_light = std::move(arg);
    return Init_SignalLightIn_hazard(msg_);
  }

private:
  ::hellocm_msgs::msg::SignalLightIn msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::SignalLightIn>()
{
  return hellocm_msgs::msg::builder::Init_SignalLightIn_signal_light();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__SIGNAL_LIGHT_IN__BUILDER_HPP_
