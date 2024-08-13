/*
f 函数怎么算？
假设 j 是 i 的约数
f[i] = f[i / j] + i / j * C(j, 2)
O(rlogr) 枚举所有的约数关系并顺手转移 DP
*/

int T;
LL f[N], t, l, r;

void solve1() {
    cin >> t >> l >> r;
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= r; i++) {
        f[i] = min(f[i], (LL)i * (i - 1) / 2);
        for (int j = 2; i * j <= r; j++) {
            f[i * j] = min(f[i * j], f[i] + (LL)j * (j - 1) / 2 * (LL)i);
        }
    }

    LL res = 0, base = 1;
    for (int i = l; i <= r; i++) {
        res += (f[i] % MOD1) * base % MOD1;
        base *= t;
        base %= MOD1;
        res %= MOD1;
    }
    cout << res << '\n';
}       
