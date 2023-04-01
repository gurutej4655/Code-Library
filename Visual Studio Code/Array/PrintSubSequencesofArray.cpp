#include<iostream>
#include<vector>
using namespace std;

void print(int a[],vector<int> ans,int i,int n)
{
    if(i==n)
    {
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }

    ans.push_back(a[i]);
    print(a,ans,i+1,n);
    ans.pop_back();
    print(a,ans,i+1,n);
}

void printS(int a[],vector<int> ans,int i,int n,int sum)
{
    if(i==n)
    {
        if(sum==0)
        {
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }

    ans.push_back(a[i]);
    printS(a,ans,i+1,n,sum-a[i]);
    ans.pop_back();
    printS(a,ans,i+1,n,sum);
}

int printCS(int a[],vector<int> ans,int i,int n,int sum)
{
    if(i==n)
    {
        if(sum==0) return(1);
        return(0);
    }

    int a1,a2;
    ans.push_back(a[i]);
    a1=printCS(a,ans,i+1,n,sum-a[i]);
    ans.pop_back();
    a2=printCS(a,ans,i+1,n,sum); 
    return(a1+a2);   
}

int printFS(int a[],vector<int> ans,int i,int n,int sum)
{
    if(i==n)
    {
        if(sum==0)
        {
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            cout<<endl;
            return(1);
        }
        return(0);
    }

    ans.push_back(a[i]);
    if(printFS(a,ans,i+1,n,sum-a[i])==1) return(1);
    ans.pop_back();
    if(printFS(a,ans,i+1,n,sum)==1) return(1);
    return(0);
}

int main()
{
    int n;
    cout<<"Enter the size : ";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    
    vector<int> ans;
    print(a,ans,0,n);     //Prints sub sequences
 
    int sum;
    cout<<"Sum = ";
    cin>>sum;
    //printS(a,ans,0,n,sum);  //Prints Sub sequences with the sum 'sum'

    //cout<<printCS(a,ans,0,n,sum);  //Counts Number of sub sequences with the sum 'sum' 

    //printFS(a,ans,0,n,sum); //Prints the firts subsequence with the sum 'sum' 
}
