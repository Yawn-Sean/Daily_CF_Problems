/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-28 10:14 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector mp(n + 1, vector (m + 1, 0));
    vector dplu(n + 2, vector (m + 2, 0ll)), dpru(n + 2, vector (m + 2, 0ll)), dprd(n + 2, vector (m + 2, 0ll));
    vector dpld(n + 2, vector (m + 2, 0ll));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = m; j; j --) {
            dpru[i][j] = max(dpru[i - 1][j], dpru[i][j + 1]) + mp[i][j];
        }
        for (int j = 1; j <= m; j ++) {
            dplu[i][j] = max(dplu[i - 1][j], dplu[i][j - 1]) + mp[i][j];
        }
    }
    for (int i = n; i; i --) {
        for (int j = 1; j <= m; j ++) {
            dpld[i][j] = max(dpld[i][j - 1], dpld[i + 1][j]) + mp[i][j];
        }
        for (int j = m; j; j --) {
            dprd[i][j] = max(dprd[i + 1][j], dprd[i][j + 1]) + mp[i][j];
        }
    }
    LL ans = 0;
    for (int i = 2; i <= n - 1; i ++) {
        for (int j = 2; j <= m - 1; j ++) {
            ans = max(ans, dplu[i - 1][j] + dprd[i + 1][j] + dpld[i][j - 1] + dpru[i][j + 1]);
            ans = max(ans, dplu[i][j - 1] + dprd[i][j + 1] + dpld[i + 1][j] + dpru[i - 1][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
