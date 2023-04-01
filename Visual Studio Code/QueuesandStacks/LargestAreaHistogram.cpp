#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int a[],int n)
{
    int b[n],c[n];
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        if(st.empty()) b[i]=0;
        else b[i]=st.top()+1;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        if(st.empty()) c[i]=n-1;
        else c[i]=st.top()-1;
        st.push(i);
    }
    int maxA=0;
    for(int i=0;i<n;i++)
    {
        if(maxA<((c[i]-b[i]+1)*(a[i]))) maxA=(c[i]-b[i]+1)*(a[i]);
    }
    cout<<maxA;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    solve(a,n);
    return(0);
}