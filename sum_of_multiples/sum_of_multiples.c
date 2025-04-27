#include "sum_of_multiples.h"

/**
 * @brief Initialize a set with all multiples of a given factor below a limit.
 *
 * This function generates all non-negative multiples of a given factor
 * that are less than the specified limit and stores them into the provided set.
 * 
 * Multiples are added sequentially until either:
 * - The next multiple would exceed the limit, or
 * - The set reaches its maximum allowed size (MAX_MULTIPLES).
 *
 * @param factor The base number to generate multiples of.
 * @param limit Upper limit (non-inclusive) for the multiples.
 * @param multiples Pointer to the set where the multiples will be stored.
 */
static void init_set_of_multiples(const unsigned int factor, const unsigned int limit, set_t *multiples) {
  unsigned int multiple = 0;

  while (multiple < limit && multiples->size < MAX_MULTIPLES) {
    multiples->elems[multiples->size++] = multiple;
    multiple += factor;
  }

}

/**
 * @brief Check if an element exists in a set.
 *
 * @param set Pointer to the set to search.
 * @param elem Element to look for.
 * @return true if element exists in the set, false otherwise.
 */ 
static bool elem_exists(const set_t *set, unsigned int elem) {
  for (size_t i = 0; i < set->size; i++) {
    if (set->elems[i] == elem) {
      return true; // Element found
    }
  }
  return false; // Element not found 
}

/**
 * @brief Create a union of multiple sets, adding only unique elements.
 *
 * This function takes multiple sets and merges them into a single union set.
 * Duplicate elements are not added — only unique elements across all input sets
 * are included in the resulting union set.
 *
 * @param sets Array of sets to merge.
 * @param number_of_sets Number of sets in the array.
 * @param union_set Pointer to the set where the union result will be stored.
 */
static void union_of_sets(const set_t *sets, const size_t number_of_sets, set_t *union_set) {
  for (size_t i = 0; i < number_of_sets; i++) {
    for (size_t j = 0; j < sets[i].size; j++) {
      if (!elem_exists(union_set, sets[i].elems[j])) {
        union_set->elems[union_set->size++] = sets[i].elems[j]; // Add unique element to the union set.
      }
    }
  }
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit) {
  size_t multiples_size = 0;
  set_t multiples[MAX_FACTORS] = {0}; // Array to store sets of multiples for each factor

  for (size_t i = 0; i < number_of_factors; i++) {
    if (factors[i] == 0) {
      continue; // If factor is 0 (invalid), skip it (because 0 is not a valid divisor)
    }
    init_set_of_multiples(factors[i], limit, &multiples[i]); // Initialize set of multiples for this factor
    multiples_size++; // Increase count of sets created
  }
  set_t unique_multiples = {0};

  union_of_sets(&multiples[0], multiples_size, &unique_multiples);
  unsigned int sum_of_multiples = 0;

  for (size_t i = 0; i < unique_multiples.size; i++) {
    sum_of_multiples += unique_multiples.elems[i];

  }
  return sum_of_multiples;
}
