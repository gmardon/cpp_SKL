/*
** new.c for cpp_SKL in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/cpp_SKL/ex_01/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Sat Jan  7 16:57:26 2017 Guillaume MARDON
** Last update Sat Jan  7 20:28:57 2017 Romain Goasdoue
*/
#include <string.h>
#include <stdlib.h>
#include "raise.h"
#include "new.h"

Object*		va_new(Class* class, va_list* ap)
{
  Class		*obj;

  if ((obj = malloc(class->__size__)) == NULL)
    raise("Out of memory");
  memcpy(obj, class, class->__size__);
  obj->__init__(obj, ap);
  return (obj);
}

Object*		new(Class * class, ...)
{
  va_list	list;
  va_start(list, class);
  return (va_new(class, &list));
}

void		delete(Object* ptr)
{
  Class		*obj;

  obj = (Class *)ptr;
  obj->__del__(obj);
  free(obj);
}
