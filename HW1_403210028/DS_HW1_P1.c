#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_STACK_SIZE 100
int cmp(int *a,int*b)
{
    return -(*(int*)a)+(*(int*)b);
}
//stacl 1
int stack1[MAX_STACK_SIZE],top1;
int push1(int item)
{
    if (top1>= MAX_STACK_SIZE -1)return -2;
    stack1[++top1] = item;
}
int pop1()
{
    if (top1 == -1 )return -1;
    return stack1[top1--];
}
//stack 2
int stack2[MAX_STACK_SIZE],top2;
int push2(int item)
{
    if(top2>=MAX_STACK_SIZE -1)return -2;
    stack2[++top2]= item;
}
int pop2()
{
    if(top2==-1)return -1;
    return stack2[top2--];
}
void moveStack(void)
{
    int item=pop1();
    if(item>0)
    {
        printf("%d\n",item);
        push2(item);
        moveStack();
    }
}
int main(void)
{
    int i,array[64];
    srand(time(NULL));
    for(i=0; i<64; i++)array[i]=abs(rand()%1000)+1;//make random number
    qsort(array,64,sizeof(int),cmp);//sort
    for(i=0; i<64; i++)push1(array[i]);
    moveStack();
    printf("**************\n");
    for(i=top2;i>0;--i)printf("%d\n",stack2[i]);
}
