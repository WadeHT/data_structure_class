#include<stdio.h>
int Fibonacci(int i)//4 byte
{
    if(i==1)return 0;//4 byte
    else if(i==2)return 1;//4 byte
    return Fibonacci(i-1)+Fibonacci(i-2);//4 byte
}
//every time need 4(parameter)+4(return) = 8 byte
//need 2^n times
//2^n * 8 byte
int main()
{
    int in;
    scanf("%d",&in);
    printf("%d\n",Fibonacci(in));
}
