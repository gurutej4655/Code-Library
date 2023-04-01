//distinct integers
//time complexity low
//space complexity high
//O(N!xN)
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void solve(int a[],int i,int n)
{
    if(i==n)
    {
        for(int k=0;k<n;k++) cout<<a[k]<<" ";
        cout<<endl;
        return;
    }
    for(int j=i;j<n;j++) 
    {
        swap(a[i],a[j]);
        solve(a,i+1,n);
        swap(a[i],a[j]);
    }   
}

int main()
{
    int n;
    cout<<"Size : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
   
    solve(a,0,n);
}