//INCOMPLETE
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout<<"N = ";
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++) cin>>a[i];

    sort(a,a+n);
    int i=0,j=n-1,k,sum;
    cout<<"K = ";
    cin>>k;

    while(i<j)
    {
        sum=a[i]+a[j]-k;
        if(sum==0)
        {
            while(i<j && a[i]==a[i+1])
            {
                cout<<a[i]<<" "<<a[j]<<endl;
                i++;
            }
            while(i<j && a[j]==a[j-1])
            {
            cout<<a[i]<<" "<<a[j]<<endl;
            j--;
            }
            if(a[i]+a[j]==k)
            {
                cout<<a[i]<<" "<<a[j]<<endl;
                i++;
                j--;                
            }
        }
        else if(sum>0) j--;
        else i++;       
    }return(0);
}