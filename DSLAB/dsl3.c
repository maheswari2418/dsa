#include <stdio.h>
#define MAX 5
void depth_first(int adj[][MAX],int visited[],int start)
{
int stack[MAX],i,top;
printf("%c–>",start + 65);
visited[start] = 1;
stack[++top] = start;
while(top!=-1)
{
start = stack[top];
for(i = 0; i < MAX; i++)
{
if(adj[start][i] && visited[i] == 0)
{
stack[++top] = i;
printf("%c–>", i + 65);
visited[i]=1;
break;
}
}
if(i == MAX)
top--;
}
}
void main()
{
int adj[MAX][MAX];
int visited[MAX]={0};
int i, j;
printf("\n Enter the adjacency matrix: ");
for(i = 0; i < MAX; i++)
{
	for(j = 0; j < MAX; j++)
	{
		scanf("%d", &adj[i][j]);
	}
}
printf("DFS Traversal: ");
depth_first(adj,visited,0);
printf("\n");

}
/*0 1 0 1 0
1 0 1 1 0
0 1 0 0 1
1 1 0 0 1
0 0 1 1 0
DFS Traver*/
