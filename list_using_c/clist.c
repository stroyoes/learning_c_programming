#include "clist.h"
#include "clist_err.h"

#include <cstdio>
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

  if (clist->buffer == NULL) {
    clist_error = CLIST_BUFFER_ALLOC_ERR;
    return CLIST_ERR_NULL;
  }

  return clist;
}

CLIST_RETURN_NOTHING append(clist_t *clist, int value) {
  if (clist->size >= clist->capacity) {
    clist->capacity *= 2;
    clist->buffer = realloc(clist->buffer, clist->capacity * sizeof(int));

    if (clist->buffer == NULL) {
      clist_error = CLIST_BUFFER_ALLOC_ERR;
      return ;
    }

  }
  clist->buffer[clist->size++] = value;
}

int get(clist_t *clist, int index) {
  if (index < 0) index += clist->size;
  if (index < 0 || index >= clist->size) {
    
    clist_error = CLIST_INDEX_ERR;
    return CLIST_UNBOUND_INDEX;

  }

  return clist->buffer[index];
}

int contains(clist_t *clist, int value) {
  for (int i = 0; i < clist->size; i++) {
    if (clist->buffer[i] == value) {
      return true; 
    }
  }
  return false;
}

int count(clist_t *clist, int value) {
  int seen = 0; 
  for (int i = 0; i < clist->size; i++) {
    if (clist->buffer[i] == value) {
      seen++;
    }
  }

  return seen;
}

CLIST_RETURN_NOTHING remove(clist_t *clist, int value) {
  int found = 0;

  for (int i = 0; i < clist->size; i++) {
    if (clist->buffer[i] == value) {
      found = true;
    }
    if (found && i < clist->size - 1) {
      clist->buffer[i] = clist->buffer[i + 1];
    }
  }
  if (found) {
    clist->size--;
  }

}

CLIST_RETURN_NOTHING destroy_list(clist_t *clist) {
    free(clist->buffer);
    free(clist);
}

clist_t* slice(clist_t *clist, int start, int end) {
  if (start < 0) {
    start += clist->size;
  }
  if (end < 0) {
    end += clist->size;
  }
  
  if (start < 0) start = 0;
  if (end > clist->size) end = clist->size;
  if (start >= end) {
    clist_error = CLIST_INDEX_ERR;
    return CLIST_ERR_NULL;
  }

  clist_t *subclist = malloc(sizeof(clist_t));
  
  if (subclist == NULL) {

  }
 
  subclist->size = end - start;
  subclist->capacity = subclist->size;

  subclist->buffer = malloc(subclist->capacity * sizeof(int));

  
}
