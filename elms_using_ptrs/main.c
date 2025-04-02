#include "pptr_elms.h"

#include <stdio.h>

int main() {
   const int ARR_SIZE = 10;

   // Make the array using for loop
   int arr[ARR_SIZE];  
   for (int i = 0; i < ARR_SIZE; i++) {
	arr[i] = (i + 1);
   }

   printf("\nThe array: \n");
   ptr_print_elms(arr, ARR_SIZE);
   
   get_sum_using_ptrs(arr, ARR_SIZE);

   return 0;

}
