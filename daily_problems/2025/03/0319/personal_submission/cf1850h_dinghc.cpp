#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200'000;
constexpr long long INF = 1e18;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> g(n);
        vector<array<int, 3>> conditions(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &conditions[i][0], &conditions[i][1], &conditions[i][2]);
            conditions[i][0] -= 1;
            conditions[i][1] -= 1;
            g[conditions[i][0]].emplace_back(conditions[i][1], conditions[i][2]);
            g[conditions[i][1]].emplace_back(conditions[i][0], -conditions[i][2]);
        }
        vector<long long> d(n, INF);
        auto dfs = [&] (this auto&& dfs, int u) -> void {
            for (auto& [v, w] : g[u]) if (d[v] == INF) {
                d[v] = d[u] + w;
                dfs(v);
            }
        };
        for (int u = 0; u < n; u++) if (d[u] == INF) {
            d[u] = 0LL;
            dfs(u);
        }
        bool ans = true;
        for (int i = 0; i < m; i++) {
            if (d[conditions[i][1]] - d[conditions[i][0]] != conditions[i][2]) {
                ans = false;
                break;
            }
        }
        printf("%s\n",  ans ? "YES" : "NO");
    }
    return 0;
}

