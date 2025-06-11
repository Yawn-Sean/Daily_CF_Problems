/*
先连成一个图，然后从小编号的开始遍历，找到所有的连通分支
严格上升的链会很多吗？如果是完全图的话似乎确实很多
对于每个严格上升链，把它们的度数之和加起来，减去 2 倍的链上边数，就是刺的个数
考虑以 i 为结尾的最长上升子序列长度，从大到小枚举 i，很容易转移

*/

int T;
LL n, m;
vector<int> e[N];
vector<LL> deg(N, 0);
vector<LL> dp(N, 0); 

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        for (auto v : e[i]) {
            if (v < i) {
                dp[i] = max(dp[i], dp[v] + 1);
            }
        }
        res = max(res, dp[i] * deg[i]);
    }
    cout << res << "\n";
}           
