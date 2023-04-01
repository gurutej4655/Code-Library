#include<iostream>
#include<string>
using namespace std;

char a[8][4]={
    {'a','b','c'},
    {'d','e','f'},
    {'g','h','i'},
    {'j','k','l'},
    {'m','n','o'},
    {'p','q','r','s'},
    {'t','u','v'},
    {'w','x','y','z'}
};

void solve(int s,string ss)
{
    if(s==0)
    {
        cout<<ss<<endl;
        return;
    }
    
    int k=s%10;
    solve(s/10,a[k-2][0]+ss);
    solve(s/10,a[k-2][1]+ss);
    solve(s/10,a[k-2][2]+ss);

    if(k==7 || k==9)
    {
        solve(s/10,ss+a[k-2][3]);
    }
}

int main()
{
    string o="";
    int i;
    cin>>i;
    solve(i,o);
    return(0);
}