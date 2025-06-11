/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-30 10:25 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> mp(n);
    for (int i = 0; i < n; i ++) cin >> mp[i];
    vector dp(n + 1, vector (k + 1, 0x3f3f3f3f));
    vector cnt(n + 1, vector (m + 1, 0));
    vector to(n + 1, vector<int> ());
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (mp[i][j] == '0') cnt[i + 1][j + 1] = 1;
            else to[i + 1].push_back(j + 1);
            cnt[i + 1][j + 1] += cnt[i + 1][j];
        }
    }
    dp[0][0] = 0;
    vector v(n + 1, vector (k + 1, 0x3f3f3f3f));
    for (int i = 1; i <= n; i ++) {
        if (to[i].size()) {
            v[i][0] = to[i].back() - to[i][0] + 1;
        } else {
            v[i][0] = 0;
        }
        for (int j = 1; j <= k; j ++) {
            if (j >= to[i].size()) {
                v[i][j] = 0;
                continue;
            }
            for (int sj = 0; sj <= j; sj ++) {
                v[i][j] = min(v[i][j], to[i][to[i].size() - 1 - (j - sj)] - to[i][sj] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= k; j ++) {
            for (int sj = 0; sj <= j; sj ++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - sj] + v[i][sj]);
            }
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}

#endif

/*

*/
