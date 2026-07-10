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
template <class S, auto op>
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

public:
    _SGT(const vector<S> &a, int n) { init(a, n); }
    void init(const vector<S> &a, int n) {
        q.resize(n * 4 + 10);
        build(a, 1, n);
    }
    S query(int l, int r, int p = 1) {
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
};
#undef PP
#undef ls
#undef rs

namespace def { // example: single set, range sum
    struct S {
        // type: 0 middle, 1 win, -1 lose
        signed char l_type, r_type;
        int l_len, r_len;
        int len, win;
    };
    S op(S a, S b) { // new s = a op b
        S c{};
        c.l_type = a.l_type, c.l_len = a.l_len;
        c.r_type = b.r_type, c.r_len = b.r_len;
        c.len = a.len + b.len;
        c.win = a.win + b.win;
        if (!a.r_type && !b.l_type) {
            c.l_len = c.r_len = c.len;
        } else if (a.r_type && !b.l_type) {
            c.r_type = a.r_type;
            c.r_len = a.r_len + b.len;
        } else if (!a.r_type && b.l_type) {
            c.l_type = b.l_type;
            c.l_len = a.len + b.l_len;
        } else {
            if (a.r_type == 1) {
                c.win += a.r_len + b.l_len;
            }
        }
        return c;
    }
    using SGT = _SGT<S, op>;
}; // namespace def
using def::S, def::SGT;

int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n, m;
    cin >> n >> m;
    const int tot = n + m;
    const S _e{0, 0, 1, 1, 1, 0};
    const S _win{1, 1, 0, 0, 1, 1};
    const S _lose{-1, -1, 0, 0, 1, 0};
    vector<S> a(tot + 1, _e);
    map<string, vector<pair<int, bool>>> mp;
    set<string> str_all;
    for (int i = 1; i <= tot; ++i) {
        int x, y;
        string s, t;
        cin >> x >> s >> y >> t;
        str_all.insert(s);
        str_all.insert(t);
        if (s == t) {
            a[i] = x > y ? _win : _lose;
        } else {
            mp[s].emplace_back(i, 1);
            mp[t].emplace_back(i, 0);
        }
    }
    SGT sgt(a, tot);
    auto query = [&]() -> int {
        S s = sgt.query(1, tot);
        if (!s.r_type) return tot;
        int win = s.win + s.l_len;
        if (s.r_type == 1) win += s.r_len;
        return win;
    };
    if (query() == n) {
        for (auto &&s : str_all) {
            if (mp.find(s) == mp.end()) {
                cout << s;
                return 0;
            }
        }
    }
    for (auto &&[str, vec] : mp) {
        for (auto [i, f] : vec) {
            sgt.set(i, f ? _win : _lose);
        }
        dbg(str, query());
        if (query() == n) {
            cout << str;
            return 0;
        }
        for (auto [i, _] : vec) {
            sgt.set(i, _e);
        }
    }
    cout << "*";
    return 0;
}
