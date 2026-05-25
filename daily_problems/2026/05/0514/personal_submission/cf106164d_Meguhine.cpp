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

#define D constexpr MI
#define C const
#define O operator
template <unsigned int mod>
struct MI {
    D() : v(0) {}
    template <typename T>
    D(T x) : v(x % mod) {
        if (v < 0) v += mod;
    }
    template <typename T>
    static D raw(T x) {
        MI z;
        z.v = x;
        return z;
    }
    D pow(LL n) C {
        MI x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    D inv() C { return pow(mod - 2); }
    D &O += (C MI & x) {
        if (unsigned(v += x.v) >= mod) v -= mod;
        return *this;
    }
    D &O -= (C MI & x) {
        if ((v -= x.v) < 0) v += mod;
        return *this;
    }
    D &O *= (C MI & x) {
        LL z = v;
        z *= x.v;
        v = z % mod;
        return *this;
    }
    D &O /= (C MI & x) { return *this = *this * x.inv(); }
    constexpr int val() C { return v; }
    static constexpr unsigned int umod() { return mod; }
    friend constexpr bool O == (C MI & x, C MI &y) { return x.val() == y.val(); }
#define OP(s, t) \
    friend D O s(C MI &x, C MI &y) { return MI(x) t y; }
    OP(+, +=)
    OP(-, -=)
    OP(*, *=)
    OP(/, /=)
#undef OP
private:
    int v;
};
#undef D
#undef C
#undef O

using Z = MI<998244353>;
#define raw(x) Z::raw(x)


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

using SGT = _SGT<
    int, [](int x, int y) { return min<int>(x, y); },
    []() { return INT_MAX; }
>;

template <class T, LL type>
    requires(type == 1 || type == T(1) / T(2))
void fwtxor(vector<T> &a, int _n = -1) {
    const int n = [&]() -> int {
        if (_n == -1) {
            const int ret = bit_ceil(a.size());
            a.resize(ret, T(0));
            return ret;
        } else {
            assert((_n & (_n - 1)) == 0);
            assert(int(a.size()) >= _n);
            return _n;
        }
    }();
    for (int x = 2; x <= n; x <<= 1) {
        int k = x >> 1;
        for (int i = 0; i < n; i += x) {
            for (int ij = i, j = 0; j < k; ++ij, ++j) {
                a[ij] += a[ij + k];
                a[ij + k] = a[ij] - a[ij + k] * 2;
                a[ij] *= type;
                a[ij + k] *= type;
            }
        }
    }
}

Z bf(const vector<int> &sg, const int m) {
    Z ans = 0;
    auto dfs = [&](auto &&self, int u, int cur) -> void {
        if (u == m) {
            ans += (!cur);
            return;
        }
        for (auto x : sg) {
            self(self, u + 1, cur ^ x);
        }
    };
    dfs(dfs, 0, 0);
    dbg(sg, m, ans.val());
    return ans;
}
Z calc(const vector<int> &sg, const int m) {
    const int sz = *max_element(all(sg));
    vector<Z> a(sz + 1);
    for (auto x : sg) a[x] += 1;
    fwtxor<Z, 1>(a);
    for (auto &x : a) x = x.pow(m);
    constexpr LL inv2 = (Z(1) / Z(2)).val();
    fwtxor<Z, inv2>(a);
#ifdef LOCAL
    assert(a[0] == bf(sg, m));
#endif
    return a[0];
}

int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n, K, R;
    cin >> n >> K >> R;
    if (K == 0) {
        cout << "0";
        return 0;
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    SGT sgt(vector<int>(n + 3, -1), n + 2);
    auto update = [&](int i, int x) -> void {
        sgt.set(i + 1, x);
    };
    auto query = [&](int x) -> int {
        return sgt.max_right(1, [&](int s) { return s >= x; });
    };
    update(0, 0);
    vector<int> sg(n + 1);
    for (int i = 1; i <= n; ++i) {
        sg[i] = query(i - a[i]);
        update(sg[i], i);
#ifdef LOCAL
        dbg(i, i - a[i], sg[i]);
        vector<int> vec = {};
        for (int j = i - a[i]; j < i; ++j) {
            vec.push_back(sg[j]);
        }
        sort(all(vec));
        vec.erase(unique(all(vec)), vec.end());
        for (int x = 0;; ++x) {
            if (x == (int)vec.size() || vec[x] != x) {
                assert(sg[i] == x);
                break;
            }
        }
        for (int x = 1; x <= n + 1; ++x) {
            cerr << sgt.at(x) << " ";
        }
        cerr << endl;
#endif
    }
    vector<int> sp{sg.end() - K, sg.end()};
    sp.reserve(n + 1);
    for (int i = n - K; i >= 0; --i) {
        if (sg[i] == sg[i + K]) {
            sp.push_back(sg[i]);
            dbg(i, sg[i], sg[i + K]);
        }
    }
    Z ans = calc(sg, R) - calc(sp, R);
    cout << ans.val();
    return 0;
}
