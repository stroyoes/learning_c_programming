#include <stdio.h>

#define MAX_QUEUE_SIZE 20

// Global Variables
int queue_size;
int front = -1;
int rear = -1;

typedef int queue_t;  // Just a type alias
queue_t queue[MAX_QUEUE_SIZE];  // The actual queue array

int is_empty() {
  return front == -1;
}

int is_full() {
  return (front == (rear + 1) % queue_size);
}

int has_only_one_item() {
  return (front == rear);
}

int enq(int item) {
  if (is_full()) {
    printf("\nERROR: Queue is full. No more insertions possible!\n");
    return -1;
  } else if (is_empty()) {
    front = rear = 0;
  } else {
    rear = (rear + 1) % queue_size;
  }

  queue[rear] = item;
  return 0;
}

int deq(int *item) {
  if (is_empty()) {
    printf("\nERROR: Queue empty. No more deletions possible!\n");
    return -1;
  }

  *item = queue[front];

  if (has_only_one_item()) {
    front = rear = -1;
  } else {
    front = (front + 1) % queue_size;
  }

  return 0;
}

void print_queue() {
  if (is_empty()) {
    printf("[ Empty Queue ]");
    return;
  }

  printf("[ ");
  int i = front;
  while (1) {
    printf("%d", queue[i]);
    if (i == rear) break;
    printf(", ");
    i = (i + 1) % queue_size;
  }
  printf(" ]");
}

int main() {
  int deleted_elm;
  int elm_to_insert;

  // Get queue size
  printf("Enter the size of the circular queue (max %d): ", MAX_QUEUE_SIZE);
  scanf("%d", &queue_size);

  if (queue_size > MAX_QUEUE_SIZE || queue_size <= 0) {
    printf("Invalid size. Setting to default size %d.\n", MAX_QUEUE_SIZE);
    queue_size = MAX_QUEUE_SIZE;
  }

  // Menu loop
  int user_input;
  do {
    printf("\nSelect an option:\n");
    printf(
      " 1) Enqueue (Insert an element into the rear end)\n"
      " 2) Dequeue (Remove an element from the front end)\n"
      " 3) Display Queue\n" 
      " 4) Exit\n"
      " > "
    );
    scanf("%d", &user_input);

    switch (user_input) {
      case 1: {
        printf("  Enter the item to be inserted: ");
        scanf("%d", &elm_to_insert);
        enq(elm_to_insert);
        break;
      }
      case 2: {
        printf("  Deleting the first inserted element \n");
        int ok = deq(&deleted_elm);
        (ok != -1) ? printf("  \"%d\" was deleted !\n", deleted_elm) : (void)0;
        break;
      }
      case 3: {
        printf("\n");
        print_queue();
        printf("\n");
        break;
      }
      case 4: {
        printf("  Exiting  \n");
        break;
      }
      default: {
        printf("\n  Invalid option \n");
      }
    }
  } while (user_input != 4);

  return 0;
}
