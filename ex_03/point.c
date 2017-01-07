#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raise.h"
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y;
    char *last_to_string;
} PointClass;

static void	ctor(Object* self, va_list * args)
{
  PointClass	*point = (PointClass*) self;

  point->x = va_arg(*args, int);
  point->y = va_arg(*args, int);
  va_end(*args);
}

static void	dtor(Object* self)
{
  PointClass	*point;

  point = (PointClass*) self;
  if (point->last_to_string)
    free(point->last_to_string);
}

static char const	*to_string(Object *self)
{
  PointClass		*point;
  char			*str;
  int			size;

  point = (PointClass*) self;
  if (point->last_to_string)
    free(point->last_to_string);
  if ((str = malloc(26 + strlen(point->base.__name__))) == NULL)
    raise("Out of memory");
  size = sprintf(str, "<%s (%d, %d)>", point->base.__name__, point->x, point->y);
  point->last_to_string = str;
  str[size] = 0;
  return (str);
}

static Object		*add_operator(const Object* self, const Object *other)
{
  PointClass		*self_point;
  PointClass		*other_point;
  PointClass		*result_point;

  self_point = (PointClass*) self;
  other_point = (PointClass*) other;
  result_point = new(Point);
  result_point->x = self_point->x + other_point->x;
  result_point->y = self_point->y + other_point->y;
  return (result_point);
}

static Object	*sub_operator(const Object* self, const Object *other)
{
  PointClass	*self_point;
  PointClass	*other_point;
  PointClass	*result_point;

  self_point = (PointClass*) self;
  other_point = (PointClass*) other;
  result_point = new(Point);
  result_point->x = self_point->x - other_point->x;
  result_point->y = self_point->y - other_point->y;
  return (result_point);
}

static PointClass _description = {
    { sizeof(PointClass), "Point", &ctor, &dtor, &to_string,
  &add_operator, &sub_operator},
    0, 0, NULL
};

Class* Point = (Class*) &_description;
