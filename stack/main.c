#include <stdio.h>
#include <string.h>

#include "infix_postfix.h"

int main() {
  char infix[MAX_EXPR_LEN];
  char postfix[MAX_EXPR_LEN];

  printf("Enter infix expression (e.g., 3 + 4 * (2 - 1)):\n> ");
  fgets(infix, sizeof(infix), stdin);

  //  NOTE: strcspn: Returns the number of characters in str1 before the first occurrence of any character that appears in str2 
  infix[strcspn(infix, "\n")] = '\0'; // Remove new line or terminating the string at the first occurence of a new line char 

  infix_to_postfix(infix, postfix);
  printf("\nPostfix: %s\n", postfix);

  int result = evaluate_postfix(postfix);
  printf("Evaluated result: %d\n", result);

  return 0;
}

