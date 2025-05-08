#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int value;
    struct node *l;
    struct node *r;
};
struct node *root = NULL;
struct node *temp = NULL;
void insert();
void create();
void search(struct node *t);
void postorder(struct node *t);
void main()
{
    int ch;
    printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
     printf("2 - postorder Traversal\n");
     printf("3 - Exit\n");
      while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:    
		insert();
            	break;
        case 2:    
            	postorder(root);
            	break;
        case 3:    
            	exit(0);
        default :     
            	printf("Wrong choice, Please enter correct choice  ");
            	break; 
        }
     }
}
void insert()
{
	create();
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		search(root);
	}
}
void create()
{
	int data;
	printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
	temp=malloc(sizeof(struct node));
	temp->value=data;
	temp->l=NULL;
	temp->r=NULL;
}
void search(struct node *t)
{
	if((temp->value > t->value) && (t->r!=NULL))
	{
		search(t->r);
	}
	else if((temp->value > t->value) && (t->r==NULL))
	{
		t->r=temp;
	}
	else if((temp->value < t->value) && (t->l!=NULL))
	{
		search(t->l);
	}
	else if((temp->value < t->value) && (t->l==NULL))
	{
		t->l=temp;
	} 
}
void postorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (t->l != NULL) 
        postorder(t->l);
    if (t->r != NULL) 
        postorder(t->r);
    printf("%d -> ", t->value);
}




