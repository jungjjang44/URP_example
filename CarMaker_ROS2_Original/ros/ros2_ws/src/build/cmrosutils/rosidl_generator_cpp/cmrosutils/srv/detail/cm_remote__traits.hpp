// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cmrosutils:srv/CMRemote.idl
// generated code does not contain a copyright notice

#ifndef CMROSUTILS__SRV__DETAIL__CM_REMOTE__TRAITS_HPP_
#define CMROSUTILS__SRV__DETAIL__CM_REMOTE__TRAITS_HPP_

#include "cmrosutils/srv/detail/cm_remote__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const cmrosutils::srv::CMRemote_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg: ";
    value_to_yaml(msg.msg, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const cmrosutils::srv::CMRemote_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<cmrosutils::srv::CMRemote_Request>()
{
  return "cmrosutils::srv::CMRemote_Request";
}

template<>
inline const char * name<cmrosutils::srv::CMRemote_Request>()
{
  return "cmrosutils/srv/CMRemote_Request";
}

template<>
struct has_fixed_size<cmrosutils::srv::CMRemote_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cmrosutils::srv::CMRemote_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cmrosutils::srv::CMRemote_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const cmrosutils::srv::CMRemote_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: res
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "res: ";
    value_to_yaml(msg.res, out);
    out << "\n";
  }

  // member: msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg: ";
    value_to_yaml(msg.msg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const cmrosutils::srv::CMRemote_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<cmrosutils::srv::CMRemote_Response>()
{
  return "cmrosutils::srv::CMRemote_Response";
}

template<>
inline const char * name<cmrosutils::srv::CMRemote_Response>()
{
  return "cmrosutils/srv/CMRemote_Response";
}

template<>
struct has_fixed_size<cmrosutils::srv::CMRemote_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cmrosutils::srv::CMRemote_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cmrosutils::srv::CMRemote_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cmrosutils::srv::CMRemote>()
{
  return "cmrosutils::srv::CMRemote";
}

template<>
inline const char * name<cmrosutils::srv::CMRemote>()
{
  return "cmrosutils/srv/CMRemote";
}

template<>
struct has_fixed_size<cmrosutils::srv::CMRemote>
  : std::integral_constant<
    bool,
    has_fixed_size<cmrosutils::srv::CMRemote_Request>::value &&
    has_fixed_size<cmrosutils::srv::CMRemote_Response>::value
  >
{
};

template<>
struct has_bounded_size<cmrosutils::srv::CMRemote>
  : std::integral_constant<
    bool,
    has_bounded_size<cmrosutils::srv::CMRemote_Request>::value &&
    has_bounded_size<cmrosutils::srv::CMRemote_Response>::value
  >
{
};

template<>
struct is_service<cmrosutils::srv::CMRemote>
  : std::true_type
{
};

template<>
struct is_service_request<cmrosutils::srv::CMRemote_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cmrosutils::srv::CMRemote_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CMROSUTILS__SRV__DETAIL__CM_REMOTE__TRAITS_HPP_
