//should check in circular manner also
#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

void solve(int a[],int b[],int n)
{
    stack<int> st;
    int j=0;
    for(int i=2*n-1;i>=0;i--)
    {
        j=i%n;
        while(!st.empty() && st.top()<=a[j]) st.pop();
        if(i<n)
        {
            if(!st.empty()) b[i]=st.top();
            else{
                b[i]=-1;
            } }
            st.push(a[j]);
        
    }
}

int main()
{
    int n;
    cout<<"Size = ";
    cin>>n;
    int a[n],b[n];

    for(int i=0;i<n;i++) cin>>a[i];
    solve(a,b,n);
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
}