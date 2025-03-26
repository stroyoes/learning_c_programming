#include "complex_nums.h"

#include <math.h>

complex_t c_add(complex_t a, complex_t b) {

  complex_t result = {0};
  
  result.real = a.real + b.real;
  result.imag = a.imag + b.imag;

  return result;
}

complex_t c_sub(complex_t a, complex_t b) {

  complex_t result = {0};

  result.real = a.real - b.real;
  result.imag = a.imag - b.imag;

  return result;
}

complex_t c_mul(complex_t a, complex_t b) {

  complex_t result = {0};

  result.real = a.real * b.real - a.imag * b.imag;
  result.imag = a.imag * b.real + a.real + b.imag;

  return result;
}

complex_t c_div(complex_t a, complex_t b) {

  complex_t result = {0};

  result.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
    result.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);

  return result;
}

double c_abs(complex_t x) {
  double complex_abs = sqrt(x.real * x.real + x.imag * x.imag);
  
  return complex_abs;
}

complex_t c_conjugate(complex_t x) {
  
  complex_t result = {0};

  result.real = x.real;
  result.imag = -1 * x.imag;
  
  return result;
}

double c_real(complex_t x) {
  return x.real;
}

double c_imag(complex_t x) {
  return x.imag;
}

complex_t c_exp(complex_t x) {

  complex_t result = {0};
  
  result.real = exp(x.real) * cos(x.imag);
  result.imag = exp(x.real) * sin(x.imag);

  return result;
}
