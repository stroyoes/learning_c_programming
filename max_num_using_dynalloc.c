#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr_len;

  printf("Enter number of elements in the array: ");
  
  if (scanf("%d", &arr_len) != 1) {
    printf("\nERROR: Wrong input given\n");
    return -1;
  }

  

  int *arr = (int *)malloc(sizeof(int) * arr_len);

  if (arr == NULL) {
    printf("\nERROR: Failed allocating array\n");
    return -1;
  }

  // Input the elements
  for (int i = 0; i < arr_len; i++) {
    printf("Enter element for position (%d) -> ", i);
    
    if (scanf("%d", (arr + i)) != 1) {
      printf("\nERROR: Wrong input given\n");
      return -1;
    }
  }

  // Get the max element 
  int largest = *arr; // Assumed to the first element at the beginning 

  for (int i = 1; i < arr_len; i++) {
    if (*(arr + i) > largest) {
      largest = *(arr + i); // Another max is found  
    }

  }

  printf("\nThe larget element is : %d\n", largest);
  
  // Free the dynamically allocated memory
  free(arr);

  return 0;
  
}
