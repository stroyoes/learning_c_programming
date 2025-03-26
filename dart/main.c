#include <stdio.h>

#include "darts.h"

static void show_err() {
  printf("\nERROR: Expected 2 float values as the coordinates.\n");
}

static void printArr(float* arr, int size_of_arr) {
  printf("[");
  for (int i = 0; i < size_of_arr; i++) {
    printf("%f", arr[i]);

    if (i < (size_of_arr - 1)) {
      printf(", ");
    }
  }
  printf("]");
}

int main() {
  uint8_t result;
  coordinate_t landing_position;

  printf("Enter the two coordinates: ");
  if (scanf("%f %f", &landing_position[0], &landing_position[1]) != 2) {
    show_err();
    return -1;
  }
  result = get_score(landing_position);

  printf("The dart hit at ");
  printArr(landing_position,2);
  printf(" . Your score is \"%hhu\".\n", result); //  NOTE: `uint8_t` is typically defined as `unsigned char`, 
                                                //        and the char type requires a special format specifier (%hhu) because 
                                                //        the regular %u is for `unsigned int`, 
                                                //        which typically has a larger size. 

  return 0;
}
