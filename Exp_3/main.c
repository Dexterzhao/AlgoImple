#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define maxnodenum 1000
#define maxedgenum 1000
#define MAX_VALUE 500

int matrix[maxnodenum][maxnodenum];
int nodes[maxnodenum], dist[maxnodenum], prev[maxnodenum];
int nodenum, edgenum;

void dijkstra(int v);
void print_dijkstra(int v, int e);

int main(void)
{
    int m,n;
    clock_t start;
    long timecnt=0;


    int i, j, row, col, w;

    int cnt;
    time_t seed;

    printf("Input nodenum and edgenum:\n");
    scanf("%d %d", &nodenum, &edgenum);
    getchar();

    seed=time(NULL);
    srand(seed);

    for(i = 1; i <= nodenum; i++)
    {
        for(j = 1; j <= nodenum; j++)
        {
            matrix[i][j] = MAX_VALUE;
        }
    }


    for(cnt=0; cnt != edgenum; i++)
    {

        row=rand()%nodenum+1;
        col=rand()%nodenum+1;
        if(matrix[row][col]==MAX_VALUE&&row!=col){
            matrix[row][col] = rand()%MAX_VALUE;
            cnt++;
        }
    }

    getchar();

    printf("start\tend\tlength\tnodelists\n");
    for(m=1;m<=nodenum;m++){
        for(w=0;w<maxnodenum;w++){
            prev[w]=0;
            nodes[w]=0;
            dist[w]=0;
        }
        start=clock();
        dijkstra(m);
        timecnt+=clock()-start;
        for(n=1;n<=nodenum;n++){
            if(n!=m)
            print_dijkstra(m, n);
        }
    }
    printf("Time is %ld",   timecnt);
    return 0;
}



void dijkstra(int v)
{
    int i, j, u, temp, newdist;

    for(i = 1; i <= nodenum; i++)
    {
        dist[i] = matrix[v][i];
        if((dist[i] == MAX_VALUE))
        {
            prev[i] = 0;
        }
        else
        {
            prev[i] = v;
        }
    }

    nodes[v] = 1;
    for(i = 1; i < nodenum; i++)
    {
        temp = MAX_VALUE;
        u = v;
        for(j = 1; j <= nodenum; j++)
        {
            if((!nodes[j]) && (dist[j] < temp))
            {
                temp = dist[j];
                u = j;
            }
        }
        nodes[u] = 1;
        for(j = 1; j <= nodenum; j++)
        {
            if((!nodes[j]) && (matrix[u][j] < MAX_VALUE))
            {
                newdist = matrix[u][j] + dist[u];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
        }
    }
}

void print_dijkstra(int v, int e)
{
    int i,j;
    int t[maxnodenum];

    for(i = e,j=maxnodenum-1; i != v; i = prev[i],j--)
    {
        t[j]=prev[i];

    }

    printf("%d\t%d\t%d\t",v,e,dist[e]);
    for(++j;j<=maxnodenum-1;j++)
    {
        printf("%d->",t[j]);
    }
    printf("%d",e);
    printf("\n");
}
