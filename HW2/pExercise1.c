#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    int coef,expon;
} polynomial;
int searchExp(polynomial arr[],int start,int finish,int N);
int CMP(polynomial *a,polynomial*b);
int main(void)
{
    int startA,startB,*startD,finishA,finishB,*finishD,avail=0;
    polynomial arr[300];
    char temp[500]= {" "};
    int i,j,temp0;
    memset(arr,0,sizeof(arr));
    printf("Just for exp/cof is int and exp>= 0 polynomial\n");
    //test in
    freopen("test0.txt","r",stdin);
    //A poly in
    startA= finishA= 0;
    printf("Input all exponent of A, as the end of polynomial please input 0\n");
    scanf("%d",&arr[finishA].expon);
    while(arr[finishA].expon)
    {
        finishA++;
        scanf("%d",&arr[finishA].expon);
    }
    finishA++;
    printf("Input all none zero coefficient and the exponent0's coefficient of A:\n");
    for(i=startA; i<finishA; i++)scanf("%d",&arr[i].coef);
    //B poly in
    startB= finishB= finishA+1;
    printf("Input all exponent of B, as the end of polynomial please input 0\n");
    scanf("%d",&arr[finishB].expon);
    while(arr[finishB].expon)
    {
        finishB++;
        scanf("%d",&arr[finishB].expon);
    }
    finishB++;
    printf("Input none zero coefficient and the exponent0's coefficient of B:\n");
    for(i= startB; i< finishB; i++)scanf("%d",&arr[i].coef);
    //try print
    printf("\n\n***********data number*************\nA's exp=");
    for(i=startA;i<finishA;i++)printf("%d ",arr[i].expon);
    printf("\nA's cof=");
    for(i=startA;i<finishA;i++)printf("%d ",arr[i].coef);
    printf("\nB's exp=");
    for(i=startB;i<finishB;i++)printf("%d ",arr[i].expon);
    printf("\nB's cof=");
    for(i=startB;i<finishB;i++)printf("%d ",arr[i].coef);
    printf("\n");
    printf("***********data number*************\n\n");
    //D(x)= A(x)* B(x)
    int exp,tempS=finishB+1,tempF=finishB+1;
    for(i=startA; i<finishA; i++)
        for(j=startB; j<finishB; j++)
        {
            exp= arr[i].expon+arr[j].expon;
            temp0=searchExp(arr,tempS,tempF,exp);
            if(temp0!=-1)arr[temp0].coef+=arr[i].coef*arr[j].coef;
            else
            {
                arr[tempF].coef=arr[i].coef*arr[j].coef;
                arr[tempF].expon=exp;
                tempF++;
            }
        }
    for(i=tempS;i<tempF;i++)printf("exp= %d coef= %d\n",arr[i].expon,arr[i].coef);
    startD=  &arr[tempS];
    finishD= &arr[tempF];
    qsort(startD,tempF-tempS,sizeof(polynomial),CMP);
    printf("D's exp=");
    for(i=tempS; i<tempF; i++)printf("%3d ",arr[i].expon);
    printf("\nD's cof=");
    for(i=tempS; i<tempF; i++)printf("%3d ",arr[i].coef);

    printf("\n");
}
int searchExp(polynomial arr[],int start,int finish,int N)
{
    int i;
    for(i= start; i< finish; i++)if(arr[i].expon==N)return i;
    return -1;
}
int CMP(polynomial *a,polynomial*b)
{
    return b->expon-a->expon;
}
