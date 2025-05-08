#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int choice,track,no_req,head,head1,distance;
int disc_req[100];

void sort()
{
    int i,j,temp;
    for(i=0;i<no_req;i++)
    {
        for(j=0;j<no_req;j++)
        {
            if(disc_req[i]<disc_req[j])
            {
                temp=disc_req[i];
                disc_req[i]=disc_req[j];
                disc_req[j]=temp;
            }
        }
    }
}  

void scan()
{
    int index,dir;
    int i;
    distance=0;
    head=head1;
    printf("\n Enter the direction of head \n 1 -(Right) \n 0 -(left)");
    scanf("%d",&dir);
    sort();
    
    i=0;
    while(head >= disc_req[i])
    {
        index=i;
        i++;
    }
    if(dir==1)
    {
        sort();
        for(i=index+1;i<no_req;i++)
        {
            printf("%d=>",disc_req[i]);
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
        
        distance=distance+abs(track-1-disc_req[i-1]);
        distance=distance+abs(track-1-0);
        printf("%d=>0=>",track-1);
        head=0;
        
        for( i=0;i<index;i++)
        {
             printf("%d=>",disc_req[i]);
             distance+=abs(head-disc_req[i]);
             head=disc_req[i];   
        }
    }
    else
    {
        sort();
        for(i=index;i>=0;i--)
        {
            printf("%d=>",disc_req[i]);
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
        distance+=abs(disc_req[i-1] - 0);
        distance+=abs(track-1-0);
        printf("0=>%d=>",track-1);
        head=track-1;
        
        for(i=no_req-1;i>=index+1;i--)
        {
            printf("%d=>",disc_req[i]);
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }                  
    }
    printf("end/n");
    printf("Total Distance Traversed=%d",distance);
}

int main()
{
    printf("Enter Total number of tracks");
    scanf("%d",&track);
    printf("Enter total number of disc requests");
    scanf("%d",&no_req);
    printf("\n Enter disc requests in FCFS order");
    for(int i=0;i<no_req;i++)
    {
        scanf("%d",&disc_req[i]);     
    }
    printf("\n Enter current head position");
    scanf("%d",&head1);
    scan();
}u
