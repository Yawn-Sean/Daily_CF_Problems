#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n+1);
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].push_back(i); G[i].push_back(p);
    }

    // from oi-wiki
    vector<int> fa(n+1), dep(n+1), siz(n+1), son(n+1), top(n+1), dfn(n+1), rnk(n+1);
    int cnt = 0;
    auto dfs1 = [&](auto &&self, int u) -> void {
        son[u] = -1;
        siz[u] = 1;
        for (auto &v: G[u]) if (!dep[v]) {
            dep[v] = dep[u] + 1;
            fa[v] = u;
            self(self, v);
            siz[u] += siz[v];
            if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
        }
    };
    auto dfs2 = [&](auto &&self, int u, int rt) {
        top[u] = rt;
        dfn[u] = ++cnt;
        rnk[cnt] = u;
        if (son[u] == -1) return;
        self(self, son[u], rt);
        for (auto &v: G[u]) if (v != fa[u] && v != son[u]) self(self, v, v);
    };
    auto lca = [&](int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) u = fa[top[u]];
            else v = fa[top[v]];
        }
        return dep[u] > dep[v] ? v : u;
    };
    dep[1] = 1;
    dfs1(dfs1, 1);
    dfs2(dfs2, 1, 1);

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = lca(a, b), e = lca(b, c), f = lca(c, a);
        int ans = 0;
        if (d == e && e == f) ans = max({dep[a], dep[b], dep[c]}) - dep[d];
        else {
            int u = d ^ e ^ f, v = (d + e + f - u) / 2;
            if (v != a && v != b && v != c) {
                if (u == d) ans = max({dep[u] + dep[c] - 2 * dep[v], dep[a] - dep[u], dep[b] - dep[u]});
                else if (u == e) ans = max({dep[u] + dep[a] - 2 * dep[v], dep[c] - dep[u], dep[b] - dep[u]});
                else ans = max({dep[u] + dep[b] - 2 * dep[v], dep[a] - dep[u], dep[c] - dep[u]});
            } else ans = max({abs(dep[a] - dep[u]), abs(dep[b] - dep[u]), abs(dep[c] - dep[u])});
        }
        cout << (ans + 1) << endl;
    }
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
