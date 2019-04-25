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
    }
    else
    {
        node=malloc(sizeof(POL));
        node->link=avail;
    }
    return node;
}
void pread(POL *(*head),int coef,int expon)
{
    POL *temp;
    if(*head==NULL)
    {
        (*head)=getNode();
        (*head)->coef=coef;
        (*head)->expon=expon;
        (*head)->link=(*head);
        return;
    }
    for(temp=(*head)->link; temp->link!=(*head); temp=temp->link); //find the last node
    temp->link=getNode();//link last node with new node
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
/**********function*********/
int main(void)
{
    freopen("HW4P1.txt","r",stdin);

    POL *head=NULL;
    int coef,expon;
    while(scanf("%d%d",&coef,&expon)!=EOF)pread(&head,coef,expon);
    pwrite(head);
}
