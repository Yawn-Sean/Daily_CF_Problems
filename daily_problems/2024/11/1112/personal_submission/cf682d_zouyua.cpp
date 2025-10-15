void solve()
{
    int n, m, k; cin >> n >> m >> k;
    string s, t; cin >> s >> t;
    s = " " + s, t = " " + t;
    vector dp(n + 1, vector<int> (m + 1));//前k段，s的前i与t的前j匹配的最长长度
    ll res = 0;
    for(int p = 1; p <= k; p ++) {
        //vector ndp(n + 1, vector<int> (m + 1));
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                //dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(s[i] == t[j]) {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            }
        }
        //debug(1);
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i - 1][j]});
            }
        }
    }
    cout << dp[n][m] << endl;
}
