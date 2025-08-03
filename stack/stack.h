#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef struct {
  int items[MAX_STACK_SIZE];
  int top;
} stack_t;

void init_stack(stack_t *stack);
int get_size(stack_t *stack);
int peek(stack_t *stack);
void push(stack_t *stack, int item);
int pop(stack_t *stack);
void clear(stack_t *stack);

int is_empty(stack_t *stack);
int is_full(stack_t *stack);


#endif


