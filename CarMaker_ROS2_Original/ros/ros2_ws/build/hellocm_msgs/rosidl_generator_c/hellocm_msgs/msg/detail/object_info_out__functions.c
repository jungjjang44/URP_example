// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hellocm_msgs:msg/ObjectInfoOut.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/msg/detail/object_info_out__functions.h"

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
hellocm_msgs__msg__ObjectInfoOut__init(hellocm_msgs__msg__ObjectInfoOut * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    hellocm_msgs__msg__ObjectInfoOut__fini(msg);
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__init(&msg->time)) {
    hellocm_msgs__msg__ObjectInfoOut__fini(msg);
    return false;
  }
  // cycleno
  // synthdelay
  // num
  // id
  // x
  // y
  // w
  // h
  // vx
  // vy
  // alpha
  // global_vx
  // global_vy
  return true;
}

void
hellocm_msgs__msg__ObjectInfoOut__fini(hellocm_msgs__msg__ObjectInfoOut * msg)
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
  // num
  // id
  // x
  // y
  // w
  // h
  // vx
  // vy
  // alpha
  // global_vx
  // global_vy
}

bool
hellocm_msgs__msg__ObjectInfoOut__are_equal(const hellocm_msgs__msg__ObjectInfoOut * lhs, const hellocm_msgs__msg__ObjectInfoOut * rhs)
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
  // num
  if (lhs->num != rhs->num) {
    return false;
  }
  // id
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->id[i] != rhs->id[i]) {
      return false;
    }
  }
  // x
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->x[i] != rhs->x[i]) {
      return false;
    }
  }
  // y
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->y[i] != rhs->y[i]) {
      return false;
    }
  }
  // w
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->w[i] != rhs->w[i]) {
      return false;
    }
  }
  // h
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->h[i] != rhs->h[i]) {
      return false;
    }
  }
  // vx
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->vx[i] != rhs->vx[i]) {
      return false;
    }
  }
  // vy
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->vy[i] != rhs->vy[i]) {
      return false;
    }
  }
  // alpha
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->alpha[i] != rhs->alpha[i]) {
      return false;
    }
  }
  // global_vx
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->global_vx[i] != rhs->global_vx[i]) {
      return false;
    }
  }
  // global_vy
  for (size_t i = 0; i < 50; ++i) {
    if (lhs->global_vy[i] != rhs->global_vy[i]) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__msg__ObjectInfoOut__copy(
  const hellocm_msgs__msg__ObjectInfoOut * input,
  hellocm_msgs__msg__ObjectInfoOut * output)
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
  // num
  output->num = input->num;
  // id
  for (size_t i = 0; i < 50; ++i) {
    output->id[i] = input->id[i];
  }
  // x
  for (size_t i = 0; i < 50; ++i) {
    output->x[i] = input->x[i];
  }
  // y
  for (size_t i = 0; i < 50; ++i) {
    output->y[i] = input->y[i];
  }
  // w
  for (size_t i = 0; i < 50; ++i) {
    output->w[i] = input->w[i];
  }
  // h
  for (size_t i = 0; i < 50; ++i) {
    output->h[i] = input->h[i];
  }
  // vx
  for (size_t i = 0; i < 50; ++i) {
    output->vx[i] = input->vx[i];
  }
  // vy
  for (size_t i = 0; i < 50; ++i) {
    output->vy[i] = input->vy[i];
  }
  // alpha
  for (size_t i = 0; i < 50; ++i) {
    output->alpha[i] = input->alpha[i];
  }
  // global_vx
  for (size_t i = 0; i < 50; ++i) {
    output->global_vx[i] = input->global_vx[i];
  }
  // global_vy
  for (size_t i = 0; i < 50; ++i) {
    output->global_vy[i] = input->global_vy[i];
  }
  return true;
}

hellocm_msgs__msg__ObjectInfoOut *
hellocm_msgs__msg__ObjectInfoOut__create()
{
  hellocm_msgs__msg__ObjectInfoOut * msg = (hellocm_msgs__msg__ObjectInfoOut *)malloc(sizeof(hellocm_msgs__msg__ObjectInfoOut));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hellocm_msgs__msg__ObjectInfoOut));
  bool success = hellocm_msgs__msg__ObjectInfoOut__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
hellocm_msgs__msg__ObjectInfoOut__destroy(hellocm_msgs__msg__ObjectInfoOut * msg)
{
  if (msg) {
    hellocm_msgs__msg__ObjectInfoOut__fini(msg);
  }
  free(msg);
}


bool
hellocm_msgs__msg__ObjectInfoOut__Sequence__init(hellocm_msgs__msg__ObjectInfoOut__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  hellocm_msgs__msg__ObjectInfoOut * data = NULL;
  if (size) {
    data = (hellocm_msgs__msg__ObjectInfoOut *)calloc(size, sizeof(hellocm_msgs__msg__ObjectInfoOut));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hellocm_msgs__msg__ObjectInfoOut__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hellocm_msgs__msg__ObjectInfoOut__fini(&data[i - 1]);
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
hellocm_msgs__msg__ObjectInfoOut__Sequence__fini(hellocm_msgs__msg__ObjectInfoOut__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hellocm_msgs__msg__ObjectInfoOut__fini(&array->data[i]);
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

hellocm_msgs__msg__ObjectInfoOut__Sequence *
hellocm_msgs__msg__ObjectInfoOut__Sequence__create(size_t size)
{
  hellocm_msgs__msg__ObjectInfoOut__Sequence * array = (hellocm_msgs__msg__ObjectInfoOut__Sequence *)malloc(sizeof(hellocm_msgs__msg__ObjectInfoOut__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = hellocm_msgs__msg__ObjectInfoOut__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
hellocm_msgs__msg__ObjectInfoOut__Sequence__destroy(hellocm_msgs__msg__ObjectInfoOut__Sequence * array)
{
  if (array) {
    hellocm_msgs__msg__ObjectInfoOut__Sequence__fini(array);
  }
  free(array);
}

bool
hellocm_msgs__msg__ObjectInfoOut__Sequence__are_equal(const hellocm_msgs__msg__ObjectInfoOut__Sequence * lhs, const hellocm_msgs__msg__ObjectInfoOut__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hellocm_msgs__msg__ObjectInfoOut__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__msg__ObjectInfoOut__Sequence__copy(
  const hellocm_msgs__msg__ObjectInfoOut__Sequence * input,
  hellocm_msgs__msg__ObjectInfoOut__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hellocm_msgs__msg__ObjectInfoOut);
    hellocm_msgs__msg__ObjectInfoOut * data =
      (hellocm_msgs__msg__ObjectInfoOut *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hellocm_msgs__msg__ObjectInfoOut__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hellocm_msgs__msg__ObjectInfoOut__fini(&data[i]);
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
    if (!hellocm_msgs__msg__ObjectInfoOut__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
