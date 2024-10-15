#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {

  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = 1, log = 0;
        while (size <= _n)
            size *= 2, log ++;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

long long op1(long long x, long long y) {
    return 0;
}

long long op2(long long x, long long y) {
    return min(x, y);
}

long long e() {
    return 0;
}

long long e_to_depth() {
    return (long long) 1e12;
}


long long add(long long x, long long y) {
    return x + y;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> us(2 * n - 2), vs(2 * n - 2), ws(2 * n - 2), to_root(n, 0);
    vector<vector<int>> tree(n);

    for (int i = 0; i < (n - 1) * 2; i ++) {
        cin >> us[i] >> vs[i] >> ws[i];
        us[i] --, vs[i] --;

        if (i < n - 1) tree[us[i]].emplace_back(i);
        else to_root[us[i]] = ws[i];
    }

    vector<long long> depth(n);
    vector<int> ls(n), rs(n), stk = {0}, order;

    while (stk.size()) {
        int u = stk.back();
        stk.pop_back();
        if (u >= 0) {
            ls[u] = order.size();
            order.emplace_back(u);
            stk.emplace_back(~u);
            for (auto &i: tree[u]) {
                depth[vs[i]] = depth[us[i]] + ws[i];
                stk.emplace_back(vs[i]);
            }
        }
        else rs[~u] = order.size();
    }

    vector<long long> dfs_depth(n, 0);

    for (int i = 0; i < n; i ++) dfs_depth[i] = depth[order[i]];
    lazy_segtree<long long, op1, e, long long, add, add, e> seg_depth(dfs_depth);
    
    for (int i = 0; i < n; i ++) dfs_depth[i] += to_root[order[i]];
    lazy_segtree<long long, op2, e_to_depth, long long, add, add, e> seg_to_root(dfs_depth);

    while (q --) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i --;

            int delta = x - ws[i];
            ws[i] = x;

            if (i < n - 1) {
                seg_depth.apply(ls[vs[i]], rs[vs[i]], delta);
                seg_to_root.apply(ls[vs[i]], rs[vs[i]], delta);
            }
            else
                seg_to_root.apply(ls[us[i]], ls[us[i]] + 1, delta);
        }
        else {
            int u, v;
            cin >> u >> v;
            u --, v --;
            if (ls[u] <= ls[v] && rs[v] <= rs[u])
                cout << seg_depth.get(ls[v]) - seg_depth.get(ls[u]) << '\n';
            else
                cout << seg_to_root.prod(ls[u], rs[u]) - seg_depth.get(ls[u]) + seg_depth.get(ls[v]) << '\n';
        }
    }

    return 0;
}