
#include<stdio.h>
#include<stdlib.h>
#include "my graph.h"

void prim(int*,int);

void main()
{
    int n;
    printf("ENTER THE NUMNBER OF VERTICES IN THE GRAPH:");
    scanf("%d",&n);
    int* a;
    a=(int*)malloc(n*n*sizeof(int));

    loaddata(a,n);
    prim(a,n);
}

void prim(int* a,int n)
{
    int d[n],pi[n],k=0,u,aux[n],i,j,w;
    initialize(d,pi,n);

    for(i=0;i<n;i++) aux[i]=-1;

    while(k!=n)
    {
        u=extractmin(d,aux,n);
        k++;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i*n+j]!=0)
                {
                    w=a[i*n+j];
                    relaxp(d,pi,i,j,w);
                }
            }
        }aux[u]=d[u];

    }

    for(i=0;i<n;i++)
    {
        printf("%d %d\n",aux[i],pi[i]);
    }
}

