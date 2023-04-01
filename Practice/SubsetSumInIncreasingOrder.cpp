//Same methodology as Printing sub sequences of the array
#include<iostream>
#include<vector>
using namespace std;

void solve(int a[],vector<int>& ans,int i,int n,int sum)
{
    if(i==n) 
    {
        ans.push_back(sum);
        return;
    }

    solve(a,ans,i+1,n,sum+a[i]);
    solve(a,ans,i+1,n,sum);
}

int main()
{
    int n;
    cout<<"Size : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> ans;

    solve(a,ans,0,n,0);

    //To sort it it will take O(N)logN which is not done here
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}