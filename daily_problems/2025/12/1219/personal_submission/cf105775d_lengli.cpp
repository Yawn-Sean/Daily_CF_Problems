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

struct Factorial {
    int n;
    vector<long long> fact, invfact;

    Factorial(int n) : n(n), fact(n + 1), invfact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invfact[n] = modpow(fact[n], MOD - 2);
        for (int i = n; i > 0; i--) {
            invfact[i - 1] = invfact[i] * i % MOD;
        }
    }

    long long combi(int n, int k) const {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Factorial f(n * m);

    long long ans = 0;
    long long target = 1LL * n * (m + 1) / 2;

    for (long long i = 0; i <= target / (m + 1); i++) {
        long long total = target - i * m;

        long long term =
            f.combi(total - 1, n - 1) *
            f.combi(n, i) % MOD;

        if (i & 1) term = (MOD - term) % MOD;

        ans = (ans + term) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
