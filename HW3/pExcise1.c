#include<stdio.h>
#include<string.h>
#define MAX 50
#define dir 26
/**************data*******************/
typedef struct
{
    short int vert,horiz;
} action;
typedef struct
{
    int X,Y,Z;
} state;
state path[MAX*5];
int step=0;
/**************data*******************/

/**********function area*************/
void INput(int maze[][MAX][MAX],int *SIZE);
int SearchMaze(int maze[][MAX][MAX],int SIZE);
void OUTput(void);
int DFS(int maze[][MAX][MAX],int SIZE,short int visited[][MAX][MAX],state now);
void NextState(state now,state *nextup,state *nextdoun,state *nextNorth,state *nextSouth,state *nextWest,state *nextEast);
int Legal(state now,int SIZE);
int IsGoal(state now,int SIZE);
int MoveRule(state now,state next);
int MakeMoveList(action MOVE[],int SIZE);
/**********function area*************/

int main(void)
{
    int maze[MAX][MAX][MAX];
    int SIZE;
    freopen("test1.txt","r",stdin);
    action MOVE[MAX*5];
    INput(maze,&SIZE);
    memset(MOVE,0,sizeof(MOVE));
    if(SearchMaze(maze,SIZE))OUTput();
    else  printf("There is no available path.\n");
}

/**********function area*************/
void INput(int maze[][MAX][MAX],int *SIZE)
{
    printf("pls input the size of maze\n");
    scanf("%d",SIZE);
    printf("input from 1st row, from 1st column, from 1st level\n");
    int i,j,k;
    for(k=0; k<(*SIZE); k++)
        for(i=0; i<(*SIZE); i++)
            for(j=0; j<(*SIZE); j++)
                scanf("%d",&maze[i][j][k]);
    return;
}
void OUTput(void)
{
    if(!step)printf("Starting position is Goal\n");
    while(--step>=0)printf("%d %d %d\n",path[step].X,path[step].Y,path[step].Z);
    return;
}
int SearchMaze(int maze[][MAX][MAX],int SIZE)
{
    short int visited[MAX][MAX][MAX];
    state now,next;
    memset(&now,0,sizeof(state));
    memset(visited,0,sizeof(visited));
    if(IsGoal(now,SIZE))return 1;
    if(DFS(maze,SIZE,visited,now))
    {
        step++;
        return 1;
    }
    return 0;
}
int DFS(int maze[][MAX][MAX],int SIZE,short int visited[][MAX][MAX],state now)
{
    state next[27];
    visited[now.X][now.Y][now.Z]=1;
    if(IsGoal(now,SIZE)) return 1;
    int i=0,X,Y,Z;
    for(X=-1; X<=1; X++)
        for(Y=-1; Y<=1; Y++)
            for(Z=-1; Z<=1; Z++)
            {
                next[i].X=now.X+X;
                next[i].Y=now.Y+Y;
                next[i].Z=now.Z+Z;
                i++;
            }
    for(i=0; i<27; i++)
        if(Legal(next[i],SIZE) && !maze[next[i].X][next[i].Y][next[i].Z] && !visited[next[i].X][next[i].Y][next[i].Z])if(DFS(maze,SIZE,visited,next[i]))
            {
                path[step++]=next[i];
                return 1;
            }
    return 0;
}
int Legal(state now,int SIZE)
{
    if(now.X>=SIZE || 0>now.X)return 0;
    if(now.Y>=SIZE || 0>now.Y)return 0;
    if(now.Z>=SIZE || 0>now.Z)return 0;
    return 1;
}
int IsGoal(state now,int SIZE)
{
    if(now.X==SIZE-1 && now.Y==SIZE-1 && now.Z==SIZE-1)return 1;
    return 0;
}
