#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
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
        f[y] = x;
        return true;
    }
};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> g;

    int rt = 0x3f3f3f3f;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        g.push_back({c, a, b});
        rt = std::min(rt, std::abs(k - c));
    }
    std::sort(g.begin(), g.end());
    DSU d(n + 1);
    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        if (d.merge(g[i][1], g[i][2])) {
            ans += std::max(g[i][0] - k, 0);
        }
    }
   
    std::cout << (ans == 0 ? rt : ans) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
