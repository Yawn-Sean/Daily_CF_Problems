#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr i64 inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> w0;
    vector<vector<array<int, 2>>> edge(n);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        w0.push_back(w);
    }

    i64 ans = inf;
    for (const auto& x : w0) {
        priority_queue<array<i64, 2>, vector<array<i64, 2>>, greater<array<i64, 2>>> que;
        vector<i64> dist(n, inf);
        que.push({dist[0] = 0, 0});
        while (!que.empty()) {
            auto [dis, u] = que.top();
            que.pop();
            if (dis != dist[u]) {
                continue;
            }
            for (const auto& [v, w] : edge[u]) {
                if (dist[v] > dist[u] + max(w, x)) {
                    dist[v] = dist[u] + max(w, x);
                    que.push({dist[v], v});
                }
            }
        }

        ans = min(ans, dist[n - 1] - k * x);
    }

    cout << max<i64>(ans, 0);
    return 0;
}