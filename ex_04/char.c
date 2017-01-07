/*
** char.c for ex_04 in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/cpp_SKL/ex_04/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Sat Jan  7 21:33:51 2017 Guillaume MARDON
** Last update Sat Jan  7 21:33:55 2017 Guillaume MARDON
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char value;
    char *last_to_string;
} CharClass;

static void	ctor(Object* self, va_list * args)
{
  CharClass	*obj = (CharClass*) self;

  if (args != NULL)
    obj->value = (char) va_arg(args, int);

  va_end(*args);
}

static void	dtor(Object* self)
{
  CharClass	*obj;

  obj = (CharClass*) self;
  if (obj->last_to_string)
    free(obj->last_to_string);
}

static char const	*to_string(Object *self)
{
  CharClass		*obj;
  char			*str;
  int			size;

  obj = (CharClass*) self;
  if (obj->last_to_string)
    free(obj->last_to_string);
  str = malloc(12);
  size = sprintf(str, "%d", obj->value);
  obj->last_to_string = str;
  str[size] = 0;
  return (str);
}

static Object		*add_operator(const Object* self, const Object *other)
{
  CharClass		*self_obj;
  CharClass		*other_obj;
  CharClass		*result_obj;

  self_obj = (CharClass*) self;
  other_obj = (CharClass*) other;
  result_obj = new(Char);
  result_obj->value = self_obj->value + other_obj->value;
  return (result_obj);
}

static Object		*sub_operator(const Object* self, const Object *other)
{
  CharClass		*self_obj;
  CharClass		*other_obj;
  CharClass		*result_obj;

  self_obj = (CharClass*) self;
  other_obj = (CharClass*) other;
  result_obj = new(Char);
  result_obj->value = self_obj->value - other_obj->value;
  return (result_obj);
}

static Object		*mul_operator(const Object* self, const Object *other)
{
  CharClass		*self_obj;
  CharClass		*other_obj;
  CharClass		*result_obj;

  self_obj = (CharClass*) self;
  other_obj = (CharClass*) other;
  result_obj = new(Char);
  result_obj->value = self_obj->value * other_obj->value;
  return (result_obj);
}

static Object		*div_operator(const Object* self, const Object *other)
{
  CharClass		*self_obj;
  CharClass		*other_obj;
  CharClass		*result_obj;

  self_obj = (CharClass*) self;
  other_obj = (CharClass*) other;
  result_obj = new(Char);
  if (self_obj->value != 0 && other_obj->value != 0)
    result_obj->value = self_obj->value / other_obj->value;
  else
    result_obj->value = 0;
  return (result_obj);
}

static bool		eq_operator(const Object* self, const Object *other)
{
  CharClass		*self_obj;
  CharClass		*other_obj;

  self_obj = (CharClass*) self;
  other_obj = (CharClass*) other;
  return (self_obj->value == other_obj->value);
}

static bool		gt_operator(const Object* self, const Object *other)
{
  CharClass		*self_obj;
  CharClass		*other_obj;

  self_obj = (CharClass*) self;
  other_obj = (CharClass*) other;
  return (self_obj->value > other_obj->value);
}

static bool		lt_operator(const Object* self, const Object *other)
{
  CharClass		*self_obj;
  CharClass		*other_obj;

  self_obj = (CharClass*) self;
  other_obj = (CharClass*) other;
  return (self_obj->value < other_obj->value);
}

static CharClass _description = {
    { sizeof(CharClass), "Char", &ctor, &dtor, &to_string,
  &add_operator, &sub_operator, &mul_operator, &div_operator,
  &eq_operator, &gt_operator, &lt_operator },
    0, 0, NULL
};

Class* Char = (Class*) &_description;
