// To implement a dictionary of word-meaning pairs using binary search trees

#include "dictionary.h"

node_t* create_node(char *word, char *meaning) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    strncpy(new_node->word, word, MAX_WORD_LEN);
    strncpy(new_node->meaning, meaning, MAX_MEANING_LEN);

    new_node->left = new_node->right = NULL;

    return new_node;
}

node_t* insert(node_t *root, char *word, char *meaning) {
    if (root == NULL) {
        return create_node(word, meaning);

    }

    if (strncmp(word, root->word, MAX_WORD_LEN) < 0) {
        root->left = insert(root->left, word, meaning);
    } else if (strncmp(word, root->word, MAX_WORD_LEN) > 0) {
        root->right = insert(root->right, word, meaning);
    } else {
        printf("\nWord already exists in the dictionary!\n");
    }

    return root;
}

bool search(node_t *root, char *word) {
    if (root == NULL) {
        printf("\nWord not found!\n");
        return false;
    }

    if (strncmp(word, root->word, MAX_WORD_LEN) == 0) {
        printf("\nMeaning of \"%s\" is %s .\n", word, root->meaning);
        return true;
    } else if (strncmp(word, root->word, MAX_WORD_LEN) < 0) {
        search(root->left, word);
    } else {
        search(root->left, word);
    }
}

void inorder(node_t *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("\nMeaning of \"%s\" is %s \n", root->word, root->meaning); 
        inorder(root->right);
    }
}

void free_dict(node_t *root) {
    if (root != NULL) {
        free_dict(root->left);
        free_dict(root->right);
        free(root);
    }
}