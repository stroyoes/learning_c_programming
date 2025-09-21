#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Generic linear search
void* gen_linear_search(void *arr, int N, int one_elm_size, void* seen, bool (*predicate)(const void *param1, const void *param2)) {
    char *base = (char *)arr; // lets treat the array as bytes so that when incremented we move one byte at a time 
    // base always points to first byte of the array

    for (int i = 0; i < N; i++) {
        void *elm = base + i * one_elm_size;
        // for example if our array is of int one_elm_size = 4
        // Then, if arr = [1, 2, 3, 4]:
        // In the first loop (i = 0): elm = base + 0*4 -> points to arr[0] (value 1)
        // In the second loop (i = 1): elm = base + 1*4 -> points to arr[1] (value 2) 
        // and so on ...
        
        if (predicate(elm, seen)) {
            return elm;
        }

    }
    return NULL;
}

// Define predicate funcs for int, string and character 
bool pred_int(const void* a, const void* b) {
    return (*(int*)a == *(int*)b);
}

bool pred_char(const void* a, const void* b) {
    return (*(char*)a == *(char*)b);
}

bool pred_str(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b) == 0;
}

int main() {
    // Integers
    int arr_int[] = {10, 20, 30, 40, 50};
    int key_int = 30;
    int* found_int = (int*) gen_linear_search(arr_int, 5, sizeof(int), &key_int, pred_int);
    if (found_int) printf("Found int: %d\n", *found_int);

    // Characters
    char arr_char[] = {'a', 'b', 'c', 'd'};
    char key_char = 'c';
    char* found_char = (char*) gen_linear_search(arr_char, 4, sizeof(char), &key_char, pred_char);
    if (found_char) printf("Found char: %c\n", *found_char);

    // Strings
    const char* arr_str[] = {"apple", "banana", "cherry"};
    const char* key_str = "banana";
    char** found_str = (char**) gen_linear_search(arr_str, 3, sizeof(char*), &key_str, pred_str);
    if (found_str) printf("Found string: %s\n", *found_str);

    return 0;
}

/*
Output
------

Found int: 30
Found char: c
Found string: banana
*/
