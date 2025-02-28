/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-08 09:52 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, k, l;
    cin >> n >> l >> k;
    const int MOD = 1000000007;
    vector dp(k + 1, vector (n + 1, 0));
    vector a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i ++) cin >> a[i], b[i] = a[i];
    sort(b.begin(), b.end());
    b.push_back(0x3f3f3f3f);
    int ans = 0;
    vector to(n + 1, 0);
    to[n] = n;
    for (int i = n - 1; i; i --) {
        if (b[i] == b[i + 1]) to[i] = to[i + 1];
        else to[i] = i;
    }
    for (int i = 1; i <= min(k, l / n); i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == 1) dp[i][j] = 1;
            else dp[i][j] += dp[i - 1][to[j]], dp[i][j] %= MOD;
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
        ans += 1ll * (l / n - i + 1) % MOD * dp[i][n] % MOD;
        ans %= MOD;
    }
    if (l % n)
    for (int i = 1; i <= min(l / n + 1, k); i ++) {
        for (int j = 1; j <= l % n; j ++) {
            int now = upper_bound(b.begin(), b.end(), a[j]) - b.begin() - 1;
            if (i == 1) ans += 1, ans %= MOD;
            else {
                ans += dp[i - 1][to[now]];
                ans %= MOD;
            }
        }

    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
