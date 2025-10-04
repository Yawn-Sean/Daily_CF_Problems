#include <bits/stdc++.h>

using namespace std;

static inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> nodes(k);
    for (int &x : nodes) cin >> x;

    vector<vector<int>> g(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int cur = 1;
    for (int x : nodes) {
        if (cur != x) {
            g[cur].emplace_back(x);
            g[x].emplace_back(cur);
            cur = x;
        }
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    bool ok = true;
    for (int i = 1; i < k; ++i) {
        if (dist[nodes[i]] <= dist[nodes[i - 1]]) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "-1\n";
        return;
    }

    cout << (nodes[0] == 1 ? k - 1 : k) << '\n';
    cur = 1;
    for (int x : nodes) {
        if (cur != x) {
            cout << cur << ' ' << x << '\n';
            cur = x;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
