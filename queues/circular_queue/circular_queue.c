/**
 * Circular Queue is a linear ds in which the last posn is connected back to first, forming a circle. 
 * It overcomes the space inefficieny of a linear queue by allowing wrap around .
 */ 

#include <stdio.h>

#include "circular_queue.h"

/**
 * Dynamically initialize the queue stack. 
 * Returns -1 if allocation fails. 
 */ 
int init_queue(circular_queue_t *queue, int size) {
  int size_by_user = (size > 0 && size <= MAX_QUEUE_SIZE) ? size : MAX_QUEUE_SIZE; // A negative size or a size that is greater than max size will default to the max size of the queue itself 

  queue->elms = malloc(sizeof(int) * size_by_user);

  if (!queue->elms) {
    return QUEUE_ERR; // Allocation failed 
  }

  queue->capacity = size_by_user;

  queue->front = -1;
  queue->rear = -1;

  return QUEUE_OK; // Everything worked 

}

// Defining some predicate funcs 
static bool is_empty(circular_queue_t *queue) {
  return queue->front == -1;
} 

static bool is_full(circular_queue_t *queue) {
  return queue->front == (queue->rear + 1) % queue->capacity;
}

/**
 * Insert an element to the rear of the queue.
 * Returns -1 if insertion failed else returns 0
 */
int enq(circular_queue_t *queue, int item) {
  if (is_full(queue)) {
    printf("\nERROR: Queue is full. No more insertions possible!\n");
    return QUEUE_ERR;

  } else if (is_empty(queue)) {
    queue->front = queue->rear = 0;

  } else {
    queue->rear = (queue->rear + 1) % queue->capacity;
  }

  queue->elms[queue->rear] = item;
  return QUEUE_OK;
}

/**
 * Delete an element from the rear of the queue 
 * Returns -1 if deletion failed else returns 0 
 */ 
int deq(circular_queue_t *queue, int *get_elm) {
  if (is_empty(queue)) {
    printf("\nERROR: Queue empty. No more deletions possible!\n");
    return QUEUE_ERR;

  }

  *get_elm = queue->elms[queue->front]; // Store the element in a var 

  // Has only one elemnt left then reset the front and rear 
  if (queue->front == queue->rear) {
    queue->front = queue->rear = -1;

  } else {
    queue->front = (queue->front + 1) % queue->capacity;
  }

  return QUEUE_OK;
}

/**
 * Print the circular queue with wrap around logic. 
 */
void print_circular_queue(circular_queue_t *queue) {
  if (is_empty(queue)) {
    printf("\n Empty_Circular_Queue \n");
    return; 
  }

  printf("\n");

  int front = queue->front;

  do {
    printf(" %d", queue->elms[front]); 

    front = (front + 1) % queue->capacity;
  } while (front != (queue->rear + 1) % queue->capacity);
}
