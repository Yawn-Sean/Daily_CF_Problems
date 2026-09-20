#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::tuple<int, int, int>> e(M);
    for (int i = 0; i < M; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        e[i] = {w, x, y};
    }

    std::sort(e.begin(), e.end());
    DSU dsu(N);
    std::vector<std::vector<int>> adj(N);
    int sum = 0;
    for (int i = 0; i < M; i++) {
        auto [w, x, y] = e[i];
        if (dsu.merge(x, y)) {
            sum += w;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    std::vector<int> ans;
    auto dfs = [&](this auto &&self, int x, int fa) -> void {
        ans.push_back(x);
        for (auto y : adj[x]) {
            if (y != fa) {
                self(y, x);
                ans.push_back(x);
            }
        }
    };
    dfs(0, -1);
    
    std::cout << sum * 2 << "\n";
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
