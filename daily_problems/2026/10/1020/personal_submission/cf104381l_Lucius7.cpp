#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, T;
    std::cin >> n >> m >> T;
    T--;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    constexpr int inf = 1E18;
    std::vector dis(n, std::vector<int>(n, inf));
    dis[0][0] = 0;
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    for (int d = 0; d < n; d++) {
        for (int i = 0; i < n; i++) {
            if (dis[i][d] != inf) {
                pq.push({dis[i][d], i});
            }
        }

        while (!pq.empty()) {
            auto [dx, x] = pq.top();
            pq.pop();

            if (dis[x][d] < dx) {
                continue;
            }

            for (auto [y, w] : adj[x]) {
                if (w == 0) {
                    if (dx < dis[y][d]) {
                        dis[y][d] = dx;
                        pq.push({dx, y});
                    }
                }
            }
        }

        if (d + 1 < n) {
            for (int x = 0; x < n; x++) {
                if (dis[x][d] == inf) {
                    continue;
                }

                for (auto [y, w] : adj[x]) {
                    if (w > 0) {
                        dis[y][d + 1] = std::min(dis[y][d + 1], dis[x][d] + d * w);
                    }
                }
            }
        }
    }

    int ans = inf;
        for (int d = 0; d < n; d++) {
            ans = std::min(ans, dis[T][d]);
        }
    std::cout << (ans == inf ? -1 : ans) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
