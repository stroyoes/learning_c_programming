/**
 * Linear search is a very simple search algorithm and straight forward approach to find an element from an array.
 */ 

#include <stdio.h>

typedef int Index;
typedef int Element; 

typedef struct {
  Element arr[100]; // Statically allocated array (change size as needed)
  int size; // Stores the actual number of elements
} Array;

/**
 * Function to perform linear search of element
 */ 

Index linearSearch(Array a, Element key) {
  for (Index i = 0;i < a.size; i++ ) {
    if (a.arr[i] == key) 
      return i; // Found element that return the con
  }
  return -1;
}

/**
 * Function to print array
 */ 
void printArr(int* arr, int size_of_arr) {
  printf("[");

  for (int i = 0; i < size_of_arr; i++) {
    printf("%d", arr[i]);

    if (i < (size_of_arr - 1))
      printf(", ");
  }
  printf("]");

}

int main() {
  Array arr;
  Index idx;
  Element key;

  printf("Enter the number of elements: ");
  scanf("%d", &arr.size);

  printf("Enter %d elements: ", arr.size);
  for (idx = 0; idx < arr.size; idx++) {
    scanf("%d", &arr.arr[idx]);
  }

  printf("Enter the element to search: ");
  scanf("%d", &key);

  Index result = linearSearch(arr, key);

  if (result != -1)
    printf("Element found at index %d\n", result);
  else 
    printf("Element not found\n");

  return 0;
}



