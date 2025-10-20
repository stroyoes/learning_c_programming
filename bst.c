#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node_t {
    int data;
    struct bst_node_t *left;
    struct bst_node_t *right;
} bst_node_t;

// Create a new node
bst_node_t* create_node(int value) {
    bst_node_t *new_node = (bst_node_t*)malloc(sizeof(bst_node_t));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a value into BST
bst_node_t* insert_node(bst_node_t *root, int value) {
    if (root == NULL)
        return create_node(value);

    if (value < root->data)
        root->left = insert_node(root->left, value);
    else if (value > root->data)
        root->right = insert_node(root->right, value);

    return root;
}

// Inorder traversal
void inorder_traversal(bst_node_t *root) {
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Search in BST
bst_node_t* search_node(bst_node_t *root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search_node(root->left, value);
    else
        return search_node(root->right, value);
}

// Find minimum node in BST (used in deletion)
bst_node_t* find_min(bst_node_t *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
bst_node_t* delete_node(bst_node_t *root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = delete_node(root->left, value);
    else if (value > root->data)
        root->right = delete_node(root->right, value);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            bst_node_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_node_t *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        bst_node_t *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

// Menu-driven program
int main(void) {
    bst_node_t *root = NULL;
    int choice, value;
    
    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert_node(root, value);
                printf("%d inserted into BST.\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete_node(root, value);
                printf("%d deleted from BST (if it existed).\n", value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search_node(root, value))
                    printf("%d found in BST.\n", value);
                else
                    printf("%d not found in BST.\n", value);
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

/*
Output
------


--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert: 2
2 inserted into BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert: 5
5 inserted into BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert: 7
7 inserted into BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert: 1
1 inserted into BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert: 10
10 inserted into BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 1
Enter value to insert: 4
4 inserted into BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 4
Inorder traversal: 1 2 4 5 7 10

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 3
Enter value to search: 3
3 not found in BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 3
Enter value to search: 2
2 found in BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 2
Enter value to delete: 7
7 deleted from BST (if it existed).

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 3
Enter value to search: 7
7 not found in BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 4
Inorder traversal: 1 2 4 5 10

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 8
Invalid choice! Try again.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Exit
Enter your choice: 5
Exiting program.
*/