/*
一共有 n 天，假设坏事发生了 cnt 天，则隔板法知坏事有 C(b - 1, cnt - 1) * b! 种方案
好事发生了 n - cnt 天，其中 n - cnt >= 2（因为必须分两段）
只关心好事的方案数，发现有 C(w - 1, n - cnt - 1) * w! 种方案
然后考虑把坏事插入到好事中，好事分了 n - cnt 天，则有 n - cnt - 1 个空，把坏事插入到任何一个空里面都可以
所以其实就是把上面算的这两个数乘起来，再乘以 n - cnt - 1
枚举 cnt，把所有的都算出来，求和即可
*/

LL n, w, b;
LL c[M][M], fact[M];

void meibao() {
    cin >> n >> w >> b;
    int mod = 1e9 + 9;
    c[0][0] = 1;
    for (int i = 1; i < M; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }

    fact[0] = 1;
    for (int i = 1; i < M; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }

    LL res = 0;
    for (int cnt = 1; cnt <= b && n - cnt >= 2; cnt++) {
        LL c1 = c[b - 1][cnt - 1] * fact[b] % mod;
        LL c2 = c[w - 1][n - cnt - 1] * fact[w] % mod;
        res += (c1 * c2 % mod) * (n - cnt - 1) % mod;
        res %= mod;
    }
    cout << res << "\n";
}     
