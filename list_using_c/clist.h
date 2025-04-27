#ifndef CLIST_H
#define CLIST_H

#include <stdbool.h>

#define CLIST_RETURN_NOTHING void
#define CLIST_UNBOUND_INDEX -1

typedef struct {
  int *buffer;
  int size;
  int capacity;
} clist_t;

#endif



