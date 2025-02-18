/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-29 19:42 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    string s;
    cin >> n >> s >> q;
    const int MOD = 998244353;
    vector cnt(n + 1, 0);
    vector dp(n + 1, vector (n + 1, 0)), to(n + 1, vector (n + 1, 0));
    for (int i = 0; i < n; i ++) {
        if (s[i] == '?') cnt[i + 1] = 1;
        cnt[i + 1] += cnt[i];
    }
    for (int i = 0; i < n; i ++) {
        dp[i][i] = 0;
        if (s[i] == '?') to[i][i] = 1;
    }
    for (int l = n - 1; l >= 0; l --) {
        for (int r = l + 1; r < n; r ++) {
            if (dp[l + 1][r - 1] == -1) {
                dp[l][r] = -1;
            } else if (s[l] != '?' && s[r] != '?' && s[l] != s[r]) dp[l][r] = -1;
            else {
                dp[l][r] = dp[l + 1][r - 1];
                to[l][r] = to[l + 1][r - 1];
                if (s[l] == '?' && s[r] != '?') {
                    dp[l][r] |= (1 << (s[r] - 'a'));
                } else if (s[l] != '?' && s[r] == '?') {
                    dp[l][r] |= (1 << (s[l] - 'a'));
                } else if (s[l] == '?' && s[r] == '?') {
                    to[l][r] ++;
                }
            }
        }
    }
    vector ans(20, vector (1 << 20, 0));
    vector powik(20, vector (n + 1, 0));
    for (int i = 1; i <= 17; i ++) {
        powik[i][0] = 1;
        for (int j = 1; j <= n; j ++) {
            powik[i][j] = 1ll * powik[i][j - 1] * i % MOD;
        }
    }
    for (int i = 1; i <= 17; i ++) {
        for (int l = 0; l < n; l ++) {
            for (int r = l; r < n; r ++) {
                if (dp[l][r] == -1) continue;
                ans[i][dp[l][r]] += powik[i][to[l][r] + cnt[l] + cnt[n] - cnt[r + 1]];
                ans[i][dp[l][r]] %= MOD;
            }
        }
    }
    for (int i = 1; i <= 17; i ++) {
        for (int j = 0; j < 17; j ++) {
            for (int k = 0; k < (1 << 17); k ++) {
                if ((k >> j) & 1) ans[i][k] += ans[i][k ^ (1 << j)];
                ans[i][k] %= MOD;
            }
        }
    }
    for (int i = 1; i <= q; i ++) {
        string now;
        cin >> now;
        int nums = 0;
        for (int i = 0; i < now.size(); i ++) {
            nums += 1 << (now[i] - 'a');
        }
        cout << ans[now.size()][nums] << "\n";
    }
    return 0;
}

#endif

/*

*/
