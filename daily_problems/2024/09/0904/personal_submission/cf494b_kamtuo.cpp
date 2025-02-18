/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-04 20:05 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int MOD = 1e9 + 7;
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    s.insert(s.begin(), '0');
    p.insert(p.begin(), '0');
    vector dp(n + 1, 0);
    if (m > n) cout << 0 << "\n";
    else {
        vector ne(m + 1, 0), pre(n + 1, 0), dp(n + 1, 0);
        for (int i = 2, j = 0; i <= m; i ++) {
            while (j && p[i] != p[j + 1]) j = ne[j];
            if (p[i] == p[j + 1]) j ++;
            ne[i] = j;
            if (p[i + 1] == p[ne[i] + 1]) ne[i] = ne[ne[i]];
        }
        for (int i = 1, j = 0; i <= n; i ++) {
            while (j && s[i] != p[j + 1]) j = ne[j];
            if (s[i] == p[j + 1]) j ++;
            if (j == m) {
                pre[i] = i - m + 1;
                j = ne[j];
            }
        }
        for (int i = 1; i <= n; i ++) {
            if (pre[i] == 0) pre[i] = pre[i - 1];
        }
        dp[0] = 1;
        vector s(n + 1, 0), cnt(n + 1, 0);
        s[0] = 1;
        cnt[0] = 1;
        for (int i = 1; i <= n; i ++) {
            if (pre[i]) {
                dp[i] = dp[i] + s[pre[i] - 1];
                dp[i] %= MOD;
            }
            cnt[i] += dp[i] + cnt[i - 1];
            cnt[i] %= MOD;
            s[i] += cnt[i] + s[i - 1];
            s[i] %= MOD;
        }
        cout << (((cnt[n] - 1) % MOD) + MOD) % MOD << "\n";
    } 
    return 0;
}

#endif

/*

*/
