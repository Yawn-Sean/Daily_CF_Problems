/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-21 19:32 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n + 1, 0);
    vector edge(n + 1, vector<int> ());
    vector dp(n + 1, vector (2, 0ll));
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x >> a[i];
        if (i == 1) continue;
        edge[x].push_back(i);
    }
    LL ans = 0;
    for (int i = 1; i <= n; i ++) dp[i][1] = -0x3f3f3f3f3f3f3f3f;
    std::function<void (int)> dfs = [&] (int now) {
        for (auto v : edge[now]) {
            dfs(v);
            dp[v][1] = max(dp[v][1], dp[v][0] + a[v]);
            LL v0 = dp[now][0], v1 = dp[now][1];
            dp[now][0] = max(dp[v][1] + v1, dp[v][0] + v0);
            dp[now][1] = max(dp[v][1] + v0, dp[v][0] + v1);
        } 
    };
    dfs(1);
    cout << max(dp[1][1], dp[1][0] + a[1]) << "\n";
    return 0;
}

#endif

/*

*/
