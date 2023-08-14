#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int starting = INT_MAX;
    vector<pair<int, pair<int, int>>> program;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    // cout << "Total program: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        program.push_back({i, {a, b}});
        starting = min(starting, a);
    }
    int total_time = starting;
    int cnt = 0;
    while (true) {
        for (int i = 0; i < n; i++) {
            if (program[i].second.first > -1 && program[i].second.first <= total_time) {
                qu.push({program[i].second.second, program[i].first});
                program[i].second.first = -1;
            }
        }
        if (qu.empty()) {
            cout << " - ";
            total_time++;
            continue;
        }
        cout << total_time << " ";
        int b_t = qu.top().first;
        int p_n = qu.top().second;
        total_time += b_t;
        cout << "P" << p_n << " ";
        cnt++;
        qu.pop();
        if (cnt == n) {
            cout << total_time << endl;
            break;
        }
    }
    return 0;
}
