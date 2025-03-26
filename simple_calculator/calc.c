/**
 * A simple calculator that can do the following operations between two numbers : addition, subtraction, division,
 * mulitplication, remainder (modulo), floor division. 
 */ 

#include <math.h>

#include "calc.h"

/**
* Adds to numbers . 
 *
* Now what is addition ... 🤔 ? 
 *
 * "Addition" is one of the four fundamental operations in arithmetic, alongside subtraction, multiplication, and division. 
 * It involves combining two or more numbers or quantities to produce a total or sum. For example, adding 2 and 3 results in 5.
 * In mathematical notation, addition is typically represented by the plus sign ("+"). 
 * The numbers being added are called addends, and the result is known as the sum.
 * For instance, in the expression 2 + 3 = 5, 2 and 3 are addends, and 5 is the sum.
 * Addition possesses several key properties:
 *  - Commutative Property: The order of the addends does not affect the sum. That is, a + b = b + a.
 *  - Associative Property: When adding three or more numbers, 
 *                          the grouping of the addends does not change the sum. For example, (a + b) + c = a + (b + c).
 *  - Identity Property: Adding zero to any number does not change its value. That is, a + 0 = a.
 *  
 * The operation is both precise and universal, ensuring that no matter where you 
 * are in the universe, 2 + 3 will always yield 5. 😁 
 *
 * @param {double} a - The first number 
 * @param {double} b - The second number
 * @returns {double} Result of a added to b 
 *
 * @example
 * double result = add(2.3, 4);
 */ 
double add(double a, double b) {
  return a + b; 
}

double subtract(double a, double b) {
  return a - b;
}

double multiply(double a, double b) {
  return a * b;
}

double divide(double a, double b) {
  if (b != 0) {
    return a / b; 
  } else {
    return DIVISION_BY_ZERO; 
  }
}

double floor_division(double a, double b) {
    if (b != 0) {
      return floor(a / b);
    } else {
      return DIVISION_BY_ZERO;
  }
}

double remainder(double a, double b) {
  if (b != 0) {
    return fmod(a, b);
  } else {
    return DIVISION_BY_ZERO;
  }
}

double power(double a, double b) {
  return pow(a, b);
}
