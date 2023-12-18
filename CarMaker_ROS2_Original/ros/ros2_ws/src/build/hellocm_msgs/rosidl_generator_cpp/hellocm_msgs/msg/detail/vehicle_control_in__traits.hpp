// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:msg/VehicleControlIn.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__VEHICLE_CONTROL_IN__TRAITS_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__VEHICLE_CONTROL_IN__TRAITS_HPP_

#include "hellocm_msgs/msg/detail/vehicle_control_in__struct.hpp"
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
  const hellocm_msgs::msg::VehicleControlIn & msg,
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

  // member: sw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sw: ";
    value_to_yaml(msg.sw, out);
    out << "\n";
  }

  // member: ax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ax: ";
    value_to_yaml(msg.ax, out);
    out << "\n";
  }

  // member: steer_ang
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer_ang: ";
    value_to_yaml(msg.steer_ang, out);
    out << "\n";
  }

  // member: gear_no
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gear_no: ";
    value_to_yaml(msg.gear_no, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const hellocm_msgs::msg::VehicleControlIn & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<hellocm_msgs::msg::VehicleControlIn>()
{
  return "hellocm_msgs::msg::VehicleControlIn";
}

template<>
inline const char * name<hellocm_msgs::msg::VehicleControlIn>()
{
  return "hellocm_msgs/msg/VehicleControlIn";
}

template<>
struct has_fixed_size<hellocm_msgs::msg::VehicleControlIn>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<hellocm_msgs::msg::VehicleControlIn>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<hellocm_msgs::msg::VehicleControlIn>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__MSG__DETAIL__VEHICLE_CONTROL_IN__TRAITS_HPP_
