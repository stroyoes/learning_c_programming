#ifndef DOUBLE_ENDED_QUEUE
#define DOUBLE_ENDED_QUEUE

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
} deque_t;

int init_deque(deque_t *queue, int size);

int insert_front(deque_t *queue, int item);
int insert_rear(deque_t *queue, int item);

int delete_front(deque_t *queue, int *get_elm);
int delete_rear(deque_t *queue, int *get_elm);

void print_deque(deque_t *queue);

#endif
