#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stdbool.h>
#include <stddef.h> // For `size_t` datatype 

#define MAX_FACTORS 20
#define MAX_MULTIPLES 10000

typedef struct {
  unsigned int elems[MAX_MULTIPLES]; // Array storing the multiples
  size_t size; // Tracks how many valid elements are in the set
} set_t;

/**
 * @brief Calculate the sum of all unique multiples of given factors below a limit.
 *
 * Given an array of factors, this function finds all multiples of each factor
 * that are less than the specified limit, removes duplicate multiples, and then
 * sums them up to return the final result.
 *
 * Factors equal to 0 are skipped as 0 is not a valid divisor.
 *
 * @param factors Array of base values to find multiples of.
 * @param number_of_factors Number of elements in the factors array.
 * @param limit Upper limit (non-inclusive) for multiples.
 * @return Sum of all unique multiples below the limit.
 */
unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit);

#endif // SUM_OF_MULTIPLES_H 



