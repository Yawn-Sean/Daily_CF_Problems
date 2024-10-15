#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> d(n + 1, -1);
    auto rad = [&](int u) -> pair<int, int> {
        int c = u;
        auto dfs = [&](auto &&self, int u, int fa) -> void {
            for (auto v: G[u]) if (v != fa) {
                d[v] = d[u] + 1;
                if (d[v] > d[c]) c = v;
                self(self, v, u);
            }
        };
        auto bdfs = [&](auto &&self, int u1, int fa1, int u2, int fa2, int flag) -> int {
            if (u1 == u2) return u1;
            if (flag) {
                for (auto v1: G[u1]) if (v1 != fa1) {
                    int res = self(self, v1, u1, u2, fa2, flag ^ 1);
                    if (res) return res;
                }
            } else {
                for (auto v2: G[u2]) if (v2 != fa2) {
                    int res = self(self, u1, fa1, v2, u2, flag ^ 1);
                    if (res) return res;
                }
            }
            return 0;
        };
        d[c] = 0;
        dfs(dfs, u, 0); int s = c;
        d[c] = 0; dfs(dfs, c, 0);
        return { bdfs(bdfs, s, 0, c, 0, 0), d[c] };
    };
    vector<int> center;
    int mx = -1, mu;
    for (int i = 1; i <= n; ++i) if (d[i] < 0) {
        auto [u, r] = rad(i);
        if (mx < r) mx = r, mu = u;
        center.push_back(u);
    }
    vector<pair<int, int>> edges;
    for (auto &u: center) if (u != mu) {
        G[u].push_back(mu); G[mu].push_back(u);
        edges.push_back({u, mu});
    }
    auto [_, ans] = rad(1);
    cout << ans << '\n';
    for (auto [u, v]: edges) cout << u << ' ' << v << '\n';
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
