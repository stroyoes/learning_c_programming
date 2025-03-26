#include <stdio.h>

#include "swappers.h"

int main() {
  int x = 10, y = 20;

  printf("Before swapping: x = %d, y = %d\n", x, y);

  printf("\nNo pointer swapping: \n");
  noptr_swap(x, y);

  printf("\nPointer swapping: \n");
  ptr_swap(&x, &y);
  printf("Swapped happened outside the function: a = %d, b = %d\n", x, y);


}
