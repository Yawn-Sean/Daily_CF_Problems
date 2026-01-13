#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e6;

map<int, int> pi {
  {2, 0}, {3, 1}, {5, 2}, {7, 3}, {11, 4}, {13, 5}, {17, 6}, {19, 7}, {23, 8},{29, 9},
  {31, 10}, {37, 11}, {41, 12}, {43, 13}, {47, 14}, {53, 15}, {59, 16}, {61, 17}, {67, 18}
};

struct fast_lca {
    vector<vector<int>>& g;
    vector<int> tin, tout;
    vector<vector<int>> up;
    int timer = 0;
    int l = 0;
    fast_lca(int n, vector<vector<int>>& t)
        : g(t), timer(0), tin(n, 0), tout(n, 0) {
        l = 32 - __builtin_clz(n);
        up.assign(n, vector<int>(l + 1));
        dfs(0, 0);
    }
    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];
        for (auto& u : g[v]) if (u != p) {
            dfs(u, v);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<vector<int>> g(n, vector<int>());
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    vector<int> parent(n, 0);
    vector<int> xors(n, 0);
    auto dfs = [&] (auto&& dfs, int u, int p) -> void {
        parent[u] = p;
        xors[u] = xors[p];
        int q = a[u];
        for (auto& [p, i] : pi) {
            if (q == 1) break;
            while (q % p == 0) {
                q /= p;
                xors[u] ^= 1 << i;
            }
        }
        for (auto& v : g[u]) if (v != p) {
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 0, 0);
    fast_lca f(n, g);
    int q;
    scanf("%d", &q);
    for (int i = 0, u, v; i < q; i++) {
        scanf("%d %d", &u, &v);
        u -= 1;
        v -= 1;
        int lca = f.lca(u, v);
        int val = xors[u] ^ xors[v] ^ xors[lca];
        if (lca) {
            val ^= xors[parent[lca]];
        }
        printf("%d\n", val ? 1 : 0);
    }
    return 0;
}

