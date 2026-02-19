#include <stdio.h>

int stack[100], n, top = -1, choice;
int i;

void push();
void pop();
void show();

int main()
{
    printf("Enter the number of elements in stack: ");
    scanf("%d", &n);

    printf("\n********* STACK OPERATIONS USING ARRAY *********\n");

    do
    {
        printf("\nChoose one option:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Show");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            show();
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Please enter a valid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

void push()
{
    int val;
    if (top == n - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter the value to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void show()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

