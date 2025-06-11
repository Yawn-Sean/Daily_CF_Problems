/*
problem:    https://codeforces.com/contest/1033/problem/C
submission: https://codeforces.com/contest/1033/submission/266788802
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    vector<vector<int>> dp(n, vector<int> (2, -1));
    // dp[i][j]: 从位置i出发，j先开始，最终的状态(0: j输，1: j赢)
    // 递归+记忆化搜索
    auto dfs = [&](auto&& self, int i, int j) -> int {
        if (dp[i][j] != -1) return dp[i][j];
        int res = -1;
        for (int k = i + a[i]; k < n; k += a[i]) 
            if (a[k] > a[i]) {
                res = res == -1? self(self, k, 1 - j): res & self(self, k, 1 - j);
            }
        for (int k = i - a[i]; k >= 0; k -= a[i]) 
            if (a[k] > a[i]) {
                res = res == -1? self(self, k, 1 - j): res & self(self, k, 1 - j);
            }
        dp[i][j] = res == -1? 0: 1 - res;
        return dp[i][j];
    };

    string ans = "";
    for (int i = 0; i < n; i ++ ) {
        if (dfs(dfs, i, 0)) ans += 'A';
        else ans += 'B';
    }
    cout << ans << "\n";
}
