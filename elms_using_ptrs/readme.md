# Practice Code: Pointer-Based Array Operations

## Overview
This practice code demonstrates basic operations on arrays using pointers in C. It includes:
- Printing elements of an array using pointer arithmetic.
- Calculating the sum of array elements using pointers.

## Files
- **`pptr_elms.h`**: Header file declaring the functions.
- **`main.c`**: Contains the main function and calls utility functions.
- **`pptr_elms.c`**: Implements functions for printing and summing array elements.

## Functions
### `void ptr_print_elms(int *arr, int size_of_arr);`
Prints the elements of an array using pointer arithmetic.

### `int get_sum_using_ptrs(int *arr, int size_of_arr);`
Computes and prints the sum of the elements of an array.

## Compilation & Execution
To compile and run the program:
```sh
gcc main.c pptr_elms.c -o program
./program
```

## Example Output
```
The array:
[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
The sum of elements of array: 55
```

## Notes
- Uses pointer arithmetic instead of standard indexing.
- Demonstrates modular programming with separate header and implementation files.
