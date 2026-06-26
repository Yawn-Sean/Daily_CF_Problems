#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include <local/dbg.h>
#else
    #define dbg(...) 42
#endif

using LL = long long;

// clang-format off
#define ai(x) using ai##x = array<int, x>;
ai(2); ai(3); ai(4); ai(5); ai(6); ai(7); ai(8); ai(9); ai(10); ai(26);
#undef ai
// clang-format on

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
template <class T>
inline bool updmx(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template <class T>
inline bool updmn(T &x, const T &y) { return y < x ? x = y, 1 : 0; }
template <class T>
inline void clr(T &x) { T().swap(x); }

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l, LL r) { return rng() % (r - l + 1) + l; }

#define ls (p << 1)
#define rs (p << 1 | 1)
#define PP int mid = (q[p].l + q[p].r) >> 1
template <class S, auto op, auto e>
struct _SGT { // acl-like segtree
private:
    struct Node {
        int l, r;
        S s;
    };
    vector<Node> q;
    void pull(int p) { q[p].s = op(q[ls].s, q[rs].s); }
    void build(const vector<S> &a, int l, int r, int p = 1) {
        q[p].l = l, q[p].r = r;
        if (l == r) return (void)(q[p].s = a[l]);
        int mid = (l + r) >> 1;
        build(a, l, mid, ls);
        build(a, mid + 1, r, rs);
        pull(p);
    }
    template <class G>
    int _minl(int r, const G &g, S &s, int p = 1) {
        if (q[p].r == r) {
            S ns = op(q[p].s, s);
            if (g(ns)) return s = ns, q[p].l;
        }
        if (q[p].l == q[p].r) return q[p].l + 1;
        PP;
        if (r <= mid)
            return _minl(r, g, s, ls);
        else {
            int res = _minl(r, g, s, rs);
            if (res > mid + 1)
                return res;
            else
                return _minl(mid, g, s, ls);
        }
    }
    template <class G>
    int _maxr(int l, const G &g, S &s, int p = 1) {
        if (q[p].l == l) {
            S ns = op(s, q[p].s);
            if (g(ns)) return s = ns, q[p].r;
        }
        if (q[p].l == q[p].r) return q[p].r - 1;
        PP;
        if (l > mid)
            return _maxr(l, g, s, rs);
        else {
            int res = _maxr(l, g, s, ls);
            if (res < mid)
                return res;
            else
                return _maxr(mid + 1, g, s, rs);
        }
    }

public:
    _SGT(int n) { init(n); }
    _SGT(const vector<S> &a, int n) { init(a, n); }
    void init(int n) { init(vector<S>(n + 1, e()), n); }
    void init(const vector<S> &a, int n) {
        q.resize(n * 4 + 10);
        build(a, 1, n);
    }
    S all_prod() const { return q[1].s; }
    S query(int l, int r, int p = 1) const {
        if (q[p].l == l && q[p].r == r) return q[p].s;
        PP;
        if (r <= mid)
            return query(l, r, ls);
        else if (l > mid)
            return query(l, r, rs);
        else
            return op(query(l, mid, ls), query(mid + 1, r, rs));
    }
    void set(int x, S s, int p = 1) {
        if (q[p].l == q[p].r) return (void)(q[p].s = s);
        PP;
        set(x, s, x <= mid ? ls : rs);
        pull(p);
    }
    S at(int x, int p = 1) {
        if (q[p].l == q[p].r) return q[p].s;
        PP;
        return at(x, x <= mid ? ls : rs);
    }
    template <auto g>
    int min_left(int r) { return min_left<decltype(g)>(r, g); }
    template <class G>
    int min_left(int r, const G &g) {
        assert(q[1].l <= r && r <= q[1].r);
        S s = e();
        return _minl(r, g, s);
    }
    template <auto g>
    int max_right(int l) { return max_right<decltype(g)>(l, g); }
    template <class G>
    int max_right(int l, const G &g) {
        assert(q[1].l <= l && l <= q[1].r);
        S s = e();
        return _maxr(l, g, s);
    }
};
#undef PP
#undef ls
#undef rs

namespace def { // example: single set, range sum
    using S = LL;
    S op(S a, S b) { // new s = a op b
        return std::gcd<LL>(a, b);
    }
    S e() { // x op e() = e() op x = x
        return S{};
    }
    using SGT = _SGT<S, op, e>;
}; // namespace def
using def::SGT;


int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n;
    cin >> n;
    if (n == 2) {
        vector<LL> a(2);
        cin >> a[0] >> a[1];
        {
            int u, v;
            cin >> u >> v;
        }
        int Q;
        for (cin >> Q; Q--;) {
            int u;
            LL x;
            cin >> u >> x;
            a[u] = x;
            if (a[1] == 1 or a[2] == 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        return 0;
    }
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<int>> e(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> leaf;
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 1)
            leaf.push_back(i);
        else
            root = i;
    }
    assert(root != -1);
    leaf.shrink_to_fit();
    vector<int> dfn(n + 1);
    const int non_leaf = [&]() -> int {
        int tot = 0;
        auto dfs = [&](auto &&self, int u, int fa) -> void {
            dfn[u] = ++tot;
            for (auto v : e[u]) {
                if (v == fa || e[v].size() == 1) continue;
                self(self, v, u);
            }
        };
        dfs(dfs, root, 0);
        const int ret = tot;
        for (auto u : leaf) dfn[u] = ++tot;
        return ret;
    }();
    vector<LL> sgt_init(n + 1);
    for (int u = 1; u <= n; ++u) sgt_init[dfn[u]] = a[u];
    SGT sgt(sgt_init, n);
    int Q;
    vector<LL> pre(leaf.size() + 1);
    for (cin >> Q; Q--;) {
        int u;
        LL x;
        cin >> u >> x;
        sgt.set(dfn[u], a[u] = x);
        if (sgt.all_prod() != 1) {
            cout << "No\n";
            continue;
        }
        if (leaf.size() >= 16) {
            cout << "Yes\n";
            continue;
        }
        const LL base = sgt.query(1, non_leaf);
        if (base == 1) {
            cout << "Yes\n";
            continue;
        }
        for (int i = 0; i < int(leaf.size()); ++i) {
            pre[i + 1] = std::gcd<LL>(pre[i], a[leaf[i]]);
        }
        bool ok = 0;
        LL suf = 0;
        for (int i = int(leaf.size()) - 1; i >= 0; --i) {
            const LL res = std::gcd<LL>(std::gcd<LL>(base, pre[i]), suf);
            if (res == 1) {
                ok = 1;
                break;
            }
            suf = std::gcd<LL>(suf, a[leaf[i]]);
        }
        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}

/*
首先, 显然只会割掉叶子和父亲的边
考虑最极端的情况, 一个菊花树, 除根节点外的点都是叶子
比如 1-2; 1-3; 1-4
a[1]=2*3*5, a[2]=2*3, a[3]=2*5, a[4]=3*5
这种情况下, 割掉哪一条边, 剩下的 gcd 都 != 1
w(10^18) == 15 < 16
所以如果叶子 >=16 个, 当整棵树的 gcd == 1 时, 直接输出 1 即可
不然的话, 就每个叶子暴力判断
上面的代码为了凑 2 的次幂, 选择在叶子 >16 个的时候, 才直接输出 1
*/
