#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
   struct node *prev;
}*front = NULL,*rear = NULL;

void enqueue(int);
void dequeue();
void display();

void main()
{
   int choice, value,n;
   
   while(1){
     
      printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1://printf("enter no of nodes");
	        //scanf("%d",&n);
	         printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 enqueue(value);
		 break;
	 case 2: dequeue();
	       // printf("deleted element is:",dequeue());
	        break;
	 case 3: display(); 
	        break;
	 case 4: exit(0);
	 default: 
	       printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}
void enqueue(int value)
{
   struct node *new,*temp,*ptr;
   ptr=rear;
   new = malloc(sizeof(struct node));
   new->data = value;
   new -> next = NULL;
   new->prev=NULL;
   if(front == NULL)
      front = rear = new;
   else{
      //newNode=temp;
       rear -> next =new;
      new->prev=rear;
      
      //newNode->next=rear;
      //temp=temp->next;
      rear = new;
      
   }
   
}
void dequeue()
{
   if(front==NULL)
      printf("\nQueue is Empty");
   else{
      struct node *temp = front;
    
      
      front = front -> next;
      
      front->prev=NULL;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}
void display()
{
   if(front == NULL)
      printf("\nQueue is Empty\n");
   else{
            struct node *temp=front; 
          
      while(temp!= NULL)
      {
       printf("%d\n",temp->data);
        temp=temp->next;
        }
	       
}
}
