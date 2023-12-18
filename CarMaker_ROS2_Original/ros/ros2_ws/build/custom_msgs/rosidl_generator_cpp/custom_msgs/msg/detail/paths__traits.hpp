// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/Paths.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__PATHS__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__PATHS__TRAITS_HPP_

#include "custom_msgs/msg/detail/paths__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const custom_msgs::msg::Paths & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x.size() == 0) {
      out << "x: []\n";
    } else {
      out << "x:\n";
      for (auto item : msg.x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.y.size() == 0) {
      out << "y: []\n";
    } else {
      out << "y:\n";
      for (auto item : msg.y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.s.size() == 0) {
      out << "s: []\n";
    } else {
      out << "s:\n";
      for (auto item : msg.s) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.h.size() == 0) {
      out << "h: []\n";
    } else {
      out << "h:\n";
      for (auto item : msg.h) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.id.size() == 0) {
      out << "id: []\n";
    } else {
      out << "id:\n";
      for (auto item : msg.id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_roi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_roi.size() == 0) {
      out << "left_roi: []\n";
    } else {
      out << "left_roi:\n";
      for (auto item : msg.left_roi) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_roi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_roi.size() == 0) {
      out << "right_roi: []\n";
    } else {
      out << "right_roi:\n";
      for (auto item : msg.right_roi) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const custom_msgs::msg::Paths & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<custom_msgs::msg::Paths>()
{
  return "custom_msgs::msg::Paths";
}

template<>
inline const char * name<custom_msgs::msg::Paths>()
{
  return "custom_msgs/msg/Paths";
}

template<>
struct has_fixed_size<custom_msgs::msg::Paths>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::msg::Paths>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::msg::Paths>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__PATHS__TRAITS_HPP_
