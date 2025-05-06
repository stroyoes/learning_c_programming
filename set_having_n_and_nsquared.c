// A special set in which for every n there exists a unique n^2 

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

int main() {
  int set_len;

  printf("Enter number of elements in the set: ");

  if (scanf("%d", &set_len) != 1) {
    printf("\nERROR: Wrong input given\n");
    return -1;
  }

  int *arr = (int *)malloc(sizeof(int) * set_len * 2); // For accomodating the square elements too 

  if (arr == NULL) {
    printf("\nERROR: Failed allocating array\n");
    return -1;
  }

  // Input the elements
  for (int i = 0; i < set_len * 2; i += 2) {

    printf("Enter element for position (%d) -> ", (i / 2));

    if (scanf("%d", (arr + i)) != 1) {
      printf("\nERROR: Wrong input given\n");
      free(arr);
      return -1;
    }

    *(arr + i + 1) = *(arr + i) * *(arr + i); // Add square of element at i th position to j = (i + 1) th position  

  }

  // Display the set 
  printf("The resultant set: (");

  for (int i = 0; i < set_len * 2; i ++) {
    printf(" %d ", *(arr + i));
  }
  printf(")\n");

  free(arr);
}
