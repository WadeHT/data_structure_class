#include<stdio.h>
#include<string.h>
#define MAX 500

/**************data*******************/
char Stack[MAX][2];
int StackTop=0;
/**************data*******************/


/**********function area*************/
void INput(char Infix[]);
void OUTput(char Postfix[]);
void ToPostfix(char Infix[],char Postfix[]);
int GetLV(char In[]);
int IsOpSet(char In);
int IsTwo(char In[]);
/**********function area*************/


int main(void)
{
    freopen("test2.txt","r",stdin);
    char Infix[MAX],Postfix[MAX];
    INput(Infix);
    ToPostfix(Infix,Postfix);
    OUTput(Postfix);
}


/**********function area*************/
void INput(char Infix[])
{
    scanf("%s",Infix);
    return;
}
void OUTput(char Postfix[])
{
    printf("%s\n",Postfix);
}
void ToPostfix(char Infix[],char Postfix[])
{
    int i,j=0;
    for(i=0; i<strlen(Infix); i++)
    {
        while(StackTop>0 && GetLV(&Stack[StackTop-1])>=GetLV(&Infix[i]))
            {
                memcpy(&Postfix[j++],&Stack[--StackTop][0],2);
                if(IsTwo(&Stack[StackTop]))j++;
            }
            memcpy(&Stack[StackTop++],&Infix[i],2);
            if(IsTwo(&Infix[i]))i++;
    }
    while(StackTop>0)
    {
        memcpy(&Postfix[j++],&Stack[--StackTop],2);
        if(IsTwo(&Stack[StackTop]))j++;
    }
    Postfix[j]='\0';
    return;
}
int IsOpSet(char In)
{
    if(In=='&' || In=='!' || In=='<' || In=='>' || In=='='  || In=='+'|| In=='-' || In=='*' || In=='/')return 1;
    return 0;
}
int GetLV(char In[])
{
    if(In[0]=='&'&&In[1]=='&')return 0;
    else if(In[0]=='<'&&In[1]=='<' || In[0]=='>'&&In[1]=='>')return 2;
    else if(In[0]=='!'&&In[1]=='=' || In[0]=='<'&&In[1]=='=' || In[0]=='>'&&In[1]=='=' || In[0]=='<'&&!IsOpSet(In[1])|| In[0]=='>'&&!IsOpSet(In[1]))return 1;
    else if(In[0]=='+' || In[0]=='-')return 3;
    else if(In[0]=='*' || In[0]=='/')return 4;
    else if(In[0]=='!')return 6;
    return 7;
}
int IsTwo(char In[])
{
    if(In[0]=='<'&&In[1]=='<' || In[0]=='>'&&In[1]=='>'|| In[0]=='!'&&In[1]=='=' || In[0]=='<'&&In[1]=='=' || In[0]=='>'&&In[1]=='=' ||In[0]=='&'&&In[1]=='&')return 1;
    return 0;
}
