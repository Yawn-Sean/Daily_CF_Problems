#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n+1);
    vector<pair<int,int>> edges(m);
    vector<set<int>> T(n+1);
    vector<int> flow(n+1);
    vector<bool> vis(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        edges[i] = {u, v};
        flow[u] += w; flow[v] += w;
    }
    for (int i = 1; i <= n; ++i) flow[i] /= 2;
    flow[1] = 0; flow[n] = INT32_MAX;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w]: G[u]) {
            if (flow[v]) {
                flow[v] -= w;
                T[u].insert(v);
            }
            if (!flow[v] && !vis[v]) q.push(v);
        }
    }
    for (auto [u, v]: edges) cout << !T[u].count(v) << endl;
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
