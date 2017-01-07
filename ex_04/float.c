#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raise.h"
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    float value;
    char *last_to_string;
} FloatClass;

static void	ctor(Object* self, va_list * args)
{
  FloatClass	*obj = (FloatClass*) self;

  if (args != NULL)
    obj->value = va_arg(*args, double);

  va_end(*args);
}

static void	dtor(Object* self)
{
  FloatClass	*obj;

  obj = (FloatClass*) self;
  if (obj->last_to_string)
    free(obj->last_to_string);
}

static char const	*to_string(Object *self)
{
  FloatClass		*obj;
  char			*str;
  int			size;

  obj = (FloatClass*) self;
  if (obj->last_to_string)
    free(obj->last_to_string);
  if ((str = malloc(12)) == NULL)
    raise("Out of memory");
  size = sprintf(str, "%f", obj->value);
  obj->last_to_string = str;
  str[size] = 0;
  return (str);
}

static Object		*add_operator(const Object* self, const Object *other)
{
  FloatClass		*self_obj;
  FloatClass		*other_obj;
  FloatClass		*result_obj;

  self_obj = (FloatClass*) self;
  other_obj = (FloatClass*) other;
  result_obj = new(Int);
  result_obj->value = self_obj->value + other_obj->value;
  return (result_obj);
}

static Object		*sub_operator(const Object* self, const Object *other)
{
  FloatClass		*self_obj;
  FloatClass		*other_obj;
  FloatClass		*result_obj;

  self_obj = (FloatClass*) self;
  other_obj = (FloatClass*) other;
  result_obj = new(Int);
  result_obj->value = self_obj->value - other_obj->value;
  return (result_obj);
}

static Object		*mul_operator(const Object* self, const Object *other)
{
  FloatClass		*self_obj;
  FloatClass		*other_obj;
  FloatClass		*result_obj;

  self_obj = (FloatClass*) self;
  other_obj = (FloatClass*) other;
  result_obj = new(Int);
  result_obj->value = self_obj->value * other_obj->value;
  return (result_obj);
}

static Object		*div_operator(const Object* self, const Object *other)
{
  FloatClass		*self_obj;
  FloatClass		*other_obj;
  FloatClass		*result_obj;

  self_obj = (FloatClass*) self;
  other_obj = (FloatClass*) other;
  result_obj = new(Int);
  if (self_obj->value != 0 && other_obj->value != 0)
    result_obj->value = self_obj->value / other_obj->value;
  else
    result_obj->value = 0;
  return (result_obj);
}

static bool		eq_operator(const Object* self, const Object *other)
{
  FloatClass		*self_obj;
  FloatClass		*other_obj;

  self_obj = (FloatClass*) self;
  other_obj = (FloatClass*) other;
  return (self_obj->value == other_obj->value);
}

static bool		gt_operator(const Object* self, const Object *other)
{
  FloatClass		*self_obj;
  FloatClass		*other_obj;

  self_obj = (FloatClass*) self;
  other_obj = (FloatClass*) other;
  return (self_obj->value > other_obj->value);
}

static bool		lt_operator(const Object* self, const Object *other)
{
  FloatClass		*self_obj;
  FloatClass		*other_obj;

  self_obj = (FloatClass*) self;
  other_obj = (FloatClass*) other;
  return (self_obj->value < other_obj->value);
}

static FloatClass _description = {
    { sizeof(FloatClass), "Float", &ctor, &dtor, &to_string,
  &add_operator, &sub_operator, &mul_operator, &div_operator,
  &eq_operator, &gt_operator, &lt_operator },
    0, 0, NULL
};

Class* Float = (Class*) &_description;
