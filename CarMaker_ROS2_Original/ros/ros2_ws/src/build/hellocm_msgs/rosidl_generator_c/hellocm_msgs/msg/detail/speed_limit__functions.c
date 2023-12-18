// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hellocm_msgs:msg/SpeedLimit.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/msg/detail/speed_limit__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `time`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
hellocm_msgs__msg__SpeedLimit__init(hellocm_msgs__msg__SpeedLimit * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    hellocm_msgs__msg__SpeedLimit__fini(msg);
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__init(&msg->time)) {
    hellocm_msgs__msg__SpeedLimit__fini(msg);
    return false;
  }
  // cycleno
  // synthdelay
  // distance
  // speed_limit
  return true;
}

void
hellocm_msgs__msg__SpeedLimit__fini(hellocm_msgs__msg__SpeedLimit * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // time
  builtin_interfaces__msg__Time__fini(&msg->time);
  // cycleno
  // synthdelay
  // distance
  // speed_limit
}

bool
hellocm_msgs__msg__SpeedLimit__are_equal(const hellocm_msgs__msg__SpeedLimit * lhs, const hellocm_msgs__msg__SpeedLimit * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->time), &(rhs->time)))
  {
    return false;
  }
  // cycleno
  if (lhs->cycleno != rhs->cycleno) {
    return false;
  }
  // synthdelay
  if (lhs->synthdelay != rhs->synthdelay) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // speed_limit
  if (lhs->speed_limit != rhs->speed_limit) {
    return false;
  }
  return true;
}

bool
hellocm_msgs__msg__SpeedLimit__copy(
  const hellocm_msgs__msg__SpeedLimit * input,
  hellocm_msgs__msg__SpeedLimit * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->time), &(output->time)))
  {
    return false;
  }
  // cycleno
  output->cycleno = input->cycleno;
  // synthdelay
  output->synthdelay = input->synthdelay;
  // distance
  output->distance = input->distance;
  // speed_limit
  output->speed_limit = input->speed_limit;
  return true;
}

hellocm_msgs__msg__SpeedLimit *
hellocm_msgs__msg__SpeedLimit__create()
{
  hellocm_msgs__msg__SpeedLimit * msg = (hellocm_msgs__msg__SpeedLimit *)malloc(sizeof(hellocm_msgs__msg__SpeedLimit));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hellocm_msgs__msg__SpeedLimit));
  bool success = hellocm_msgs__msg__SpeedLimit__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
hellocm_msgs__msg__SpeedLimit__destroy(hellocm_msgs__msg__SpeedLimit * msg)
{
  if (msg) {
    hellocm_msgs__msg__SpeedLimit__fini(msg);
  }
  free(msg);
}


bool
hellocm_msgs__msg__SpeedLimit__Sequence__init(hellocm_msgs__msg__SpeedLimit__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  hellocm_msgs__msg__SpeedLimit * data = NULL;
  if (size) {
    data = (hellocm_msgs__msg__SpeedLimit *)calloc(size, sizeof(hellocm_msgs__msg__SpeedLimit));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hellocm_msgs__msg__SpeedLimit__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hellocm_msgs__msg__SpeedLimit__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hellocm_msgs__msg__SpeedLimit__Sequence__fini(hellocm_msgs__msg__SpeedLimit__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hellocm_msgs__msg__SpeedLimit__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hellocm_msgs__msg__SpeedLimit__Sequence *
hellocm_msgs__msg__SpeedLimit__Sequence__create(size_t size)
{
  hellocm_msgs__msg__SpeedLimit__Sequence * array = (hellocm_msgs__msg__SpeedLimit__Sequence *)malloc(sizeof(hellocm_msgs__msg__SpeedLimit__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = hellocm_msgs__msg__SpeedLimit__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
hellocm_msgs__msg__SpeedLimit__Sequence__destroy(hellocm_msgs__msg__SpeedLimit__Sequence * array)
{
  if (array) {
    hellocm_msgs__msg__SpeedLimit__Sequence__fini(array);
  }
  free(array);
}

bool
hellocm_msgs__msg__SpeedLimit__Sequence__are_equal(const hellocm_msgs__msg__SpeedLimit__Sequence * lhs, const hellocm_msgs__msg__SpeedLimit__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hellocm_msgs__msg__SpeedLimit__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__msg__SpeedLimit__Sequence__copy(
  const hellocm_msgs__msg__SpeedLimit__Sequence * input,
  hellocm_msgs__msg__SpeedLimit__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hellocm_msgs__msg__SpeedLimit);
    hellocm_msgs__msg__SpeedLimit * data =
      (hellocm_msgs__msg__SpeedLimit *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hellocm_msgs__msg__SpeedLimit__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hellocm_msgs__msg__SpeedLimit__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hellocm_msgs__msg__SpeedLimit__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
