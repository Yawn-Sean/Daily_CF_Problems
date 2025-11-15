/*
一定是剩偶数个，两两抵消
如果 a[i] 和 a[i + 1] 能配对，a[i + 1] 和 a[i + 2] 也能配对，那么选什么匹配呢？
我们把能匹配的当成一条线段
则这些线段要么是一个完全包含另一个，要么完全无交集
如果只交了一部分，则这两个就没法做到
有点像剥洋葱和括号匹配
考虑区间 DP
dp[i][j] 表示为了把从 i 到 j 的都给消除掉，需要至少删掉多少个
枚举 i 和谁配
dp[i][j] = min(dp[i][k] + dp[k + 1][j])
dp[i][i] = 1
还需要记录 from[i][j]，也就是我们枚举的能让 dp[i][j] 最小的 k
如果是 i 和 j 配，不妨记一个特殊的数
最后使用一个 dfs 追溯一下就好了
*/

int n, a[N], dp[N][N], from[N][N];

void dfs(int l, int r, vector<int> &deleted_node) {
    if (l > r) {
        return;
    }
    if (dp[l][r] == 0) {
        return;
    }
    if (from[l][r] == -1) {
        dfs(l + 1, r - 1, deleted_node);
        return;
    }
    if (l == r) {
        deleted_node.push_back(l);
        return;
    }
    
    dfs(l, from[l][r], deleted_node);
    dfs(from[l][r] + 1, r, deleted_node);
} 

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                from[i][j] = -1;
                if (i + 1 == j) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            for (int k = i; k < j; k++) {
                if (dp[i][j] > dp[i][k] + dp[k + 1][j]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j];
                    from[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
    vector<int> deleted_node;
    dfs(1, n, deleted_node);
    sort(deleted_node.begin(), deleted_node.end());
    for (auto v : deleted_node) {
        cout << v << " ";
    }
}
