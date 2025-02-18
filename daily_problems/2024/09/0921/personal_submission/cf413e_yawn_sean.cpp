#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

int inf = 1e6 + 5;

template <class S, S (*op)(S, S), S (*e)()> struct segtree {

  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = 1, log = 0;
        while (size <= _n)
            size *= 2, log ++;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

typedef array<int, 4> node;

node op(node x, node y) {
    node ans;
    ans[0] = min(x[0] + y[0], x[1] + y[2]);
    ans[1] = min(x[0] + y[1], x[1] + y[3]);
    ans[2] = min(x[2] + y[0], x[3] + y[2]);
    ans[3] = min(x[3] + y[3], x[2] + y[1]);
    for (int i = 0; i < 4; i ++) ans[i] = min(ans[i], inf);
    return ans;
}

node e() {
    node ans = {0, inf, inf, 0};
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    string s1, s2;
    cin >> s1 >> s2;

    vector<node> ar(n);

    for (int i = 0; i < n; i ++) {
        if (s1[i] == 'X') {
            if (s2[i] == 'X') ar[i] = {inf, inf, inf, inf};
            else ar[i] = {inf, inf, inf, 0};
        }
        else {
            if (s2[i] == 'X') ar[i] = {0, inf, inf, inf};
            else ar[i] = {0, 1, 1, 0};
        }
    }

    segtree<node, op, e> seg(ar);

    while (q --) {
        int u, v;
        cin >> u >> v;
        u --, v --;

        int l = u, sl = 0, r = v, sr = 0;
        if (l >= n) l -= n, sl = 1;
        if (r >= n) r -= n, sr = 1;

        if (l > r) swap(l, r), swap(sl, sr);

        int ans = seg.prod(l, r + 1)[2 * sl + sr];
        cout << (ans < inf ? ans + r - l : -1) << '\n'; 
    }

    return 0;
}