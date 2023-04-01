#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> g, int n)
{
    cout << "AFGER";
    // 1 unvisited
    // 2 visited and in queue
    <int> temp;
    vector<int> status;

    for (int i = 0; i < n; i++)
    {
        status[i] = 1;
    }

    status[0] = 2;
    // cout<<0;
    temp.push(0);
    cout << "EFHTY";

    while (temp.empty() != 1)
    {
        cout << "__";
        int cur = temp.front();
        temp.pop();
        cout << cur << endl;
        for (int i = 0; i < n; i++)
        {
            if (g[cur][i] == 1 && status[i] == 1)
            {
                status[i] = 2;
                temp.push(i);
            }
        }
    }
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

    bfs(g, n);
    return(0);
}
