#include "reverse_string.h"

#include <stdio.h>
#include <string.h>

int main() {
  char a_string[MAX_STR_LEN]; // An array of characters
  char reverse_string[MAX_STR_LEN];

  printf("Enter a string: ");
  if (fgets(a_string, MAX_STR_LEN, stdin)) {
      a_string[strcspn(a_string, "\n")] = '\0';  // Remove trailing newline if present and replace with null character
  }

  rev_str(a_string, reverse_string);

  printf("\nResults: \n The number of charcs in the string: %d\n The reverse of the string: %s\n", get_str_len(a_string), reverse_string);
  
}