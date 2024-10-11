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
        assert(x < n);
        return -p[find(x)];
    }

    int size() const {
        return sz;
    }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> st(n);
    DSU dsu(n * 2);

    for (int i = 0, a; i < n; ++ i) {
        std::cin >> a;
        st[a - 1] = i;
        dsu.merge(i, i + n);
    }
    for (int i = 0, b; i < n; ++ i) {
        std::cin >> b;
        dsu.merge(st[b - 1], i + n);
    }

    st.assign(2 * n, 0);

    int pos = 0;

    for (int i = 0; i < n; ++ i) {
        int p = dsu.find(i);
        if (st[p]) continue;
        st[p] = true;
        pos += dsu.size(p) / 4;
    }

    i64 res = 0;

    for (int i = n; i > n - pos; -- i)
        res += i;

    for (int i = 1; i <= pos; ++ i)
        res -= i;
    
    std::cout << res * 2 << '\n';
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
    std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}