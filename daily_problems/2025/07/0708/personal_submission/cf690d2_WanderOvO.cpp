/*
有 C 列，相当于 x[1] + ... + x[c] = m, 1 <= m <= n 的整数解个数
答案是 C(m + c - 1, c - 1)，for m in 1...n
使用阶乘逆元计算即可
*/

LL n, c, fact[N], invfact[N];

LL qpow(LL a, LL b, LL mod) {
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
    cin >> n >> c;
    fact[0] = 1;
    invfact[0] = 1;
    const int mod = 1e6 + 3;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        invfact[i] = qpow(fact[i], mod - 2, mod);
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res += ((fact[i + c - 1] * invfact[c - 1] % mod) * invfact[i] % mod);
        res %= mod;
    }
    cout << res << "\n";
}
