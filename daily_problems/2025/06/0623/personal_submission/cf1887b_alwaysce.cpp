#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;

int inf = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    vector<vector<pair<int, int>>> path(n);
    for (int tt = 1; tt <= t; tt++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            path[u].emplace_back(tt, v);
            path[v].emplace_back(tt, u);
        }
    }

    int k;
    cin >> k;
    vector<int> ts(k);
    for (int i = 0; i < k; i++) {
        cin >> ts[i];
    }

    map<int, vector<int>> time_map;
    for (int i = 0; i < k; i++) {
        time_map[ts[i]].push_back(i + 1);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, inf);
    dist[0] = 0;
    pq.push({0, 0}); // {time, node}

    while (!pq.empty()) {
        auto [time, node] = pq.top();
        pq.pop();

        if (time > dist[node]) continue;

        for (auto &[eid, nxt_node] : path[node]) {
            auto it = lower_bound(time_map[eid].begin(), time_map[eid].end(), time + 1);
            if (it == time_map[eid].end()) continue; // No valid travel time
            int next_time = *it;
            if (next_time < dist[nxt_node]) {
                dist[nxt_node] = next_time;
                pq.push({next_time, nxt_node});
            }
        }
    }

    int ans = dist[n - 1];
    cout << (ans == inf ? -1 : ans) << endl;
    return 0;

}
