//element can be taken as amny times to make a sum
#include<iostream>
#include<vector>
using namespace std;

void printComb(int a[],vector<int> ans,int i,int n,int sum)
{
    if(i==n)
    {
        if(sum==0)
        {
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            cout<<endl;
        }return;
    }

        if(sum-a[i]>=0) { ans.push_back(a[i]); printComb(a,ans,i,n,sum-a[i]); ans.pop_back(); }
        printComb(a,ans,i+1,n,sum);
}

int main()
{
    int n;
    cout<<"Size = ";
    cin>>n;

    int a[n],sum;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Sum = ";
    cin>>sum;
    vector<int> ans;

    printComb(a,ans,0,n,sum);
}
