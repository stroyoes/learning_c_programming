/**
 * Project Euler Problem 6:
 *
 * Find the difference between the sum of the squares of the first N natural numbers and
 * square of the sum of the N first natural numbers.
 * 
 * Explanation:
 * 
 * 1. Sum of the squares of the first N natural numbers can be found out mathematically as:
 *        
 *                                (N( N+1 )( 2N+1 )) / 6
 * 2. Square of the sum of first N natural numbers can be found out mathematically as:
 *
 *                                ((N(N+1)) / 2)^2
 * 3. So the difference would be (square of the sum - sum of the squares)
 * 
 * 4. Instead of iterating through numbers and calculating each term, we directly use 
 *    the formulas mentioned above to compute the result in O(1) time. 
 */

#include <stdio.h> 

unsigned long long sumSquareDiff(int N) {

  unsigned long long sum_of_squares = (N * (N+1) * (2 * N + 1)) / 6;

  unsigned long long sum = (N * (N+1)) / 2;
  unsigned long long square_of_sum = sum * sum;

  return (square_of_sum - sum_of_squares);

}

int main() {
  int N;

  printf("Enter the value of N: ");
  if (scanf("%d", &N) != 1) {
    printf("ERROR: Invalid input value of N. Expected one integer value. \n");
    return -1; // A non-zero value indicating an error 
  }

  unsigned long long result = sumSquareDiff(N);
  printf("The difference between the square of the sum and the sum of the squares for the first %d natural numbers is: %llu\n", N, result);

  return 0;
}



