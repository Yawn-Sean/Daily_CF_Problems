/*
相当于选两个点，把两个点之间的边的数量 + 两个点的点权加起来，要求最大
如果钦定了某个点 u 了，那么要么找离自己很远的 v，要么找点权很大的 v
能否先看 u 所在子树里，和自己配对最大的呢
相当于在子树里找 depth[v] + a[v] 最大的，和就是 depth[v] - depth[u] + a[u] + a[v]
其实也可以是不选 u，但是在 u 的子树的两个不同孩子里，分别选一个点
假设选的是 v1 和 v2，则要 depth[v1] + depth[v2] - 2 * depth[u] + a[v1] + a[v2] 最大
即要找 (depth[v1] + a[v1]) + (depth[v2] + a[v2]) - 2 * depth[u] 最大的，u 固定了
所以本质上只需要维护每个以 u 为根的子树中，最大的 depth[v] + a[v]，然后就可以算答案了
*/

int n;
LL a[N], depth[N], dp[N];
vector<vector<int>> e(N);

void dfs(int u, int d) {
    depth[u] = d;
    dp[u] = depth[u] + a[u];
    for (auto v : e[u]) {
        dfs(v, d + 1);
        dp[u] = max(dp[u], dp[v]);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        e[p].push_back(i);
    }
    
    dfs(1, 0);
    
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        LL mx1 = -1, mx2 = -1;
        for (auto v : e[i]) {
            if (dp[v] > mx1) {
                mx2 = mx1;
                mx1 = dp[v];
            } else if (dp[v] > mx2) {
                mx2 = dp[v];
            }
        }
        
        if (mx2 >= 0) {
            res = max(res, mx1 + mx2 - 2 * depth[i]);    
        } 
        res = max(res, mx1 + a[i] - depth[i]);
    }
    cout << res;
}
