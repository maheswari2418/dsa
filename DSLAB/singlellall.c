// C program for the all operations in
// the Singly Linked List
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* start = NULL;
  
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
            start = newnode;
            temp = start;
            printf("\nEnter number to"
                   " be inserted : ");
            scanf("%d\n", &num);
            start->data = num;
  
            for (int i = 1; i < n; i++) {
                newnode = malloc(sizeof(struct node));
                temp->next = newnode;
                //printf("\nEnter number to"
                      // " be inserted : ");
                scanf("%d", &num);
                newnode->data = num;
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
 
/*void insertAtFront()
{
    int num;
    struct node* new;
    new = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &num);
    new->data = num;
  
  
    new->next = start;
    start = new;
 } 

void insertAtEnd()
{
    int num;
    struct node *new, *temp;
    new = malloc(sizeof(struct node));
  
    
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &num);
  
  
    new->next = 0;
    new->data = num;
    temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
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
    while (i < pos-1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}*/
  

void deleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        free(temp);
    }
}

void deleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->next != 0) {
            prevnode = temp;
            temp = temp->next;
        }
        free(temp);
        prevnode->next = 0;
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
        temp1 = malloc(sizeof(struct node));
        temp = start;
  
     
        while (i < pos-1) {
            temp = temp->next;
            i++;
        }
  
       
        temp1 = temp->next;
        temp->next = temp1->next;
  
       
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
       // case 3:
            //insertAtFront();
           // break;
        //case 4:
            //insertAtEnd();
            //break;
       // case 5:
            //insertAtPosition();
            //break;
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

