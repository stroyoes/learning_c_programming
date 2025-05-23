#include <stddef.h>
#include <stdio.h>

#include <string.h>
#include <stdlib.h>

#include "elm_to_front.h"

// Allocated memory for a dynamic array 
void init_dynamic_arr(dynamic_arr_t *arr, size_t initial_size, const char *desc) {
  arr->arr = (int *)malloc(sizeof(int) * initial_size);
  arr->arr_size = 0;

  arr->allocated_arr_size = initial_size;

  // Add the description of array 
  strncpy(arr->desc, desc, sizeof(arr->desc) - 1);
  arr->desc[sizeof(arr->desc) - 1] = '\0'; // Null terminate the string 

}

void print_dynamic_arr(dynamic_arr_t *arr) {

  printf("\nThe array and its info : ( arr = {");
  for (size_t i = 0; i < arr->arr_size; i++) {
    printf("%d", arr->arr[i]);

    if (i < arr->arr_size - 1) { printf(", "); }
  }
  printf("}, arr_size = %zu, allocated_arr_size = %zu, desc = %s )\n", arr->arr_size, arr->allocated_arr_size, arr->desc);
}

void resize_dynamic_arr(dynamic_arr_t *arr, size_t new_alloc_size) {
  int *new_arr = (int *)realloc(arr->arr, new_alloc_size * sizeof(int));

  if (new_arr == NULL) {
    printf("\nERROR: Failed allocating array !\n"); 
    return; 
  }

  arr->arr = new_arr;
  arr->allocated_arr_size = new_alloc_size;
}

// Adds elements normally to a dynamic array 
void dynamic_arr_add(dynamic_arr_t *arr, int element) {
  if (arr->arr_size >= arr->allocated_arr_size) {
    resize_dynamic_arr(arr, arr->allocated_arr_size * 2); // Double the size 
  }

  arr->arr[arr->arr_size++] = element; // Add element to the last of an array 
}

// Add more than one elements to the end of an array
void dynamic_arr_add_many(dynamic_arr_t *arr, int *elements, size_t num_of_elements) {

  for (size_t i = 0; i < num_of_elements; i++) {
    dynamic_arr_add(arr, elements[i]); // Add each element to the end of the dynamic array 
  }
}

// Add at a specific place 
void dynamic_arr_add_at(dynamic_arr_t *arr, size_t index, int element) {

  if (index > arr->arr_size) {
    printf("\nERROR: Inserting index cannot be greater than size of array !\n");
    return;
  }
  
  // If index is same as the length 
  if (index == arr->arr_size) {
    dynamic_arr_add(arr, element); // Add to end 
    return; 
  }
  
  // Resize if needed for more space 
  if (arr->arr_size + 1 >= arr->allocated_arr_size) {
    resize_dynamic_arr(arr, arr->allocated_arr_size * 2); // Double the size 
  }

  // Shift element from the position index to the end of array 
  for (size_t i = arr->arr_size; i > index; i--) {
    arr->arr[i] = arr->arr[i - 1]; // Shift element from position n-1 to n except less than index 
  }

  // Insert element at that index 
  arr->arr[index] = element;
  arr->arr_size++;
}

void del_dynamic_arr(dynamic_arr_t *arr) {
  if (arr == NULL) { return; }

  // As defined as stack in main function 
  free(arr->arr); // Free the inner array 
  arr->arr = NULL; // Ensure safety  
}
