/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-14 19:28 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        int n, m;
        cin >> n >> m;
        vector<string> mp(n);
        for (int i = 0; i < n; i ++) cin >> mp[i];
        vector cnt(n + 1, vector (m + 1, 0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (mp[i][j] == '1') cnt[i + 1][j + 1] = 1;
                // cnt[i + 1][j + 1] += cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j];
            }
        }
        vector space(m + 1, 0);
        vector flag(m + 1, 0);
        int ans = n * m;
        for (int i = 1; i <= n; i ++) {
            if (i + 4 > n) break; 
            for (int j = 1; j <= m; j ++) space[j] = 0;
            for (int j = i + 1; j < i + 4; j ++) {
                for (int k = 1; k <= m; k ++) {
                    space[k] += cnt[j][k];
                }
            }
            for (int j = i + 4; j <= n; j ++) {
                for (int k = 1; k <= m; k ++) flag[k] = space[k];
                for (int k = 1; k <= m; k ++) {
                    flag[k] += 2 - cnt[i][k] - cnt[j][k];
                    flag[k] += flag[k - 1];
                }
                int now = n * m;
                for (int k = m; k >= 4; k --) {
                    now = min(now, flag[k - 1] + j - i - 1 - space[k]);
                    ans = min(ans, now - flag[k - 3] + j - i - 1 - space[k - 3]);
                } 
                for (int k = 1; k <= m; k ++) {
                    space[k] += cnt[j][k];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

#endif

/*

*/
