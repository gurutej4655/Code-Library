#include<iostream>
#include<vector>
#define k 9
#define l 3
using namespace std;

int checkPlace(int a[k][k],int i,int j,int z,int n)
{
    int ii=i,jj=j;
    
    for(j=0;j<n;j++)
    {
        if(a[i][j]==z) return(0);
    }
    j=jj;

    for(i=0;i<n;i++)
    {
        if(a[i][j]==z) return(0);
    }
    i=ii;

    ii=i/3;
    jj=j/3;
    for(int s=0;s<3;s++)
    {
        if(a[ii][s+jj]==z || a[ii+1][jj+s]==z || a[ii+2][jj+s]==z) return(0);
    }
    return(1);
}

int solve(int a[k][k],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0)
            {
                for(int z=1;z<=9;z++)
                {
                    if(checkPlace(a,i,j,z,n))
                    {
                        a[i][j]=z;
                        if(solve(a,n)) return(1);
                        else return(0);
                        a[i][j]=0;
                    }
                }
            }return(0);
        }
    }
    return(1);
}

int main()
{
    int n;
    cout<<"Size = ";
    cin>>n;

    int a[][9]=
       { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    solve(a,n);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
}