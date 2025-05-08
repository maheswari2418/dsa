#include<stdio.h>
#include<stdlib.h>
#define size 50
int stack[50],n,top,x,i;

void push();
void pop();
void display();
void main()
{

    top=-1;
    int choice,j;
    while(1)
    {
   
 
  
   //for(j=0;j<n;j++)
    printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.exit");
    
   
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            
                push();
                break;
           
            case 2:
            
                pop();
                break;
            
            case 3:
            
                display();
                break;
            
            case 4:
            
                printf("\nExiting...");
                break;
            
            default:
           
                printf ("\n Enter a Valid Choice");
           
                 
        }
    }
    
}

void push(int n)
{
     //printf("enter the size of stack");
    // scanf("%d",&n);
    if(top==n-1)
    {
        printf("\nstack is over flow");
         
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\n Stack is under flow");
    }
    else
    {
        printf("\nThe popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=-1)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        //printf("enter next choice");
    }
    else
    {
        printf("\n The STACK is empty");
   }
}
