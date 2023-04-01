#include <bits/stdc++.h>
#include <iostream>
#define k 4
using namespace std;
int n;

int dfs(int a[k][k],int i,int j,int n)
{
    int ii=i,jj=j;
    while(i>=0 && j>=0)
    {
        if(a[i][j]==1) return(0);
        i--;
        j--;
    }

    i=ii;
    j=jj;
    while(j>=0)
    {
        if(a[i][j]==1) return(0);
        j--;
    }

    j=jj;
    while(i<n && j>=0)
    {
        if(a[i][j]==1) return(0);
        i++;
        j--;
    }
    return(1);
}

void NQueen(int a[k][k],int j,int n)
{
    if(j==n)
    {
        for(int c=0;c<n;c++)
        {
            for(int d=0;d<n;d++)
            {
                cout<<a[c][d]<<" ";
            }cout<<endl;
        }cout<<endl;
    }

    for(int i=0;i<n;i++)
    {
        if(dfs(a,i,j,n))
        {
            a[i][j]=1;
            NQueen(a,j+1,n);
            a[i][j]=0;
        }
    }
}

int main()
{
    //int n;
    cout<<"Size : ";
    cin>>n;
    int a[k][k];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }

    NQueen(a,0,n);
}