#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::map<int, std::vector<pii>> graph;
    std::vector<int> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, l;
        cin >> a >> b >> edges[i];
        a--; b--;
        graph[a].emplace_back(b, i);
        graph[b].emplace_back(a, i);
    }

    vector<i64> contrib(n - 1);
    vector<i64> size(n);
    auto dfs = [&](auto self, int cur, int parent) -> void {
        ++size[cur];
        for (auto[u, edge_id] : graph[cur]) {
            if (u == parent) {
                continue;
            }
            self(self, u, cur);
            contrib[edge_id] = 1ll * size[u] * (n - size[u]);
            size[cur] += size[u];
        }
    };
    dfs(dfs, 0, -1);

    const double p = 6.0 / n / (n - 1.0); 
    i64 ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += edges[i] * contrib[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int r, w;
        cin >> r >> w;
        r--;
        ans -= (edges[r] - w) * contrib[r];
        edges[r] = w;

        cout << fixed << setprecision(10) << ans * p << '\n';
    }

    return 0;
}