#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node*prev;
    int data;
    struct node* next;
};
struct node* start = NULL;
 struct node*newnode; 
void createList()
{
    if (start == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        //if (n != 0) {
            int num;
            struct node* newnode;
            struct node* temp;
            newnode = malloc(sizeof(struct node));
            //start = newnode;
            //temp = start;
            printf("\nEnter number to"
                   " be inserted : ");
            scanf("%d", &num);
            newnode->data = num;
            //newnode->next=NULL;
            //newnode->prev=NULL;
            start=newnode;
            temp=start;
            
  
            for (int i = 1; i < n; i++) {
                newnode = malloc(sizeof(struct node));
                
                printf("\nEnter number to"
                       " be inserted : ");
                scanf("%d", &num);
                newnode->data = num;
                newnode->next=NULL;
                newnode->prev=start;
                temp->next=newnode;
                temp = temp->next;
            }
        
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
}
  

void traverse()
{
    struct node* temp;
  
   
    if (start == NULL)
        printf("\nList is empty\n");
  
  
    else {
        temp = start;
        while (temp != NULL) {
            printf(" %d\n", temp->data);
            temp = temp->next;
        }
    }
}
 
void insertAtFront()
{
    int num;
    struct node* new,*temp;
    new = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &num);
   // newnode=temp;
    new->data = num;
    //temp = temp->next;
  
   // temp->next = temp
    new->prev=NULL;
    new->next=start;
    start->prev=new;
    start=new;
    
   // temp = temp->next;
 } 

void insertAtEnd()
{
    int num;
    struct node *temp, *head;
    newnode= malloc(sizeof(struct node));
  
    
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &num);
  
  
    //newnode=temp;
    newnode->data = num;
    newnode->next=NULL;
    temp = start;
    //temp=temp->next;
    while (temp->next != NULL) {
       temp = temp->next;
    }
   
    temp->next=newnode;
    newnode->prev=temp;
   // newnode->next=NULL;
}
  

void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, num, i = 1;
    newnode = malloc(sizeof(struct node));
  
    
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &num);
  
   
    temp = start;
    newnode->data = num;
    newnode->next = 0;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    temp->next->prev = newnode;
}
  

void deleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        start->prev=NULL;
        free(temp);
    }
}

void deleteEnd()
{
    struct node *temp, *temp1;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->next !=NULL) {
            temp1= temp;
            temp = temp->next;
        }
        temp1->prev->next=NULL;
        free(temp);
    
    }
}
  
void deletePosition()
{
    struct node *temp, *temp1;
    int i = 1, pos;
  
   
    if (start == NULL)
        printf("\nList is empty\n");
  
    
    else {
        printf("\nEnter index : ");
  
        
        scanf("%d", &pos);
        //temp1 = malloc(sizeof(struct node));
        temp = start;
  
     
        while (i < pos - 1) {
            temp1=temp;
            temp = temp->next;
            i++;
        }
  
       
        temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev=temp;
       
        free(temp1);
    }
}
 
void main()
{
    int choice;
    while (1) {
  
        printf("\n1  To see list");
        printf("\n2 to create");
        printf("\n3 to display");
        printf("\n4  For insertion at"
        
               " starting");
        printf("\n5  For insertion at"
               " end");
        printf("\n6  For insertion at "
               "any position");
        printf("\n7  For deletion of "
               "first element");
        printf("\n8  For deletion of "
               "last element");
        printf("\n9  For deletion of "
               "element at any position");
        
        printf("\n10 To exit");
        printf("\nEnter Choice :");
        scanf("%d", &choice);
  
        switch (choice) {
        case 1:
            createList();
            break;
        case 2:
            traverse();
            break;
        case 3:
            insertAtFront();
            break;
        case 4:
            insertAtEnd();
            break;
        case 5:
            insertAtPosition();
            break;
        case 6:
            deleteFirst();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            deletePosition();
            break;
        
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
 
}

