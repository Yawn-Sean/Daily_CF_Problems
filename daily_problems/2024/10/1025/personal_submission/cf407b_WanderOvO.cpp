/*
n 比较小，或许可以多一些枚举
由样例 2 和 3 可以看出，会有很多重复走之前的
1 <= p[i] <= i，所以要么回退回去了，要么原地得停一下
cnt[i][0/1]：从 1 走到 i，且第 i 个位置有偶数/奇数个 x 的步数
第奇数次走到 i 的时候，前面所有的 1-i - 1 一定都被访问了偶数次，否则根本过不来
cnt[i][1] = cnt[i - 1][0] + 1
cnt[i][0] = 1 + 2 * cnt[i][1] - cnt[p[i]][1]
*/

LL n, p[N];
LL cnt[N][2];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cnt[1][1] = 0;
    cnt[1][0] = 1;
    int mod = MOD1;
    for (int i = 2; i <= n; i++) {
        cnt[i][1] = cnt[i - 1][0] + 1;
        cnt[i][1] %= mod;
        cnt[i][0] = 1 + 2 * cnt[i][1] - cnt[p[i]][1];
        cnt[i][0] %= mod;
    }
    cout << ((cnt[n][0] + 1) % mod + mod) % mod << "\n";
}  
