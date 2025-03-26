#include <stdio.h>

#include "complex_nums.h"

int main(void) {
    
    // Define two complex numbers
    complex_t num1 = {3.0, 4.0};   // 3 + 4i
    complex_t num2 = {1.0, -2.0};  // 1 - 2i

    // Perform operations
    complex_t sum = c_add(num1, num2);
    complex_t difference = c_sub(num1, num2);
    complex_t product = c_mul(num1, num2);
    complex_t quotient = c_div(num1, num2);
    double abs_value = c_abs(num1);
    complex_t conjugate = c_conjugate(num1);
    complex_t exp_value = c_exp(num1);

    // Print results
    printf("num1: %.2f + %.2fi\n", num1.real, num1.imag);
    printf("num2: %.2f + %.2fi\n\n", num2.real, num2.imag);

    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Difference: %.2f + %.2fi\n", difference.real, difference.imag);
    printf("Product: %.2f + %.2fi\n", product.real, product.imag);
    printf("Quotient: %.2f + %.2fi\n", quotient.real, quotient.imag);
    printf("Absolute value of num1: %.2f\n", abs_value);
    printf("Conjugate of num1: %.2f + %.2fi\n", conjugate.real, conjugate.imag);
    printf("Exponential of num1: %.2f + %.2fi\n", exp_value.real, exp_value.imag);

    return 0;
}

