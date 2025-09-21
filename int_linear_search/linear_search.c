#include <stdio.h>
#include <stdlib.h>

int linear_search(int *arr, int N, int target) {
    for (int i = 0; i < N; i++) {
        if (*(arr + i) == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int no_of_terms, target;

    printf("Enter the number of terms: ");
    scanf("%d", &no_of_terms);

    // Allocate memeory for the int array 
    int *user_arr = (int *)malloc(no_of_terms * sizeof(int));

    if (!user_arr) {
        printf("\nERROR: Memory allocation failed!\n");
        return -2;
    }

    printf("Enter %d elements: ", no_of_terms);
    for (int i = 0; i < no_of_terms; i++) {
        scanf("%d", (user_arr + i));
    }

    printf("Enter target element: ");
    scanf("%d", &target);

    int result = linear_search(user_arr, no_of_terms, target);
    if (result != -1) {
        printf("\nElement found at: %d\n", result);
    } else {
        printf("\nElement not found!\n");
    }

    // free the array 
    free(user_arr);

    return 0;

}

/*
Output
------
Case-1:
------

Enter the number of terms: 3
Enter 3 elements: 1 2 3
Enter target element: 2

Element found at: 1

Case-2:
------

Enter the number of terms: 2
Enter 2 elements: 1 2
Enter target element: 3

Element not found!
*/