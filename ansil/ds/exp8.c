#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create new node */
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/* Inorder Traversal (Left, Root, Right) */
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder Traversal (Root, Left, Right) */
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal (Left, Right, Root) */
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Insert into Binary Search Tree */
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

/* Main function */
int main()
{
    struct Node *root = NULL;
    int choice, data;

    while (1)
    {
        printf("\n1.Insert Node");
        printf("\n2.Inorder Traversal");
        printf("\n3.Preorder Traversal");
        printf("\n4.Postorder Traversal");
        printf("\n5.Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("Node inserted successfully.\n");
            break;

        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
