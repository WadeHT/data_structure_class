#include<stdio.h>
#include<string.h>
#define MAX 50
typedef struct
{
    int X,Y,Z;
} ST;
ST p[MAX*5];
int s=0;
void INput(int m[][MAX][MAX],int *SIZE)
{
    scanf("%d",SIZE);int i,j,k;
    for(k=0; k<(*SIZE); k++)for(i=0; i<(*SIZE); i++)for(j=0; j<(*SIZE); j++)scanf("%d",&m[i][j][k]);
}
void OUTput(void)
{
    if(!s)printf("Starting position is Goal\n");
    while(--s>=0)printf("%d %d %d\n",p[s].X,p[s].Y,p[s].Z);
}
int DFS(int m[][MAX][MAX],int SIZE,short int v[][MAX][MAX],ST now)
{
    int i=0,X,Y,Z;ST next[27];v[now.X][now.Y][now.Z]=1;
    if(now.X==SIZE-1 && now.Y==SIZE-1 && now.Z==SIZE-1) return 1;
    for(X=-1; X<=1; X++)for(Y=-1; Y<=1; Y++)for(Z=-1; Z<=1; Z++)
            {
                next[i].X=now.X+X;
                next[i].Y=now.Y+Y;
                next[i++].Z=now.Z+Z;
            }
    for(i=0; i<27; i++)if(L(next[i],SIZE) && !m[next[i].X][next[i].Y][next[i].Z] && !v[next[i].X][next[i].Y][next[i].Z])if(DFS(m,SIZE,v,next[i]))
            {
                p[s++]=next[i];
                return 1;
            }
    return 0;
}
int SM(int m[][MAX][MAX],int SIZE)
{
    short int v[MAX][MAX][MAX]={{0},{0},{0}};ST now,next;
    memset(&now,0,sizeof(ST));
    if(now.X==SIZE-1 && now.Y==SIZE-1 && now.Z==SIZE-1)return 1;
    if(DFS(m,SIZE,v,now))
    {
        s++;
        return 1;
    }
    return 0;
}
int L(ST now,int SIZE)
{
    if(now.X>=SIZE || 0>now.X || now.Y>=SIZE || 0>now.Y || now.Z>=SIZE || 0>now.Z)return 0;
    return 1;
}
int main(void)
{
    int m[MAX][MAX][MAX],SIZE;
    INput(m,&SIZE);
    if(SM(m,SIZE))OUTput();
    else  printf("There is no available path.\n");
}


