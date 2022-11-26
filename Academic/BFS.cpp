#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, int visited[], vector<int> adj[])
{
    queue<int> qu;
    qu.push(start);
    visited[start] = 1;
    while (!qu.empty())
    {
        int node = qu.front();
        cout << node << " ";
        qu.pop();
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                qu.push(it);
            }
        }
    }
}

int main()
{
    int edge;
    int start;
    int totalNode;
    vector<int> adj[totalNode + 2];
    int visited[totalNode + 2] = {0};
    // input total node number and total connections
    cin >> totalNode >> edge;
    // input connections
    for (int i = 1; i <= edge; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // input starting node
    cin >> start;
    BFS(start, visited, adj);
}