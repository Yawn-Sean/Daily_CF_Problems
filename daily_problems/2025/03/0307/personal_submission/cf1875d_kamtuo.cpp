/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-07 09:25                         */
/* Software : Visual Studio Code                            */
/*                                                          */
/*  ██╗  ██╗ █████╗ ███╗   ███╗████████╗██╗   ██╗ ██████╗   */
/*  ██║ ██╔╝██╔══██╗████╗ ████║╚══██╔══╝██║   ██║██╔═══██╗  */
/*  █████╔╝ ███████║██╔████╔██║   ██║   ██║   ██║██║   ██║  */
/*  ██╔═██╗ ██╔══██║██║╚██╔╝██║   ██║   ██║   ██║██║   ██║  */
/*  ██║  ██╗██║  ██║██║ ╚═╝ ██║   ██║   ╚██████╔╝╚██████╔╝  */
/*  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝   ╚═╝    ╚═════╝  ╚═════╝   */
/*----------------------------------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector a(n, 0), cnt(n, 0);
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
            if (a[i] < n) cnt[a[i]] ++;
        }
        vector dp(n + 1, 0);
        int now = n - 1;
        for (int i = 0; i < n; i ++) {
            if (cnt[i] == 0) {
                now = i - 1;
                break;
            }
        }
        for (int j = now; j >= 0; j --) {
            dp[j] = (cnt[j] - 1) * (now + 1) + j;
            for (int k = j + 1; k <= now; k ++) {
                dp[j] = min(dp[j], dp[k] + k * (cnt[j] - 1) + j);
            }
        }
        cout << dp[0] << "\n";
    }
    return 0;
}

#endif

/*

*/
