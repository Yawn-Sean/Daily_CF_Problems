#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e9 + 7, P = 1e9 + 7;


template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    
    SegmentTree(int _n): n(_n), info(2 << (32 - __builtin_clz(_n))) {}
    SegmentTree(std::vector<Info>& _init): SegmentTree(_init.size()) {
        auto build = [&](auto&& self, int p, int l, int r) {
            if (l == r) {
                info[p] = _init[l];
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

    void modify(int p, int l, int r, int x, const Info& v) {
        if (l == r) {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) modify(p << 1, l, mid, x, v);
        else modify(p << 1 | 1, mid + 1, r, x, v);
        pull(p);
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
    int x = inf;
    Info operator + (const Info& b) const {
        return  { std::min(x, b.x) };
    }
};


void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), nxt(n, n);

    std::map<int, int> last;

    for (int i = 0; i < n; i ++ ) {
        std::cin >> a[i];
        if (last.count(a[i]))
            nxt[last[a[i]]] = i;
        last[a[i]] = i;
    }
    std::vector<Info> d(n);
    for (int i = 0; i < n; i ++ )
        if (nxt[i] < n) 
            d[nxt[i]] = { nxt[i] - i };

    SegmentTree<Info> sgt(d);

    std::vector<std::array<int, 3>> q(m);
    std::vector<int> ans(m);
    for (int i = 0, l, r; i < m; i ++ ) 
        std::cin >> l >> r, q[i] = { l, r, i };
    std::sort(q.begin(), q.end(), [](auto& x, auto& y) {
        return x[0] < y[0];
    });

    for (int i = 0, st = 0; i < m; i ++ ) {
        auto [l, r, id] = q[i];
        -- l, -- r;
        while (st < l) {
            if (nxt[st] < n)
                sgt.modify(nxt[st], Info());
            ++ st;
        }
        ans[id] = sgt.rangeQuery(l, r).x;
    }

    for (int x : ans) std::cout << (x < inf ? x : -1) << '\n';
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}