#include<stdio.h>
#include<stdlib.h>
#include "my graph.h"

void dijkstra(int*,int);

void main()
{
    int n;
    printf("ENTER THE NUMNBER OF VERTICES IN THE GRAPH:");
    scanf("%d",&n);
    int* a;
    a=(int*)malloc(n*n*sizeof(int));

    loaddata(a,n);
    dijkstra(a,n);
}

void dijkstra(int* a,int n)
{
    int d[n],pi[n],k=0,u,aux[n],i,j,w;
    initialize(d,pi,n);

    for(i=0;i<n;i++) aux[i]=-1;

    while(k!=n)
    {
        u=extractmin(d,aux,n);
        k++;

            for(j=0;j<n;j++)
            {
                if(a[w*n+j]!=0 && aux[j]==-1)
                {
                    w=a[u*n+j];
                    relax(d,pi,u,j,w);
                }
            }
        aux[u]=d[u];

    }

    printf("%d",k);
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",aux[i],pi[i]);
    }
}

