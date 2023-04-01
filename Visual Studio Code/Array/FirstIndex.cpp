#include<iostream>
using namespace std;

int solve(int a[],int i,int n,int x)
{
    if(i==n) return(-1);

    if(a[i]==x) return(i);
    else 
    {
        return(solve(a,i+1,n,x));
    }
}

int main()
{
    int n;
    cout<<"Enter the size :";
    cin>>n;
    int a[n],x;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>x;

    cout<<solve(a,0,n,x);
}