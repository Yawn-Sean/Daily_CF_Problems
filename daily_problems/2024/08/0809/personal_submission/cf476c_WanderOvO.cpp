/*
x % b == k -> x = k + i * b -> x / b = i
1 <= i / k <= a，i 需要能整除 k，所以 i 取 k, 2 * k, ... a * k
枚举 k，只要 k <= i <= a * k，可以求出 x 的首项和项数从而求和
(b + 1) * k + ... + (a * b + 1) * k
= (b + 1 + a * b + 1) * a * k / 2
*/

int T;
LL a, b;

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

void solve1() {
    cin >> a >> b;
    LL res = 0;
    int mod = MOD1;
    LL inv2 = qpow(2, mod - 2, mod);
    for (int k = 1; k < b; k++) {
        res += (b + 1 + a * b + 1) % mod * a % mod * k % mod * inv2 % mod;
        res %= mod;
    }
    cout << res << "\n";
}                                                                                                              
