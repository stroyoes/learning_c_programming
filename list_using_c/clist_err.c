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
    case CLISTS_CONCAT_ERR:
      return "Concatenation failed (Check the concat parameters once again) ❌➕ !";
    case CLIST_MAP_ERR:
      return "Failed to map function to the list ❌⚙  !";
    case CLIST_FILTER_ERR:
      return "Failed to filter elements from list ❌🔎 !";
    default:
      return "Some unknown error occured ❌ !";
  
  }
}
