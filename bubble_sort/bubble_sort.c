#include "bubble_sort.h"

void bubble_sort(int64_t *arr, uint32_t N) {
  for (uint32_t i = 0; i < (N - 1); i++)
    for (uint32_t j = 0; j < (N - i - 1); j++)
      if (arr[j] > arr[j+1]) {

        int64_t temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;

      }
}


