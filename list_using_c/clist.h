#ifndef CLIST_H
#define CLIST_H

#include <stdbool.h>

typedef struct {
  int *buffer;
  int size;
  int capacity;
} clist_t;

clist_t* create_list(); // Create a new empty list 
void append(clist_t *clist, int value); // Append an integer to the end of the buffer 
int get(clist_t *clist, int index); // Get the value from an index position 
bool contains(clist_t *clist, int value); // Checks if a element exists in a buffer 
int count(clist_t *clist, int value); // Count the number of elements in the buffer 
void remove_item(clist_t *clist, int value); // Remove an item from a buffer 
clist_t* slice(clist_t *clist, int start, int end); // Get a sublist from a list 

void trash_all_lists(clist_t *clist); // Collect and free the pointers

#endif
