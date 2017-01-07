/*
** vextex.c for cpp_SKL in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/cpp_SKL/ex_02/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Sat Jan  7 18:09:19 2017 Guillaume MARDON
** Last update Sat Jan  7 18:18:52 2017 Guillaume MARDON
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vertex.h"

typedef struct
{
    Class base;
    int x, y, z;
} VertexClass;

static void Vertex_ctor(Object* self, va_list * args)
{
  VertexClass *point = (VertexClass*) self;

  point->x = va_arg(*args, int);
  point->y = va_arg(*args, int);
  point->z = va_arg(*args, int);
  va_end(*args);
}

static void Vertex_dtor(Object* self)
{
    (void) self;
}

static char const *to_string(Object *self)
{
  VertexClass *vertex;
  char *str;
  int size;

  vertex = (VertexClass*) self;
  str = malloc(38 + strlen(vertex->base.__name__));
  size = sprintf(str, "<%s (%d, %d, %d)>", vertex->base.__name__, vertex->x, vertex->y, vertex->z);
  str[size] = 0;
  return (str);
}

static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &to_string },
    0, 0, 0
};

Class* Vertex = (Class*) &_description;
