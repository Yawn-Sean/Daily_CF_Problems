/*
被删除的边很少
我们要求的是只走保留下来的边，走 k 步，路径方案数是多少
如果是在完全图中，每走 1 步，都有 n - 1 种方案，所以应该是有 (n - 1)^k 种
在这个的基础上，减去走 k 步但至少走了一条被删去的边的路径数，就是我们要求的答案了
等下，其实不用这样搞的，我们知道谁被删了，其实就已经知道每个点的下一步有多少种走法了
走 1 步，显然就是 1 号点的邻点数
走 2 步，相当于走 1 步能到的那些点的邻点数之和
后边就不好统计了，并且这样做没有用到 m 很小这个性质，我感觉 m 应该是要出现在正解复杂度里的
dp[i][j]: 从 i 开始走 j 步的路径数
dp[i][0] = 1
dp[i][j] = 0
dp[i][j] += dp[k][j - 1]，其中 k 是 i 的邻点
其实，相当于对于每条边，两个端点要互相把对方的权值加过来
如果是删去的边组成的图，那么每次我们多走一步，直接枚举边就好了
总共只需要 m 的枚举去更新，复杂度就是 O(nm)
现在考虑咋通过删去的边组成的图的这个结果算出来答案
其实，我们可以先求所有的点走 0 轮的路径数，把这些数加起来，记作 sum
然后考虑走 1 轮的，假设我们考虑的是 i 这个点，我们不枚举邻点，而是枚举非邻点
从 sum 中，把非邻点的这些贡献给减掉，就是仅走保留的边走 1 轮的方案了
算走 2 轮的也是一样的，先把走 1 轮的总的加起来，然后减掉不相邻的贡献
而每个点各自的新值，其实就是老 sum - 老的自己的值 - 非邻点的贡献
思路大概就是这样，但如何才能以正确的复杂度把这套逻辑实现了?

羊的实现思路：没有在 m 条边里出现过的点，转移肯定是满的，不妨把它们当成一个点
这样本质上至多有 2m + 1 个点
对于没出现过的点，其对其他任何点都有贡献，也接受其他任何点的贡献
对于出现过的点，其可以默认先把所有点的贡献加起来，再减去非邻点的
这样复杂度就正确了
*/

LL n, m;
LL dp[2][N];
vector<vector<int>> e(N);
const int mod = 998244353;

void solve() {
    cin >> n >> m;
    set<int> appear;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        appear.insert(u);
        appear.insert(v);
    }
    
    vector<int> s;
    for (auto v : appear) {
        s.push_back(v);
    }
    
    int disappear_cnt = n - s.size();
    for (auto v : s) {
        dp[0][v] = 1;
    }
    dp[0][n + 1] = 1;
    
    for (int i = 1; i < n; i++) {
        LL sum = 0;
        for (auto v : s) {
            sum += dp[1 - i % 2][v];
            sum %= mod;
        }
        
        sum += dp[1 - i % 2][n + 1] * disappear_cnt % mod;
        sum %= mod;
        
        dp[i % 2][n + 1] = sum - dp[1 - i % 2][n + 1] % mod;
        dp[i % 2][n + 1] %= mod;
        
        for (auto v : s) {
            dp[i % 2][v] = sum - dp[1 - i % 2][v];
            dp[i % 2][v] %= mod;
            for (auto w : e[v]) {
                dp[i % 2][v] -= dp[1 - i % 2][w];
                dp[i % 2][v] %= mod;
            }
        }
        
        if (appear.count(1)) {
            cout << (dp[i % 2][1] % mod + mod) % mod << " ";
        } else {
            cout << (dp[i % 2][n + 1] % mod + mod) % mod << " ";
        }
    }
}
