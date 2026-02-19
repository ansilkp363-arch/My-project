#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int count = 0;
struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *temp;


void display()
{
    temp = front;

    if ((front == NULL) && (rear)== NULL)
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nThere are currently %d items:-\n", count);

    while (temp != rear)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    if (temp == rear)
        printf("%d", temp->data);

    printf("\n");
}


void insert(int el)
{
    if (rear == NULL)
    {
        rear = (struct Node *)malloc(sizeof(struct Node));
        rear->next = NULL;
        rear->data = el;
        front = rear;
    }
    else
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        rear->next = temp;
        temp->data = el;
        temp->next = NULL;
        rear = temp;
    }

    count++;
    display();
}


void delete()
{
    temp = front;

    if (temp == NULL)
    {
        printf("\nQueue is Empty!\n");
        return;
    }
    else
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
            printf("\nElement removed is %d\n", front->data);
            free(front);
            front = temp;
        }
        else
        {
            printf("\nElement removed is %d\n", front->data);
            free(front);
            front = rear=NULL;
        }
    }

    count--;
    display();
}

/* Main function */
int main()
{
    int choice, el;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nElement to insert: ");
            scanf("%d", &el);
            insert(el);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        default:
           printf("\nInvalid Choice!");
           }
           }
           return 0;
           }
