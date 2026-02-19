#include<stdio.h>
#define MAX 5 // Defining the maximum size of the queue

int queue[MAX];
int front =-1,rear=-1;

//Function to check if the queue is full
int isFull()
{
 if(rear==MAX-1)
 return 1;
 return 0;
 }
 //Function to cheack if the queue is empty
 int isEmpty()
 {
   if(front==-1||front>rear)
   return 1;
   return 0;
   }
   //Function to enqueue(insert)an elemant
   void enqueue(int value)
   {
    if(isFull()){
    printf("queue is full.cannot enqueue %d\n",value);
    }
    else
    {
    if(front==-1)
    front=0;
    rear++;
    queue[rear]=value;
    printf("%d enqueued to the queue.\n",value);
    }
    }
    //Function is dequeue(remove)an elemant
    void dequeue()
    {
    if(isEmpty())
    {
    printf("Queue is empty.cannot dequeue.\n");
    }
    else
    {
    printf("%d dequeued from the queue.\n", queue[front]);
    front++;
    
    }
    }
    //Function to display the queue
    void display()
    {
    if(isEmpty())
    {
    printf("Queue is empty.\n");
    }
    else
    {
    printf("queue elemant: ");
    for(int i=front;i<=rear;i++)
    {
    printf("%d",queue[i]);
    }
    printf("\n");
    }
    }
    int main()
    {
    int choice,value;
    do{
    printf("\nQueue Operation Menu\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    switch(choice){
     case 1:
      printf("Enter value to enqueue:");
      scanf("%d",&value);
      enqueue(value);
      break;
      case 2:
      dequeue();
      break;
      case 3:
      display();
      break;
      case 4:
      printf("Exiting the program.\n");
      break;
      default:
      printf("Invalid choice.please try again.\n");
      }
      
     }while(choice !=4);
     
     return 0;
     }
      
