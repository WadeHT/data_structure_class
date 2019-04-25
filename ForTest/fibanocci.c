#include <stdio.h>
#include <stdlib.h>
int fib(int n)
{
    return (n==1 || n==0)? n:(fib(n-1)+fib(n-2));
}
int iter(int n)
{
    int i,a=0,b=1,c;
    if(n==0)return 0;
    for(i=2; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}
int main(void)
{
    int n=10;
    printf("fib=%d iter=%d\n",fib(n),iter(n));
}
