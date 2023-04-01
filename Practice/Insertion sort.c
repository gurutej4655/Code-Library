#include<stdio.h>
#include<stdlib.h>

void insertionsort(int*,int);

void main()
{
    int n,i;
    printf("ENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&n);

    int a[n];
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    insertionsort(a,n);

    for(i=0;i<n;i++) printf("%d ",a[i]);
}

void insertionsort(int* a,int n)
{
    int i,key,j;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;

        while(j<n && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
