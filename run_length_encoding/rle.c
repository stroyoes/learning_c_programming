#include "rle.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void append(char *result, char char_X, int count_X) {
  char buffer[MAX_TEMP_BUFFER_LEN] = {0}; //  NOTE:  The buffer to store "nX" where 'n' is 
                                          //  the number of time the character 'X' repeats

  if (count_X > 1) {
    sprintf(buffer, "%d%c", count_X, char_X);

  } else {
    sprintf(buffer, "%c", char_X);
  }

  strncat(result, buffer, MAX_BUFFER_LEN - strlen(result) - 1);
}

void encode(const char *const text, char result[MAX_BUFFER_LEN]) {
  result[0] = '\0'; // Cleat the buffer 

  int count = 0;
  char last = '\0';

  for (size_t i = 0; i < strlen(text); i++) {
    if (text[i] != last) {
      if (count > 0) {
        append(result, last, count);
      }
      last = text[i];
      count = 1;
    
    } else {
      count++;
    } 
  }

  if (count > 0) append(result, last, count); // Ensures the last group is also added 

} 

void decode(const char *const data, char result[MAX_BUFFER_LEN]) {
  result[0] = '\0'; // Clear the buffer
  size_t result_len = 0;

  for (size_t i = 0; i < strlen(data) && result_len < MAX_BUFFER_LEN - 1; i++) {
    int counter = 1;

    if (isdigit(data[i])) {
      sscanf(&data[i], "%d", &counter);
      while (isdigit(data[i])) i++; // Move 'i' to the character skipping the numbers 
    }

    for (int j = 0; j < counter && result_len < MAX_BUFFER_LEN - 1; j++) {
      result[result_len++] = data[i]; // Append the character 'n' number of times 
    }
  }

  result[result_len] = '\0';  // Null-terminate the string
}


