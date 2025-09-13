/**
 * Implenting a doubly linked list and its operations in C
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for bool type 

// define some status codes 
typedef enum {
  Allocation_Err = -3,
  Node_Not_Found,
  Empty_Linked_List, 
} return_status;

struct node {
  struct node *left_link;
  int data;
  struct node *right_link;
};

typedef struct node node; // give a type alias 

/**
 * Check if linked list is empty 
 */ 
static bool is_empty(node *head) {
  return head == NULL;
}

/** 
 * Get count of total nodes in the linked list using traversal 
 */ 
int get_num_of_nodes(node *head) {
  int total_nodes = 0;
  node *seen = head;

  while (seen) {
    total_nodes++; // increment the counter 
    seen = seen->right_link; // move node pointer right 
  }

  return total_nodes;
}

/**
 * Just allocates a new node
 */ 
static node* alloc_node() {
  node *new_node = (node *)malloc(sizeof(node));

  if (!new_node) {
    printf("\nERROR: Memory allocation failed!\n");
    return NULL;
  }

  return new_node;
}

/**
 * Insert a node to the front of the linked list 
 */
int insert_front(node **head, int value) {
  node *new_node = alloc_node();
  if (!new_node) { // allocation failed
    return Allocation_Err;
  }

  new_node->data = value;
  new_node->left_link = NULL;
  new_node->right_link = *head;

  if (*head) { // list is not empty
    (*head)->left_link = new_node;
  }

  *head = new_node; // update head pointer
  return 0;
}

/**
 * Insert a node to the end of the linked list
 */ 
int insert_end(node **head, int value) {
  node *new_node = alloc_node();
  if (!new_node) {
    return Allocation_Err;
  }

  new_node->data = value;
  new_node->right_link = NULL;
  new_node->left_link = NULL;

  // list is empty, new_node becomes head
  if (is_empty(*head)) {   // using your is_empty function
    *head = new_node;
    return 0;
  }

  // traverse to the last node
  node *seen = *head;
  while (seen->right_link) {
    seen = seen->right_link;
  }

  seen->right_link = new_node;
  new_node->left_link = seen;

  return 0;
}

/**
 * Insert a node after some node with a specific data.
 */
int insert_after(node **head, int value, int after) {
  node *seen = *head;

  while (seen && seen->data != after) {
    seen = seen->right_link;
  }

  if (!seen) {
    return Node_Not_Found;
  }

  node *new_node = alloc_node();
  new_node->data = value;

  new_node->right_link = seen->right_link;
  new_node->left_link = seen;

  if (seen->right_link) {
    seen->right_link->left_link = new_node;
  }

  seen->right_link = new_node;

  return 0;
}

/**
 * Delete front node from the linked list  
 */ 
int delete_front(node **head) {
  if (is_empty(*head)) {
    return Empty_Linked_List;
  }

  node *temp_node = *head;

  // move head to next node
  *head = temp_node->right_link;

  if (*head != NULL) {
    // there is more than one node
    (*head)->left_link = NULL;
  }

  free(temp_node);
  return 0;
}

/**
 * Delete last node from the linked list 
 */ 
int delete_end(node **head) {
  if (is_empty(*head)) {
    return Empty_Linked_List;
  }

  node *seen = *head;
  while (seen->right_link) { // stop at last node 
    seen = seen->right_link;
  }

  // only one node in linked list 
  if (!seen->left_link) {
    *head = NULL; // empty the list 
  } else {
    seen->left_link->right_link = NULL;
  }

  free(seen); 
  return 0;
}

/**
 * Delete a node with a specific data 
 */
