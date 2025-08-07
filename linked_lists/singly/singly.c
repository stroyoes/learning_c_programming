#include <stdio.h>

#include "singly.h"

static bool is_empty(list_node *head) {
  return head == NULL;
}

// Get the total number of nodes in linked list
int get_num_of_nodes(list_node **head) {
  int total_nodes = 0;
  list_node *node_seen = *head;

  while (node_seen) {
    total_nodes++; // Increment by counter 
    node_seen = node_seen->link; // Move to next node 
  }
  return total_nodes;
}


// Create a new node 
static list_node* create_node(int value) {
  list_node *new_node = (list_node *)malloc(sizeof(list_node));

  if (!new_node) {
    printf("\nERROR: Memory allocation failed!\n");
    return NULL;
  }

  new_node->data = value;
  new_node->link = NULL;

  return new_node;
}

// Insert at front 
int insert_front(list_node **head, int value) {
  list_node *new_node = create_node(value);

  if (!new_node) { return -1; }

  new_node->link = *head;
  *head = new_node;
  
  return 0;
}

// Insert at end 
int insert_end(list_node **head, int value) {
  list_node *new_node = create_node(value);

  if (!new_node) { return -1; }
  
  // If there are zero nodes and head is null 
  if (*head == NULL) {
    *head = new_node;
    return 0;
  }
 
  list_node *node_seen = *head;
  while (node_seen->link) {
    node_seen = node_seen->link;
  }
  node_seen->link = new_node;

  return 0;
}

// Insert in between two nodes 
// Returns -1 if element not found and -2 for allocation error
int insert_after(list_node **head, int value, int after) {
  list_node *node_seen = *head;

  while (node_seen && node_seen->data != after) {
    node_seen = node_seen->link;
  }

  if (!node_seen) return -1; // Element not found

  list_node *new_node = create_node(value);
  if (!new_node) return -2; 

  new_node->link = node_seen->link;
  node_seen->link = new_node;

  return 0;
}


//  TODO:  Add delete functions 

// Display the linked list 
// As we are not modifying the head so we take only copy of the header pointer 
void print_list(list_node *head) {
  while (head) {
    printf("%d ->", head->data);
    head = head->link;
  }
  printf(" NULL\n");
}

// Clean everything free the nodes 
// Here the head pointer is enough as we are freeing each node and making no modifications to head 
void free_list(list_node *head) {
  list_node *node_seen; 

  while (head) {
    node_seen = head;
    head = head->link;

    // Free the node seen
    free(node_seen);    
  }
}


