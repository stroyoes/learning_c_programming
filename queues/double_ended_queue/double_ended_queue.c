/**
 * Double ended queue is a generalized form of a queue in which insertions and deletions can be performed 
 * at both front and rear ends. 
 */ 

#include <stdio.h>

#include "double_ended_queue.h"

/**
 * Dynamically initialize the queue. 
 * Returns -1 if allocation fails. 
 */ 

int init_deque(deque_t *queue, int size) {
  int size_by_user = (size > 0 && size <= MAX_QUEUE_SIZE) ? size : MAX_QUEUE_SIZE; // A negative size or a size that is greater than max size will default to the max size of the queue itself 
  queue->elms = malloc(sizeof(int) * size_by_user);

  if (!queue->elms) {
    return QUEUE_ERR; // The allocation failed
  } 

  queue->capacity = size_by_user;

  queue->front = -1;
  queue->rear = -1;

  return QUEUE_OK; // Everything worked out 
}

// Defining some predicate funcs
static bool is_empty(deque_t *queue) {
  return queue->front == -1;
} 

static bool is_full(deque_t *queue) {
  return (queue->front == 0) && (queue->rear == queue->capacity - 1);
}

/**
 * Insert an element to the rear of the queue.
 * Returns -1 if insertion failed else returns 0
 */ 
int insert_front(deque_t *queue, int item) {
  if (is_full(queue)) {
    printf("\nERROR: Queue is full. No more insertions possible!\n");
    return QUEUE_ERR;

  } else if (is_empty(queue)) {
    queue->front = queue->rear = 0;

  } else if (queue->front > 0) { // There is space on front side 

    queue->front--;
  } else { // There is no space in front side 

    // Shift elements one posn right 
    for (int r = queue->rear; r >= queue->front; r--) {
      queue->elms[r + 1] = queue->elms[r];
    }
    queue->elms[queue->front] = item;
    queue->rear++;

    return QUEUE_OK;
  }

  queue->elms[queue->front] = item;

  return QUEUE_OK;

}

int insert_rear(deque_t *queue, int item) {
  if (is_full(queue)) {
    printf("\nERROR: Queue is full. No more insertions possible!\n");
    return QUEUE_ERR;

  } else if (is_empty(queue)) {
    queue->front = queue->rear = 0;

  } else if (queue->rear < queue->capacity - 1) { // There is some space in the rear side 

    queue->rear++;
  } else { // There is no space in the rear side 

    // Shift elems one posn left 
    for (int f = queue->front; f < queue->rear; f++) {
      queue->elms[f] = queue->elms[f + 1];
    }
    queue->elms[queue->rear] = item;
    queue->front--;

    return QUEUE_OK;
  }

  queue->elms[queue->rear] = item;

  return QUEUE_OK;
}

int delete_front(deque_t *queue, int *get_elm) {
  if (is_empty(queue)) {
    printf("\nERROR: Queue empty. No more deletions possible!\n");
    return QUEUE_ERR;

  }

  *get_elm = queue->elms[queue->front]; // Store the element in a var 

  // Has only one elemnt left then reset the front and rear 
  if (queue->front == queue->rear) {
    queue->front = queue->rear = -1;

  } else {
    queue->front++;
  }

  return QUEUE_OK;
}

int delete_rear(deque_t *queue, int *get_elm) {
  if (is_empty(queue)) {
    printf("\nERROR: Queue empty. No more deletions possible!\n");
    return QUEUE_ERR;
  }

  *get_elm = queue->elms[queue->rear];  // Store the rear element

  // If only one element left, reset front and rear
  if (queue->front == queue->rear) {
    queue->front = queue->rear = -1;

  } else {
    queue->rear--;
  }

  return QUEUE_OK;
}

void print_deque(deque_t *queue) {
  if (is_empty(queue)) {
    printf("\n Empty_Double_Ended_Queue \n");
    return; 
  }

  printf("\n");

  int front = queue->front;

  do {
    printf(" %d", queue->elms[front]); 

    front = (front + 1) % queue->capacity;
  } while (front != (queue->rear + 1) % queue->capacity);

}
