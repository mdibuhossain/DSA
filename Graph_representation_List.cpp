#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // n = vertices and m = edges
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}