#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        long long invk = modpow(k, MOD - 2);
        long long ans = n % MOD;

        for (int i = 1; i < k; ++i) {
            long long p = 1LL * i * invk % MOD;  
            long long p_n = modpow(p, n);           
            long long one_minus_p = (1 - p + MOD) % MOD;
            long long term = (1 - p_n + MOD) % MOD;
            term = term * modpow(one_minus_p, MOD - 2) % MOD;
            ans = (ans + term) % MOD;
        }
        ans = ans * modpow(k, n - 1) % MOD;

        cout << ans << "\n";
    }

    return 0;
}
