#include <bits/stdc++.h>
#include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1e-9;

struct DSU {
    std::vector<int> p;
    int n, sz;
    DSU(int _n) : p(_n, -1), n(_n), sz(_n) {}
    
    void init () {
        p.assign(n, -1);
    }

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
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
    std::vector<std::array<int, 3>> edges(m);
    
    i64 mi = inf64;
    for (int i = 0, a, b, c; i < m; ++ i) {
        std::cin >> a >> b >> c;
        edges[i] = { a - 1, b - 1, c };
        mi = std::min<i64>(mi, abs(c - k));
    }

    std::ranges::sort(edges, [](auto& a, auto& b) -> bool {
        return a[2] < b[2];
    });
    DSU dsu(n);
    i64 res = 0;

    for (auto& [a, b, c] : edges) {
        if (dsu.merge(a, b))
            res += std::max(0, c - k);
    }

    std::cout << (res ? res : mi) << '\n';
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
    std::cin >> t;
    while (t --)
        solve();

    return 0;
}