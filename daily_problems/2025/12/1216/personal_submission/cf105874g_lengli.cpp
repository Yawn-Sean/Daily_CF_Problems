#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;
constexpr int MAXN = 200000;
constexpr int SQ = 450;

long long mod_pow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct Comb {
    vector<int> fac, ifac;

    Comb(int n = 0) {
        fac.resize(n + 1);
        ifac.resize(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; ++i)
            fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[n] = mod_pow(fac[n], MOD - 2);
        for (int i = n; i; --i)
            ifac[i - 1] = 1LL * ifac[i] * i % MOD;
    }

    int operator()(int n, int k) const {
        if (k < 0 || k > n) return 0;
        return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
    }
};

inline void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Comb C(MAXN * 2);

    static int dp[SQ + 1][MAXN + 1];

    for (int k = 1; k <= SQ; ++k) {
        dp[k][0] = 1;
        for (int i = 1; i <= MAXN; ++i) {
            dp[k][i] = dp[k][i - 1];
            if (i >= k) add(dp[k][i], dp[k][i - k]);
        }
        for (int i = 1; i <= MAXN; ++i)
            add(dp[k][i], dp[k][i - 1]);
    }

    int n, q;
    cin >> n >> q;

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        if (k <= SQ) {
            cout << (dp[k][r] - dp[k][l - 1] + MOD) % MOD << '\n';
        } else {
            int ans = 0;
            for (int cnt = 0; cnt <= r / k; ++cnt) {
                int R = r - cnt * k;
                int L = max(l - cnt * k, 0) - 1;
                add(ans, C(R + cnt + 1, cnt + 1));
                add(ans, MOD - C(L + cnt + 1, cnt + 1));
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
