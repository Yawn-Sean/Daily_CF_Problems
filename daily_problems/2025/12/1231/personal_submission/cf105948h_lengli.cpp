#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
inline void sub(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

long long qpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;

    int MAXS = n * n;

    vector<int> fact(n + 1), invfact(n + 1), inv(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = 1LL * fact[i - 1] * i % MOD;

    invfact[n] = qpow(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--)
        invfact[i - 1] = 1LL * invfact[i] * i % MOD;

    for (int i = 1; i <= n; i++)
        inv[i] = 1LL * fact[i - 1] * invfact[i] % MOD;

    auto Cinv = [&](int N, int K) -> int {
        return 1LL * invfact[N] * fact[K] % MOD * fact[N - K] % MOD;
    };

    vector<vector<int>> dp(n + 1, vector<int>(MAXS + 1, 0));
    dp[0][0] = 1;

    for (int v : nums) {
        for (int j = n - 1; j >= 0; j--) {
            for (int k = 0; k + v <= MAXS; k++) {
                if (dp[j][k]) {
                    add(dp[j + 1][k + v], dp[j][k]);
                }
            }
        }
    }

    vector<int> ans(n + 1, 0);

    for (int v : nums) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k + v <= MAXS; k++) {
                if (dp[j][k]) {
                    sub(dp[j + 1][k + v], dp[j][k]);
                }
            }
        }
        for (int j = 1; j < n; j++) {
            for (int k = 0; k <= MAXS; k++) {
                if (dp[j][k] && 1LL * j * v > k) {
                    add(ans[j + 1], dp[j][k]);
                }
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            for (int k = 0; k + v <= MAXS; k++) {
                if (dp[j][k]) {
                    add(dp[j + 1][k + v], dp[j][k]);
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        long long res = ans[i];
        res = res * Cinv(n, i) % MOD;
        res = res * inv[i] % MOD;
        cout << res << (i == n ? '\n' : ' ');
    }

    return 0;
}
