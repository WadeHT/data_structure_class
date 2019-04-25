#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int IsSameTree(int u,int v,int spanTree[][7])
{
    int visited0[7]= {0},visited1[7]= {0};
    if(DFS(u,spanTree,visited0) == DFS(v,spanTree,visited1))return 1;
    return 0;
}
int DFS(int u,int spanTree[][7],int visited[])
{
    int i,minVetrex=0x7fffffff,minTemp;
    visited[u]=1;
    for(i=0; i<7; i++)if(spanTree[i][u] && !visited[i])
        {
            minTemp=DFS(i,spanTree,visited);
            minVetrex=minVetrex<minTemp?minVetrex:minTemp;
        }
    return u<minVetrex?u:minVetrex;
}
int main(void)
{
    int u,v,cost,A[7][7],spanTree[7][7]= {{0},{0}};
    int i,j,k,minpos=0;
    freopen("pExercise1.txt","r",stdin);
    for(i=0; i<7; i++)for(j=0; j<7; j++)A[i][j]=0x7fffffff;
    while(scanf("%d%d%d",&u,&v,&cost)!=EOF)
    {
        A[u][v]=cost;
        A[v][u]=cost;
    }
    for(i=0; i<7; i++)
    {
        for(j=0; j<7; j++)if(A[i][j] && A[i][j]<A[i][minpos])minpos=j;
        spanTree[i][minpos]=A[i][minpos];
        spanTree[minpos][i]=A[minpos][i];
    }
    int minI,minJ;
    for(k=0; k<7; k++)
    {
        minI=minJ=-1;
        for(i=0; i<7; i++)for(j=0; j<7; j++)if(!IsSameTree(i,j,spanTree) && (A[i][j]<A[minI][minJ] || minI==-1 && minJ==-1))
                {
                    minI=i;
                    minJ=j;
                }
        spanTree[minI][minJ]=A[minI][minJ];
        spanTree[minJ][minI]=A[minJ][minI];
    }
    for(i=0; i<7; i++)
    {
        for(j=0; j<7; j++)printf("%3d ",spanTree[i][j]);
        printf("\n");
    }
}
