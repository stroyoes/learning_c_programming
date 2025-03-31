#include "concat_strings.h"

#include <stdio.h>

int main() {
  char str1[] = "Hello, ";
  char str2[] = "World!";
  char str3[MAX_STR_LEN];  // Ensure enough space for concatenation
  
  str_concat(str1, str2, str3);
  
  printf("Concatenated String: %s\n", str3);

  return 0;
}
