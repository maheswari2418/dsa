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
    for(i=0;i<(n-1);i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
       if(arr[pos]>arr[j])
          pos=j;
     }
     if(pos!=i)
     {
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
     }
   }
   printf("sorted list:");
   for(i=0;i<n;i++)
      printf("%d\n",arr[i]);
  }
  
       
       
