#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

template <class S, S (*op)(S, S), S (*e)()> struct segtree {

  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = 1, log = 0;
        while (size < _n)
            size <<= 1, log ++;
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

int fmin(int x, int y) {return min(x, y);}

int e() {return 1e6;}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;;

    vector<int> nums(n);
    for (auto &num: nums) cin >> num;

    vector<int> next_pos(n, n), dist(n, n);
    map<int, int> mp;

    for (int i = 0; i < n; i ++) {
        if (mp.find(nums[i]) != mp.end())
            dist[i] = i - mp[nums[i]];
        mp[nums[i]] = i;
    }

    mp.clear();
    for (int i = n - 1; i >= 0; i --) {
        if (mp.find(nums[i]) != mp.end())
            next_pos[i] = mp[nums[i]];
        mp[nums[i]] = i;
    }

    vector<int> ls(q), rs(q);
    for (int i = 0; i < q; i ++)
        cin >> ls[i] >> rs[i], ls[i] --;
    
    vector<int> queries(q), ans(q);
    iota(queries.begin(), queries.end(), 0);

    sort(queries.begin(), queries.end(), [&] (int i, int j) {return ls[i] < ls[j];});
    segtree<int, fmin, e> seg(dist);
    int pt = 0;

    for (auto &i: queries) {
        while (pt < ls[i]) {
            if (next_pos[pt] != n)
                seg.set(next_pos[pt], 1e6);
            pt ++;
        }
        ans[i] = seg.prod(ls[i], rs[i]);
    }

    for (auto &x: ans)
        cout << (x < n ? x : -1) << '\n';

    return 0;
}