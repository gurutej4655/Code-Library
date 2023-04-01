#include<iostream>
#include<string>
using namespace std;

char fun(int t)
{
    char ch='a'+t-1;
    return(ch);
}

void solve(string s,string &ss,int i)
{
    if(i==s.size())
    {
        cout<<ss;
        ss.pop_back();
        cout<<endl;
        return;
    }

    int t=s[i]-'0';
    ss=ss+fun(t);
    solve(s,ss,i+1);

    if(s.size()==i+1) return;

     ss.pop_back(); 
     if(i==0 && s.size()%2==0) ss.pop_back();

    t=t*10+(s[i+1]-'0');
    if(t>26) return;
    ss=ss+fun(t);
    solve(s,ss,i+2);
}

int main()
{
    string s,ss;
    cin>>s;
    ss="";
    solve(s,ss,0);
}