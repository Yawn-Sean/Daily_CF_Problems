/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-30 17:28 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    const LL MAX = 0x3f3f3f3f3f3f3f3f;
    vector dp(n + 1, vector (11, 1ll * -MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        vector v(3, vector<LL> ());
        for (int j = 1; j <= k; j ++) {
            int c, d;
            cin >> c >> d;
            c --;
            v[c].push_back(d);
        }
        for (int j = 0; j < 3; j ++) {
            if (v[j].size()) {
                sort(v[j].begin(), v[j].end());
            }
        }
        std::function<LL (int x)> find = [&] (int x) -> LL {
            if (x == 0) return 0;
            if (x == 1) {
                LL m = 0;
                for (int i = 0; i < 3; i ++) {
                    if (v[i].size()) m = max(m, v[i].back());
                }
                return m;
            } else if (x == 2) {
                LL m = 0;
                if (v[0].size() >= 2) m = max(m, v[0].back() + v[0][v[0].size() - 2]);
                if (v[1].size() >= 1 && v[0].size() >= 1) m = max(m, v[0].back() + v[1].back());
                return m;
            } else {
                LL m = 0;
                if (v[0].size() >= 3) m = max(m, v[0].back() + v[0][v[0].size() - 2] + v[0][v[0].size() - 3]);
                return m;
            }
        };
        std::function<LL (int x)> find2 = [&] (int x) -> LL {
            if (x == 0) return 0;
            if (x == 1) {
                LL m = 0;
                for (int i = 0; i < 3; i ++) {
                    if (v[i].size()) m = max(m, v[i].back() * 2);
                }
                return m;
            } else if (x == 2) {
                LL m = 0;
                if (v[0].size() >= 2) m = max(m, v[0].back() * 2 + v[0][v[0].size() - 2]);
                if (v[1].size() >= 1 && v[0].size() >= 1) m = max(m, v[0].back() + v[1].back() + max(v[0].back(), v[1].back()));
                return m;
            } else {
                LL m = 0;
                if (v[0].size() >= 3) m = max(m, v[0].back() + v[0][v[0].size() - 2] + v[0][v[0].size() - 3] + v[0].back());
                return m;
            }
        };
        // debug("f2:", find(2));
        for (int j = 0; j <= min(3, k); j ++) {
            for (int sj = 0; sj < 10; sj ++) {
                if (sj - j >= 0 && dp[i - 1][sj - j] != -MAX) dp[i][sj] = max(dp[i - 1][sj - j] + find(j), dp[i][sj]);
                else {
                    if (dp[i - 1][((sj - j) % 10 + 10) % 10] != -MAX) {
                        dp[i][sj] = max(dp[i][sj], dp[i - 1][((sj - j) % 10 + 10) % 10] + find2(j));
                    }
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i < 10; i ++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
