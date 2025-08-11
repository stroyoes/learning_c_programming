#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <stdlib.h>

#include <stdbool.h>

struct list_node {
  int data;
  struct list_node *link;
};

typedef struct list_node list_node;

int get_num_of_nodes(list_node *head);

// To modify a pointer we have to provide the address of the pointer, so **pointer (double pointer)
int insert_front(list_node **head, int value); 

int insert_end(list_node **head, int value);
int insert_after(list_node **head, int value, int after);

int delete_front(list_node **head);
int delete_end(list_node **head);
int delete_after(list_node **head, int after);

void print_list(list_node *head);
void free_list(list_node *head); 


#endif
