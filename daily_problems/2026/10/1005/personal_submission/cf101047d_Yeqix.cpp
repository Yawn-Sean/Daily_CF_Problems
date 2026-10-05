#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using ld = long double;
namespace rgs = ranges;

constexpr int inf = 1e9;
constexpr ld EPS = 1e-10;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 2>>> edge(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    vector<int> dist(n + 1, inf);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> que;
    que.push({dist[n] = 0, n});
    while (!que.empty()) {
        auto [dis, u] = que.top();
        que.pop();
        if (dis != dist[u]) {
            continue;
        }
        for (const auto& [v, w] : edge[u]) {
            if (dist[v] > dis + w) {
                que.push({dist[v] = dis + w, v});
            }
        }
    }

    ld l = 0, r = 1e9;
    for (int i = 1; i <= 100; i++) {
        ld mid = (l + r) / 2;
        ld ans = 0;
        for (int j = 1; j <= n; j++) {
            ans += min<ld>(dist[j], mid + k);
        }
        ans /= n;
        if (mid - ans > EPS) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(12) << min<ld>((l + r) / 2 + k, dist[1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}