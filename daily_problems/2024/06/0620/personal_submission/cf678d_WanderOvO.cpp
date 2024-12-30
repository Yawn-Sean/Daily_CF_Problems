/*
g_n(x) = a^n * x + b * (1 + a + ... + a^(n-1))
计算中的结果很大，可能需要手写龟速乘
*/

int T;
LL a, b, n, x;

void solve1() {
    cin >> a >> b >> n >> x;
    a %= MOD1;
    b %= MOD1;
    x %= MOD1;
    LL res1 = mul(qpow(a, n, MOD1), x, MOD1);
    LL res2 = mul(b, ( a == 1 ? n : (mul(((qpow(a, n, MOD1) - 1) % MOD1 + MOD1) % MOD1, qpow(a - 1, MOD1 - 2, MOD1), MOD1)) ), MOD1);
    LL res = ((res1 + res2) % MOD1 + MOD1) % MOD1;
    cout << res << "\n";
}             