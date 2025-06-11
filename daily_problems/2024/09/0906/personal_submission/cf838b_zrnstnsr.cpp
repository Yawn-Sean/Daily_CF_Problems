#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

class LazySegTree {
    vector<ll> tree, lazy;
    int l, r;
    void build(vector<ll> &arr, int v, int l, int r) {
        if (l == r) tree[v] = arr[l];
        else {
            int mid = l + (r - l) / 2;
            build(arr, v * 2 + 1, l, mid);
            build(arr, v * 2 + 2, mid + 1, r);
            tree[v] = min(tree[v*2+1], tree[v*2+2]);
        }
    }
    void push(int v) {
        tree[v*2+1] += lazy[v]; lazy[v*2+1] += lazy[v];
        tree[v*2+2] += lazy[v]; lazy[v*2+2] += lazy[v];
        lazy[v] = 0;
    }
    void update(int v, int l, int r, int cl, int cr, int add) { // [cl, cr]: tree interval; [l, r]: update interval
        if (cl >= l && cr <= r) {
            tree[v] += add;
            lazy[v] += add;
        } else if (l <= r) {
            push(v);
            int m = cl + (cr - cl) / 2;
            update(v * 2 + 1, l, min(r, m), cl, m, add);
            update(v * 2 + 2, max(l, m + 1), r, m + 1, cr, add);
            tree[v] = min(tree[v*2+1], tree[v*2+2]);
        }
    }
    ll query(int v, int l, int r, int cl, int cr) {
        if (l > r) return 0x3f3f3f3f;
        else if (cl >= l && cr <= r) return tree[v];
        push(v);
        int m = cl + (cr - cl) / 2;
        ll left = query(v * 2 + 1, l, min(r, m), cl, m);
        ll right = query(v * 2 + 2, max(l, m + 1), r, m + 1, cr);
        return min(left, right);
    }
public:
    LazySegTree(vector<ll> &arr, int l, int r)
        : tree((r - l + 1) << 2), lazy((r - l + 1) << 2), l(l), r(r) { build(arr, 0, l, r); }
    void update(int l, int r, int add) { update(0, l, r, this->l, this->r, add); }
    ll query(int l, int r) { return query(0, l, r, this->l, this->r); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n+1);
    vector<int> end(n+1);
    vector<tuple<int, int, int>> edge(2 * n);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(i);
        edge[i] = {u, v, w};
    }
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[n-1+i] = {u, v, w};
        end[u] = w;
    }

    vector<ll> dis(n+1); // distance of 1->dfn[i]->1
    vector<int> fa(n+1), sz(n+1), rnk(n+1), dep(n+1), top(n+1), son(n+1);
    int cnt = 0;
    auto dfs1 = [&](auto &&self, int u) -> void { // note that we don't need ensure continuous dfn on heavy links
        sz[u] = 1;
        rnk[u] = ++cnt;
        auto cur = dis[cnt];
        for (auto e: G[u]) {
            auto [_, v, w] = edge[e];
            dis[cnt+1] = cur + w;
            dep[v] = dep[u] + 1;
            fa[v] = u;
            self(self, v);
            sz[u] += sz[v];
            if (dep[son[u]] < dep[v]) son[u] = v;
        }
        dis[rnk[u]] += end[u];
    };
    auto dfs2 = [&](auto &&self, int u, int t) -> void {
        top[u] = t;
        if (son[u]) self(self, son[u], t);
        for (auto e: G[u]) {
            auto v = get<1>(edge[e]);
            if (v != son[u]) self(self, v, v);
        }
    };
    auto lca = [&](int u, int v) -> int {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) u = fa[top[u]];
            else v = fa[top[v]];
        }
        return dep[u] > dep[v] ? v : u;
    };
    dfs1(dfs1, 1);
    dfs2(dfs2, 1, 1);

    LazySegTree seg(dis, 1, n);
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            if (a < n) {
                auto [_, v, w] = edge[a];
                seg.update(rnk[v], rnk[v] + sz[v] - 1, b - w);
                get<2>(edge[a]) = b;
            } else {
                auto [u, v, _] = edge[a];
                seg.update(rnk[u], rnk[u], b - end[u]);
                end[u] = b;
            }
        } else {
            auto u = seg.query(rnk[a], rnk[a]) - end[a];
            auto v = seg.query(rnk[b], rnk[b]) - end[b];
            if (lca(a, b) == a) cout << v - u << '\n';
            else {
                auto mn = seg.query(rnk[a], rnk[a] + sz[a] - 1);
                cout << mn - u + v << '\n';
            }
        }
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
