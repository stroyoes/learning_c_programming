#include "reverse_string.h"

int get_str_len(const char *str) {
  int count = 0;
  for (int i = 0; i < MAX_STR_LEN; i++) {
    if (*(str + i) == '\0') {
      return count;
    }
    count++;
  }
  return count;
}

void rev_str(const char *str, char newstr[MAX_STR_LEN]) {
  int str_len = get_str_len(str);

  for (int i = 0; i < str_len; i++) {
    newstr[i] = str[str_len - 1 - i];
  }
  newstr[str_len] = '\0';  // Null-terminate the reversed string
}
