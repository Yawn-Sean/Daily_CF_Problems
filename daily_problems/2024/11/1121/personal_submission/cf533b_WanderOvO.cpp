/*
dp[u][0/1] 表示当前子树选了偶数/奇数个结点的最大效率
最开始先不选 a[u]
每算好一个子树的 dp[v][0/1]，就考虑合并到 dp[u][0/1] 里面去
最后用 dp[u][0] + a[u] 更新 dp[u][1]
*/

int n, root;
LL a[N], dp[N][2];
vector<vector<int>> e(N);

void dfs(int u) {
    dp[u][0] = 0;
    dp[u][1] = -INFLL;
    for (auto v : e[u]) {
        dfs(v);
        LL v0 = max(dp[u][0] + dp[v][0], dp[u][1] + dp[v][1]);
        LL v1 = max(dp[u][0] + dp[v][1], dp[u][1] + dp[v][0]);
        dp[u][0] = v0;
        dp[u][1] = v1;
    }
    dp[u][1] = max(dp[u][1], dp[u][0] + a[u]);
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p >> a[i];
        if (p == -1) {
            root = i;
        } else {
            e[p].push_back(i);
        }
    }
    
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << "\n";
}
