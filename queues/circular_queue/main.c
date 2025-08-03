//  NOTE: Try implementing your own custom main logic here 

#include <stdio.h>

#include "circular_queue.h"

int main() {
  circular_queue_t queue;

  // Initialize with size 5
  if (init_queue(&queue, 5) == -1) {
    printf("\nERROR: Queue initialization failed.\n");
    return QUEUE_ERR;
  }

  // Insert a few elements
  enq(&queue, 10);
  enq(&queue, 20);
  enq(&queue, 30);
  enq(&queue, 40);
  enq(&queue, 50);

  // Try inserting into full queue
  enq(&queue, 60); // Should show error

  // Print current queue
  printf("Queue after enqueues:");
  print_circular_queue(&queue);

  // Dequeue one element
  int removed;
  if (deq(&queue, &removed) == 0) {
    printf("Dequeued element: %d\n", removed);
  }

  // Print queue after one deletion
  printf("Queue after dequeue:");
  print_circular_queue(&queue);

  // Cleanup
  free(queue.elms);
  return QUEUE_OK;
}

