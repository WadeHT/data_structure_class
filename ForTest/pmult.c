#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**INput:exp>> cof with end 0, A>> B**/
typedef struct
{
    int cof,exp;
} pol;
int sExp(pol arr[],int s,int f,int N)
{
    int i;
    for(i= s; i< f; i++)if(arr[i].exp==N)return i;
    return -1;
}
int CMP(pol *a,pol*b)
{
    return b->exp-a->exp;
}
int main(void)
{
    int sA,sB,*sD,fA,fB,*fD,i,j,t;pol arr[300]={0};
    sA= fA= 0;
    scanf("%d",&arr[fA].exp);
    while(arr[fA].exp)scanf("%d",&arr[++fA].exp);
    for(i=sA; i<fA+1; i++)scanf("%d",&arr[i].cof);
    fA++;
    sB= fB= fA+1;
    scanf("%d",&arr[fB].exp);
    while(arr[fB].exp)scanf("%d",&arr[++fB].exp);
    for(i= sB; i< fB+1; i++)scanf("%d",&arr[i].cof);
    fB++;
    int exp,tS=fB+1,tF=fB+1;
    for(i=sA; i<fA; i++)for(j=sB; j<fB; j++)
        {
            exp= arr[i].exp+arr[j].exp;
            t=sExp(arr,tS,tF,exp);
            if(t!=-1)arr[t].cof+=arr[i].cof*arr[j].cof;
            else
            {
                arr[tF].cof=arr[i].cof*arr[j].cof;
                arr[tF].exp=exp;
                tF++;
            }
        }
    sD=  &arr[tS];fD= &arr[tF];
    qsort(sD,tF-tS,sizeof(pol),CMP);
    printf("D's exp cof\n");
    for(i=tS; i<tF; i++)printf("   %3d %3d\n",arr[i].exp,arr[i].cof);
}


