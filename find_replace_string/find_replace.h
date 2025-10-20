#ifndef FIND_REPLACE_H
#define FIND_REPLACE_H

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

// Type definition (if needed later for passing structured data)
typedef char string_t[MAX_LEN];

// Function declaration
void find_and_replace(char *str, const char *old_word, const char *new_word);

#endif // FIND_REPLACE_H
