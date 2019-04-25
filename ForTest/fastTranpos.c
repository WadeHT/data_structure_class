#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct
{
    int r,c,v;
}MA;
void fT(MA a[],MA b[])
{
    int rT[MAX]={0},sP[MAX],i,j;
    memcpy(b,a,sizeof(MA));
    if(!a[0].v)return 0;
    for(i=1;i<=b[0].v;i++)rT[a[i].c]++;
    sP[0]=1;
    for(i=1;i<a[0].c;i++)sP[i]= sP[i-1]+rT[i-1];
    for(i=1;i<=b[0].v;i++)
    {
        j=sP[a[i].c]++;
        b[j].r=a[i].c;
        b[j].c=a[i].r;
        b[j].v=a[i].v;
    }
}
int main(void)
{
    int i=1; MA m[MAX],mT[MAX];
    scanf("%d%d%d",&m[0].r,&m[0].c,&m[0].v);
    for(i=1;i<=m[0].v;i++)scanf("%d%d%d",&m[i].r,&m[i].c,&m[i].v);
    fT(m,mT);
    for(i=0;i<=mT[0].v;i++)printf("%d %d %d\n",mT[i].r,mT[i].c,mT[i].v);
}

