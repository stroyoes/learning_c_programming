/**
 * Get the sum and average value of elements from an array.
 */ 

#include <stdio.h>

typedef const char* num_format_string;

int calculateSum(int *arr, unsigned int arr_size) {
  int sum = 0;

  for (unsigned int index = 0; index < arr_size; index++) {
    sum += arr[index];
  }
  return sum;
}

float calculateAvg(int sum, unsigned int total_elements) {
  return (float)sum / total_elements;
}

static num_format_string get_num_suffix(int N) {
  if (N % 10 == 1 && N != 11) {
    return "st";
  } else if (N % 10 == 2 && N != 12) {
    return "nd";
  } else if (N % 10 == 3 && N != 13) {
    return "rd";
  } else {
    return "th";
  }
  
}

int main() {
  unsigned int arr_size;

  // Let the user input the array size. After that the array wont change. 
  printf("Enter the size of the array: ");
  if (scanf("%u", &arr_size) != 1) {
    printf("\nExpected one positive integer. Got something else !\n");
    return -1;

  }

  int arr[arr_size]; //  NOTE: Variable Length Array (VLA) - An array data structure whose 
                     //        length is determined at runtime, instead of at compile time.

  // Let the user input the elements.
  printf("Enter %d element for the array: \n", arr_size);
  for (unsigned int index = 0; index < arr_size; index++) {
    printf("Enter the %d%s element: ",index, get_num_suffix(index));
    if (scanf("%d", &arr[index]) != 1) {
      printf("\nExpected one integer value. Got something else !\n");
      return -1;
    }
  }

  // Calculate Sum and Avg 
  int arr_sum = calculateSum(arr,arr_size);
  float arr_avg = calculateAvg(arr_sum, arr_size);

  // Print results
  printf("Results: \n Sum = %d\n", arr_sum);
  printf(" Average = %.2f\n", arr_avg);

  return 0;

}
