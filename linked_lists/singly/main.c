#include <stdio.h>

#include "singly.h"

int main() {
  list_node *head = NULL;

  printf("Adding to the front 2, 3 and 4 ... \n");
  insert_front(&head, 2);
  insert_front(&head, 3);
  insert_front(&head, 4);

  printf("Linked list: ");
  print_list(head);

  printf("Adding to the end 9 and 10 ... \n");
  insert_end(&head, 9);
  insert_end(&head, 10);

  printf("Linked list: ");
  print_list(head);
  
  printf("Adding 5 after 4 and 11 after 10 ... \n");
  insert_after(&head, 5, 4); //  TODO:  Use the returend integers to handle errors 
  insert_after(&head, 11, 10);
  printf("Linked list: ");
  print_list(head);

  int num_of_nodes = get_num_of_nodes(&head);
  printf("\nThe number of nodes of this linked list is : %d\n", num_of_nodes);

  free_list(head);
  return 0;
}
