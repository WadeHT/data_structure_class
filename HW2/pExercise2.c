#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct
{
    int row,column,value;
}matrice;
void fastTranspose(matrice a[],matrice b[]);
int main(void)
{
    int i=1;
    matrice matr[MAX],matrTrans[MAX];
    freopen("testFor_fTp.txt","r",stdin);
    printf("Input the number of row ,column and how many want to input");
    scanf("%d%d%d",&matr[0].row,&matr[0].column,&matr[0].value);
    printf("Input row column value in order\n");
    for(i=1;i<=matr[0].value;i++)scanf("%d%d%d",&matr[i].row,&matr[i].column,&matr[i].value);
    fastTranspose(matr,matrTrans);
    for(i=0;i<=matrTrans[0].value;i++)printf("%d %d %d\n",matrTrans[i].row,matrTrans[i].column,matrTrans[i].value);
}
void fastTranspose(matrice a[],matrice b[])
{
    int rowTerms[MAX],startingPos[MAX];
    int i,j;
    memcpy(b,a,sizeof(matrice));
    if(!a[0].value)return 0;
    memset(rowTerms,0,sizeof(rowTerms));
    for(i=1;i<=b[0].value;i++)rowTerms[a[i].column]++;
    startingPos[0]=1;
    for(i=1;i<a[0].column;i++)startingPos[i]= startingPos[i-1]+rowTerms[i-1];
    for(i=1;i<=b[0].value;i++)
    {
        j=startingPos[a[i].column]++;
        b[j].row=a[i].column;
        b[j].column=a[i].row;
        b[j].value=a[i].value;
    }
}
