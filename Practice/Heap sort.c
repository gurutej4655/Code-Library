#include<stdio.h>
#include<stdlib.h>

void maxheapify(int*,int,int);
void buildmaxheap(int*,int);
void heapsort(int*,int);
void swap(int*,int*);

void main()
{
    int n,i;
    printf("ENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&n);

    int a[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY:");
    for(i=1;i<=n;i++) scanf("%d",&a[i]);

    heapsort(a,n);

    for(i=1;i<=n;i++) printf("%d ",a[i]);
}

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapsort(int* a,int n)
{

    buildmaxheap(a,n);
    int i;
    for(i=n;i>=1;i--)
    {
        swap(&a[1],&a[i]);
        maxheapify(a,i,1);
    }
}

void buildmaxheap(int* a,int n)
{
    int i;
    for(i=(n/2);i>=1;i--)
    {
        maxheapify(a,n,i);
    }
}

void maxheapify(int* a,int n,int i)
{
    int l,r,large=i;
    l=2*i;
    r=2*i+1;

    if(l<n && a[l]>a[large]) large=l;

    if(r<n && a[r]>a[large]) large=r;

    if(large!=i)
    {
        swap(&a[i],&a[large]);
        maxheapify(a,n,large);
    }
}
