namespace atcoder {
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
 
    template <class S, S (*op)(S, S), S (*e)()> struct segtree {
    public:
        segtree() : segtree(0) {}
        segtree(int n) : segtree(std::vector<S>(n, e())) {}
        segtree(const std::vector<S>& v) : _n(int(v.size())) {
            log = ceil_pow2(_n);
            size = 1 << log;
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
 
        S get(int p) {
            assert(0 <= p && p < _n);
            return d[p + size];
        }
 
        S prod(int l, int r) {
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
 
        S all_prod() { return d[1]; }
 
        template <bool (*f)(S)> int max_right(int l) {
            return max_right(l, [](S x) { return f(x); });
        }
        template <class F> int max_right(int l, F f) {
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
 
        template <bool (*f)(S)> int min_left(int r) {
            return min_left(r, [](S x) { return f(x); });
        }
        template <class F> int min_left(int r, F f) {
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
}
 
int op(int x, int y) {return std::max(x, y);}
int e() {return 0;}
 
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<std::array<int,2>>> ys(n);
    for (int i = 0, x1, x2, y; i < q; ++ i){
        std::cin >> x1 >> x2 >> y;
        ys[y].emplace_back(std::array<int,2>{x1, x2});
    }
 
    std::vector<int> nums(n+1, 1);
    atcoder::segtree<int, op, e> seg(nums);
 
    for (int i = 1; i <= n-1; ++ i){
        for (auto &b : ys[i]){
            if (seg.prod(b[0], b[1]+1)){
                while (true){
                    int p = seg.max_right(b[0], [&](int x){
                        return x == 0;
                    });
                    if (p <= b[1]) seg.set(p, 0);
                    else break;
                }
                seg.set(b[0], 1);
                seg.set(b[1], 1);
            }
        }
    }
 
    int res{};
    for (int i = 1; i <= n; ++ i){
        res += seg.get(i);
    }
    std::cout << res << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T{1};
    std::cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
