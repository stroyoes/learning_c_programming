#include <stdio.h>
#include <stdlib.h>

#define Bool int
#define False 0
#define True 1

Bool inArray(int size, int element) {
    // Arguments: Size and Element to look for

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return False;
    }

    // Initialize array with values
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; // Dynamic initialization
    }

    // Check if the element is in the array
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            free(arr);  // Free the allocated memory
            return True;
        }
    }

    free(arr);  // Free the allocated memory
    return False;
}

int main() {
    int lenArr, element;
    Bool result;

    printf("Check if an element is in an array .... \n");

    printf("Enter the size of the array: ");
    scanf("%d", &lenArr);

    printf("Enter the element to check for: ");
    scanf("%d", &element);

    result = inArray(lenArr, element);

    if (result) {
        printf("The element \"%d\" is in the array.\n", element);
    } else {
        printf("The element \"%d\" is not in the array.\n", element);
    }

    return 0;
}

