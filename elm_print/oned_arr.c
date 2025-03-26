#include "elm_print.h" 

#include <stdio.h>

void print_1d_arr(int *oned_arr, uint16_t size_of_arr) {
  printf("[");
  for (uint16_t i = 0; i < size_of_arr; i++) {
    printf("%d", oned_arr[i]);
    (i < (size_of_arr - 1)) ? printf(", ") : printf(" ");;

  }
  printf("]\n");
}
