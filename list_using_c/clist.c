#include "clist.h"
#include "clist_err.h"

#include <stdlib.h>

clist_t* create_clist() {
  clist_t *clist = malloc(sizeof(clist_t));

  if (clist == NULL) {
    clist_error = CLIST_STRUCT_ALLOC_ERR;
    return CLIST_ERR_NULL;
  }

  clist->size = 0;
  clist->capacity = 4;

  clist->buffer = calloc(clist->capacity, sizeof(int)); 

  return clist;
}

void append(clist_t *list, int value) {

}

