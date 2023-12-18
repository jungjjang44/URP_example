// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:msg/ObjectInfoOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__TRAITS_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__TRAITS_HPP_

#include "hellocm_msgs/msg/detail/object_info_out__struct.hpp"
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
  const hellocm_msgs::msg::ObjectInfoOut & msg,
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

  // member: num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num: ";
    value_to_yaml(msg.num, out);
    out << "\n";
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

  // member: w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.w.size() == 0) {
      out << "w: []\n";
    } else {
      out << "w:\n";
      for (auto item : msg.w) {
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

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vx.size() == 0) {
      out << "vx: []\n";
    } else {
      out << "vx:\n";
      for (auto item : msg.vx) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vy.size() == 0) {
      out << "vy: []\n";
    } else {
      out << "vy:\n";
      for (auto item : msg.vy) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.alpha.size() == 0) {
      out << "alpha: []\n";
    } else {
      out << "alpha:\n";
      for (auto item : msg.alpha) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: global_vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.global_vx.size() == 0) {
      out << "global_vx: []\n";
    } else {
      out << "global_vx:\n";
      for (auto item : msg.global_vx) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: global_vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.global_vy.size() == 0) {
      out << "global_vy: []\n";
    } else {
      out << "global_vy:\n";
      for (auto item : msg.global_vy) {
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

inline std::string to_yaml(const hellocm_msgs::msg::ObjectInfoOut & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<hellocm_msgs::msg::ObjectInfoOut>()
{
  return "hellocm_msgs::msg::ObjectInfoOut";
}

template<>
inline const char * name<hellocm_msgs::msg::ObjectInfoOut>()
{
  return "hellocm_msgs/msg/ObjectInfoOut";
}

template<>
struct has_fixed_size<hellocm_msgs::msg::ObjectInfoOut>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<hellocm_msgs::msg::ObjectInfoOut>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<hellocm_msgs::msg::ObjectInfoOut>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__TRAITS_HPP_
