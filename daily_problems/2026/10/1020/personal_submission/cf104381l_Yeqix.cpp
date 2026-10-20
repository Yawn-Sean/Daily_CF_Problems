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
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<array<i64, 2>>> edge(n + 1);
    for (int i = 1; i <= m; i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    priority_queue<array<i64, 3>, vector<array<i64, 3>>, greater<array<i64, 3>>> que;
    vector dp(n + 1, vector<i64>(1002, inf));
    dp[1][0] = 0;
    que.push({0, 1, 0});
    while (!que.empty()) {
        auto [dis, u, d] = que.top();
        que.pop();
        if (dis != dp[u][d]) {
            continue;
        }
        for (const auto& [v, w] : edge[u]) {
            if (w == 0) {
                if (dp[v][d] > dis) {
                    dp[v][d] = dis;
                    que.push({dis, v, d});
                }
            } else {
                if (dp[v][d + 1] > dis + d * w) {
                    dp[v][d + 1] = dis + d * w;
                    que.push({dp[v][d + 1], v, d + 1});
                }
            }
        }
    }

    i64 ans = inf;
    for (int i = 0; i <= 1000; i++) {
        ans = min(ans, dp[t][i]);
    }

    if (ans >= inf) {
        cout << "-1";
    } else {
        cout << ans;
    }
    return 0;
}