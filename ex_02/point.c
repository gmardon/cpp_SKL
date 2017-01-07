#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "point.h"

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(Object* self, va_list * args)
{
  PointClass *point = (PointClass*) self;

  point->x = va_arg(*args, int);
  point->y = va_arg(*args, int);
  va_end(*args);
}

static void Point_dtor(Object* self)
{
    (void) self;
}

static char const *to_string(Object *self)
{
  PointClass *point;
  char *str;
  int size;

  point = (PointClass*) self;
  str = malloc(26 + strlen(point->base.__name__));
  size = sprintf(str, "<%s (%d, %d)>", point->base.__name__, point->x, point->y);
  str[size] = 0;
  return (str);
}

static PointClass _description = {
    { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &to_string },
    0, 0
};

Class* Point = (Class*) &_description;
