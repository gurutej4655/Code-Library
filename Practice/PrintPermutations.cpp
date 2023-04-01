#include<iostream>
#include<string>
using namespace std;

string fun(string s,int i)
{
    string x="";
    for(int j=0;j<s.size();j++)
    {
        if(j!=i) x=x+s[j];
    }
    return(x);
}

void solve(string s,string &ss)
{
    if(s.size()==0) { cout<<ss<<endl; return; }
    
    for(int j=0;j<s.size();j++)
    {
        ss=ss+s[j];
        string sb=fun(s,j);
        solve(sb,ss);
        ss.pop_back();
    }        
}

int main()
{
    string s,ss="";
    cin>>s;
    solve(s,ss);
    return(0);
}
