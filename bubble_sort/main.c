#include "bubble_sort.h"

#include <stdio.h>

static inline void print_arr(int64_t *arr, uint32_t N) {
  printf("[");
  for (uint32_t i = 0; i < N; i++) {
    (i != 0) ? printf(", %" PRId64 " ", arr[i]) : printf(" %" PRId64 " ", arr[i]);
  }
  printf("]\n");
}

static inline fill_status_t fill_arr(uint32_t size, int64_t arr[size]) {
  printf("Enter the elements for the array: \n");

  for (uint32_t i = 0; i < size; i++) {
    printf(" Element %" PRIu32 " -> ", i);
    if (scanf("%" SCNd64, &arr[i]) != 1) {
      printf("\nERROR: Expected a sigend 64 bit integer, got something else. \n");
      return NOT_FILLED;
    }
  }
  return FILLED;
}

int main() {
  uint32_t size;

  printf("Enter the size of array: ");
  
  if (scanf("%" SCNu32, &size) != 1) {
    printf("\n ERROR: Expected an unsigend 32 bit integer, got something else. \n");
    return -1;
  }
  int64_t arr[size];

  fill_status_t fill_result = fill_arr(size, arr);

  if (fill_result == FILLED) {
    printf("\n Before bubble sort, currently the array is:  \n");
    print_arr(arr, size);

    bubble_sort(arr, size);
    
    printf("\n After bubble sort, the resultant array is: \n");
    print_arr(arr, size);
  } else {
    printf("\nERROR: Array didn't fill. No elements to sort. \n");
    return -1;
  }

}
