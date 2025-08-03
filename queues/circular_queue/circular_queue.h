#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>

#include <stdlib.h>

#define MAX_QUEUE_SIZE 20 

#define QUEUE_OK 0
#define QUEUE_ERR -1

typedef struct {
  int *elms;
  int capacity;
  int front;
  int rear;
} circular_queue_t;

int init_queue(circular_queue_t *queue, int size);

int enq(circular_queue_t *queue, int item);
int deq(circular_queue_t *queue, int *get_elm);

void print_circular_queue(circular_queue_t *queue);

#endif
