#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n + 1), inver(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        inver[v].push_back(u);
    }

    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[i] = edge[i].size() / 2;
    }

    vector<array<int, 2>> det;
    auto rem = [&](int u, int v) -> void {
        det.push_back({u, v});
        cnt[u]--;
        for (auto it = edge[u].begin(); it != edge[u].end(); it++) {
            if ((*it) == v) {
                edge[u].erase(it);
                return;
            }
        }
    };

    vector<int> vis(n + 1);
    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {
        vis[u] = 1;
        for (const auto& v : inver[u]) {
            if (vis[v]) {
                continue;
            }
            if (cnt[v]) {
                rem(v, u);
                continue;
            }
            dfs(v, u);
        }
    };
    dfs(n, 0);

    vis.assign(n + 1, 0);
    auto check = [&](this auto&& check, int u, int fa) -> int {
        if (u == n) {
            return 1;
        }
        vis[u] = 1;
        int ans = 0;
        for (const auto& v : edge[u]) {
            if (vis[v]) {
                continue;
            }
            ans |= check(v, u);
        }
        return ans;
    };

    if (check(1, 0)) {
        cout << "-1\n";
        return;
    }

    cout << det.size() << "\n";
    for (const auto& [l, r] : det) {
        cout << l << " " << r << "\n";
    }
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