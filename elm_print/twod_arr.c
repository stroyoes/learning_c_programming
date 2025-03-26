#include "elm_print.h"

#include <stdint.h>
#include <stdio.h>

void print_2d_arr(uint16_t col_size, uint16_t row_size, int twod_arr[row_size][col_size]) {
  for (uint16_t i = 0; i < row_size; i++) {
    for (uint16_t j = 0; j < col_size; j++) {
      printf(" %d ", twod_arr[i][j]);
    }
    printf("\n");
  }
}


