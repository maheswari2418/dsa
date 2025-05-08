#//Breadth first traversal
#include <stdio.h>
#include<stdlib.h>
#define MAX 5
void breadth_first_search(int adj[][MAX],int visited[],int start)
{
int queue[MAX];
int rear=-1;
int front=-1;
int i;
queue[++rear] = start;
visited[start] =1;
while(rear!=front)
{
	start = queue[++front];
	if(start == 5)
	printf("5\t");
printf("%c \t",start + 65);
for(int i= 0; i < MAX; i++)
{
if(adj[start][i]==1 && visited[i] == 0)
{
queue[++rear]=i;
visited[i]=1;
}
}
}
}
void main()
{
int adj[MAX][MAX];
int i, j;
int visited[MAX]={0};
printf("\n Enter the adjacency matrix:\n");
for(i = 0; i < MAX; i++)
{
	for(j = 0; j < MAX; j++)
	{
		scanf("%d", &adj[i][j]);
	}
}
breadth_first_search(adj,visited,0);
}
