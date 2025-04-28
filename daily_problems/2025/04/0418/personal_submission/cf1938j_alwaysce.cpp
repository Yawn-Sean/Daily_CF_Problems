#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> path(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        path[u].push_back({v, w});
        path[v].push_back({u, w});
    }
    
    vector<int> dis1(n, 1e9);
    vector<int> disn(n, 1e9);
    vector<int> parent(n, -1);
    vector<int> vis(n, 0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    dis1[0] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dis1[u]) continue;

        for (auto& [v, w] : path[u]) {
            if (dis1[v] > dis1[u] + w) {
                dis1[v] = dis1[u] + w;
                parent[v] = u;
                pq.push({dis1[v], v});  
            }
        }
    }

    int cur = n - 1;
    vis[cur] = 1;
    while (parent[cur] >= 0) {
        cur = parent[cur];
        vis[cur] = 1;
    }

    disn[n - 1] = 0;
    pq.push({0, n - 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (disn[u] == d) {
            for (auto& [v, w] : path[u]) {
                if (disn[v] > d + w) {
                    disn[v] = d + w;
                    parent[v] = u;
                    pq.push({disn[v], v});
                }
            }
        }
    }

    int ans = 1e9;
    for (int u = 0; u < n; u++) {
        for (auto& [v, w]: path[u]) {
            if (vis[u] && vis[v] && (parent[u] == v || parent[v] == u)) {
                continue;
            }
            ans = min(ans, dis1[u] + disn[v] + w);
        }
    }
    cout << (ans < 1e9 ? ans + dis1[n - 1] : -1) << endl;
    return 0;
}
