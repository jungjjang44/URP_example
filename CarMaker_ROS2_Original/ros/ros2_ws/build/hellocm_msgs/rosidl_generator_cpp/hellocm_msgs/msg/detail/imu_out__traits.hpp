// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:msg/IMUOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__IMU_OUT__TRAITS_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__IMU_OUT__TRAITS_HPP_

#include "hellocm_msgs/msg/detail/imu_out__struct.hpp"
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
  const hellocm_msgs::msg::IMUOut & msg,
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

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    value_to_yaml(msg.vx, out);
    out << "\n";
  }

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy: ";
    value_to_yaml(msg.vy, out);
    out << "\n";
  }

  // member: vz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vz: ";
    value_to_yaml(msg.vz, out);
    out << "\n";
  }

  // member: roll_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_rate: ";
    value_to_yaml(msg.roll_rate, out);
    out << "\n";
  }

  // member: pitch_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_rate: ";
    value_to_yaml(msg.pitch_rate, out);
    out << "\n";
  }

  // member: yaw_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_rate: ";
    value_to_yaml(msg.yaw_rate, out);
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

  // member: ay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ay: ";
    value_to_yaml(msg.ay, out);
    out << "\n";
  }

  // member: az
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "az: ";
    value_to_yaml(msg.az, out);
    out << "\n";
  }

  // member: roll_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_acc: ";
    value_to_yaml(msg.roll_acc, out);
    out << "\n";
  }

  // member: pitch_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_acc: ";
    value_to_yaml(msg.pitch_acc, out);
    out << "\n";
  }

  // member: yaw_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_acc: ";
    value_to_yaml(msg.yaw_acc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const hellocm_msgs::msg::IMUOut & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<hellocm_msgs::msg::IMUOut>()
{
  return "hellocm_msgs::msg::IMUOut";
}

template<>
inline const char * name<hellocm_msgs::msg::IMUOut>()
{
  return "hellocm_msgs/msg/IMUOut";
}

template<>
struct has_fixed_size<hellocm_msgs::msg::IMUOut>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<hellocm_msgs::msg::IMUOut>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<hellocm_msgs::msg::IMUOut>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__MSG__DETAIL__IMU_OUT__TRAITS_HPP_
