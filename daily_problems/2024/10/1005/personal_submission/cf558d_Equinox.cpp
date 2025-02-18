#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

struct DSU {
    std::vector<int> p;
    int n, sz;
    DSU(int _n) {
        init(_n);
    }
    
    void init (int _n) {
        sz = n = _n;
        p.assign(n, -1);
    }

    int find(int x) {
        int res = x;

        while (p[res] >= 0)
            res = p[res];

        while (p[x] >= 0) {
            int t = p[x];
            p[x] = res;
            x = t;
        }

        return res;
    }

    bool merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (p[px] > p[py]) std::swap(px, py);
        p[px] += p[py], p[py] = px;
        -- sz;
        return true;
    }

    int size(int x) {
        return -p[find(x)];
    }

    int size() const {
        return sz;
    }
};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> c(n);
    for (int i = 0; i < n; ++ i) {
        std::cin >> c[i];
        -- c[i];
    }

    DSU dsu(n);

    std::vector<std::vector<int>> adj(n);
    for (int i = 0, l, r; i < m; ++ i) {
        std::cin >> l >> r;
        -- l, -- r;
        dsu.merge(l, r);
    }

    std::vector<std::map<int, int>> st(n);

    for (int i = 0; i < n; ++ i) {
        ++ st[dsu.find(i)][c[i]];
    }

    int res = n;

    for (auto &mp : st) {
        int ma = 0;
        for (auto &[_, v] : mp)
            ma = std::max(ma, v);
        res -= ma;
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}