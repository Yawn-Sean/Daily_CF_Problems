/*
注意到是 n * n 的正方形，而恰好有 n 行
m 特别大，但是怀疑只要研究明白 m 比较小的时候就能做了，后边说不定能加速计算/找到规律直接算
发现了关键性质，第 i 列和第 i - n 列放的数量应该一样，否则不能保证总和是 k
所以事实上，我们只关心前 n 列具体每列填了多少个，后边每列的数量就固定了
能否把 % n 同余的列放在一起考虑？这些都是乘 C(n, cnt)

羊神提示：就差最后一步了
设 dp[i][j] 表示前 i 列一共放了 j 个点的方案数，这里前 i 列实际上指的是前 i 列以及所有 % n 同余的那些列
dp[i][j] += dp[i - 1][j - cnt] * C(n, cnt)^c，其中 c 代表和 i 模 n 同余的列的个数
*/

LL dp[M][M * M], c[M][M], n, m, k, p[2][M][M];

LL qpow(LL a, LL b, LL MOD) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        b >>= 1;
    }
    return res % MOD;
}

void meibao() {
    cin >> n >> m >> k;
    c[0][0] = 1;
    int mod = MOD1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            p[0][i][j] = qpow(c[i][j], m / n, mod);
            p[1][i][j] = qpow(c[i][j], m / n + 1, mod);
        }
    }

    for (int j = 0; j <= k; j++) {
        dp[1][j] = qpow(c[n][j], m / n + ((m % n) >= 1), mod);
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int pp = 0;
            if (m % n >= i) {
                pp = 1;
            }
            for (int cnt = 0; cnt <= n && cnt <= j; cnt++) {
                dp[i][j] += dp[i - 1][j - cnt] * p[pp][n][cnt];
                dp[i][j] %= mod;
            }
        }
    }

    cout << dp[n][k] << "\n";
}   
