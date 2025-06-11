/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-13 11:04 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, g;
    cin >> n >> m >> g;
    const int MOD = 1e9 + 7;
    vector dp(2, 0);
    if (m == 0) dp[0] = 1;
    if (m == 1) dp[1] = 1;
    auto fastpow = [&] (int a, int b) -> int {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * res * a % MOD;
            a = 1ll * a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    vector fac(n + m + 1, 0), inv(n + m + 1, 0);
    fac[0] = inv[0] = 1;
    auto C = [&] (int n, int m) -> int {
        if (m > n) return 0;
        return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
    };
    for (int i = 1; i < n + m; i ++) {
        fac[i] = 1ll * i * fac[i - 1] % MOD;
        inv[i] = fastpow(fac[i], MOD - 2);
        dp[i & 1] += C(i, m - 1);
        dp[i & 1] %= MOD; 
    }
    cout << dp[g ^ (!((n + m) % 2))] << "\n";
    return 0;
}

#endif

/*

*/
