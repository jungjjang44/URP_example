// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hellocm_msgs:msg/SignalLightIn.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/msg/detail/signal_light_in__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
hellocm_msgs__msg__SignalLightIn__init(hellocm_msgs__msg__SignalLightIn * msg)
{
  if (!msg) {
    return false;
  }
  // signal_light
  // hazard
  return true;
}

void
hellocm_msgs__msg__SignalLightIn__fini(hellocm_msgs__msg__SignalLightIn * msg)
{
  if (!msg) {
    return;
  }
  // signal_light
  // hazard
}

bool
hellocm_msgs__msg__SignalLightIn__are_equal(const hellocm_msgs__msg__SignalLightIn * lhs, const hellocm_msgs__msg__SignalLightIn * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // signal_light
  if (lhs->signal_light != rhs->signal_light) {
    return false;
  }
  // hazard
  if (lhs->hazard != rhs->hazard) {
    return false;
  }
  return true;
}

bool
hellocm_msgs__msg__SignalLightIn__copy(
  const hellocm_msgs__msg__SignalLightIn * input,
  hellocm_msgs__msg__SignalLightIn * output)
{
  if (!input || !output) {
    return false;
  }
  // signal_light
  output->signal_light = input->signal_light;
  // hazard
  output->hazard = input->hazard;
  return true;
}

hellocm_msgs__msg__SignalLightIn *
hellocm_msgs__msg__SignalLightIn__create()
{
  hellocm_msgs__msg__SignalLightIn * msg = (hellocm_msgs__msg__SignalLightIn *)malloc(sizeof(hellocm_msgs__msg__SignalLightIn));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hellocm_msgs__msg__SignalLightIn));
  bool success = hellocm_msgs__msg__SignalLightIn__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
hellocm_msgs__msg__SignalLightIn__destroy(hellocm_msgs__msg__SignalLightIn * msg)
{
  if (msg) {
    hellocm_msgs__msg__SignalLightIn__fini(msg);
  }
  free(msg);
}


bool
hellocm_msgs__msg__SignalLightIn__Sequence__init(hellocm_msgs__msg__SignalLightIn__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  hellocm_msgs__msg__SignalLightIn * data = NULL;
  if (size) {
    data = (hellocm_msgs__msg__SignalLightIn *)calloc(size, sizeof(hellocm_msgs__msg__SignalLightIn));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hellocm_msgs__msg__SignalLightIn__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hellocm_msgs__msg__SignalLightIn__fini(&data[i - 1]);
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
hellocm_msgs__msg__SignalLightIn__Sequence__fini(hellocm_msgs__msg__SignalLightIn__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hellocm_msgs__msg__SignalLightIn__fini(&array->data[i]);
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

hellocm_msgs__msg__SignalLightIn__Sequence *
hellocm_msgs__msg__SignalLightIn__Sequence__create(size_t size)
{
  hellocm_msgs__msg__SignalLightIn__Sequence * array = (hellocm_msgs__msg__SignalLightIn__Sequence *)malloc(sizeof(hellocm_msgs__msg__SignalLightIn__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = hellocm_msgs__msg__SignalLightIn__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
hellocm_msgs__msg__SignalLightIn__Sequence__destroy(hellocm_msgs__msg__SignalLightIn__Sequence * array)
{
  if (array) {
    hellocm_msgs__msg__SignalLightIn__Sequence__fini(array);
  }
  free(array);
}

bool
hellocm_msgs__msg__SignalLightIn__Sequence__are_equal(const hellocm_msgs__msg__SignalLightIn__Sequence * lhs, const hellocm_msgs__msg__SignalLightIn__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hellocm_msgs__msg__SignalLightIn__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__msg__SignalLightIn__Sequence__copy(
  const hellocm_msgs__msg__SignalLightIn__Sequence * input,
  hellocm_msgs__msg__SignalLightIn__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hellocm_msgs__msg__SignalLightIn);
    hellocm_msgs__msg__SignalLightIn * data =
      (hellocm_msgs__msg__SignalLightIn *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hellocm_msgs__msg__SignalLightIn__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hellocm_msgs__msg__SignalLightIn__fini(&data[i]);
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
    if (!hellocm_msgs__msg__SignalLightIn__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
