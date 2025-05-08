#include <stdio.h>
#include<stdlib.h>
 
#define MAX 50
 
void insert();
void delete();
void display();
int queue[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int choice;
    while (1)
    {
        printf("1.Insertion \n");
        printf("2.Deletion \n");
        printf("3.Display \n");
        printf("4.exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } 
    } 
} 
 
void insert()
{
    int n;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else 
    {
        if (front == - 1)
        
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &n);
        rear = (rear + 1)%MAX;
        queue[rear] = n;
    }
} 
 
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf(" deleted element is : %d\n", queue[front]);
        front = (front + 1)%MAX;
    }
} 
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
} 

