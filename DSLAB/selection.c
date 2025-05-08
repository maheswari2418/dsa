#include<stdio.h>
#include<stdlib.h>

void main()
{
    int arr[100],n,pos,temp,i,j;
    printf("enter no of elements");
    scanf("%d",&n);
    printf("enter the %d value\n",n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
       
        for(j=i+1;j<n;j++)
        {
       if(arr[i]>arr[j])
        
     {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
     }
   }
 }
   printf("sorted list:");
   for(i=0;i<n;i++)
      printf("%d\n",arr[i]);
  }
  
       
       
