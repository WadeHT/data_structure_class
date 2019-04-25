#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 12
#define Num 4
/***********data**********/
int *Stack,MAX=Max;
int top[Num],buttom[Num];
/***********data**********/

/*************func************/
void Initialize(void);
void Push(int NO,int item);
void StackFull(int NO);
int MakeSpace(int NO);
int FindSpace(int NO);
int RightSum(int NO);
void RightMove(int NO,int To,int N);
/*************func*************/

main(void)
{
    int NO,item;
    Initialize();
    freopen("test3.txt","r",stdin);
    while(scanf("%d%d",&NO,&item)!=EOF)
    {
        printf("%d %d\n",NO,item);
        Push(NO,item);
        /******
        int i;
        for(i=0;i<Num;i++)printf("NO=%d top=%d but=%d\n",i,top[i],buttom[i]);
        /******/
    }
}


void Initialize()
{
    int i;
    Stack=malloc(sizeof(int)*MAX);
    memset(Stack,0,sizeof(int)*MAX);
    for(i=0; i<Num; i++)
    {
        top[i]=i*(MAX/Num)-1;
        buttom[i]=(i+1)*(MAX/Num)-1;
    }
}
void Push(int NO,int item)
{
    if(top[NO]==buttom[NO])StackFull(NO);
    Stack[++top[NO]]=item;
    /**********
    int i,j;
    for(i=0;i<=buttom[0];i++)printf("%d ",Stack[i]);
    printf(" ** ");
    for(i=1;i<Num;i++){for(j=buttom[i-1]+1;j<=buttom[i];j++)printf("%d ",Stack[j]);printf(" ** ");}
    printf("\n");
    /**********/
}
void StackFull(int NO)
{
    int Find=FindSpace(NO);
    if(Find==-1)
    {
        printf("The %d stack is full and the array is also full, but we create a new space for %d, and now the size of %d is %d\n",NO,NO,NO,MakeSpace(NO));
        return;
    }
    Include(Find,NO);
    printf("The %d stack is full, but we find a space from the %d stack, and now the size of %d is %d, and the size of %d is %d\n",NO,Find,Find,buttom[Find]-top[Find],NO,buttom[NO]-buttom[NO-1]);
    return;
}
int FindSpace(int NO)
{
    int i;
    for(i=NO+1; i<Num; i++)if(buttom[i]-top[i]>0)return i;
    return -1;
}
int MakeSpace(int NO)
{
    int *temp,i;
    temp=malloc(sizeof(int)*(MAX+1));
    //memset(temp,0,sizeof(int)*(buttom[NO]-top[NO]+1));
    memcpy(temp,Stack,sizeof(int)*MAX);
    MAX++;
    //printf("%d\n",Stack[buttom[NO]+1]);
    //for(i=0; i<MAX; i++)printf("%d ",temp[i]);
    //printf("\n");
    memcpy(&temp[buttom[NO]+2],&Stack[buttom[NO]+1],sizeof(int)*(RightSum(NO)));
    /********
    printf("try %d\n",RightSum(NO));
    for(i=0; i<MAX; i++)printf("%d ",temp[i]);
    printf("\n");
    /********/
    RightMove(NO,Num,1);
    free(Stack);
    Stack=temp;
    return buttom[NO]-buttom[NO-1];
}
int RightSum(int NO)
{
    int i,t=0;
    for(i=NO+1; i<Num; i++)t+=(buttom[i]-buttom[i-1]);
    return t;
}
void RightMove(int NO,int To,int N)
{
    int i;
    buttom[NO]+=N;
    for(i=NO+1; i<To; i++)
    {
        buttom[i]+=N;
        top[i]+=N;
    }
    return;
}
void Include(int Find,int NO)
{
    memcpy(&Stack[buttom[NO]+2],&Stack[buttom[NO]+1],sizeof(int)*(RightSum(NO)-RightSum(Find)));
    RightMove(NO,Find+1,1);
    buttom[Find]--;
    return;
}
