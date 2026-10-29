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

constexpr i64 inf = 1e18;

struct Info {
    i64 ans;

    Info() : ans(inf) {}
    Info(i64 x) : ans(x) {}
};

Info operator+(const Info& a, const Info& b) {
    return Info(min(a.ans, b.ans));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 d, l, n;
    cin >> d >> l >> n;
    vector<array<i64, 2>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i][0] >> f[i][1];
    }
    f.push_back({d, 0});

    vector<i64> p;
    for (int i = 0; i <= n + 1; i++) {
        p.push_back(2 * (l + f[i][0]) - f[i][1]);
    }

    rgs::sort(p);
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](i64 x) -> i64 { return rgs::lower_bound(p, x) - p.begin(); };

    SegmentTree<Info> st(n + 2);
    st.modify(get(2 * l), Info(0));

    vector<i64> dp(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        i64 r = f[i][1] + 2 * f[i][0];
        dp[i] = st.rangeQuery(get(r), n + 2).ans + f[i][0];
        i64 id = get(2 * (l + f[i][0]) - f[i][1]), v = st.rangeQuery(id, id + 1).ans;
        st.modify(id, Info(min(v, dp[i] - f[i][0] + f[i][1])));
    }

    if (dp[n + 1] >= inf) {
        cout << -1;
    } else {
        cout << dp[n + 1];
    }
    return 0;
}