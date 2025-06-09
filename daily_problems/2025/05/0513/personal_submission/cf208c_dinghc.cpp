#include <bits/stdc++.h>
 
using namespace std;
using int64 = long long;
constexpr int INF = 1e9;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto bfs = [&] (int s, vector<int64>& k, vector<int>& d) -> void {
        d[s] = 0;
        k[s] = 1;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto& v : g[u]) {
                if (d[u] + 1 < d[v]) {
                    d[v] = d[u] + 1;
                    k[v] = k[u];
                    q.push(v);
                } else if (d[u] + 1 == d[v]) {
                    k[v] += k[u];
                }
            }
        }
    };
    vector<int64> k1(n, 0);
    vector<int> d1(n, INF);
    bfs(0, k1, d1);
    vector<int64> k2(n, 0);
    vector<int> d2(n, INF);
    bfs(n - 1, k2, d2);
    int d = d1[n - 1];
    int64 tot = k1[n - 1];
    double ans = 1;
    for (int u = 1; u < n - 1; u++) {
        if (d2[u] + d1[u] == d || d1[u] + d2[u] == d) {
            ans = max(ans, static_cast<double>(k1[u] * k2[u] * 2) / tot);
        }
    }
    printf("%.8lf\n", ans);
    return 0;
}

