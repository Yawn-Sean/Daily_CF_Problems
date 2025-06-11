#include <bits/stdc++.h>
// #include <ranges>
 
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
 
constexpr int inf32 = 1E9 + 7;
 
int power(int a, int b, int p){
    int res = 1;
    for (; b; b >>= 1, a = 1LL * a * a % p)
        if (b & 1)
            res = 1LL * res * a % p;
    return res;
}

struct Comb{
    static constexpr int P = 1'000'000'007;
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

constexpr int P = 1E9 + 7;

void solve() {
    int n, m, g;
    std::cin >> n >> m >> g;

    Comb comb(n + m);

    if (!m) {
        int cur = 0;
        for (int i = 0; i + 1 < n; ++ i) {
            cur ^= 1;
        }
        std::cout << (cur == g ? 1 : 0) << '\n';
    }
    else if (m == 1){
        int res = 0, cur = 0;
        for (int i = 0; i < n; ++ i) {
            if (cur == g) ++ res;
            cur ^= 1;
        }
        cur ^= 1;
        if (cur == g) ++ res;
        std::cout << res;
    }
    else {
        int res = 0, cur = 0;
        for (int i = 0; i <= n; ++ i) {
            if (cur == g) {
                res += comb.binom(n + m - 1 - i, n - i);
                if (res >= P) res -= P;
            }
            cur ^= 1;
        }
        std::cout << res << '\n';
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}