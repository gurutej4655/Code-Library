//Least Recently Used cache
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int search(list<int> &a,int data)
{
    list<int>::iterator b=a.begin();
    for(int i=0;i<a.size();i++) { advance(b,i); if(*b==data) return(i); }
    return(-1);
}

void put(list<int> &a,int n,int data)
{
    int ch;
    if(ch=search(a,data)==-1)
    {
        while(a.size()>n-1) a.pop_back();
        a.push_front(data);
    }
    else{
        a.remove(data);
        a.push_front(data);      
    }
}

int get(list<int> &a,int data)
{
    if(search(a,data)==-1) return(-1);
    else{
        a.remove(data);
        a.push_front(data);
        return(data);                        
    }
}

void display(list<int> a)
{
    list<int>::iterator b=a.begin();
    for(int i=0;i<a.size();i++) cout<<*b<<" ";
}

int main()
{
    int n;
    cout<<"Size = ";
    cin>>n;

    list<int> a;
    put(a,n,1);
    cout<<endl;
    put(a,n,2);
    cout<<endl;
    cout<<get(a,1)<<endl; 
    put(a,n,3);
    cout<<endl;
    cout<<get(a,2)<<endl;
    put(a,n,4);
    cout<<endl;
    cout<<get(a,1)<<endl;
    cout<<get(a,3)<<endl;
    cout<<get(a,4)<<endl;      
}