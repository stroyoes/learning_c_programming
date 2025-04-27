#ifndef CLIST_ERR_H
#define CLIST_ERR_H

#define CLIST_ERR_NULL NULL

typedef enum { 
  CLIST_OK,
  CLIST_STRUCT_ALLOC_ERR,
  CLIST_BUFFER_ALLOC_ERR,
  CLIST_INDEX_ERR,
  CLISTS_CONCAT_ERR,
  CLIST_MAP_ERR,
  CLIST_FILTER_ERR,
} clist_err_t;

extern clist_err_t clist_error;

const char* clist_err_msg(clist_err_t err_code);

#endif
