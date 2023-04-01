#include<iostream>
using namespace std;

void Swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

int Partition(int a[],int i,int j)
{
    int c=0;
    for(int k=i+1;k<=j;k++) if(a[i]>a[k]) c++;

    Swap(a[i],a[c+i]);

    int m=i,n=j;

    while(!(m>=c+i || n<=c+i))
    {
        if(a[m]<a[c+i]) m++;
        else if(a[n]>=a[c+i]) n--;
        else { Swap(a[m],a[n]); m++; n--; }
    }
    return(c);
}

void QuickSort(int a[],int i,int j)
{
    if(i>=j) return;

    int mid=Partition(a,i,j);
    QuickSort(a,i,mid-1);
    QuickSort(a,mid+1,j);
}

int main()
{
    int n;
    cout<<"Enter the size:";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    QuickSort(a,0,n-1);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}