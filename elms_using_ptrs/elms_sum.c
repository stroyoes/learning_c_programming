#include "pptr_elms.h"

#include <stdio.h>

int get_sum_using_ptrs(int *arr, int size_of_arr) {
    int sum_of_elms = 0;
    
    for (int i = 0; i < size_of_arr; i++) {
	sum_of_elms += arr[i];
    }
    printf("The sum of elements of array: %d\n", sum_of_elms);

}
