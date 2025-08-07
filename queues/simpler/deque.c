#include <stdio.h>

#define MAX 10

int deque[MAX];
int front = -1, rear = -1;
int size = MAX;

int is_empty() {
  return front == -1;
}

int is_full() {
  return (front == 0 && rear == size - 1);
}

int insert_front(int val) {
  if (is_full()) {
    printf("Overflow at front!\n");
    return -1;
  }

  if (is_empty()) {
    front = rear = 0;
  } else if (front > 0) {
    front--;
  } else {
    for (int i = rear; i >= front; i--)
      deque[i + 1] = deque[i];
    rear++;
  }

  deque[front] = val;
  return 0;
}

int insert_rear(int val) {
  if (is_full()) {
    printf("Overflow at rear!\n");
    return -1;
  }

  if (is_empty()) {
    front = rear = 0;
  } else if (rear < size - 1) {
    rear++;
  } else {
    for (int i = front; i <= rear; i++)
      deque[i - 1] = deque[i];
    front--;
  }

  deque[rear] = val;
  return 0;
}

int delete_front(int *item) {
  if (is_empty()) {
    printf("Underflow at front!\n");
    return -1;
  }

  *item = deque[front];
  if (front == rear) {
    front = rear = -1;
  } else {
    front++;
  }

  return 0;
}

int delete_rear(int *item) {
  if (is_empty()) {
    printf("Underflow at rear!\n");
    return -1;
  }

  *item = deque[rear];
  if (front == rear) {
    front = rear = -1;
  } else {
    rear--;
  }

  return 0;
}

void print_deque() {
  if (is_empty()) {
    printf("[ Empty Deque ]\n");
    return;
  }

  printf("[ ");
  for (int i = front; i <= rear; i++) {
    printf("%d", deque[i]);
    if (i < rear) printf(", ");
  }
  printf(" ]\n");
}

int main() {
  int x;

  printf("Insert to rear 10 and 20 ... \n");
  insert_rear(10);
  insert_rear(20);

  printf("Insert to front 5 and 2 ... \n");
  insert_front(5);
  insert_front(2);
  print_deque(); // [ 2, 5, 10, 20 ]

  delete_rear(&x);
  printf("Deleted from rear: %d\n", x);
  delete_front(&x);
  printf("Deleted from front: %d\n", x);
  print_deque(); // [ 5, 10 ]

  printf("Insert to front 1 and to rear 99 and 100 ... \n");
  insert_front(1);
  insert_rear(99);
  insert_rear(100);
  print_deque(); // [ 1, 5, 10, 99, 100 ]

  return 0;
}
