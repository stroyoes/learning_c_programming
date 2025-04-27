#include "clist_err.h"

clist_err_t clist_error = CLIST_OK; 

const char* clist_err_msg(clist_err_t err_code) {
  switch (err_code) {
    case CLIST_OK:
      return "List is ok 👍 !";
    case CLIST_STRUCT_ALLOC_ERR:
      return "Failed allocation of list structure ❌🗃️ !";
    case CLIST_BUFFER_ALLOC_ERR:
      return "Failed allocation of list data ❌📝 !";
    case CLIST_INDEX_ERR:
      return "Invalid index or index out of bounds ❌📍 !";
    default:
      return "Some unknown error occured ❌ !";
  
  }
}
