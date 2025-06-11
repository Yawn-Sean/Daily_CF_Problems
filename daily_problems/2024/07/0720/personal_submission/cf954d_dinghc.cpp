#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1000;
set<int> g[N + 1];

vector<int> dijkstra(int n, int s) {
    vector<int> d(n + 1, N);
    d[s] = 0;
    set<pair<int, int>> q;
    q.emplace(0, s);
    while (!q.empty()) {
        auto [wu, u] = *q.begin(); q.erase(q.begin());
        for (auto& v : g[u]) {
            if (d[v] > wu + 1) {
                auto it = q.lower_bound(make_pair(d[v], v));
                if (it != q.end()) q.erase(it);
                d[v] = wu + 1;
                q.emplace(d[v], v);
            }
        }
    }
    return d;
}

int main() {
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].insert(v);
        g[v].insert(u);
    }
    vector<int> ds = dijkstra(n, s);
    vector<int> dt = dijkstra(n, t);
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (g[u].find(v) == g[u].end()) {
                if (ds[u] + dt[v] + 1 >= ds[t] && ds[v] + dt[u] + 1 >= ds[t]) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

