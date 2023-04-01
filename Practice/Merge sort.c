#include<stdio.h>
#include<stdlib.h>

void merge(int*,int,int,int);
void mergesort(int*,int,int);

void main()
{
    int n,i;
    printf("ENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&n);

    int a[n];
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    mergesort(a,0,n);

    for(i=0;i<n;i++) printf("%d ",a[i]);
}

void mergesort(int* a,int p,int q)
{
    if(p<q)
    {
        int m=(p+q)/2;
        mergesort(a,p,m);
        mergesort(a,m+1,q);
        merge(a,p,m,q);
    }
}

void merge(int* a,int p,int m,int q)
{
    int n1,n2,i,j,k;

    n1=m-p+1;
    n2=q-m;

    int l[n1],r[n2];

    for(i=0;i<n1;i++)
    {
        l[i]=a[i+p];
    }
    for(i=0;i<n2;i++)
    {
        r[i]=a[i+n1+1];
    }

    i=0; j=0; k=p;
    while(i!=n1 && j!=n2)
    {
        if(l[i]>r[j]) { a[k]=r[j]; j++; }
        else { a[k]=l[i]; i++; }
        k++;
    }

    if(i==n1)
    {
        while(j!=n2)
        {
            a[k]=r[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i!=n1)
        {
            a[k]=l[i];
            i++;
            k++;
        }
    }
}
