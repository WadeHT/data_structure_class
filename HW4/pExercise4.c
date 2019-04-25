#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**********data*********/
typedef struct nu
{
    int coef,expon;
    struct nu *link;
} POL;
POL* avail=NULL;
/**********data*********/
/**********function*********/
POL *getNode(void)
{
    POL *node;
    if(avail)
    {
        node=avail;
        avail=avail->link;
        node->link=NULL;
    }
    else
    {
        node=malloc(sizeof(POL));
        node->link=NULL;
    }
    return node;
}
void pread(POL *(*head),int coef,int expon,POL*(*last))
{
    POL *temp;
    if(*head==NULL)
    {
        (*last)=(*head)=getNode();
        (*head)->coef=coef;
        (*head)->expon=expon;
        (*head)->link=(*head);
        return;
    }
    for(temp=(*head); temp->link!=(*head); temp=temp->link); //find the last node
    temp->link=(*last)=getNode();//link last node with new node
    temp->link->coef=coef;
    temp->link->expon=expon;
    temp->link->link=(*head);
    return;
}
void pwrite(POL*head)
{
    POL*temp=head;
    printf("coef=%d expon=%d\n",temp->coef,temp->expon);
    for(temp=head->link; temp!=head; temp=temp->link)printf("coef=%d expon=%d\n",temp->coef,temp->expon);
    return;
}
POL* FindEQNode(POL*head,int expon)
{
    POL*temp=head;
    if(temp->expon==expon)return temp;
    for(temp=head->link; temp!=head; temp=temp->link)if(temp->expon==expon)return temp;
    return NULL;
}
POL* FindBetween(POL*head,int expon)
{
    POL*temp=head;
    if(temp->expon>expon && expon>temp->link->expon)return temp;
    for(temp=head->link; temp!=head; temp=temp->link)if(temp->expon>expon && expon>temp->link->expon)return temp;
    return temp;
}
void pmult(POL*(*headC),POL *headA,POL*headB,POL*lastA,POL*lastB)
{
    POL*i,*j,*EQ,*temp,*BT;
    int expon,coef;
    for(i=headA; ; i=i->link)
    {
        for(j=headB; ; j=j->link)
        {
            expon=i->expon+j->expon;
            coef=i->coef*j->coef;
            if(*headC==NULL)
            {
                (*headC)=malloc(sizeof(POL));
                (*headC)->coef=coef;
                (*headC)->expon=expon;
                (*headC)->link=(*headC);
            }
            else
            {
                EQ=FindEQNode(*headC,expon);
                if(EQ)EQ->coef+=coef;
                else
                {
                    BT=FindBetween(*headC,expon);
                    temp=malloc(sizeof(POL));
                    temp->coef=coef;
                    temp->expon=expon;
                    temp->link=BT->link;
                    BT->link=temp;
                }
            }
            if(j==lastB)break;
        }
        if(i==lastA)break;
    }
    return;
}
void perase(POL*(*head))
{
    POL* temp;
    if(*head)
    {
        temp=(*head)->link;
        (*head)->link=avail;
        avail=temp;
        (*head)=NULL;
    }
    return;
}
void psub(POL*(*headC),POL*headA,POL*headB,POL*lastA,POL*lastB)
{
    POL*temp,*hA=headA,*hB=headB;
    int i=0;
    (*headC)=temp=malloc(sizeof(POL));
    lastA->link=NULL;
    lastB->link=NULL;
    while(headA && headB)
    {
        if(headA->expon > headB->expon)
        {
            //printf("headA.exp=%d\n",headA->expon);
            temp->coef=headA->coef;
            temp->expon=headA->expon;
            headA=headA->link;
        }
        else if(headA->expon==headB->expon)
        {
            //printf("headAB.exp=%d\n",headA->expon);
            temp->coef=headA->coef-headB->coef;
            temp->expon=headA->expon;
            headA=headA->link;
            headB=headB->link;
        }
        else
        {
            //printf("headB.exp=%d\n",headB->expon);
            temp->coef=-headB->coef;
            temp->expon=headB->expon;
            headB=headB->link;
        }
        temp->link=malloc(sizeof(POL));
        temp=temp->link;
    }
    for(;headA; headA=headA->link)
    {
        //printf("headA.exp=%d\n",headA->expon);
        temp->coef=headA->coef;
        temp->expon=headA->expon;
        if(!(headA->link))break;
        temp->link=malloc(sizeof(POL));
        temp=temp->link;
    }
    for(;headB; headB=headB->link)
    {
        //printf("headB.exp=%d\n",headB->expon);
        temp->coef=-headB->coef;
        temp->expon=headB->expon;
        if(!(headB->link))break;
        temp->link=malloc(sizeof(POL));
        temp=temp->link;
    }
    temp->link=(*headC);
    lastA->link=hA;
    lastB->link=hB;
}
/**********function*********/
int main(void)
{
    freopen("HW4P4.txt","r",stdin);

    POL *headA=NULL,*headB=NULL,*headC=NULL,*lastA,*lastB,*lastC;
    int coef,expon=0,temp;
    scanf("%d%d",&coef,&expon);
    temp=expon+1;
    while(expon<temp)
    {
        temp=expon;
        pread(&headA,coef,expon,&lastA);
        scanf("%d%d",&coef,&expon);
    }
    pread(&headB,coef,expon,&lastB);
    while(scanf("%d%d",&coef,&expon)!=EOF)pread(&headB,coef,expon,&lastB);
    pwrite(headA);
    printf("\n\n");
    pwrite(headB);
    printf("\n\n");
    pmult(&headC,headA,headB,lastA,lastB);
    pwrite(headC);
    printf("\n\n");
    perase(&headC);
    psub(&headC,headA,headB,lastA,lastB);
    pwrite(headC);
}
