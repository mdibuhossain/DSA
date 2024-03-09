#include <bits/stdc++.h>
using namespace std;

int minimumSpanningTree(int V, vector<vector<int>> adj[]) {  // vector<vector<int>> adj[] --> adj[u] = {v, w}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    // wt, n
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;
        for (auto ii : adj[node]) {
            int adjNode = ii[0];
            int adjWt = ii[1];
            if (!vis[adjNode]) {
                pq.push({adjWt, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int V = 4;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    adj[1].push_back({3, 15});
    adj[3].push_back({1, 15});
    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});
    adj[2].push_back({0, 6});
    adj[0].push_back({2, 6});
    adj[0].push_back({3, 5});
    adj[3].push_back({0, 5});

    // for (auto it : adj) {
    //     for (auto ii : it) {
    //         cout << ii[0] << " " << ii[1] << " ";
    //     }
    //     cout << endl;
    // }

    cout << minimumSpanningTree(V, adj) << endl;
    return 0;
}
