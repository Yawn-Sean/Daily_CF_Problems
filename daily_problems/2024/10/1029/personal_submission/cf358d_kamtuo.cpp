/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-29 19:20 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    for (int i = 1; i <= n; i ++) cin >> c[i];
    vector dp(n + 1, vector (3, vector (2, 0ll)));
    dp[1][0][0] = a[1];
    dp[1][1][1] = b[1];
    for (int i = 2; i <= n; i ++) {
        dp[i][0][0] = max(dp[i - 1][1][1], dp[i - 1][2][0]) + a[i];
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][0]) + b[i];
        dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][2][0]) + b[i];
        dp[i][2][0] = max(dp[i - 1][1][0], dp[i - 1][0][0]) + c[i];
    }
    cout << max(dp[n][0][0], dp[n][1][0]) << "\n";
    return 0;
}

#endif

/*

*/
