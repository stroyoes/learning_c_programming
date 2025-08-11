#include <stdio.h>
#include <stdlib.h>
#include "singly.h"

void print_menu() {
  printf("\n==== Singly Linked List Menu ====\n");
  printf("1. Insert at front\n");
  printf("2. Insert at end\n");
  printf("3. Insert after a node\n");
  printf("4. Delete front\n");
  printf("5. Delete end\n");
  printf("6. Delete after a node\n");
  printf("7. Display list\n");
  printf("8. Count nodes\n");
  printf("0. Exit\n");
  printf("Enter your choice: ");
}

int main() {
  list_node *head = NULL;
  int choice, value, after, result;

  while (1) {
    print_menu();
    if (scanf("%d", &choice) != 1) {
      printf("Invalid input. Exiting.\n");
      break;
    }

    switch (choice) {
      case 1: {

        printf("Enter value to insert at front: ");
        scanf("%d", &value);
        result = insert_front(&head, value);
        if (result == 0) printf("Inserted %d at front.\n", value);
        else printf("Error inserting.\n");
        break;
      }
      case 2: {
        printf("Enter value to insert at end: ");
        scanf("%d", &value);
        result = insert_end(&head, value);
        if (result == 0) printf("Inserted %d at end.\n", value);
        else printf("Error inserting.\n");
        break;
      }
      case 3: {
        printf("Enter value to insert: ");
        scanf("%d", &value);
        printf("Enter value after which to insert: ");
        scanf("%d", &after);
        result = insert_after(&head, value, after);
        if (result == 0) printf("Inserted %d after %d.\n", value, after);
        else if (result == -1) printf("Value %d not found.\n", after);
        else printf("Error inserting.\n");
        break;
      }
      case 4: {
        result = delete_front(&head);
        if (result == 0) printf("Front node deleted.\n");
        else printf("List is empty.\n");
        break;
      }
      case 5: {
        result = delete_end(&head);
        if (result == 0) printf("Last node deleted.\n");
        else printf("List is empty.\n");
        break;
      }
      case 6: {
        printf("Enter value after which to delete: ");
        scanf("%d", &after);
        result = delete_after(&head, after);
        if (result == 0) printf("Node after %d deleted.\n", after);
        else printf("Could not delete after %d.\n", after);
        break;
      }
      case 7: {
        printf("Linked List: ");
        print_list(head);
        break;
      }
      case 8: {
        printf("Number of nodes: %d\n", get_num_of_nodes(head));
        break;
      }
      case 0: {
        free_list(head);
        printf("Exiting...\n");
        return 0;
      }
      default: {
        printf("Invalid choice. Please try again.\n");
      }
    }
  }
}

