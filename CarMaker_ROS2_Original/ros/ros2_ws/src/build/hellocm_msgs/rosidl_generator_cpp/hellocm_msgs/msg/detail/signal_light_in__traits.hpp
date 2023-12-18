// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:msg/SignalLightIn.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__SIGNAL_LIGHT_IN__TRAITS_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__SIGNAL_LIGHT_IN__TRAITS_HPP_

#include "hellocm_msgs/msg/detail/signal_light_in__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const hellocm_msgs::msg::SignalLightIn & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: signal_light
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "signal_light: ";
    value_to_yaml(msg.signal_light, out);
    out << "\n";
  }

  // member: hazard
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hazard: ";
    value_to_yaml(msg.hazard, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const hellocm_msgs::msg::SignalLightIn & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<hellocm_msgs::msg::SignalLightIn>()
{
  return "hellocm_msgs::msg::SignalLightIn";
}

template<>
inline const char * name<hellocm_msgs::msg::SignalLightIn>()
{
  return "hellocm_msgs/msg/SignalLightIn";
}

template<>
struct has_fixed_size<hellocm_msgs::msg::SignalLightIn>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hellocm_msgs::msg::SignalLightIn>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hellocm_msgs::msg::SignalLightIn>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__MSG__DETAIL__SIGNAL_LIGHT_IN__TRAITS_HPP_
