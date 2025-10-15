/*
从 1 开始走，第 2 个点是 u，说明 1 连的编号最小的点是 u
相邻点出现逆序的地方，则说明这个地方一定是某个点邻接的最后一个点，下一个要换新的点了
1 3 2 4 5，一定是 1 只连接 3，3 后边就比较随意了，3 可以随便连接后面连续的一段
连出来不止是个树，还可以是图，所以可能还有一些额外的边可供选择

羊神提示：dp[i][j] 表示目前遍历到排列的第 i 个元素，目前已经入队了 j 个元素的方案数
dp[i][j] 由谁转移过来，一定是 dp[i - 1][k]，其中 k <= j，k >= i，但是这个界的左边很粗糙
i - 1 需要向 k + 1...j 都连边，才能让 i 的时候最后一个元素是第 j 个元素
然后由于顺序原因，所以 a[k + 1]...a[j] 应该是单调递增的，否则访问顺序就错了
我们预处理出来单调递增的区间，就知道从哪里开始枚举 k 了
还有一件事，目前是考虑 i - 1 向谁连边，我们知道了一定要向 [k + 1, j] 连边，然而还有 [i, k] 的连边
[i, k] 在之前已经被加入到队列中了，事实上 i - 1 可以随便向 [i, k] 中的任何一个点连边，反正走不到
dp[i][j] += dp[i - 1][k] * pow(2, k - i + 1)
朴素计算需要枚举 i, j, k，需要 O(n^3)，考虑如何优化后边那个转移
j 左边单调递增假设至多到 pos = max(l[j], i)
我们早已算出来了所有的 dp[i - 1][k]，所以 dp[i - 1][k] * pow(2, k - i + 1) 也可以算出来，求前缀和即可
初始化，dp[1][1] = 1
*/

LL n, a[N], dp[M][M], s[M], p[M];
int mod = MOD2, l[M];

LL qpow(LL a, LL b, LL MOD) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return res % mod;
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    l[1] = 1;
    for (int i = 2; i <= n; i++) {
        l[i] = i;
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] < a[j + 1]) {
                l[i] = j;
            } else {
                break;
            }
        }
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = qpow(2, i, mod);
    }

    dp[1][1] = 1;
    s[1] = dp[1][1];
    for (int j = 2; j <= n; j++) {
        s[j] = (s[j - 1] + dp[1][j] * p[j - 1]) % mod;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            // for (int k = j; k >= i - 1; k--) {
            //     if (k >= j - 1 || a[k + 1] < a[k + 2]) {
            //         dp[i][j] += dp[i - 1][k] * p[k - i + 1];
            //         dp[i][j] %= mod;
            //     } else {
            //         break;
            //     }
            // }
            int pos = max(l[j] - 1, i - 1);
            assert(pos > 0);
            dp[i][j] = s[j] - s[pos - 1];
            dp[i][j] %= mod;
        }

        for (int j = 0; j <= n; j++) {
            s[j] = 0;
        }
        for (int j = i; j <= n; j++) {
            s[j] = (s[j - 1] + dp[i][j] * p[j - i]) % mod;
        }
    }
    cout << (dp[n][n] % mod + mod) % mod << "\n";
}
