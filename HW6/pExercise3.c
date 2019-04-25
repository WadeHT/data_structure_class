#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int graph[10][10],output[10][10],visited[10];
void dfs(int n)
{
    int i;
    visited[n]=1;
    for(i=0; i<10; i++)if(graph[n][i] && !visited[i])
            {

                output[n][i]=1;
                output[i][n]=1;
                dfs(i);
            }
    printf("%d ",n);
    return;
}
int main(void)
{
    int i,j;
    memset(graph,0,sizeof(graph));
    memset(output,0,sizeof(output));
    memset(visited,0,sizeof(visited));
    freopen("pExercise3.txt","r",stdin);
    while(scanf("%d%d",&i,&j)!=EOF)graph[i][j]=graph[j][i]=1;
    dfs(0);
    printf("\n");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)printf("%d ",output[i][j]);
        printf("\n");
    }
    return 0;
}
