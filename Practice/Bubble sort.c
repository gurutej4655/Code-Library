#include<stdio.h>
#include<stdlib.h>

void swap(int*,int*);
void bubblesort(int*,int);

void main()
{
    int n;
    printf("ENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&n);

    int a[n],i;
    srand(1000);

    printf("ELEMENTS BEFORE SORTING:");
    for(i=0;i<n;i++) { a[i]=rand()%1000; printf("%d ",a[i]); }

    bubblesort(a,n);

    printf("\nELEMENTS AFTER SORTING:");
    for(i=0;i<n;i++) printf("\n%d ",a[i]);

}

void swap(int* a,int* b)
{
    int x=*a;
    *a=*b;
    *b=x;
}

void bubblesort(int* a,int n)
{
    int i,j,count=0;

    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
    {
        if(a[j]<a[j-1]) { swap(a+j,a+j-1); count++; }
    }
    if(count==0) break;
    }
}
