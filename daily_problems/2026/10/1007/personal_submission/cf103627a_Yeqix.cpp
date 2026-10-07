#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

template <class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
    template <class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) { init(vector(n_, v_)); }
    template <class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        auto build = [&](auto&& build, int p, int l, int r) -> void {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(build, 2 * p, l, m);
            build(build, 2 * p + 1, m, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }
    void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }
    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info& v) { modify(1, 0, n, p, v); }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
    template <class F>
    int findFirst(int p, int l, int r, int x, int y, F&& pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findFirst(int l, int r, F&& pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template <class F>
    int findLast(int p, int l, int r, int x, int y, F&& pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findLast(int l, int r, F&& pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

constexpr int inf = 1e9;

struct Info {
    int ux, uy, vx, vy, ans;

    Info() : ux(inf), uy(inf), vx(inf), vy(inf), ans(inf) {}
    Info(int a, int b, int c, int d) : ux(a), uy(b), vx(c), vy(d) { ans = max(ux + vx, uy + vy); }
};

Info operator+(const Info& a, const Info& b) {
    Info res;
    res.ux = min(a.ux, b.ux);
    res.uy = min(a.uy, b.uy);
    res.vx = min(a.vx, b.vx);
    res.vy = min(a.vy, b.vy);
    res.ans = min({a.ans, b.ans, a.uy + b.vy, a.vx + b.ux});
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    vector<array<int, 4>> query;
    vector<array<int, 2>> dx, dy;
    vector<int> p;
    for (int i = 1; i <= q; i++) {
        int op, s, x, y;
        cin >> op >> s >> x >> y;
        query.push_back({op, s, x, y});
        if (s == 1) {
            dx.push_back({x, y});
            p.push_back(x - y);
        } else {
            dy.push_back({x, y});
            p.push_back(y - x);
        }
    }

    rgs::sort(p);
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int { return lower_bound(p.begin(), p.end(), x) - p.begin(); };

    SegmentTree<Info> st(q);
    vector<multiset<int>> ux(q, {inf}), uy(q, {inf}), vx(q, {inf}), vy(q, {inf});

    for (const auto& [op, s, x, y] : query) {
        int tx = get(x - y), ty = get(y - x);
        if (op == 1) {
            if (s == 1) {
                ux[tx].insert(x), uy[tx].insert(y);
            } else {
                vx[ty].insert(x), vy[ty].insert(y);
            }
        } else {
            if (s == 1) {
                ux[tx].erase(ux[tx].lower_bound(x));
                uy[tx].erase(uy[tx].lower_bound(y));
            } else {
                vx[ty].erase(vx[ty].lower_bound(x));
                vy[ty].erase(vy[ty].lower_bound(y));
            }
        }
        if (s == 1) {
            st.modify(tx, Info(*ux[tx].begin(), *uy[tx].begin(), *vx[tx].begin(), *vy[tx].begin()));
        } else {
            st.modify(ty, Info(*ux[ty].begin(), *uy[ty].begin(), *vx[ty].begin(), *vy[ty].begin()));
        }

        int ans = st.rangeQuery(0, q).ans;
        if (ans >= inf) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}