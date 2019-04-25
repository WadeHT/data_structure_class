#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100
/****function area****/
void INput(char string[],char stringTemp[],int *i);
void OUTput(char string[],char stringTemp[]);
void strinins(char string[],char stringTemp[],int i);
void StringPaste(char string[],char stringTemp[],int position);
void StringMove(char string[],int position,int move);
/****function area****/
int main(void)
{
    int i;
    char s[2*MAX],t[MAX];
    //freopen("stringTest.txt","r",stdin);
    INput(s,t,&i);
    strinins(s,t,i);
    OUTput(s,t);
}
/****function area****/
void INput(char string[],char stringTemp[],int *i)
{
    gets(string);
    gets(stringTemp);
    scanf("%d",i);
}
void OUTput(char string[],char stringTemp[])
{
    printf("s = %s\n",string);
    printf("t = %s\n",stringTemp);
}
void strinins(char string[],char stringTemp[],int i)
{
    StringMove(string,i,strlen(stringTemp));
    StringPaste(string,stringTemp,i);
}
void StringMove(char string[],int position,int move)
{
    memcpy(&string[position+move],&string[position],sizeof(((strlen(string)))-position-1));
}
void StringPaste(char string[],char stringTemp[],int position)
{
    memcpy(&string[position],stringTemp,sizeof(char)*strlen(stringTemp));
}
/****function area****/

