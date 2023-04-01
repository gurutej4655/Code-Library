//INCOMPLETE
#include<iostream>
using namespace std;

void rotateArray(int a[],int i,int n)
{
    for(int j=i;j<(n+i)/2;j++)
    {
        //swap(a[j],a[j]);
    }
}

int main()
{
    int n;
    cout<<"N = ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int k;
    cout<<"K = ";
    cin>>k;

    rotateArray(a,0,k);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    rotateArray(a,k,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    rotateArray(a,0,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return(0);
}