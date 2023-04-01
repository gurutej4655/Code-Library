#include<stdio.h>
#include<stdlib.h>

void insertionsort(int*,int);
void swap(int*,int*);

void main()
{
    int n,i;
    printf("ENTER THE NUMBER OF ELEMENTS TO BE SORTED:");
    scanf("%d",&n);

    int a[n];

    for(i=0;i<n;i++) scanf("%d",&a[i]);

    insertionsort(a,n);
    for(i=0;i<n;i++) printf("%d ",a[i]);
}

void insertionsort(int* a,int n)
{
    int i,j,mini;

    for(i=0;i<n;i++)
    {
        mini=i;
        for(j=i;j<n;j++)
        {
            if(a[mini]>a[j]) { mini=j; }
        }printf("%d %d\n",a[mini],mini);
        if(i!=mini) swap(&a[i],&a[mini]);
    }
}

void swap(int* a,int* b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}
