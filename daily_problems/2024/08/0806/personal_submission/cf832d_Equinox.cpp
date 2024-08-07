#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1e-9;

struct HLD {
    int n;
    std::vector<int> sz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;

    HLD() {}
    HLD(int _n)  {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        sz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }

    void dfs1(int u) { // dep和sz
        if (~parent[u]) //转有向图
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        
        sz[u] = 1;
        for (int &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            sz[u] += sz[v];
            if (sz[v] > sz[adj[u][0]])
                std::swap(v, adj[u][0]);
        }
    }

    void dfs2(int u) { // dfn
        in[u] = cur ++;
        seq[in[u]] = u;
        for (int v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;   // 欧拉序
    }

    int lca(int u, int v) const{
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]])
                u = parent[top[u]];
            else
                v = parent[top[v]];
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v) const{
        return dep[u] + dep[v] - dep[lca(u, v)] * 2;
    }

    int jump(int u, int k) { // 往上k层祖先
        if (dep[u] < k) return -1;

        int d = dep[u] - k;

        while (dep[top[u]] > d)
            u = parent[top[u]];

        return seq[in[u] - dep[u] + d];
    }

    bool isAncester(int u, int v) const{    // 括号序判断u 是否是 v 的祖先
        return in[u] <= in[v] && in[v] < out[v];
    }

    int rootedParent(int u, int v) const{   // 以v为p的u的祖先
        std::swap(u, v);
        if (u == v)
            return u;
        if (!isAncester(u, v))
            return parent[u];
        auto it = std::lower_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) -> bool {
            return in[x] < in[y];
        }) ;
        return * --it;
    }

    int rootedSize(int u, int v) {
        if (u == v)
            return n;
        if (!isAncester(v, u))
            return sz[u];
        return n - sz[rootedParent(u, v)];
    }

    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }

};

void solve() {
    int n, q;
    std::cin >> n >> q;

    HLD hld(n);

    for (int i = 1, p; i < n; ++ i) {
        std::cin >> p;
        hld.addEdge(p - 1, i);
    }

    hld.work();

    for (int i = 0, a, b, c; i < q; ++ i) {
        std::cin >> a >> b >> c;
        -- a, -- b, -- c;
        int d1 = (hld.dist(a, c) + hld.dist(b, c) - hld.dist(a, b)) / 2;
        int d2 = (hld.dist(a, b) + hld.dist(c, b) - hld.dist(a, c)) / 2;
        int d3 = (hld.dist(b, a) + hld.dist(c, a) - hld.dist(b, c)) / 2;
        std::cout << std::max({d1, d2, d3}) + 1 << '\n';
    }
}   


auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}