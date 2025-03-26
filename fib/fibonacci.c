#include "fibonacci.h"

void generate_fibs(int N, uint64_t *fib) {
  if (N <= 0) return;

  fib[0] = 1;
  fib[1] = 1;

  for (int i = 2; i < N; ++i) {
    fib[i] = fib[i - 2] + fib[i - 1];
    
  }
}


