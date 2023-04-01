//distinct integers
//time complexity high
//space complexity low
//O(N!xN)
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void solve(int a[],vector<vector<int>>& ds,vector<int> ds1,int help[],int n)
{
    if(ds1.size()==n)
    {
        for(int i=0;i<ds1.size();i++) cout<<ds1[i]<<" ";
        cout<<endl;
        ds.push_back(ds1);
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(help[i]==0)
        {
            ds1.push_back(a[i]);
            help[i]=1;
            solve(a,ds,ds1,help,n);
            help[i]=0;
            ds1.pop_back();
        }
    }
}

int main()
{
    int n;
    cout<<"Size : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int help[n];
    for(int i=0;i<n;i++) help[i]=0;
    vector<vector<int>> ds;
    vector<int> ds1;
    solve(a,ds,ds1,help,n);
}