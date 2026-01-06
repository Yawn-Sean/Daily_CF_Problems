#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1e9 + 7;

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
    vector<long long> fac, invfac;

    Factorial(int n, long long mod) : n(n), fac(n + 1), invfac(n + 1) {
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % mod;

        invfac[n] = modpow(fac[n], mod - 2);
        for (int i = n; i > 0; i--)
            invfac[i - 1] = invfac[i] * i % mod;
    }

    long long fac_(int x) const {
        return fac[x];
    }

    long long fac_inv(int x) const {
        return invfac[x];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Factorial f(1000, MOD);

    int t;
    cin >> t;

    long long rev26 = modpow(26, MOD - 2);
    vector<long long> pw_rev26(1001, 1);
    for (int i = 0; i < 1000; i++)
        pw_rev26[i + 1] = pw_rev26[i] * rev26 % MOD;

    while (t--) {
        string s;
        cin >> s;

        vector<int> cnt(26, 0);
        int to_fill = 0;

        for (char c : s) {
            if ('a' <= c && c <= 'z')
                cnt[c - 'a']++;
            else
                to_fill++;
        }

        vector<long long> dp(to_fill + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < 26; i++) {
            for (int j = to_fill; j >= 0; j--) {
                if (dp[j] == 0) continue;

                for (int k = 1; k + j <= to_fill; k++) {
                    long long add =
                        dp[j]
                        * f.fac_inv(cnt[i] + k) % MOD
                        * f.fac_inv(k) % MOD;

                    dp[j + k] = (dp[j + k] + add) % MOD;
                }

                dp[j] = dp[j] * f.fac_inv(cnt[i]) % MOD;
            }
        }

        long long ans = dp[to_fill];
        ans = ans * f.fac_(to_fill) % MOD;
        ans = ans * f.fac_(s.size()) % MOD;
        ans = ans * pw_rev26[to_fill] % MOD;

        cout << ans << '\n';
    }

    return 0;
}
