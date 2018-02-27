#include <stdio.h>

#define maxnodenum 100
#define maxedgenum 100
#define MAX_VALUE 200

int cost[maxnodenum][maxnodenum];
int nodes[maxnodenum], dist[maxnodenum], prev[maxnodenum];
int nodenum, edgenum;
void cost_init(void);
void dijkstra(int v);
void print_dijkstra(int v, int e);

int main(int argc, char **argv)
{
    int v,i;

    cost_init();
    printf("Input source node: ");
    scanf("%d", &v);
    getchar();
    dijkstra(v);

    getchar();
    printf("start\tend\tlength\tnodelists\n");
    for(i=1;i<=nodenum;i++){
        if(i!=v)
        print_dijkstra(v, i);

    }
    return(0);
}

void cost_init(void)
{
    int i, j, row, col, weight;

    printf("Input nodenum and edgenum:\n");
    scanf("%d %d", &nodenum, &edgenum);
    getchar();

    for(i = 1; i <= nodenum; i++)
    {
        for(j = 1; j <= nodenum; j++)
        {
            cost[i][j] = MAX_VALUE;
        }
    }

    printf("Input all edges:\n");
    for(i = 0; i < edgenum; i++)
    {
        scanf("%d %d %d", &row, &col, &weight);
        getchar();
        cost[row][col] = weight;
    }
}

void dijkstra(int v)
{
    int i, j, u, temp, newdist;

    for(i = 1; i <= nodenum; i++)
    {
        dist[i] = cost[v][i];
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
            if((!nodes[j]) && (cost[u][j] < MAX_VALUE))
            {
                newdist = cost[u][j] + dist[u];
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
