#include <iostream>
using namespace std;

int main()
{
    // n = vertices and m = edges
    int n, m;
    cin >> n >> m;
    int adj[n + 1][n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " \n"[j == n];
        }
    }

    return 0;
}