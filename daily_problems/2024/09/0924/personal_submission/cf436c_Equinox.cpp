#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;
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
    int n, m, k, w;
    std::cin >> n >> m >> k >> w;

    std::vector<std::vector<std::string>> g(k, std::vector<std::string>(n));
    for (int i = 0; i < k; ++ i) {
        for (int j = 0; j < n; ++ j)
            std::cin >> g[i][j];
    }

    std::vector<std::array<int, 3>> edges;

    auto getw = [&](int i, int j) -> int {
        int res = 0;
        for (int r = 0; r < n; ++ r)
            for (int c = 0; c < m; ++ c)
                if (g[i][r][c] != g[j][r][c])
                    res += w;
        return res;
    };

    for (int i = 0; i < k; ++ i) {
        edges.push_back({n * m, i, k});
        for (int j = i + 1; j < k; ++ j)
            edges.push_back({getw(i, j), i, j});
    }
    
    std::ranges::sort(edges);
    DSU dsu(k + 1);
    std::vector<std::vector<int>> adj(k + 1);
    int res = 0;
    for (auto &[c, u, v] : edges)
        if (dsu.merge(u, v)) {
            res += c;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    std::cout << res << '\n';

    std::stack<std::pair<int, int>> st;
    st.emplace(k, -1);
    while (st.size()) {
        auto [u, fa] = st.top();
        st.pop();

        for (int v : adj[u]) {
            if (v != fa) {
                std::cout << v + 1 << ' ' << (u < k ? u + 1 : 0) << '\n';
                st.emplace(v, u);
            }
        }
    }
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