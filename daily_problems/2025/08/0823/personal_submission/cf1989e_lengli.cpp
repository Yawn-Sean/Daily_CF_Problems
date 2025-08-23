#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct Comb {
    vector<long long> fact, ifact;
    Comb(int n = 0) { init(n); }
    void init(int n) {
        fact.resize(n + 1);
        ifact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        ifact[n] = modpow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    }
    inline long long C(int n, int k) const {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    const int L = k - 2;             

    int max_m = max(0, n - 2);
    vector<long long> A(max_m + 1, 0);
    if (max_m >= 0) A[0] = 1;
    if (max_m >= 1) A[1] = 1;
    if (max_m >= 2) A[2] = 1;
    for (int m = 3; m <= max_m; ++m) {
        A[m] = (2 * A[m - 1] % MOD - A[m - 2] + A[m - 3]) % MOD;
        if (A[m] < 0) A[m] += MOD;
    }


    Comb comb(n + L + 10);

    auto addmod = [&](long long &x, long long v) {
        x += v;
        if (x >= MOD) x -= MOD;
    };

    long long ans = 0;
    for (int m = 0; m <= n - 2; ++m) {
        long long total = A[m]; 
        long long remove = 0;   

        for (int t = 0; t < L; ++t) {
            if (t == 0) {     
                if (m == 0) addmod(remove, 1);
                continue;
            }
            for (int b = 0; b <= t; ++b) {
                int max_c = min(t - b, (m - t - b) / 2);
                if (max_c < 0) continue;
                long long coef_tb = comb.C(t, b);
                for (int c = 0; c <= max_c; ++c) {
                    int r = m - t - b - 2 * c;
                    long long coef = coef_tb * comb.C(t - b, c) % MOD;
                    coef = coef * comb.C(t + r - 1, r) % MOD;
                    if (b & 1) coef = (MOD - coef) % MOD;
                    addmod(remove, coef);
                }
            }
        }

        long long ways = (total - remove) % MOD;
        if (ways < 0) ways += MOD;

        long long pairs = n - m - 1;     
        ans = (ans + pairs % MOD * ways) % MOD;
    }

    if (ans < 0) ans += MOD;
    cout << ans << '\n';
    return 0;
}
