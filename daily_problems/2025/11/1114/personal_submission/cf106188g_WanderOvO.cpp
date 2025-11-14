/*
选出来 k 条边，要求任意的一条边小于其他边的和
其实就是最大的边小于其他边的和，所以不妨所有边排个序
这个题显然是 DP
dp[i][j][len]: 考虑前 i 个边里选 j 个边，总长度是 len 的方案数
如果 len 搞到 1e6，有点爆了
我们想到正难则反
总共有 C(n, k) 种方案，我们减掉不行的，就是行的
而不行的，总和肯定不会超过 1e4，因为需要其他边加起来都 <= 最长的边
预处理出来上面的东西之后，我们枚举最大的边 i，然后看 dp[i - 1][k - 1][0...a[i]] 就好了
*/

LL dp[N][M], n, k, a[N], c[N][N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + n + 1);
    
    const int mod = 1e9 + 7;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    
    dp[0][0] = 1;
    LL res = c[n][k];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= a[i]; j++) {
            res -= dp[k - 1][j];
            res %= mod;
        }
        
        for (int j = i; j >= 1; j--) {
            for (int len = M - 1; len >= a[i]; len--) {
                dp[j][len] += dp[j - 1][len - a[i]];
                dp[j][len] %= mod;
            }
        }
    }
    res = (res % mod + mod) % mod;
    cout << res;
}
