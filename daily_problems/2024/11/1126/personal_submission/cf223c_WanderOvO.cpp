/*
进行 k 轮之后，考虑每个位置中，每个 a[i] 贡献了多少次
显然，a[i] 只会贡献给 s[j], j >= i
a[1], 0, 0, 0
a[1], a[1], a[1], a[1]
a[1], 2 * a[1], 3 * a[1], 4 * a[1], 5 * a[1]
a[1], 3 * a[1], 6 * a[1], 10 * a[1], 15 * a[1]
a[1], 4 * a[1], 10 * a[1], 20 * a[1], 35 * a[1]
a[1], 5 * a[1], 15 * a[1], 35 * a[1], 70 * a[1]
a[1], 6 * a[1], 21 * a[1], 56 * a[1], 126 * a[1]
很阶乘的贡献
*/

LL n, k, a[N], s[N];
int mod = MOD1;

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
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        LL contribution = a[i];
        for (int j = i; j <= n; j++) {
            s[j] += contribution;
            s[j] %= mod;
            contribution *= (k + j - i);
            contribution %= mod;
            contribution *= qpow(j - i + 1, mod - 2, mod);
            contribution %= mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << s[i] % mod << " "; 
    }
}
