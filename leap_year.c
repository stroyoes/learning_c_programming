/** 
 * To determine whether the given year is a leap year. 
 * 
 *  NOTE: A leap year (in the Gregorian calendar) occurs: 
 *          - In every year that is evenly divisible by 4.
 *          - Unless the year is evenly divisible by 100, in which case it's only a leap year 
 *            if the year is also evenly divisible by 400.  
 */ 

#include <stdio.h>

#define Bool int
#define False 0
#define True 1 

/**
 * Checks if an year is a leap year .
 *
 * @param {int} year - The year to check for. 
 * @returns {Bool} A boolean value (True or False as 1 or 0 (integers) respectively)
 * 
 * @example 
 * Bool result = isLeapYear(1997); // Not a leap year as not divisible by 4 
 */ 
Bool isLeapYear(int year) {
  if (year < 1) {
    printf("ERROR: Invalid year \"%d\" . Year cannot be less than 1. \n",year);
    return -1;
  }

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return True;
  } else {
    return False;
  }
}

int main() {
  int year;

  printf("Program to check for leap year ... 🚀 \n");

  printf("Enter the year to check for: ");
  if (scanf("%d", &year) != 1) {
    printf("ERROR: Invalid input year . Expected atleast one integer year. \n");
    return -1; // Non-zero value indicating an error 
  }

  Bool result = isLeapYear(year);
  
  if (result == -1) {
  
    return -1;

  } else if (result) {
    printf("👍 \"%d\" is a leap year !\n",year);
  
  } else {
    printf("👎 \"%d\" is not a leap year!\n",year);
  }

  return 0;
}

