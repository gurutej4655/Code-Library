#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int a[],int n,int k)
{
    list<int> li;
    li.push_front(0);
    for(int i=0;i<k;i++)
    {
        while(!li.empty() && a[li.back()]<=a[i]) li.pop_back();
        li.push_back(i);
    }cout<<a[li.front()]<<" ";
    for(int i=k;i<n;i++)
    {
        while(li.front()<=i-k) li.pop_front();

        while(!li.empty() && a[li.back()]<=a[i]) li.pop_back();
        li.push_back(i);
        cout<<a[li.front()]<<" ";
    }
} 

int main()
{
    int n,k;
    cout<<"Size + ";
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"K = ";
    cin>>k;

    solve(a,n,k);
}