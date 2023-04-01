#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &b)
{
    for(int i=0;i<b.size();i++) cout<<b[i]<<" ";

    cout<<endl;
}

void solve(int a[],vector<int> &b,int i,int n,int k)
{
   if(k==0)
    {
        print(b);
        return;
    }

    if(i==n || k<0) { 
        return;
     }

    b.push_back(a[i]);
    solve(a,b,i+1,n,k-a[i]);
    b.pop_back();
    solve(a,b,i+1,n,k);
}

int main()
{
    int n,k;
    cout<<"Enter the size of the array:";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Enter the Sum:";
    cin>>k;
    vector<int> b;
    solve(a,b,0,n,k);
}