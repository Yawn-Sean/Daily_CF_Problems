/*
给定一棵树，可以选择至多 x 个互不相邻的结点组成集合 s，使 s 中每个点的值为 k
所有和 s 中的点相邻的点的值必须严格 < k，其他点的值只要不等于 k 即可
首先，选择点集 s，然后，相邻的点的个数就确定了，每个点有 k - 1 种取值，对于剩下的点，每个点有 m - 1 种取值
注意到 x <= 10，复杂度是否可以和 x 有关？
树上计数，考虑 DP
dp[i][j][0/1]: 以 i 为根的子树中选择 j 个点放到 s 中，其中 i 点不放/放到 s 中，有多少种方案？
如果 i 的所有孩子都不放到 s 中，则 dp[i][j][0] 可以由 dp[v][k][0] 们转移过来
如果 i 至少有一个孩子放到 s 中，则只能算 dp[i][j][0]，可以由 dp[v][k][0/1] 转移过来，然后 i 只有 k - 1 种取值
但是好像这样的状态转移起来有点混乱

羊神提示：状态定义再细化一下，第三维改成当前点填的数值是小于 等于还是大于 k
dp[u][j][0/1/2] 表示以 u 为根的子树，一共有 j 个点是 = k 的，其中 u 点本身是 < = > k 的方案数
dp[u][j][0] 可以由 dp[v][cnt][0/1/2] 转移过来，所有 cnt 的和为 j
dp[u][j][1] 可以由 dp[v][cnt][0] 转移过来，所有 cnt 的和为 j - 1
dp[u][j][2] 可以由 dp[v][cnt][0/2] 转移过来，所有 cnt 的和为 j
g[i][j] 为前 i 个子树，总共贡献了 j 个点的值为 k 的方案数是多少
枚举 i，其中第 i 个子树的根为 v，枚举 j，枚举 cnt，g[i][j] += g[i - 1][j - cnt] * dp[v][cnt][0] % mod
压掉第一维，最终 dp[u][j][1] = g[j - 1]
0 和 2 的分别为 f 和 h，类似地做一下
*/

LL n, m, k, x, dp[N][M][3];
int mod = 1e9 + 7;
vector<vector<int>> e(N);

void dfs(int u, int fa) {
    LL f[M] = {0}, g[M] = {0}, h[M] = {0};
    f[0] = 1;
    g[0] = 1;
    h[0] = 1;
    for (auto v : e[u]) {
        if (v != fa) {
            dfs(v, u);
            
            for (int j = x; j >= 0; j--) {
                LL ff = 0, gg = 0, hh = 0;
                for (int cnt = 0; cnt <= j; cnt++) {
                    ff += f[j - cnt] * ((dp[v][cnt][0] + dp[v][cnt][1] + dp[v][cnt][2]) % mod) % mod;

                    gg += g[j - cnt] * dp[v][cnt][0] % mod;
                
                    hh += h[j - cnt] * (dp[v][cnt][0] + dp[v][cnt][2]) % mod;
                    ff %= mod, gg %= mod, hh %= mod;
                }
                f[j] = ff, g[j] = gg, h[j] = hh;
            }
        }
    }

    for (int j = 0; j <= x; j++) {
        dp[u][j][0] = f[j] * (k - 1) % mod;
        if (j > 0) {
            dp[u][j][1] = g[j - 1];
        }
        dp[u][j][2] = h[j] * (m - k) % mod;
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin >> k >> x;

    dfs(1, 0);

    LL res = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < 3; j++) {
            res += dp[1][i][j];
            res %= mod;
        }
    }
    cout << res << "\n";
}
