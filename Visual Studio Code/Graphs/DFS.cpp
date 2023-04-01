#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>> g, int n)
{
    
}

int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;
    vector<int> tt(n);

    vector<vector<int>> g(n, tt);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    dfs(g, n);
    return (0);
}