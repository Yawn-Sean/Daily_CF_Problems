/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-25 09:42 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int MOD = 1e9 + 7;
    int n;
    cin >> n;
    vector p(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= n; i ++) {
        dp[i] = 2;
        if (p[i] != i) dp[i] += dp[i - 1] - dp[p[i] - 1];
        dp[i] %= MOD;
        dp[i] += MOD;
        dp[i] %= MOD;
        dp[i] += dp[i - 1];
        dp[i] %= MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}

#endif

/*

*/
