#include<stdio.h>
#include<string.h>
#define MAX 100
int main(void)
{
    int i;char s[2*MAX],t[MAX];
    scanf("%s%s%d",s,t,&i);
    memcpy(&s[i+strlen(t)],&s[i],sizeof(((strlen(s)))-i-1));
    memcpy(&s[i],t,sizeof(char)*strlen(t));
    printf("s = %s\nt = %s\n",s,t);
}
