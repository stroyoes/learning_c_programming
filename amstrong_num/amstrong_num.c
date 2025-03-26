/**
 * An Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.
 * 
 * For example:
 *   - 9 is an Armstrong number, because 9 = 9^1 = 9
 *   - 10 is not an Armstrong number, because 10 != 1^2 + 0^2 = 1
 *   - 153 is an Armstrong number, because: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
 *   - 154 is not an Armstrong number, because: 154 != 1^3 + 5^3 + 4^3 = 1 + 125 + 64 = 190
 */

#include <stdio.h>
#include "amstrong_num.h"

Bool isAmstrongNum(int N) {
  int number_of_digits = get_number_of_digits(N);

  if (number_of_digits < 2) {
    return True;
  }
  
  int sum = 0;
  for (int i = N; i > 0; i /= 10) {
    
    int digit = i % 10;
    int k = 1;
    
    // Do exponentiation in inner loop
    for (int unusedVar = 0; unusedVar < number_of_digits; unusedVar++) {

      k *= digit;
    }
    sum += k; // Add those exponentiation values 
  }

  return sum == N; // Check if the sum of all the exponentiations is equal to the number 
}

int get_number_of_digits(int number) {
  int count = 0;

  while (number > 0) {
    number /= 10;
    ++count; //  NOTE: Used ++ as prefix so that there is no memory overhead
  }
  return count;
}

int main() {
  int number;

  printf("Enter the number to check: ");
  if (scanf("%d", &number) != 1) {
    printf("ERROR: Invalid input. Expected atleast one integer value. \n");
    return -1; // Non-zero value indicating an error 
  }

  if (isAmstrongNum(number)) {
    printf("The number \"%d\" is an amstrong number. \n", number);
  } else {
    printf("The number \"%d\" is not an amstrong number. \n", number);
  }

  return 0;

}
