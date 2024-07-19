#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;

constexpr double eps = 1e-12;
const int inf = 1e9 + 7, P = 114584;

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    
    SegmentTree(int _n): n(_n), info(2 << (32 - __builtin_clz(_n))) {}
    template<class T>
    SegmentTree(std::vector<T>& _init): SegmentTree(_init.size()) {
        auto build = [&](auto&& self, int p, int l, int r) {
            if (l == r) {
                info[p] = { _init[l], l, _init[l], l };
                return;
            }
            int mid = l + r >> 1;
            self(self, p << 1, l, mid), self(self, p << 1 | 1, mid + 1, r);
            pull(p);
        };
        build(build, 1, 0, n - 1);
    }

    void pull(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y || r < x) return Info();
        if (x <= l && r <= y) 
            return info[p];
        int mid = l + r >> 1;
        return rangeQuery(p << 1, l, mid, x, y) + rangeQuery(p << 1 | 1, mid + 1, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }

};
struct Info {
    int mi = inf, mii = -1;
    int ma = -inf, mai = -1;
    Info operator + (const Info& b) const {
        Info res = {};
        if (mi < b.mi)
            res.mi = mi, res.mii = mii;
        else
            res.mi = b.mi, res.mii = b.mii;
        if (ma > b.ma)
            res.ma = ma, res.mai = mai;
        else
            res.ma = b.ma, res.mai = b.mai;
        return res;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i)
        std::cin >> a[i];
    SegmentTree<Info> sgt(a);
    for (int i = 0, l, r, x; i < m; ++ i) {
        std::cin >> l >> r >> x;
        auto t = sgt.rangeQuery(l - 1, r - 1);
        if (t.ma == x && t.mi == x) 
            std::cout << -1 << '\n';
        else {
            if (t.ma != x)
                std::cout << t.mai + 1 << '\n';
            else
                std::cout << t.mii + 1 << '\n';
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}