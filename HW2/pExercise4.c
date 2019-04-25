#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
/*************function area************/
void INput(int bits[][MAX],double value[],int *MatrixSize);
void OUTput(int bits[][MAX],double value[MAX],int MatrixSize);
void AddMatrix(int bitsA[][MAX],double valueA[],int bitsB[][MAX],double valueB[],int bitsD[][MAX],double valueD[],int MatrixSize);
/*************function area************/
int main(void)
{
    int bitsA[MAX][MAX],bitsB[MAX][MAX],bitsD[MAX][MAX],MatrixSize;
    double valueA[MAX],valueB[MAX],valueD[MAX];
    memset(bitsA,0,sizeof(bitsA));
    memset(bitsB,0,sizeof(bitsB));
    memset(bitsD,0,sizeof(bitsD));
    freopen("twoTest.txt","r",stdin);
    INput(bitsA,valueA,&MatrixSize);
    INput(bitsB,valueB,&MatrixSize);
    AddMatrix(bitsA,valueA,bitsB,valueB,bitsD,valueD,MatrixSize);                                                                                              /**/
    OUTput(bitsD,valueD,MatrixSize);
}
/*************function area************/
void INput(int bits[][MAX],double value[],int *MatrixSize)
{
    scanf("%d",MatrixSize);
    int i,j,k=0;
    for(i=0; i<*MatrixSize; i++)
        for(j=0; j<*MatrixSize; j++)
        {
            scanf("%d",&bits[i][j]);
            if(bits[i][j])k++;
        }
    for(i=0; i<k; i++)scanf("%lf",&value[i]);
    return;
}
void OUTput(int bits[][MAX],double value[MAX],int MatrixSize)
{
    int i,j,k=0;
    for(i=0; i<MatrixSize; i++)
    {
        for(j=0; j<MatrixSize; j++)
        {
            printf("%d ",bits[i][j]);
            if(bits[i][j])k++;
        }
        printf("\n");
    }
    for(i=0; i<k; i++)printf("%.3lf\n",value[i]);
    return;
}
void AddMatrix(int bitsA[][MAX],double valueA[],int bitsB[][MAX],double valueB[],int bitsD[][MAX],double valueD[],int MatrixSize)
{
    int i,j,counterA=0,counterB=0,counterD=0;
    for(i=0; i<MatrixSize; i++)
        for(j=0; j<MatrixSize; j++)
        {
            if(bitsA[i][j]!=0&bitsB[i][j]!=0)
            {
                bitsD[i][j]=1;
                valueD[counterD++]=valueA[counterA++]+valueB[counterB++];
            }
            else if(bitsA[i][j]!=0)
            {
                bitsD[i][j]=1;
                valueD[counterD++]=valueA[counterA++];
            }
            else if(bitsB[i][j]!=0)
            {
                bitsD[i][j]=1;
                valueD[counterD++]=valueB[counterB++];
            }
        }
    return;
}
/*************function area************/
