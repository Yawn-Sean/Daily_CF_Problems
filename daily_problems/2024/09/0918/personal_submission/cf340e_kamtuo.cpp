/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-18 09:43 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    const int MOD = 1e9 + 7;
    vector a(n + 1, 0);
    vector dp(n + 1, vector (n + 1, 0)); // i个数中有j个数可以随便放的方案数
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = 1ll * (i - 1) * ((dp[i - 1][0] + dp[max(i - 2, 0)][0]) % MOD) % MOD;
        for (int j = 1; j <= i; j ++) {
            dp[i][j] = 1ll * j * dp[i - 1][j - 1] % MOD + 1ll * (i - j) * dp[i - 1][j] % MOD;
            dp[i][j] %= MOD;
        }
    }
    vector st(n + 1, 0), use(n + 1, 0);
    int cou = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] == -1) cou ++;
        else use[a[i]] = 1, st[i] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (st[i] && use[i] == 0) {
            cnt ++;
        }
    }
    cout << dp[cou][cnt] << "\n";
    return 0;
}

#endif

/*

*/
