/**
 * Find the multiplication of two matrices using the Tradititional or Naive method. 
 * 
 * Given two matrices of order M x N and N x P matrix multiplication is defined as:
 *                         C = A X B , where C has order M x P 
 * Each element in matrix C is computed as:
 *                         C[i][j] = ∑ [k-1, k=0] (A[i][k] X B[k][j]) (Here 0-based indexing is assumed and 
 *                                                                     that is why summation range is from 0 to k-1)
 * Time Complexity of the Naïve Algorithm:
 * For an N X N matrix, this results in O(N^3) operations because there are N^2 elements in the result matrix
 * and each requires N multiplications.
 */ 

#include <stdio.h>

#define MAX_ROWS 20
#define MAX_COLS 20

void print_matrix(int rows, int cols, int M[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf(" %d ", M[i][j]);
    }
    printf("\n");
  }
}

int get_matrix_dimensions(const char* name, int *rows, int *cols) { //  NOTE: Here rows, cols are pointers to integers 
                                                                    //  and name is a string or character array
  printf("Enter the number of rows for matrix %s: ", name);
  if (scanf("%d", rows) != 1) {
    printf("\nExpected an integer. Got something else!\n");
    return -1;
  }

  printf("Enter the number of cols for matrix %s: ", name);
  if (scanf("%d", cols) != 1) {
    printf("\nExpected an integer. Got something else!\n");
    return -1;
  }
  return 0;
}

int fill_matrix(int rows, int cols, int M[rows][cols]) {
  printf("Enter the elements for matrix:\n");
  for (int i = 0; i < rows; i++) {
    printf("Element for : \n");

    for (int j = 0; j < cols; j++) {
      printf(" row: %d, col: %d -> ", i,j);

      if (scanf("%d", &M[i][j]) != 1) {
        printf("\nExpected an integer. Got something else!\n");
        return -1;
      }
    }
  }
  return 0;
}

void multiply_matrices(int rows_A, int cols_A, int rows_B, int cols_B, int A[rows_A][cols_B], int B[rows_B][cols_B], int C[rows_A][cols_B]) {

  for (int i = 0; i < rows_A; i++) {
    
    for (int j = 0; j < cols_B; j++) {
      
      C[i][j] = 0; //  NOTE: Fill all the position in resultant matrix with 0

      for (int k = 0; k < cols_A; k++) {

        C[i][j] += A[i][k] * B[k][j];
      } 
    }
  }
}

int main() {
  int A[MAX_ROWS][MAX_COLS], B[MAX_ROWS][MAX_COLS], C[MAX_ROWS][MAX_COLS], rows_A, cols_A, rows_B, cols_B;

  if (get_matrix_dimensions("A", &rows_A, &cols_A) == -1) //  NOTE: Gets the memory address of rows_A and passes it 
                                                          //  to get_matrix_dimensions() 
    return -1;

  if (fill_matrix(rows_A, cols_A, A) == -1) //  NOTE: Fill matrix A with values   
    return -1;

  printf("\nMatrix A:\n");
  print_matrix(rows_A, cols_A, A);

  if (get_matrix_dimensions("B", &rows_B, &cols_B) == -1)
    return -1;

  if (fill_matrix(rows_B, cols_B, B) == -1)
    return -1;

  printf("\nMatrix B:\n");
  print_matrix(rows_B, cols_B, B);

  // Do the multiplication
  multiply_matrices(rows_A, cols_A, rows_B, cols_B, A,B,C);

  printf("\nThe resultant matrix: \n");
  print_matrix(rows_A, cols_B, C);

  return 0;
}
