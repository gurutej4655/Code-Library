#include<iostream>
using namespace std;

int main()
{
    int n,x;
    cout<<"Enter the size of the array:";
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++) cin>>a[i];
    x=a[0];
    for(int i=1;i<n;i++)
    {
        x=x^a[i];
    }

    cout<<"The unique element is : "<<x;
    return(0);
}