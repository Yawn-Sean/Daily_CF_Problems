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

namespace Fac { // factorial
    constexpr int N = 6e5 + 5;
    Z fc[N], fc_inv[N], inv[N];
    auto __init_fac = []() -> bool {
        fc[0] = fc_inv[0] = raw(1);
        for (int i = 1; i < N; i++) {
            fc[i] = fc[i - 1] * raw(i);
        }
        fc_inv[N - 1] = fc[N - 1].inv();
        for (int i = N - 2; i > 0; i--) {
            fc_inv[i] = fc_inv[i + 1] * raw(i + 1);
        }
        inv[1] = 1;
        for (int i = 2; i < N; ++i) {
            inv[i] = fc_inv[i] * fc[i - 1];
        }
        return 1;
    }();
    Z I(const int x) { return inv[x]; }
    Z P(const int x, const int y) {
        return fc[x] * fc_inv[x - y];
    }
    Z C(const int x, const int y) {
        if (x == y) return raw(1);
        if (x < 0 || y < 0 || x - y < 0) return raw(0);
        return fc[x] * fc_inv[y] * fc_inv[x - y];
    }
} // namespace Fac

struct DSU {
    vector<int> fa, siz, cnt;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        siz.assign(n, 1);
        cnt.assign(n, 0);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
    void merge(int x, int y, Z &ans) {
        x = get(x), y = get(y);
        if (x == y) {
            if (++cnt[x] > 1)
                ans = 0;
            else
                ans = ans * Fac::I(siz[x]) * 2;
            return;
        }
        if (siz[y] > siz[x]) swap(x, y);
        if (cnt[x] && cnt[y]) {
            ans = 0;
            return;
        } else if (cnt[x]) {
            ans *= Fac::I(siz[y]);
        } else if (cnt[y]) {
            ans *= Fac::I(siz[x]);
        } else {
            ans = ans * Fac::I(siz[x]) * Fac::I(siz[y]) * (siz[x] + siz[y]);
        }
        siz[x] += siz[y], fa[y] = x;
        cnt[x] += cnt[y];
    }
    int size(int x) {
        return siz[get(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ai2> a(n);
    vector<int> b;
    b.reserve(n << 1);
    for (auto &[x, y] : a) {
        cin >> x >> y;
        b.push_back(x);
        b.push_back(y);
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    DSU dsu(b.size());
    Z ans(1);
    for (auto [x, y] : a) {
        if (ans.val()) {
            x = lower_bound(all(b), x) - b.begin();
            y = lower_bound(all(b), y) - b.begin();
            dsu.merge(x, y, ans);
        }
        cout << ans.val() << ' ';
    }
    cout << '\n';
}
int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
