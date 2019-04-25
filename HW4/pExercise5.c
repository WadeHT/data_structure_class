#include<stdio.h>
typedef struct node
{
    int num;
    struct node *right;
    struct node *down;
} node_t;
int bit[2][2],value[4],am[2][2],bm[2][2];
void ToArrayA(node_t *a)
{
    int i,j;
    node_t *temp,*ast;
    ast=a;
    for(i=0; i<2; i++)
    {
        temp=ast;
        for(j=0; j<2; j++)
        {
            am[j][i]=temp->num;
            temp=temp->right;
        }
        ast=ast->down;
    }
}
void ToArrayB(node_t *b)
{
    int i,j;
    node_t *temp,*bst;
    bst=b;
    for(i=0; i<2; i++)
    {
        temp=bst;
        for(j=0; j<2; j++)
        {
            bm[j][i]=temp->num;
            temp=temp->right;
        }
        bst=bst->down;
    }
}
void Mul(node_t *a, node_t *b)
{
    int i,sum,c,d,k;
    ToArrayA(a);
    ToArrayB(b);
    sum=0;
    i=0;
    for (c = 0; c < 2; c++)
    {
        for (d = 0; d < 3; d++)
        {
            for (k = 0; k < 4; k++)
            {
                sum = sum + am[c][k]*bm[k][d];
            }
            if(sum)
            {
                bit[c][d] = 1;
                value[i]=sum;
                i++;
            }
            sum = 0;
        }
    }
}
void Insert(node_t **a,node_t **b)
{
    (*a)=(node_t *)malloc(sizeof(node_t));
    (*a)->num=2;
    (*a)->right=(node_t *)malloc(sizeof(node_t));
    (*a)->right->num=7;
    (*a)->down=(node_t *)malloc(sizeof(node_t));
    (*a)->down->num=0;
    (*a)->down->right=(node_t *)malloc(sizeof(node_t));;
    (*a)->down->right->num=0;
    (*a)->right->down=(*a)->down->right;
    (*a)->right->right=NULL;
    (*a)->down->down=NULL;
    (*a)->down->right->right=NULL;
    (*a)->down->right->down=NULL;
    (*b)=(node_t *)malloc(sizeof(node_t));
    (*b)->num=5;
    (*b)->right=(node_t *)malloc(sizeof(node_t));
    (*b)->right->num=0;
    (*b)->down=(node_t *)malloc(sizeof(node_t));
    (*b)->down->num=0;
    (*b)->down->right=(node_t *)malloc(sizeof(node_t));;
    (*b)->down->right->num=0;
    (*b)->right->down=(*a)->down->right;
    (*b)->right->right=NULL;
    (*b)->down->down=NULL;
    (*b)->down->right->right=NULL;
    (*b)->down->right->down=NULL;
}
int main(void)
{
    int i,j,k;
    node_t *a,*b;
    memset(bit,0,sizeof(bit));
    memset(am,0,sizeof(am));
    memset(bm,0,sizeof(bm));
    memset(value,0,sizeof(value));
    Insert(&a,&b);
    Mul(a,b);
    k=0;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d ",bit[i][j]);
            if(bit[i][j])
                k++;
        }
        printf("\n");
    }
    for(i=0; i<k; i++)
    {
        if(value[i])
            printf("%d ",value[i]);
    }
    return 0;
}
