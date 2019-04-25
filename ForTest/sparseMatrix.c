#include<stdio.h>
#include<string.h>
#define MAX 100
void INput(int b[][MAX],double v[],int *MS)
{
    scanf("%d",MS);
    int i,j,k=0;
    for(i=0; i<*MS; i++)
        for(j=0; j<*MS; j++)
        {
            scanf("%d",&b[i][j]);
            if(b[i][j])k++;
        }
    for(i=0; i<k; i++)scanf("%lf",&v[i]);
}
void OUTput(int b[][MAX],double v[MAX],int MS)
{
    int i,j,k=0;
    for(i=0; i<MS; i++)
    {
        for(j=0; j<MS; j++)
        {
            printf("%d ",b[i][j]);
            if(b[i][j])k++;
        }
        printf("\n");
    }
    for(i=0; i<k; i++)printf("%.3lf\n",v[i]);
}
void AM(int bA[][MAX],double vA[],int bB[][MAX],double vB[],int bD[][MAX],double vD[],int MS)
{
    int i,j,cA=0,cB=0,cD=0;
    for(i=0; i<MS; i++)for(j=0; j<MS; j++)
        {
            bD[i][j]=1;
            if(bA[i][j]!=0&bB[i][j]!=0)vD[cD++]=vA[cA++]+vB[cB++];
            else if(bA[i][j]!=0)vD[cD++]=vA[cA++];
            else if(bB[i][j]!=0)vD[cD++]=vB[cB++];
            else bD[i][j]=0;
        }
}
int main(void)
{
    int bA[MAX][MAX]={{0},{0}},bB[MAX][MAX]={{0},{0}},bD[MAX][MAX]={{0},{0}},MS;double vA[MAX],vB[MAX],vD[MAX];
    INput(bA,vA,&MS);INput(bB,vB,&MS);
    AM(bA,vA,bB,vB,bD,vD,MS);
    OUTput(bD,vD,MS);
}
