#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define maxnodenum 1000
#define maxedgenum 1000
#define MAX_VALUE 500

int matrix[maxnodenum][maxnodenum];
int a[maxnodenum][maxnodenum];
int nodenum, edgenum;

void allpaths(void);
void print_allpaths(int v, int e);

int main(void)
{
    int m,n;
    long timecnt=0;


    int i, j, row, col;

    clock_t start,end;

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


    start=clock();
    allpaths();
    timecnt=(clock() - start);
    printf("Time is %ld ms\n",timecnt);
    printf("start\tend\tlength\tnodelists\n");
    for(m=1;m<=nodenum;m++){

        //start=clock();

        //timecnt+=(clock() - start);
        for(n=1;n<=nodenum;n++){
            if(n!=m)
            print_allpaths(m, n);
        }
    }
    //end=(clock() - start);//CLOCKS_PER_SEC;
    //printf("Time is %ld ms",timecnt);
    return 0;
}



void allpaths(void)
{
    int i,j,k;
    int n=nodenum;
    for(i=1;i<=n;i++)
    {
         for(j=1;j<=n;j++)
         {
             a[i][j]=matrix[i][j];
         }
    }

    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
             if((a[i][k]+a[k][j])<a[i][j])
                a[i][j]=a[i][k]+a[k][j];
            }
        }
    }
}

void print_allpaths(int v, int e)
{

    printf("%d\t%d\t%d\n",v,e,a[v][e]);


}
