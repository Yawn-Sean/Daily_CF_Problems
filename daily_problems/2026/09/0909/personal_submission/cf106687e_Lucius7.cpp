#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    std::queue<int> q;
    std::vector<int> vis(n);
    q.push(0);
    vis[0] = true;
    std::vector<std::vector<int>> f;
    std::vector<int> S;
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        S.push_back(x);
        for (auto [y, w] : adj[x]) {
            if (w == 0 && !vis[y]) {
                q.push(y);
                vis[y] = true;
            }
        }
    }
    f.push_back(S);
    std::vector<int> val{0};
    std::vector<int> minv(n, 1E13);
    for (int i = 0; i < f.size(); i++) {
        auto &v = f[i];
        for (auto x : v) {
            q.push(x);
        }
        
        std::vector<int> upd;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (auto [y, w] : adj[x]) {
                if (!vis[y]) {
                    upd.push_back(y);
                    minv[y] = std::min(minv[y], w);
                }
            }
        }

        std::map<int, std::vector<int>> mp;
        for (auto x : upd) {
            vis[x] = true;
            mp[minv[x]].push_back(x);
        }

        for (auto [w, vec] : mp) {
            f.push_back(vec);
            val.push_back((val[i] * k % P + w) % P);
        }
    }

    std::vector<int> ans(n, -1);
    for (int i = 0; i < f.size(); i++) {
        auto &v = f[i];
        for (auto x : v) {
            ans[x] = val[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
