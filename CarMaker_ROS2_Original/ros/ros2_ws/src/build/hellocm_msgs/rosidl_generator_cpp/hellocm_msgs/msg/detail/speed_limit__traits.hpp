// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:msg/SpeedLimit.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__SPEED_LIMIT__TRAITS_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__SPEED_LIMIT__TRAITS_HPP_

#include "hellocm_msgs/msg/detail/speed_limit__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const hellocm_msgs::msg::SpeedLimit & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_yaml(msg.header, out, indentation + 2);
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time:\n";
    to_yaml(msg.time, out, indentation + 2);
  }

  // member: cycleno
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cycleno: ";
    value_to_yaml(msg.cycleno, out);
    out << "\n";
  }

  // member: synthdelay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "synthdelay: ";
    value_to_yaml(msg.synthdelay, out);
    out << "\n";
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: speed_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_limit: ";
    value_to_yaml(msg.speed_limit, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const hellocm_msgs::msg::SpeedLimit & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<hellocm_msgs::msg::SpeedLimit>()
{
  return "hellocm_msgs::msg::SpeedLimit";
}

template<>
inline const char * name<hellocm_msgs::msg::SpeedLimit>()
{
  return "hellocm_msgs/msg/SpeedLimit";
}

template<>
struct has_fixed_size<hellocm_msgs::msg::SpeedLimit>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<hellocm_msgs::msg::SpeedLimit>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<hellocm_msgs::msg::SpeedLimit>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__MSG__DETAIL__SPEED_LIMIT__TRAITS_HPP_
