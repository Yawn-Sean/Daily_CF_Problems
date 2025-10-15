/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-06 13:58                         */
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
    int n, k;
    cin >> n >> k;
    vector dp(n + 2, vector (k + 1, 0)); // 后n个数，使用k位是否可以合法组成数字
    dp[n + 1][0] = 1;
    vector<string> s = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"}, a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = n; i; i --) {
        for (int j = 0; j < 10; j ++) {
            int res = 0;
            bool ok = false;
            for (int l = 0; l < 7; l ++) {
                if (a[i][l] != s[j][l] && a[i][l] == '0') res ++;
                if (a[i][l] != s[j][l] && a[i][l] == '1') ok = true;
            }
            if (ok) continue;
            for (int l = res; l <= k; l ++) {
                dp[i][l] |= dp[i + 1][l - res];
            }
        }
    }
    if (!dp[1][k]) cout << -1;
    else {
        int now = k;
        for (int i = 1; i <= n; i ++) {
            for (int j = 9; j >= 0; j --) {
                int res = 0;
                bool ok = false;
                for (int l = 0; l < 7; l ++) {
                    if (a[i][l] != s[j][l] && a[i][l] == '0') res ++;
                    if (a[i][l] != s[j][l] && a[i][l] == '1') ok = true;
                }
                if (ok) continue;
                if (now >= res)
                if (dp[i + 1][now - res]) {
                    cout << j;
                    now -= res;
                    break;
                }
            } 
        }
    }
    return 0;
}

#endif

/*

*/
