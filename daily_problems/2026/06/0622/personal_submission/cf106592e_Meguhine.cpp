#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include <local/dbg.h>
#else
    #define dbg(...) 42
#endif

using LL = long long;

// clang-format off
#define ai(x) using ai##x = array<int, x>;
ai(2); ai(3); ai(4); ai(5); ai(6); ai(7); ai(8); ai(9); ai(10); ai(26);
#undef ai
// clang-format on

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
template <class T>
inline bool updmx(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template <class T>
inline bool updmn(T &x, const T &y) { return y < x ? x = y, 1 : 0; }
template <class T>
inline void clr(T &x) { T().swap(x); }

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l, LL r) { return rng() % (r - l + 1) + l; }

struct DSU {
    vector<int> fa, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        siz.assign(n, 1);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
    bool merge(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (siz[y] > siz[x]) swap(x, y);
        siz[x] += siz[y], fa[y] = x;
        return 1;
    }
    int size(int x) {
        return siz[get(x)];
    }
};

void solve() {
    constexpr int root = 1;
    int n, m, X;
    cin >> n >> m >> X;
    if (m + 1 == n) {
        vector<int> a(m);
        LL base = 0;
        for (int u, v; auto &w : a) {
            cin >> u >> v >> w;
            base += w;
        }
        LL ans = LL(1e16);
        for (auto w : a) {
            updmn(ans, base - w + (w ^ X));
        }
        cout << ans << '\n';
        return;
    }
    vector<ai3> edges(m);
    for (auto &[w, u, v] : edges) cin >> u >> v >> w;
    sort(all(edges));
    vector<vector<ai2>> e(n + 1);
    DSU dsu(n + 1);
    LL base = 0;
    vector<bool> not_mst(m);
    for (int i = 0; auto [w, u, v] : edges) {
        dbg(u, v, w);
        dbg(u, v, dsu.same(u, v));
        if (dsu.merge(u, v)) {
            e[u].push_back({v, w});
            e[v].push_back({u, w});
            base += w;
        } else
            not_mst[i] = 1;
        ++i;
    }
    LL ans = base;
    vector<int> dep(n + 1);
    const int mx_p = bit_width((unsigned)n) + 1;
    vector lca(n + 1, vector<int>(mx_p));
    vector mx(n + 1, vector<int>(mx_p));
    auto dfs_init = [&](auto &&self, int u, int fa) -> void {
        dep[u] = dep[fa] + 1, lca[u][0] = fa;
        for (auto [v, w] : e[u]) {
            if (v == fa) continue;
            mx[v][0] = w;
            self(self, v, u);
        }
    };
    dfs_init(dfs_init, root, 0);
    for (int p = 1; p < mx_p; p++) {
        for (int u = 1; u <= n; u++) {
            const int v = lca[u][p - 1];
            lca[u][p] = lca[v][p - 1];
            mx[u][p] = max(mx[u][p - 1], mx[v][p - 1]);
        }
    }
    auto LCA = [&](int u, int v) -> int {
        if (dep[v] < dep[u]) swap(u, v);
        int r = 0;
        for (int p = mx_p - 1; p >= 0; p--) {
            if (dep[lca[v][p]] >= dep[u]) {
                updmx(r, mx[v][p]);
                v = lca[v][p];
            }
        }
        if (u == v) return r;
        for (int p = mx_p - 1; p >= 0; p--) {
            if (lca[u][p] != lca[v][p]) {
                updmx(r, mx[u][p]);
                updmx(r, mx[v][p]);
                u = lca[u][p],
                v = lca[v][p];
            }
        }
        updmx(r, mx[u][0]);
        updmx(r, mx[v][0]);
        return r;
    };
    for (int i = 0; i < m; ++i) {
        const auto [w, u, v] = edges[i];
        if (not_mst[i]) {
            dbg(u, v, LCA(u, v));
            updmn(ans, base - LCA(u, v) + (w ^ X));
        } else {
            updmn(ans, base - w + (w ^ X));
        }
    }
    cout << ans << '\n';
}
int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
