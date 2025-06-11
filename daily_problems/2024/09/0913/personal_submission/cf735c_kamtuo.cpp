/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-13 10:27 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n;
    cin >> n;
    vector dp(100000, 0ll);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i ++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] > n) {
            cout << i - 1 << "\n";
            return 0;
        }
    }
    return 0;
}

#endif

/*

*/
