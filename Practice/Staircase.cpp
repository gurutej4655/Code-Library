#include<iostream>
using namespace std;

int solve(int n)
{
    if(n==0) return(1);
    if(n<0) return(0);

    int ans=0; 
    ans=ans+solve(n-1);
    ans=ans+solve(n-2);
    ans=ans+solve(n-3);

    return(ans);
}

int main()
{
    int n;
    cin>>n;

    cout<<solve(n);
}