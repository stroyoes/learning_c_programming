#include <stdio.h>
#include "double_ended_queue.h"

int main() {
  deque_t deque;
  int deleted_item;

  // init deque with size 5 (small to trigger overflow easily)
  if (init_deque(&deque, 5) == QUEUE_ERR) {
    printf("Failed to allocate deque\n");
    return 1;
  }

  printf("\nCurrently empty: \n");
  print_deque(&deque);

  printf("\nInserting at front: 11, 22, 33\n");
  insert_front(&deque, 11);
  insert_front(&deque, 22);
  insert_front(&deque, 33);
  
  printf("\nCurrent Deque\n");
  print_deque(&deque); // 33 22 11

  printf("\nInserting at rear: 44, 55\n");
  insert_rear(&deque, 44);
  insert_rear(&deque, 55);

  printf("\nCurrent Deque\n");
  print_deque(&deque); // 33 22 11 44 55

  printf("\nAttempting Rear Overflow with 66\n");
  insert_rear(&deque, 66); // should show overflow error

  printf("\nDeleting from Front\n");
  delete_front(&deque, &deleted_item);
  printf("Deleted from front: %d\n", deleted_item);

  printf("\nDeleting from Rear\n");
  delete_rear(&deque, &deleted_item);
  printf("Deleted from rear: %d\n", deleted_item);

  printf("\nCurrent Deque\n");
  print_deque(&deque); // 22 11 44

  printf("\nDeleting Remaining Elements\n");
  delete_front(&deque, &deleted_item);
  delete_front(&deque, &deleted_item);
  delete_front(&deque, &deleted_item);

  printf("\nAttempting Front Underflow\n");
  delete_front(&deque, &deleted_item); // should show underflow error

  printf("\nReinserting at Front: 77, 88, 99, 100\n");
  insert_front(&deque, 77);
  insert_front(&deque, 88);
  insert_front(&deque, 99);
  insert_front(&deque, 100);

  printf("\nAttempting Front Overflow with 111\n");
  insert_front(&deque, 111); // should show overflow error

  return 0;
}

