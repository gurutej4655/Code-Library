#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    vector<vector<int>> a;
	    for(int i=0;i<n;i++)
	    {
	        cin>>k;
	        vector<int> b(k);
	        for(int j=0;j<k;j++) cin>>b[j];
	        a.push_back(b);
	    }
	    for(int i=0;i<n;i++)
	    {
            vector<int> b(k);
	        b=a[i];
	    }
	}
	return 0;
}
