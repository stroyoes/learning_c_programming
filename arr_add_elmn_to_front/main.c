#include "elm_to_front.h"

int main() {
  // Create and initialize the array
  dynamic_arr_t my_arr;
  init_dynamic_arr(&my_arr, 4, "Sample Dynamic Array");

  // Add elements to the array
  dynamic_arr_add(&my_arr, 10);
  dynamic_arr_add(&my_arr, 20);
  dynamic_arr_add(&my_arr, 30);

  // Print the results 
  print_dynamic_arr(&my_arr);

  // Add an element at a specific index
  dynamic_arr_add_at(&my_arr, 1, 15);  // Should insert 15 between 10 and 20
  
  // Print the arr 
  print_dynamic_arr(&my_arr);

  // Add multiple elements
  int new_elements[] = {40, 50, 60};
  dynamic_arr_add_many(&my_arr, new_elements, 3);  // Appends [40, 50, 60]

  // Print the array
  print_dynamic_arr(&my_arr);

  // Free the memory
  del_dynamic_arr(&my_arr);

  return 0;
}

