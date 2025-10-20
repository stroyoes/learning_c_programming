#include "dictionary.h"


int main() {
    node_t *root = NULL;
    int user_input;

    char word[MAX_WORD_LEN], meaning[MAX_MEANING_LEN];

    do {
        printf("\n--- Dictionary ---\n");
        printf(
            "1) Insert word\n"
            "2) Search word\n"
            "3) Display Dictionary\n"
            "4) Exit\n"
        );
        printf("\nEnter your choice: ");

        scanf("%d", &user_input);
        getchar(); // clear the input buffer

        switch (user_input) {
            case 1: {
                printf("\nEnter the word: ");
                fgets(word, sizeof(word), stdin), word[strcspn(word, "\n")] = '\0';
                printf("\nEnter meaning: ");
                fgets(meaning, sizeof(meaning), stdin), meaning[strcspn(meaning, "\n")] = '\0';
                root = insert(root, word, meaning);

                break;

            }

            case 2: {
                printf("\nEnter word to search: ");
                fgets(word, sizeof(word), stdin), word[strcspn(word, "\n")] = '\0';
                search(root, word);

                break;
            } 

            case 3: {
                printf("\n--- All words and meanings ---\n");
                inorder(root);

                break;
            }

            case 4: {
                printf("\nExiting ...\n");
                free_dict(root);

                return 0;
            } 

            default: {
                printf("\nInvalid choice ... try once more ... \n");
            }
        }
    } while (true);
    return 0;
}