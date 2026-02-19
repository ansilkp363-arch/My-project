#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to search for a value in the binary tree
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0;  // Key not found
    }

    if (root->data == key) {
        return 1;  // Key found
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// In-order traversal of binary tree
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, searchKey;

    do {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display (In-Order Traversal)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &searchKey);
                if (search(root, searchKey)) {
                    printf("Value %d found in the tree.\n", searchKey);
                } else {
                    printf("Value %d not found in the tree.\n", searchKey);
                }
                break;

            case 3:
                printf("In-Order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

