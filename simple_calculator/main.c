#include <math.h>
#include <stdio.h>

#include "calc.h"

static void show_err(int err_type) {
  (err_type == -1) ? printf("\nERROR: Expected 3 values: a float, a character and again a float.\n") : 
  (err_type == -2) ? printf("\nERROR: Invalid operator. \n") :
  printf("\nDANGER: Invalid error type, only -1 and -2 are supported.\n");
}

int main() {
  double num_1, num_2, result;
  char oprt;

  printf("\nA simple calculator\n\nThis program can calculate :\n- Addition (+)\n- Subtraction (-)\n- Division (/)\n- Mulitplication (*)\n- Remainder or Modulo (%%)\n- Floor division (F)\n- Exponentiation (^)\n");

  printf("Enter an arithmetic expression (e.g, 5 + 3) \n> ");
  if (scanf("%lf %c %lf", &num_1, &oprt, &num_2) != 3) {
    show_err(-1);
    return -1;
  }

  switch (oprt) {

    case '+':
      result = add(num_1,num_2);
      break;
    
    case '-':
      result = subtract(num_1,num_2);
      break;

    case '/':
      result = divide(num_1, num_2);
      break;

    case '*':
      result = multiply(num_1, num_2);
      break;

    case '%':
      result = remainder(num_1, num_2);
      break;

    case 'F':
      result = floor_division(num_1, num_2);
      break;
    
    case '^':
      result = power(num_1,num_2);
      break;

    default: 
      show_err(-2);
      return -1;
  }

  printf("Result: %.2lf \n", result);
  return 0;
}
