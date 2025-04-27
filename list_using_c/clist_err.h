#ifndef CLIST_ERR_H
#define CLIST_ERR_H

typedef enum { 
  CLIST_OK,
  CLIST_STRUCT_ALLOC_ERR,
  CLIST_BUFFER_ALLOC_ERR,
  CLIST_INDEX_ERR,
} clist_err_t;

extern clist_err_t clist_error;

#endif
