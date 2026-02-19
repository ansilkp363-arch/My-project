#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head;

/* Initialize list */
void init()
{
    head = NULL;
}

/* Insert at beginning */
void insertfirst(int element)
{
    struct node *New;
    New = (struct node *)malloc(sizeof(struct node));
    New->value = element;
    New->next = head;
    head = New;
}

/* Print list */
void print()
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }

    struct node *cur = head;
    int count = 0;

    while (cur != NULL)
    {
        printf("%d -> ", cur->value);
        count++;
        cur = cur->next;
    }

    printf("NULL\n");
    printf("number of nodes %d\n", count);
}

/* Delete a specific element */
void deleteitem(int ele)
{
    if (head == NULL)
    {
        printf("list is empty and nothing to delete\n");
        return;
    }

    struct node *cur = head;
    struct node *prev = NULL;

    while (cur != NULL && cur->value != ele)
    {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL)
    {
        printf("element not found\n");
        return;
    }

    if (prev == NULL)
        head = cur->next;
    else
        prev->next = cur->next;

    free(cur);
}

/* Search element */
int searchitem(int ele)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        if (temp->value == ele)
            return 1;
        temp = temp->next;
    }
    return 0;
}

/* Insert at last */
void insertlast(int ele)
{
    struct node *New, *temp;
    New = (struct node *)malloc(sizeof(struct node));

    if (New == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }

    New->value = ele;
    New->next = NULL;

    if (head == NULL)
    {
        head = New;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = New;
    printf("DATA INSERTED SUCCESSFULLY\n");
}

/* Delete last element */
void deletelast()
{
    if (head == NULL)
    {
        printf("list is empty and nothing to delete\n");
        return;
    }

    struct node *cur = head;
    struct node *prev = NULL;

    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }

    if (prev != NULL)
        prev->next = NULL;
    else
        head = NULL;

    free(cur);
}

/* Delete first element */
void deletefirst()
{
    if (head == NULL)
    {
        printf("list is empty and nothing to delete\n");
        return;
    }

    struct node *cur = head;
    head = head->next;
    free(cur);
}

/* Insert after a given element */
void insertafter(int elem, int num)
{
    struct node *New, *prev;
    New = (struct node *)malloc(sizeof(struct node));
    New->value = elem;
    New->next = NULL;

    prev = head;
    while (prev != NULL && prev->value != num)
        prev = prev->next;

    if (prev == NULL)
    {
        printf("element not found\n");
        free(New);
        return;
    }

    New->next = prev->next;
    prev->next = New;
}

/* Print in reverse using recursion */
void printReverse(struct node *head)
{
    if (head == NULL)
        return;

    printReverse(head->next);
    printf("%d -> ", head->value);
}

/* Reverse the linked list */
void reverselist()
{
    struct node *prev = NULL;
    struct node *cur = head;
    struct node *nxt;

    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    head = prev;
}

/* Sum of elements */
void sum()
{
    int s = 0;
    struct node *cur = head;

    while (cur != NULL)
    {
        s += cur->value;
        cur = cur->next;
    }

    printf("Sum of elements is %d\n", s);
}

/* Main menu */
int main()
{
    init();
    int ch, element;

    while (1)
    {
        printf("\n1.Insert First");
        printf("\n2.Delete Item");
        printf("\n3.Search Item");
        printf("\n4.Insert Last");
        printf("\n5.Print List");
        printf("\n6.Delete Last");
        printf("\n7.Delete First");
        printf("\n8.Insert After");
        printf("\n9.Print Reverse");
        printf("\n10.Sum");
        printf("\n11.Reverse List");
        printf("\n12.Exit");

        printf("\nEnter choice of input: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("enter element to list: ");
            scanf("%d", &element);
            insertfirst(element);
        }
        else if (ch == 2)
        {
            int de;
            printf("enter element to delete: ");
            scanf("%d", &de);
            deleteitem(de);
        }
        else if (ch == 3)
        {
            int se, reply;
            printf("enter element to search: ");
            scanf("%d", &se);
            reply = searchitem(se);

            if (reply == 1)
                printf("element found\n");
            else
                printf("element not found\n");
        }
        else if (ch == 4)
        {
            int le;
            printf("enter element to insert at last: ");
            scanf("%d", &le);
            insertlast(le);
        }
        else if (ch == 5)
        {
            print();
        }
        else if (ch == 6)
        {
            deletelast();
        }
        else if (ch == 7)
        {
            deletefirst();
        }
        else if (ch == 8)
        {
            int ie, p;
            printf("enter element to insert: ");
            scanf("%d", &ie);
            printf("enter after which element to insert: ");
            scanf("%d", &p);
            insertafter(ie, p);
        }
        else if (ch == 9)
        {
            printReverse(head);
            printf("NULL\n");
        }
        else if (ch == 10)
        {
            sum();
        }
        else if (ch == 11)
        {
            reverselist();
            printf("List reversed\n");
        }
        else if (ch == 12)
        {
            return 0;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
}
	

