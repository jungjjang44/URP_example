// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hellocm_msgs:msg/ObjectInfoOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__STRUCT_H_
#define HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'time'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in msg/ObjectInfoOut in the package hellocm_msgs.
typedef struct hellocm_msgs__msg__ObjectInfoOut
{
  std_msgs__msg__Header header;
  builtin_interfaces__msg__Time time;
  int64_t cycleno;
  double synthdelay;
  int16_t num;
  double id[50];
  double x[50];
  double y[50];
  double w[50];
  double h[50];
  double vx[50];
  double vy[50];
  double alpha[50];
  double global_vx[50];
  double global_vy[50];
} hellocm_msgs__msg__ObjectInfoOut;

// Struct for a sequence of hellocm_msgs__msg__ObjectInfoOut.
typedef struct hellocm_msgs__msg__ObjectInfoOut__Sequence
{
  hellocm_msgs__msg__ObjectInfoOut * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__msg__ObjectInfoOut__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HELLOCM_MSGS__MSG__DETAIL__OBJECT_INFO_OUT__STRUCT_H_
