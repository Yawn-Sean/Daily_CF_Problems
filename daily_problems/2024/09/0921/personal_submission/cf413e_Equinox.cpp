#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    
    SegmentTree(int _n): n(_n), info(2 << (32 - __builtin_clz(_n))) {}

    template<class T>
    SegmentTree(std::vector<T>& _init): SegmentTree(_init.size()) {
        auto build = [&](auto&& self, int p, int l, int r) {
            if (l == r) {
                info[p].init(_init[l]);
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

    void modify(int x, const Info& v) {
        modify(1, 0, n - 1, x, v);
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
    std::array<int, 4> d{ 0, inf32, inf32, 0 };
    void init(const std::array<int, 4> &d_) {
        d = d_;
    }
};

Info operator + (const Info& a, const Info& b) {
    Info res;
    std::array<int, 4> d;

    d[0] = std::min(a.d[0] + b.d[0], a.d[1] + b.d[2]);
    d[1] = std::min(a.d[0] + b.d[1], a.d[1] + b.d[3]);
    d[2] = std::min(a.d[2] + b.d[0], a.d[3] + b.d[2]);
    d[3] = std::min(a.d[2] + b.d[1], a.d[3] + b.d[3]);

    for (int i = 0; i < 4; ++ i)
        d[i] = std::min(d[i], inf32);
    
    res.init(d);
    return res;
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::vector<std::array<int, 4>> info(n);

    // AA AB BA BB

    for (int i = 0; i < n; ++ i) {
        if (s1[i] == 'X') {
            if (s2[i] == 'X') info[i] = { inf32, inf32, inf32, inf32 };
            else info[i] = { inf32, inf32, inf32, 0 };
        }
        else {
            if (s2[i] == 'X') info[i] = { 0, inf32, inf32, inf32 };
            else info[i] = { 0, 1, 1, 0 };
        }
    }

    SegmentTree<Info> sgt(info);

    for (int i = 0, l, r, fl, fr; i < m; ++ i) {
        std::cin >> l >> r;
        -- l, -- r;
        fl = fr = 0;
        if (l >= n) l -= n, fl = 1;
        if (r >= n) r -= n, fr = 1;
        if (l > r) std::swap(l, r), std::swap(fl, fr);

        int dir = fl * 2 + fr;
        int ans = sgt.rangeQuery(l, r).d[dir];
        std::cout << (ans < inf32 ? ans + r - l : -1) << '\n'; 
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}