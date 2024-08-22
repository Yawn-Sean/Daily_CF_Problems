#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    vector<int> fa(n+1), sel(n+1), vis(n+1), ans;
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        fa[v] = u;
    }
    for (int i = 1; i <= n; ++i) cin >> sel[i], vis[sel[i]] = 1;
    auto dfs = [&](auto &&self, int u, int f) -> bool {
        if (vis[u]) ans.push_back(f = u);
        if (sel[u] != f) return false;
        for (auto v: G[u]) if (!self(self, v, f)) return false;
        return true;
    };
    bool suc = true;
    for (int i = 1; i <= n && suc; ++i) if (!fa[i]) suc = dfs(dfs, i, i);
    if (suc) {
        cout << ans.size() << '\n';
        for (auto p = ans.rbegin(); p != ans.rend(); ++p) cout << *p << '\n';
    } else cout << "-1\n";
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
