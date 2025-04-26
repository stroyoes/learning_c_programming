#include "clist.h"

#include <stdio.h>
#include <stdlib.h>

clist_t* create_clist() {
  clist_t *clist = malloc(sizeof(clist_t));

  clist->size = 0;
  clist->capacity = 4;

  clist->buffer = calloc(clist->capacity, sizeof(int)); 

  return clist;
}

void append(clist_t *list, int value) {
  if 
}

