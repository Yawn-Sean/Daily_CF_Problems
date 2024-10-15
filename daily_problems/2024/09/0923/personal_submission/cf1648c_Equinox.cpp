#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

int power(int a, int b, int p){
    int res = 1;
    for (; b; b >>= 1, a = 1LL * a * a % p)
        if (b & 1)
            res = 1LL * res * a % p;
    return res;
}

struct Comb{
    static constexpr int P = 998'244'353;
    int n;
    std::vector<int> _fac;
    std::vector<int> _invfac;
    std::vector<int> _inv;

    Comb(): n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n): Comb() {
        init(n);
    }

    void init(int m) {
        if (m <= n) return;

        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; ++ i)
            _fac[i] = 1LL * _fac[i - 1] * i % P;
        _invfac[m] = power(_fac[m], P - 2, P);
        for (int i = m; i > n; -- i) {
            _invfac[i - 1] = 1LL * _invfac[i] * i % P;
            _inv[i] = 1LL * _invfac[i] * _fac[i - 1] % P;
        }
        n = m;
    }

    int fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }

    int invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }

    int inv(int m){
        if (m > n) init(2 * m);
        return _inv[m];
    }

    int binom(int n, int m) {
        if (n < 0 || m < 0) return 0;
        return 1LL * fac(n) * invfac(m) % P * invfac(n - m) % P;
    }
};

template<typename T = int>
class FenWick {
private:
    int n;
    std::vector<T> tr;
public:
    FenWick(int _n) : n(_n), tr(_n + 1) 
    {}
    FenWick(const std::vector<T> &_init) : FenWick(_init.size()) {
        init(_init);
    }

    void init(const std::vector<T> &_init) {
        for (int i = 1; i <= n; ++ i) {
            tr[i] += _init[i - 1];
            int j = i + (i & -i);
            if (j <= n)
                tr[j] += tr[i];
        }
    }

    void add(T x, T k) {
        for (; x <= n; x += x & -x) tr[x] += k;
    }

    void add(T l, T r, T k) {
        add(l, k), add(r + 1, -k);
    }

    T query(T x) const {
        T res = T{};
        for (; x; x &= x - 1) res += tr[x];
        return res;
    }

    T query(T l, T r) const {
        if (l > r) return T{};
        return query(r) - query(l - 1);
    }

    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + tr[x + i] <= k) {
                x += i;
                cur = cur + tr[x];
            }
        }
        return x;
    }
};

constexpr int P = 998'244'353;

void solve() {
    constexpr int N = 200'000;
    Comb comb(N);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> cnt(N + 1);
    FenWick<int> tr(N);

    for (int i = 0, x; i < n; ++ i) {
        std::cin >> x;
        ++ cnt[x];
        tr.add(x, 1);
    }

    int cur = comb.fac(n);

    for (int x : cnt) {
        cur = 1LL * cur * comb.invfac(x) % P;
    }

    int res = 0;
    for (int i = 0, x; i < m; ++ i) {
        std::cin >> x;

        if (i >= n) {
            ++ res;
            if (res >= P) res -= P;
            break;
        }

        cur = 1LL * cur * comb.inv(n - i) % P;
        res += 1LL * cur * tr.query(x - 1) % P;

        if (res >= P) res -= P;

        if (cnt[x] == 0) break;

        cur = 1LL * cur * cnt[x] % P;

        -- cnt[x];
        tr.add(x, -1);
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}