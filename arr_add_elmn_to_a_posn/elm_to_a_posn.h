#ifndef ELM_TO_A_POSN
#define ELM_TO_A_POSN

#include <stddef.h>

#define MAX_STR_LEN 100

typedef struct {
  int *arr;
  size_t arr_size;
  size_t allocated_arr_size;
  char desc[MAX_STR_LEN];
} dynamic_arr_t;

// Function prototypes
void init_dynamic_arr(dynamic_arr_t *arr, size_t initial_size, const char *desc);
void print_dynamic_arr(dynamic_arr_t *arr);
void resize_dynamic_arr(dynamic_arr_t *arr, size_t new_alloc_size);
void dynamic_arr_add(dynamic_arr_t *arr, int element);
void dynamic_arr_add_many(dynamic_arr_t *arr, int *elements, size_t num_of_elements);
void dynamic_arr_add_at(dynamic_arr_t *arr, size_t index, int element);
void del_dynamic_arr(dynamic_arr_t *arr);

#endif
