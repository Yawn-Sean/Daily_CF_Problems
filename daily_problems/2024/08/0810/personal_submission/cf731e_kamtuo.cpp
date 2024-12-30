/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-10 14:52 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    const int N = n + 1;
    vector s(N, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    LL ans = -0x3f3f3f3f3f3f3f3f;
    vector dp(N, 0ll);
    dp[n] = s[n];
    ans = s[n];
    for (int i = n - 1; i > 1; i --) {
        dp[i] = s[i] - ans;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}

#endif

/*

*/
