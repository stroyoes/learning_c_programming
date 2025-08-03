#include <stdio.h>

#define MAX 20 

void display(int sparse[MAX][3], int num_of_rows) {
  printf("Row\tCol\tVal\n");
  for (int i = 0; i < num_of_rows; i++) {
    printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
  }
}

void print_matrix(int matrix[MAX][MAX], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}


void to_sparse(int matrix[MAX][MAX], int rows, int cols, int sparse[MAX][3], int *non_zs) {
  // Returns the number of non zero terms 

  int k = 0;

  // Add the two cols in header row 
  sparse[0][0] = rows;
  sparse[0][1] = cols;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] != 0) {
        k++;
        sparse[k][0] = i;
        sparse[k][1] = j;
        sparse[k][2] = matrix[i][j];
      }
    }
    }
    sparse[0][2] = k;
    *non_zs = k;
}

void transpose(int sparse[MAX][3], int tsp[MAX][3]) {
    tsp[0][0] = sparse[0][1];
    tsp[0][1] = sparse[0][0];
    tsp[0][2] = sparse[0][2];

    int k = 1; // Keeps the row index of result 
    int m = sparse[0][1]; // Num of cols in sparse matrix 
    int nz = sparse[0][2]; // Num of non-zero terms 
    
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < nz + 1; j++) {
            if (sparse[j][1] == i) {
                tsp[k][0] = sparse[j][1];
                tsp[k][1] = sparse[j][0];
                tsp[k][2] = sparse[j][2];
                k++;
            }
        }
    }
}

int add_sparse(int sp1[MAX][3], int sp2[MAX][3], int spr[MAX][3], int *non_zs) {
    if (sp1[0][0] != sp2[0][0] || sp1[0][1] != sp2[0][1]) {
        printf("Matrix dimensions do not match! Cannot perform addition! ");
        return -1; // Indicating an error has occured 
    }

    // Fill header row of result (except non-zero elements)
    spr[0][0] = sp1[0][0];
    spr[0][1] = sp1[0][1];

    // Variables pointing the matrices 
    int m = 1, n = 1, k = 1;
    for (int i = 0; i < sp1[0][0]; i++) {
        for (int j = 0; j < sp1[0][1]; j++) {
            if ((sp1[m][0] == i && sp1[m][1] == j) && (sp2[n][0] == i && sp2[n][1] == j)) {
                spr[k][0]  = sp1[m][0];
                spr[k][1] = sp1[m][1];
                spr[k][2] = (sp1[m][2] + sp2[n][2]);
                m++;n++;k++;
            } else if (sp1[m][0] == i && sp1[m][1] == j) {
                spr[k][0]  = sp1[m][0];
                spr[k][1] = sp1[m][1];
                spr[k][2] = sp1[m][2];
                k++;m++;
            } else if (sp2[n][0] == i && sp2[n][1] == j) {
                spr[k][0] = sp2[n][0];
                spr[k][1] = sp2[n][1];
                spr[k][2] = sp2[n][2];
                k++;n++;
            }
        }
    }
    spr[0][2] = k - 1;
    *non_zs = k - 1;
    return 0; // Just to know there was no error 
}

int main() {
    int r1, c1, r2, c2;
    int matrix1[MAX][MAX], matrix2[MAX][MAX];
    int sp1[MAX][3], sp2[MAX][3], tsp1[MAX][3], tsp2[MAX][3], sp_sum[MAX][3];
    int nz1, nz2, nz_sum;

    // Input the matrix sizes 
    printf("Enter the rows and cols of Matrix 1: \n");
    printf(" Rows: ");
    scanf("%d", &r1);
    printf(" Cols: ");
    scanf("%d", &c1);

    printf("Enter the rows and cols of Matrix 2: \n");
    printf(" Rows: ");
    scanf("%d", &r2);
    printf(" Cols: ");
    scanf("%d", &c2);

    // Iterate for elements
    printf("Enter elements for Matrix 1: \n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) {
            printf(" Element at (%d, %d): ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
      
    printf("Enter elements for Matrix 2: \n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++) {
            printf(" Element at (%d, %d): ", i, j);
            scanf("%d", &matrix2[i][j]);
        }

    // Display those normal matrices 
    printf("Matrix 1:\n");
    print_matrix(matrix1, r1, c1);

    printf("Matrix 2:\n");
    print_matrix(matrix2, r2, c2);

    // Convert to sparse form 
    to_sparse(matrix1, r1, c1, sp1, &nz1);
    int sp1_rows = nz1 + 1;

    to_sparse(matrix2, r2, c2, sp2, &nz2);
    int sp2_rows = nz2 + 1;

    // Display the sparse matrices 
    printf("Matrix 1 in tuple form: \n");
    display(sp1, sp1_rows);

    printf("\n");

    printf("Matrix 2 in tuple form: \n");
    display(sp2, sp2_rows);

    // Transpose the matrices 
    transpose(sp1, tsp1);
    transpose(sp2, tsp2);
    
    printf("Transpose of Matrix 1: \n");
    display(tsp1, sp1_rows);

    printf("\n");

    printf("Transpose of Matrix 2: \n");
    display(tsp2, sp2_rows);

    // Add the matrices 
    int result_flag = add_sparse(sp1, sp2, sp_sum, &nz_sum);
    int sp_sum_rows = nz_sum + 1;
    if (result_flag != -1) {
        printf("Sum of Matrix 1 and Matrix 2 is : \n");
        display(sp_sum, sp_sum_rows);
    }

    return 0;    	
}

/* 
Enter the rows and cols of Matrix 1:
 Rows: 3
 Cols: 3
Enter the rows and cols of Matrix 2:
 Rows: 3
 Cols: 3
Enter elements for Matrix 1:
 Element at (0, 0): 1
 Element at (0, 1): 0
 Element at (0, 2): 0
 Element at (1, 0): 0
 Element at (1, 1): 2
 Element at (1, 2): 0
 Element at (2, 0): 0
 Element at (2, 1): 0
 Element at (2, 2): 3
Enter elements for Matrix 2:
 Element at (0, 0): 0
 Element at (0, 1): 4
 Element at (0, 2): 0
 Element at (1, 0): 0
 Element at (1, 1): 0
 Element at (1, 2): 5
 Element at (2, 0): 6
 Element at (2, 1): 0
 Element at (2, 2): 0
Matrix 1:
1       0       0
0       2       0
0       0       3
Matrix 2:
0       4       0
0       0       5
6       0       0
Matrix 1 in tuple form:
Row     Col     Val
3       3       3
0       0       1
1       1       2
2       2       3

Matrix 2 in tuple form:
Row     Col     Val
3       3       3
0       1       4
1       2       5
2       0       6
Transpose of Matrix 1:
Row     Col     Val
3       3       3
0       0       1
1       1       2
2       2       3

Transpose of Matrix 2:
Row     Col     Val
3       3       3
0       2       6
1       0       4
2       1       5
Sum of Matrix 1 and Matrix 2 is :
Row     Col     Val
3       3       6
0       0       1
0       1       4
1       1       2
1       2       5
2       0       6
2       2       3
*/

