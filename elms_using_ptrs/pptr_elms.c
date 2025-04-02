#include "pptr_elms.h"

#include <stdio.h>

void ptr_print_elms(int *arr, int size_of_arr) {
    printf("[ ");
    for (int i = 0; i < size_of_arr; i++) {
	printf("%d", *(arr + i));
	(i < (size_of_arr - 1)) ? printf(", ") : printf(" ");
    }
    printf(" ]\n");

}

