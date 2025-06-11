// 0805
#include <bits/stdc++.h>
using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;
        edges.emplace_back(w, u, v);
    }
 
    std::sort(begin(edges), end(edges));
    DSU dsu(n);
    i64 ret = 0;
    for (auto[w, u, v] : edges) {
        if (dsu.merge(u, v)) {
            ret += std::max(0, w - k);
        }
    }
    
    // All the edges in the minimal spanning tree have weight at most k.
    if (ret == 0) {
        ret = 1e9;
        for (auto [w, _, __] : edges) {
            ret = std::min(ret, (i64) abs(w - k));
        }
    }

    std::cout << ret << '\n';
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}  