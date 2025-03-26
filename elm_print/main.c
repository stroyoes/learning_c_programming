#include "elm_print.h"

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int main() {
  uint16_t oned_arr_size, col_size, row_size;

  printf("\n One d array \n");

  printf("Enter the size of one D array: ");
  if (scanf("%" SCNu16, &oned_arr_size) != 1) {
    printf("\nERROR: Expected a unsigned 16bit integer argument. Got something else !\n");
    return -1; //  NOTE: Non zero value returned indicating an error 
  }

  int oned_arr[oned_arr_size];

  printf("Enter the elements: \n");
  for (uint16_t i = 0; i < oned_arr_size; i++) {
    printf(" At Index %" PRIu16 " -> ", i);
    if (scanf("%d", &oned_arr[i]) != 1) {
      printf("\nERROR: Expected an integer argument. Got something else !\n");
      return -1;
    }

  }

  printf("\nResultant one d array: \n");
  print_1d_arr(oned_arr, oned_arr_size);

  printf("\n Two d array \n");

  printf("Enter row and col size for 2d array: ");
  if (scanf("%" SCNu16 " %" SCNu16, &row_size, &col_size) != 2) {
    printf("\nERROR: Expected 2 integer arguments. Got something else !\n");
    return -1;
  }

  int twod_arr[row_size][col_size];

  for (uint16_t i = 0; i < row_size; i++) {
    for (uint16_t j = 0; j < col_size; j++) {
      printf(" At Position (%" PRIu16 ", %" PRIu16 ") -> ", i,j);
      if (scanf("%d", &twod_arr[i][j]) != 1) {
        printf("\nERROR: Expected an integer argument. Got something else !\n");
        return -1;
      }
    }
  }

  printf("\nResultant two d array: \n");
  print_2d_arr(col_size, row_size, twod_arr);
}