int delete_if_data(node **head, int del_value) {
  if (is_empty(*head)) {
    return Empty_Linked_List;
  }

  node *seen = *head;

  while (seen && seen->data != del_value) {
    seen = seen->right_link;
  }

  // node not found in linked list 
  if (!seen) {
    return Node_Not_Found;
  }

  // its the 1st node 
  if (!seen->left_link) {
    *head = seen->right_link; // move to next node 
    if (*head) {
      (*head)->left_link = NULL; // unlink previous node 
    }
  } else if (seen->right_link) { // deleting a middle node 
    seen->left_link->right_link = seen->right_link;
    seen->right_link->left_link = seen->left_link;

  } else { // its the last node 
    seen->left_link->right_link = NULL;
  }

  free(seen);
  return 0;
}

/**
 * Do a linear search for a value 
 */ 
bool is_node(node *head, int value) {
  if (is_empty(head)) return false; 
  for (node *seen = head; seen; seen = seen->right_link)
    if (seen->data == value) return true;
  return false;
}

/**
 * Loop thorugh the nodes and print the full dll
 */
void walk_list(node *head) {
  if (is_empty(head)) {
    printf("\n List is empty\n");
    return;
  }

  node *seen = head;
  while (seen) {
    printf("%d", seen->data);
    if (seen->right_link) {
      printf(" <-> ");
    }
    seen = seen->right_link;
  }
  printf("\n");
}

int main() {
  node *head = NULL;
  int choice, value, after;

  do {
    printf(
      "\n--- Doubly Linked List Menu ---\n"
      "1. Insert at front\n"
      "2. Insert at end\n"
      "3. Insert after\n"
      "4. Delete front\n"
      "5. Delete end\n"
      "6. Delete by value\n"
      "7. Display list\n"
      "8. Count nodes\n"
      "9. Search node\n"
      "0. Exit\n"
    );

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: { 
        printf(" Enter value: ");
        scanf("%d", &value);
        insert_front(&head, value);
        break;
      } 

      case 2: { 
        printf(" Enter value: ");
        scanf("%d", &value);
        insert_end(&head, value);
        break;
      } 

      case 3: { 
        printf(" Enter value: ");
        scanf("%d", &value);
        printf(" Insert after which node? ");
        scanf("%d", &after);
        if (insert_after(&head, value, after) == Node_Not_Found)
          printf(" Node %d not found!\n", after);
        break;
      }

      case 4: {
        if (delete_front(&head) == Empty_Linked_List)
          printf(" Linked list is empty!\n");
        break;
      }

      case 5: {
        if (delete_end(&head) == Empty_Linked_List)
          printf(" Linked list is empty!\n");
        break;
      }

      case 6: {
        printf(" Enter value to delete: ");
        scanf("%d", &value);
        int status = delete_if_data(&head, value);
        if (status == Node_Not_Found)
          printf(" Value %d not found!\n", value);
        else if (status == Empty_Linked_List)
          printf(" Linked list is empty!\n");
        break;
      }

      case 7: {
        walk_list(head);
        break;
      }
        
      case 8: {
        printf(" Total nodes: %d\n", get_num_of_nodes(head));
        break;
      }

      case 9: {
        printf(" Enter value to search: ");
        scanf("%d", &value);
        if (is_node(head, value))
          printf(" Node %d found!\n", value);
        else
          printf(" Node %d not found!\n", value);
        break;
      }

      case 0: {
        printf(" Exiting...\n");
        break;
      }

      default: {
        printf("Invalid choice!\n");
      }
    }

  } while (choice != 0);

  return 0;
}

/* 
Output
------

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 1
 Enter value: 2

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 2
 Enter value: 3

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 3
 Enter value: 6
 Insert after which node? 2

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 7
2 <-> 6 <-> 3

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 8
 Total nodes: 3

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 9
 Enter value to search: 3
 Node 3 found!

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 4

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 5

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 7
6

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 6
 Enter value to delete: 6

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 7

 List is empty

--- Doubly Linked List Menu ---
1. Insert at front
2. Insert at end
3. Insert after
4. Delete front
5. Delete end
6. Delete by value
7. Display list
8. Count nodes
9. Search node
0. Exit

Enter choice: 0
 Exiting...
*/
