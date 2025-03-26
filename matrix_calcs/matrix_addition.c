#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define ROWS 3
#define COLS 3

void print_matrix(int32_t matrix[ROWS][COLS]) {

  for (uint32_t i = 0; i < ROWS; i++) {
    for (uint32_t j = 0; j < COLS; j++) {
      printf(" %" PRId32 " ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int32_t A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];

  // Get the matrix A from the user
  printf("Enter the elements for the matrix A:\n");
  for (uint32_t i = 0; i < ROWS; i++) {
    printf("Enter element for col: %" PRIu32 "\n", i);

    for (uint32_t j = 0; j < COLS; j++) {
      printf(" row: %" PRIu32 " -> ", j);

      if (scanf("%" PRId32, &A[i][j]) != 1) {
        printf("\nExpected a signed max 32 bit integer data. Got something else. \n");
        return -1;
      }
    }
  }

  // Get the matrix B from the user
  printf("Enter the elements for the matrix B:\n");
  for (uint32_t i = 0; i < ROWS; i++) {
    printf("Enter element for col: %" PRIu32 "\n", i);

    for (uint32_t j = 0; j < COLS; j++) {
      printf(" row: %" PRIu32 " -> ", j);

      if (scanf("%" PRId32, &B[i][j]) != 1) {
        printf("\nExpected a signed max 32 bit integer data. Got something else. \n");
        return -1;
      }
    }
  }

  // Do the addition
  for (uint32_t i = 0; i < ROWS; i++) {
    for (uint32_t j = 0; j < COLS; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }

  // Print the result
  printf("\nResultant matrix:\n");
  print_matrix(C);

  return 0;
}
