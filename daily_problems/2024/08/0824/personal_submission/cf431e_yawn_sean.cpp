#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

struct container {
    long long tot;
    int vol;
    int sz;
};

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

container op(container c1, container c2) {
    if (c1.sz == 0) return c2;
    if (c2.sz == 0) return c1;
    container ans = {c1.tot + c2.tot + 1ll * (c2.vol - c1.vol) * c1.sz, c2.vol, c1.sz + c2.sz};
    return ans;
}

container e() {
    container ans = {0, 0, 0};
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> volumes = nums, xs(q, -1);
    vector<long long> ys(q);
    for (int i = 0; i < q; i ++) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            cin >> xs[i] >> ys[i];
            xs[i] --, volumes.emplace_back(ys[i]);
        }
        else
            cin >> ys[i];
    }
    sort(volumes.begin(), volumes.end());
    int k = unique(volumes.begin(), volumes.end()) - volumes.begin();

    map<int, int> mp;
    for (int i = 0; i < k; i ++)
        mp[volumes[i]] = i;
    
    vector<container> ar(k);
    for (int i = 0; i < k; i ++)
        ar[i].vol = volumes[i];
    
    for (int i = 0; i < n; i ++)
        ar[mp[nums[i]]].sz ++;
    
    segtree<container, op, e> seg(ar);

    cout << setprecision(10);

    int idx;
    for (int i = 0; i < q; i ++) {
        if (~xs[i]) {
            idx = mp[nums[xs[i]]];
            ar[idx].sz --;
            seg.set(idx, ar[idx]);

            nums[xs[i]] = ys[i];

            idx = mp[nums[xs[i]]];
            ar[idx].sz ++;
            seg.set(idx, ar[idx]);
        }
        else {
            container ans = seg.prod(0, seg.max_right(0, [&] (container c) -> bool {return c.tot <= ys[i];}));
            cout << 1.0 * (ys[i] - ans.tot) / ans.sz + ans.vol << '\n';
        }
    }

    return 0;
}