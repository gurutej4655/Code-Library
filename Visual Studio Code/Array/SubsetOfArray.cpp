//same as sub sequences
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &b)
{
    for(int i=0;i<b.size();i++) cout<<b[i]<<" ";

    cout<<endl;
}

void solve(int a[],vector<int> &b,int i,int n)
{
    if(i==n) { 
        if(b.size()==0) cout<<"{}"<<endl;
        else print(b);
        return;
     }

    b.push_back(a[i]);
    solve(a,b,i+1,n);
    b.pop_back();
    solve(a,b,i+1,n);
}

int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b;
    solve(a,b,0,n);
}