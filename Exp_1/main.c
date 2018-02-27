#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#define R 5

void insertionsort(int *,int ,int);
void interchange(int *a,int *b);

int partition(int *a,int p,int r);
int select2(int *a,int m ,int p,int k);

int main(void)
{

    int amount;
    int i=0;
    int t,k;
    time_t seed;

    printf("input the number amount and k-th:\t");
    scanf("%d %d",&amount,&k);
    int a[amount];
    seed=time(NULL);
    srand(seed);
    for(t=0;t<amount;t++)
    {
        a[t]=rand()%100;
    }

    //int a[10]= {86,9,3,0,4,77,20,33,87,10};

    //insertionsort(a,0,9);
    //interchange(&a[1],&a[2]);
    for(i=0; i<amount; i++)
    {

        printf("%d\t",a[i]);
    }
    int order=select2(a,0,amount-1,k);
    //t=partition(a,0,9);


    printf("The k-th number is %d",a[order]);

    return 0;
}

void interchange(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void insertionsort(int *a,int m,int p)
{
    int i,j;
    int temp;
    for (i = m+1; i<=p; i++)
    {
        temp = a[i];
        j=i-1;
        while(a[j] > temp&&j>=m)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }

}

int partition(int *a,int p,int r)
//以x为基准，将a[p...r]分割成两部分，并返回x的下标。
{
    int x=a[p];
    int i=p,j=r+1;
    while(1)
    {
        while(a[++i]<x&&i<r);
        while(a[--j]>x);
        if(i>=j)     break;
        interchange(&a[i],&a[j]);
    }
    a[p]=a[j];
    a[j]=x;
    return j;
}

int select2(int *a,int m ,int p,int k)
{

    int i,j,temp,n;

    for(; ; )
    {
         if(p-m+1<=R)
        {
        insertionsort(a,m,p);
        return m+k-1;
        }

        n=p-m+1;
        for(i=1;i<=((n%R==0)?n/R:n/R+1);i++)//对多余的数的处理
        {
            if(n%R==0)
            {
            insertionsort(a,m+(i-1)*R,m+i*R-1);
            interchange(&a[m+i-1],&a[m+(i-1)*R+R/2]);
            }
            else
            {
                if(i!=n/R+1)
                {
                    insertionsort(a,m+(i-1)*R,m+i*R-1);
                    interchange(&a[m+i-1],&a[m+(i-1)*R+R/2]);
                }
                else
                {
                    insertionsort(a,m+(i-1)*R,p);
                    interchange(&a[m+i-1],&a[(p+m+(i-1)*R)/2]);
                }
            }
        }
        j=select2(a,m,m+n/R-1,(n/R)/2+1);
        interchange(&a[m],&a[j]);
        //j=p+1;
        //j=p;
        temp=partition(a,m,p);
        if(temp-m+1==k)
            return temp;
        else if(temp-m+1>k)
            p=temp-1;
        else{
            k=k-(temp-m+1);
            m=temp+1;
            }

    }

}


