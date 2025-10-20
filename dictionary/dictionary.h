#ifndef Dictionary_H
#define Dictionary_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

#define MAX_WORD_LEN 51
#define MAX_MEANING_LEN ((MAX_WORD_LEN * 2) - 1)

typedef struct node {
    char word[MAX_WORD_LEN];
    char meaning[MAX_MEANING_LEN];
    struct node *left, *right;
} node_t;

// Function to create a new node 
node_t* create_node(char *word, char *meaning);

// Function to insert a node 
node_t* insert(node_t *root, char *word, char *meaning);

// Function to search for a word
bool search(node_t *root, char *word);

// Function for in-order traversal (display words in order)
void inorder(node_t *root);

// Free the bst from heap memory
void free_dict(node_t *root);

#endif