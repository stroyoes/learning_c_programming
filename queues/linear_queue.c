/** 
 * In this implmentation of a Linear Queue (using a static array) the insertion function 
 * is named as "enq" and deletion func as "deq".  
 */

#include <stdio.h>

#define MAX_QUEUE_SIZE 20

// Global variables that is same within the scope of the program 
int queue_size;

int front = -1;
int rear = -1;

typedef int queue_t; // A type alias named queue_t just for an int array 

queue_t queue[MAX_QUEUE_SIZE]; // The queue elements are stored in this 

int is_empty() {
  return front == -1;
} 

int is_full() {
  return rear == queue_size - 1; 
}

int has_only_one_item() {
  return (rear - front + 1) == 1;
}

/**
 * Insert an element to the rear of the queue
 * Returns -1 if insertion failed else returns 0
 */
int enq(int item) {
  if (is_full()) {
    printf("\nERROR: Queue is full. No more insertions possible!\n");
    return -1;

  } else if (is_empty()) {
    
    // The first element 
    front = 0;
    rear = 0;

  } else {

    rear++;
  }

  queue[rear] = item;

  return 0;
}

/**
 * Delete an element from the rear of the queue 
 * Returns -1 if deletion failed else returns 0 
 */ 
int deq(int *item) {
  if (is_empty()) {
    printf("\nERROR: Queue empty. No more deletions possible!\n");
    return -1;

  } 

  *item = queue[front]; // Store the elemmt in the front

  if (has_only_one_item()) {
// The last element is removed, so reset the front and rear 
    front = -1;
    rear = -1;
  } else {

front++;
  }
  return 0;
}

void print_queue() {
  if (is_empty()) {
    printf("[ Empty Queue ]");
  return;
  }

  int length = rear - front + 1;
  
  printf("[ ");
  for (int i = 0; i < length; i++) {
    printf("%d", queue[i]);
    if (i != (length - 1)) { printf(", "); } 
  }
  printf(" ]");
}

int main() {
  int deleted_elm;
  int elm_to_insert;

  // Get the size of queue and store in the global variable 
  printf("Enter the size of the queue: ");
  scanf("%d", &queue_size);

  // The menu loop 
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
        printf("  Deleting the first inserted element ...\n");
        int flag_delete_possible = deq(&deleted_elm);
        (flag_delete_possible != -1) ? printf("  \"%d\" was deleted !", deleted_elm) : (void)0; // do nothing 

        break;
      }
      case 3: {
        printf("\n");
        print_queue();
        printf("\n");

    break;
      }
      case 4: {
        printf("  Exiting... \n");

        break;
      }
      default: {
        printf("\n  Invalid option \n");
      }
    }
  } while (user_input != 4);

  return 0;
}


/*
Output
------
Enter the size of the queue: 5

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 1
  Enter the item to be inserted: 1

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 1
  Enter the item to be inserted: 2

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 1
  Enter the item to be inserted: 3

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 1
  Enter the item to be inserted: 4

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 1
  Enter the item to be inserted: 5

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 1
  Enter the item to be inserted: 6

ERROR: Queue is full. No more insertions possible!

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 3

[ 1, 2, 3, 4, 5 ]

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 2
  Deleting the first inserted element ...
  "1" was deleted !
Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 2
  Deleting the first inserted element ...
  "2" was deleted !
Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 2
  Deleting the first inserted element ...
  "3" was deleted !
Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 2
  Deleting the first inserted element ...
  "4" was deleted !
Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 2
  Deleting the first inserted element ...
  "5" was deleted !
Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 2
  Deleting the first inserted element ...

ERROR: Queue empty. No more deletions possible!

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 5

  Invalid option

Select an option:
 1) Enqueue (Insert an element into the rear end)
 2) Dequeue (Remove an element from the front end)
 3) Display Queue
 4) Exit
 > 4
  Exiting...
*/
