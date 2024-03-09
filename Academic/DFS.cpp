#include <iostream>
#include <vector>
using namespace std;

void BFS(int start, int visited[], vector<int> adj[]) {
    visited[start] = 1;
    cout << start << " ";
    for (auto it : adj[start]) {
        if (!visited[it]) {
            BFS(it, visited, adj);
        }
    }
}

int main() {
    int edge;
    int start;
    int totalNode;
    vector<int> adj[totalNode + 2];
    int visited[totalNode + 2] = {0};
    // input total node number and total connections
    cin >> totalNode >> edge;
    // input connections
    for (int i = 1; i <= edge; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // input starting node
    cin >> start;
    BFS(start, visited, adj);
}