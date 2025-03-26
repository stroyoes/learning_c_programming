#include <stdio.h>
#include "fibonacci.h"

int main() {
  int N;

  uint64_t fib[1000];

  printf("Enter the value till you need the fib sequence: ");
  if (scanf("%d", &N) != 1) {
    printf("\nInvlaid input. Expected one integer value.\n");
  }

  generate_fibs(N, fib);

  printf("[ ");
  for (int i=0; i < N; i++) {

    printf(", %jd", (intmax_t)fib[i]);
  }
  printf(" ]\n");

  return 0;
}
