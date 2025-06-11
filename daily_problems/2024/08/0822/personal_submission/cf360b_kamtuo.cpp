/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-22 19:58 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector a(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    LL l = 0, r = 2e9;
    while (l < r) {
        int mid = l + r >> 1;
        for (int i = 1; i <= n; i ++) dp[i] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j < i; j ++) {
                if (abs(a[i] - a[j]) <= 1ll * mid * (i - j)) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(dp[i], ans);
        }
        if (ans >= n - k) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
    return 0;
}

#endif

/*

*/
