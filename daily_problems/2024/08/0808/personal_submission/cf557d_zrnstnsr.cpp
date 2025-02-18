#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    vector<int> fa(n+1);
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](auto &&self, int x) -> int { return fa[x] == x ? fa[x] : fa[x] = self(self, fa[x]); };
    auto merge = [&](int u, int v) {
        u = find(find, u);
        v = find(find, v);
        if (u != v) fa[u] = v;
    };
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
        merge(u, v);
    }
    map<int, int> mp;
    int z = 0, o = 0;
    for (int i = 1; i <= n; ++i) ++mp[find(find, i)];
    for (auto [u, cnt]: mp) if (cnt == 1) ++z; else if (cnt == 2) ++o;
    int t; ll w;
    if (z == n) t = 3, w = 1LL * n * (n - 1) * (n - 2) / 6;
    else if (z + o * 2 == n) t = 2, w = 1LL * o * (n - 2);
    else {
        vector<int> vis(n+1);
        int siz[2];
        t = 1; w = 0;
        auto b = [](int x) { return (x + 1) / 2; };
        auto dfs = [&](auto &&self, int u) -> bool {
            ++siz[b(vis[u])];
            for (auto &v: G[u]) {
                if (!vis[v]) {
                    vis[v] = -vis[u];
                    if (!self(self, v)) return false;
                } else if (vis[v] + vis[u]) return false;
            }
            return true;
        };
        for (int i = 1; i <= n; ++i) if (mp[fa[i]] > 1 && !vis[i]) {
            vis[i] = 1;
            siz[0] = siz[1] = 0;
            if (!dfs(dfs, i)) {
                t = 0; w = 1;
                break;
            }
            for (int j = 0; j < 2; ++j) w += 1LL * siz[j] * (siz[j] - 1) / 2;
        }
    }
    cout << t << ' '  << w << endl;
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
