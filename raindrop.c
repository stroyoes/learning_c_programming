/**
 * Raindrops is a slightly more complex version of the FizzBuzz challenge, a classic interview question.
 * 
 * The task is to convert a number into its corresponding raindrop sounds.
 * If a given number:
 *    - is divisible by 3, add 'Pling' to the result.
 *    - is divisible by 5, add 'Plang' to the result.
 *    - is divisible by 7, add 'Plong' to the result.
 *    - not divisible by 3,5 or 7, the result should be the number of as a string. 
 * 
 * Examples:
 *    - 28 is divisible by 7, but not 3 or 5, so the result would be 'Plong'.
 *    - 30 is divisible by 3 and 5, but not 7, so the result would be 'PlingPlang'.
 *    - 34 is not divisible by 3, 5, or 7, so the result would be '34'.
 * 
 */

#include <stdio.h>
#include <string.h>

#define Bool int 
#define True 1
#define False 0

/**
 * Checks if the number is divisible by 3,5 or 7 and stores the necessary sound. 
 *
 * @param {int} N - The number to check divisibilty.
 * @returns {void} 
 *
 * @example 
 * raindropSound(105); // Since 105 is divisible by 3,5 and 7 it prints "PlingPlangPlong"
 */
void raindropSound(int N) {
  char result[50] = ""; // The buffer to hold the result 
  Bool isWritten = False;

  if (N % 3 == 0) {
    isWritten = True;
    strcat(result, "Pling");
  }
  if (N % 5 == 0) {
    isWritten = True;
    strcat(result, "Plang");
  }
  if (N % 7 == 0) {
    isWritten = True;
    strcat(result, "Plong");
  }

  if (!isWritten) {
    sprintf(result, "%d", N);
    isWritten = True;
  }

  printf("%s\n", result);
}

int main() {
  int N;

  printf("Enter a number: ");
  if (scanf("%d", &N) != 1) {
    printf("ERROR: Invalid input. Expected atleast one integer value. \n");
    return -1; // Non-zero value indicating an error 
  } 

  raindropSound(N);

  return 0;
}

