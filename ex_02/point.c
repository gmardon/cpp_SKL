#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "point.h"
#include "raise.h"

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

static PointClass _description = {
    { sizeof(PointClass), "Point", &ctor, &dtor, &to_string },
    0, 0, NULL
};

Class* Point = (Class*) &_description;
