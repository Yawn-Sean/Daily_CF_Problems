/*
是否只要不出现同一颜色直接连边，且不出现一个点连了两个相同颜色的点，就是合法的？
为了满足这个条件，我们只需要分别枚举两种颜色之间一对一的连接怎么连即可，这样肯定合法。
*/

int T;
LL c[N][N], fact[N];
LL cnta, cntb, cntc;

void solve1() {
    cin >> cnta >> cntb >> cntc;
    LL res1 = 0, res2 = 0, res3 = 0;
    for (int i = 0; i <= min(cnta, cntb); i++) {
        res1 += ((c[cnta][i] * c[cntb][i] % MOD2) * fact[i]) % MOD2;
        res1 %= MOD2;
    }
    for (int i = 0; i <= min(cnta, cntc); i++) {
        res2 += ((c[cnta][i] * c[cntc][i] % MOD2) * fact[i]) % MOD2;
        res2 %= MOD2;
    }
    for (int i = 0; i <= min(cntb, cntc); i++) {
        res3 += ((c[cntb][i] * c[cntc][i] % MOD2) * fact[i]) % MOD2;
        res3 %= MOD2;
    }
    cout << ((res1 * res2 % MOD2) * res3) % MOD2 << "\n";
}      