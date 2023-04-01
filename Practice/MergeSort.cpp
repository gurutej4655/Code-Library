#include<iostream>
using namespace std;

void Merge(int a[],int p,int m,int q)
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
        r[i]=a[i+m+1];
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

void MergeSort(int a[],int i,int j)
{
    if(j<=i) return;
    cout<<1;
    int mid=(i+j)/2;
    MergeSort(a,i,mid);
    MergeSort(a,mid+1,j);
    Merge(a,i,mid,j);
}

int main()
{
    int n;
    cout<<"Enter size :";
    cin>>n;

    int a[n],i=0,j=n;
    for(int i=0;i<n;i++) cin>>a[i];

    MergeSort(a,i,j);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}