#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int graph[10][10],temp[10][10],visited[10],articulation[10];
void dfs(int n)
{
    int i;
    visited[n]=1;
    for(i=0; i<10; i++)if(temp[n][i])if(!visited[i])dfs(i);
    return;
}
int main(void)
{
    int i,j,n;
    memset(graph,0,sizeof(graph));
    memset(temp,0,sizeof(temp));
    memset(visited,0,sizeof(visited));
    memset(articulation,0,sizeof(articulation));
    freopen("pExercise4.txt","r",stdin);
    while(scanf("%d%d",&i,&j)!=EOF)graph[i][j]=graph[j][i]=1;
    for(n=0; n<10; n++)
    {
        for(i=0; i<10; i++)for(j=0; j<10; j++)temp[i][j]=graph[i][j];
        for(i=0; i<10; i++)temp[i][n]=temp[n][i]=0;
        n?dfs(0):dfs(1);
        visited[n]=1;
        for(i=0; i<10; i++)if(visited[i]==0)
            {
                articulation[n]=1;
                break;
            }
        memset(visited,0,sizeof(visited));
    }
    printf("articulation points:");
    for(i=0; i<10; i++)if(articulation[i])printf(" %d",i);
    return 0;
}

