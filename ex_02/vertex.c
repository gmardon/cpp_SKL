/*
** vextex.c for cpp_SKL in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/cpp_SKL/ex_02/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Sat Jan  7 18:09:19 2017 Guillaume MARDON
** Last update Sat Jan  7 19:52:56 2017 Guillaume MARDON
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vertex.h"

typedef struct
{
    Class base;
    int x, y, z;
  	char *last_to_string;
} VertexClass;

static void ctor(Object* self, va_list * args)
{
  VertexClass *vertex = (VertexClass*) self;

  vertex->x = va_arg(*args, int);
  vertex->y = va_arg(*args, int);
  vertex->z = va_arg(*args, int);
  va_end(*args);
}

static void dtor(Object* self)
{
  VertexClass *vertex;

  vertex = (VertexClass *)self;
  if (vertex->last_to_string)
    free(vertex->last_to_string);
}

static char const *to_string(Object *self)
{
  VertexClass *vertex;
  char *str;
  int size;

  vertex = (VertexClass*) self;
  if (vertex->last_to_string)
    free(vertex->last_to_string);
  str = malloc(38 + strlen(vertex->base.__name__));
  size = sprintf(str, "<%s (%d, %d, %d)>", vertex->base.__name__, vertex->x, vertex->y, vertex->z);
  vertex->last_to_string = str;
  str[size] = 0;
  return (str);
}

static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &ctor, &dtor, &to_string },
    0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
