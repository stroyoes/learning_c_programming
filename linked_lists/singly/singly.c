#include <stdio.h>

#include "singly.h"

/**
 * Check if the linked list is empty. 
 */ 
static bool is_empty(list_node *head) {
  return head == NULL;
}

/**
 * Get the count of total nodes in the linked list using traversal. 
 */
int get_num_of_nodes(list_node *head) {
  int total_nodes = 0;
  list_node *node_seen = head;

  while (node_seen) {
    total_nodes++; // Increment the counter
    node_seen = node_seen->link; // Move to next node 
  }
  return total_nodes;
}

/**
 * Allocate a new node and set its fields. A new nodes link should be initialized
 * to NULL or to an existing node. 
 */
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

/*  
 *  NOTE: 
 *  Double pointer lets us change the actual head pointer in the caller. With a single pointer, we'd only change a local copy. Use ** when reassigning the head itself; use * when only accessing or modifying existing nodes.
 *  Remember: head itself is a pointer, so here we're passing a pointer to a pointer when using ** .  When we are not modifying the head we take only copy of the header pointer (only one * enough). 
*/


/**
 * Insert an element to the front of the linked list. 
 * Returns:
 *  -1 if there was an error in allocating the node 
 *  0 if insertion was succesfull
 */
int insert_front(list_node **head, int value) {
  list_node *new_node = create_node(value);

  if (!new_node) { return -1; }

  new_node->link = *head;
  *head = new_node;
  
  return 0;
}

/**
 * Insert an element to the end of the linked list.
 * Returns:
 *  -1 if there was an error allocating the node
 *  0 if insertion was succesfull
 */
int insert_end(list_node **head, int value) {
  list_node *new_node = create_node(value);

  if (!new_node) { return -1; }
  
  // If there are zero nodes that is head points to NULL  
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

/**
 * Insert an element after the first occurence of a node with given "after" value (i.e. in between the linked list). 
 * Returns:
 *  -1 if element is not found 
 *  -2 if node allocation failed 
 *  0 if insertion was succesfull
 */
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

/**
 * Delete the front (1st) node of the linekd list. 
 * Returns:
 *  -1 if list is empty
 *  0 if deletion was succesfull
 */
int delete_front(list_node **head) {
  if (is_empty(*head)) {
    return -1;
  } 

  list_node *tmp = *head;
  *head = (*head)->link;

  free(tmp);

  return 0;
} 

/**
 * Delete the last node of the linked list.  
 * Returns:
 *  -1 if the list is empty 
 *  0 if deletions was succesfull
 */ 
int delete_end(list_node **head) {
  if (is_empty(*head)) {
    return -1;
  } 

  list_node *node_seen = *head;
  list_node *node_seen_before = NULL;

  // If only one node exists 
  if (node_seen->link == NULL) {
    // Then free that one node 
    free(node_seen);

    *head = NULL;
    return 0;
  } 

  // Traverse to second last node 
  while (node_seen->link) {
    node_seen_before = node_seen;
    node_seen = node_seen->link;

  }

  // Make previous node as last node and remove last node 
  node_seen_before->link = NULL;
  free(node_seen);

  return 0;
}

/**
 * Delete the node after the first occurence of a node with the given "after" value (i.e. in b/w the linked list).
 * Returns:
 *  -1 if list is empty or node with "after" not found
 *  0 if deletion was succesfull
 */
int delete_after(list_node **head, int after) {
  if (is_empty(*head)) {
    return -1;
  }

  list_node *node_seen = *head;

  // Get the node with value "after"
  while (node_seen && node_seen->data != after) {
    node_seen = node_seen->link;
  }

  // Check if there is a node with "after" and has a next node too (to delete)
  if (!node_seen || !(node_seen->link)) {
    return -1;
  }

  list_node *node_to_delete = node_seen->link;

  node_seen->link = node_to_delete->link; // Skip the node_to_delete from linked list 

  // Remove the node 
  free(node_to_delete);

  return 0;
}


/**
 * Display the linked list.
 * Traverses the linked list starting from the given head pointer and prints 
 * each node's data in sequence until the end of the list (NULL) is reached.
 *
 * The head pointer is passed by value (a copy), so the original list remains unchanged.
 */
void print_list(list_node *head) {
  while (head) {
    printf("%d ->", head->data);
    head = head->link;
  }
  printf(" NULL\n");
}

/**
 * Free all nodes in the linked list.
 * Iterates through the linked list, freeing each node one by one.
 *
 * The head pointer is passed by value and is not modified outside 
 * the function, but since the memory is freed, the list becomes invalid.
 */
void free_list(list_node *head) {
  list_node *node_seen; 

  while (head) {
    node_seen = head;
    head = head->link;

    // Free the node seen
    free(node_seen);    
  }
}


