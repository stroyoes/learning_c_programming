#include <stdio.h>

#include "swappers.h"

void ptr_swap(int *a, int *b) {

  int temp = *a; //  NOTE: Can assign a ptr variable to a normal variable but 
                 //        NOT the other way around. (This is called dereferencing a pointer)
  *a = *b;

  *b = temp;
}

void noptr_swap(int a, int b) {

  int temp = a;

  a = b;

  b = temp;

  printf("Swapped happened inside the function: a = %d, b = %d\n", a, b);
}
