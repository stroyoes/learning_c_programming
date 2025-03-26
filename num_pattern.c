#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
  //  NOTE: Using 8-bit unsigned integer (0 -> 255).
  uint8_t n = 4;
  
  printf("Resultant pattern: \n");
  for (uint8_t oi = 1; oi <= n; oi++) {
    for (uint8_t ii = 1; ii <= oi; ii++) {
      printf("%" PRIu8, ii);

    }
    printf("\n");
  }
  return 0;
}
