#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[4][4],aplus[4][4],astar[4][4],visited[4];

void dfsrtc(int n)
{
    int i;
    visited[n]=1;
    for(i=0; i<4; i++)if(a[n][i])if(!visited[i])dfsrtc(i);
    return;
}
void dfstc(int n)
{
    int i;
    for(i=0; i<4; i++)if(a[n][i])if(!visited[i])
            {
                visited[i]=1;
                dfstc(i);
            }
    return;
}

int main(void)
{
    int i,j;
    memset(a,0,sizeof(a));
    memset(aplus,0,sizeof(aplus));
    memset(astar,0,sizeof(astar));
    memset(visited,0,sizeof(visited));
    freopen("pExercise2.txt","r",stdin);
    while(scanf("%d%d",&i,&j)!=EOF)a[i][j]=1;
    for(i=0; i<4; i++)
    {
        memset(visited,0,sizeof(visited));
        dfstc(i);
        for(j=0; j<4; j++)if(visited[j]) aplus[i][j]=1;
    }
    for(i=0; i<4; i++)
    {
        memset(visited,0,sizeof(visited));
        dfsrtc(i);
        for(j=0; j<4; j++)if(visited[j])astar[i][j]=1;
    }
    printf("A+\n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)printf("%3d ",aplus[i][j]);
        printf("\n");
    }
    printf("A*\n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)printf("%3d ",astar[i][j]);
        printf("\n");
    }
    return 0;
}
