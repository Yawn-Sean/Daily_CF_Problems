/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-04 18:03 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(2, vector (n + 1, 0ll));
    vector cnt(2, vector (n + 1, 0ll));
    vector dp(2, vector (n + 1, 0ll));
    for (int i = 0; i < 2; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            cnt[i][j] = a[i][j] + cnt[i][j - 1];
        }
    }
    LL ans = 0;
    for (int i = 0; i < 2; i ++) {
        dp[i][n] = a[i ^ 1][n];
        for (int j = n - 1; j; j --) {
            dp[i][j] = 1ll * a[i ^ 1][j] * (2ll * (n - j + 1) - 1);
            dp[i][j] += cnt[0][n] - cnt[0][j] + cnt[1][n] - cnt[1][j] + dp[i][j + 1];
        }
    }
    LL now = 0, num = 0;
    for (int i = 1; i <= n; i ++) {
        ans = max(ans, now + dp[!(i % 2)][i] + num * (cnt[0][n] - cnt[0][i - 1] + cnt[1][n] - cnt[1][i - 1]));
        now += num * a[!(i % 2)][i];
        num ++;
        now += num * a[(i % 2)][i];
        num ++;
    }
    cout << max(ans, now) << "\n";
    return 0;
}

#endif

/*

*/
