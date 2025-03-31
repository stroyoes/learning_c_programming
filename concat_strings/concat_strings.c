#include "concat_strings.h"

void str_concat(char *str1, char *str2, char newstr[MAX_STR_LEN]) {
  // Copy str1 to result
  while (*str1) {
    *newstr = *str1;
    newstr++;
    str1++;

  }

  // Copy str2 to result
  while (*str2) {
    *newstr = *str2;
    newstr++;
    str2++;
  }

  *newstr = '\0';
}
