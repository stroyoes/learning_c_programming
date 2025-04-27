#include <stdio.h>
#include "sum_of_multiples.h"

int main() {
  // Example of factors and limit to calculate multiples' sum
  unsigned int factors[MAX_FACTORS] = {3, 5};  // Factors (e.g., multiples of 3 and 5)
  size_t number_of_factors = 2;  // Number of factors (3 and 5)
  unsigned int limit = 1000;  // Limit up to which multiples are considered

  // Calculate the sum of multiples
  unsigned int result = sum(factors, number_of_factors, limit);

  // Print the result
  printf("The sum of unique multiples of ");
  for (size_t i = 0; i < number_of_factors; i++) {
    printf("%u", factors[i]);
    if (i < number_of_factors - 1) {
      printf(" and ");
    }
  }
  printf(" below %u is: %u\n", limit, result);

  return 0;
}

