#include "find_replace.h"

void find_and_replace(char *str, const char *old_word, const char *new_word) {
    char result[MAX_LEN];
    int i = 0, j = 0;
    int old_len = strlen(old_word);
    int new_len = strlen(new_word);

    while (str[i] != '\0') {
        // Check if old_word matches at position i
        if (strncmp(&str[i], old_word, old_len) == 0) {
            strcpy(&result[j], new_word);
            j += new_len;
            i += old_len;
        } else {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';
    strcpy(str, result); // Copy result back to original string
}
