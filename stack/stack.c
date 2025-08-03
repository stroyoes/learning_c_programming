/**
 * A stack is a linear data structure that follows the "LIFO" principle - "Last In, First Out" 
 * - The last element that is added (pushed) to the stack is the first one to be removed (popped).
* - Think of a stack of plates or books: You can only remove the top plate/book — not the ones below it.  
 */   

#include "stack.h"

#include <stdio.h>

void init_stack(stack_t *stack) {
  stack->top = -1;
}

int is_empty(stack_t *stack) { 
  return stack->top == -1;
}

int is_full(stack_t *stack) { 
  return stack->top == MAX_STACK_SIZE - 1;
}

int get_size(stack_t *stack) {
  return stack->top + 1;
}

int peek(stack_t *stack) {
  if (is_empty(stack)) {
    printf("\nERROR: Stack is empty!\n");
    return -1;
  }
  return stack->items[stack->top];
}

void push(stack_t *stack, int item) {
  if (is_full(stack)) {
    printf("\nERROR: Stack overflow!\n");
    return;
  }
  stack->items[++stack->top] = item;
}

int pop(stack_t *stack) {
  if (is_empty(stack)) {
    printf("\nERROR: Stack underflow!\n");
    return -1;
  }
  return stack->items[stack->top--];
}

void clear(stack_t *stack) {
  if (is_empty(stack)) {
    printf("\nERROR: Stack underflow!\n");
    return;
  }
  stack->top = -1; 

}



