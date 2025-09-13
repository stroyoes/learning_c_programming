#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 101

// Status codes
typedef enum {
  Allocation_Err = -5,
  Invalid_Url_Err = -4,
  No_Pages_Back_Warn = -3,
  No_Pages_Front_Warn = -2,
  Empty_List_Warn = -1,
  All_Good = 1
} browser_status_t;

// Node structure
typedef struct node {
  struct node *left_link;   // pointer to previous page
  char url[MAX_URL_LEN];    // url of the page
  struct node *right_link;  // pointer to next page
} node;

node *current_page = NULL; // global pointer to track current page

// This function returns status message from status code
const char* msg_from_browser_status(browser_status_t status) {
  switch (status) {
    case Allocation_Err: return "Error: Memory allocation failed";
    case Invalid_Url_Err: return "Error: Invalid URL";
    case No_Pages_Back_Warn: return "Warning: No pages in the back history";
    case No_Pages_Front_Warn: return "Warning: No pages in the forward history";
    case Empty_List_Warn: return "Warning: No pages visited yet";
    case All_Good: return "Success";
    default: return "Unknown status";
  }
}

// Visit a new page
browser_status_t visit_a_new_page(const char *url) {
  if (!url || url[0] == '\0') { // check if url is null or empty
    return Invalid_Url_Err;
  }

  node *new_node = malloc(sizeof(node)); // allocate memory for new node
  if (!new_node) return Allocation_Err; // this checks for allocation failure

  strncpy(new_node->url, url, MAX_URL_LEN - 1); // copy url
  new_node->url[MAX_URL_LEN - 1] = '\0';        // ensure null termination
  new_node->left_link = NULL;                   // no left link initially
  new_node->right_link = NULL;                  // no right link initially

  if (current_page == NULL) { // if there are no pages yet
    current_page = new_node;
    return All_Good;
  }

  // link the new node with the current page
  new_node->left_link = current_page;
  current_page->right_link = new_node;
  current_page = new_node;

  return All_Good;
}

// Go back a page
browser_status_t go_back_a_page() {
  if (current_page == NULL) return Empty_List_Warn;       // no pages exist
  if (current_page->left_link == NULL) return No_Pages_Back_Warn; // no back history
  current_page = current_page->left_link; // move back
  return All_Good;
}

// Go forward a page
browser_status_t go_forward_a_page() {
  if (current_page == NULL) return Empty_List_Warn;          // no pages exist
  if (current_page->right_link == NULL) return No_Pages_Front_Warn; // no forward history
  current_page = current_page->right_link; // move forward
  return All_Good;
}

// Get current page url
const char* get_current_page_url() {
  if (current_page == NULL) return NULL; // return null if no page
  return current_page->url;              // return current url
}

// Main program the main loop
int main() {
  int choice;
  char url[MAX_URL_LEN];
  browser_status_t status;

  do {
    printf("\n--- Browser Menu ---\n");
    printf("1. Visit new page\n");
    printf("2. Move Back\n");
    printf("3. Move Forward\n");
    printf("4. Display Current page\n");
    printf("5. Exit\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    getchar(); // this consumes newline

    switch (choice) {
      case 1: {
        printf("\n Enter URL: ");
        fgets(url, MAX_URL_LEN, stdin);
        url[strcspn(url, "\n")] = '\0'; // this removes newline
        status = visit_a_new_page(url);
        if (status != All_Good) printf("%s\n", msg_from_browser_status(status)); 
        break;
      }
      case 2: {
        status = go_back_a_page();
        if (status != All_Good) printf("%s\n", msg_from_browser_status(status));
        break;
      }
      case 3: {
        status = go_forward_a_page();
        if (status != All_Good) printf("%s\n", msg_from_browser_status(status));
        break;
      }
      case 4: {
        if (get_current_page_url())
          printf("Current page: %s\n", get_current_page_url());
        else
          printf("%s\n", msg_from_browser_status(Empty_List_Warn));
        break;
      }
      case 5: {
        printf("Exiting...\n");
        break;
      }
      default: {
        printf("Invalid choice\n");
      }
    }
  } while (choice != 5);

  return 0;
}

/*
Output
------

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 1

 Enter URL: www.google.com

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 1

 Enter URL: www.youtube.com

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 2

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 4
Current page: www.google.com

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 3

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 4
Current page: www.youtube.com

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 2

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 4
Current page: www.google.com

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 2
Warning: No pages in the back history

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 3

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 3
Warning: No pages in the forward history

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 7
Invalid choice

--- Browser Menu ---
1. Visit new page
2. Move Back
3. Move Forward
4. Display Current page
5. Exit

Enter choice: 5
Exiting...
*/
