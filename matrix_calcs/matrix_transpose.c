/**
 * Transpose a matrix using simple for loops.
 */ 

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define ROWS 10
#define COLS 10

int main() {
  int32_t matrix[ROWS][COLS], transpose[ROWS][COLS];
  uint32_t smaller_rows, smaller_cols;

  printf("Enter the number of rows: ");
  if (scanf("%" PRIu32, &smaller_rows) != 1) {
    printf("\nExpected an unsigned 32-bit long integer. Got something else !\n");
    return -1;
  }

  printf("Enter the number of cols: ");
  if (scanf("%" PRIu32,&smaller_cols) != 1) {
    printf("\nExpected an unsigned 32-bit long integer. Got something else !\n");
    return -1;
  }

  printf("Enter the elements for the matrix: \n");
  for (uint32_t i = 0; i < smaller_rows; i++) {
    printf("Elements for col: %" PRIu32 "\n", i);
    
    for (uint32_t j = 0; j < smaller_cols; j++) {
      printf(" row: %" PRIu32 " -> ",j);
      
      if (scanf("%" PRId32, &matrix[i][j]) != 1) {
        printf("\nExpected a signed 32-bit long integer. Got something else !\n");
        return -1;
      }
    }
    printf("\n");
  }

  // Print the current matrix
  printf("The matrix: \n");
  for (uint32_t i = 0; i < smaller_rows; i++) {
    for (uint32_t j = 0; j < smaller_cols; j++) {
      printf(" %" PRId32 " ", matrix[i][j]);
    }
    printf("\n");
  }



  // Lets transpose the matrix now
  for (uint32_t i = 0; i < smaller_rows; i++) {
    for (uint32_t j = 0; j < smaller_cols; j++) {
      transpose[j][i] = matrix[i][j];
    }
  }

  printf("The resultant matrix: \n");
  for (uint32_t i = 0; i < smaller_rows; i++) {
    for (uint32_t j = 0; j < smaller_cols; j++) {
      printf(" %" PRId32 " ", transpose[i][j]);
    }
    printf("\n");
  }

  return 0;

}

