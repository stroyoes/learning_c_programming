#include "find_replace.h"

int main(void) {
    string_t text, find, replace;

    printf("Enter the text:\n");
    fgets(text, MAX_LEN, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline

    printf("Enter the word to find: ");
    scanf("%s", find);

    printf("Enter the word to replace it with: ");
    scanf("%s", replace);

    find_and_replace(text, find, replace);

    printf("\nModified text:\n%s\n", text);

    return 0;
}
