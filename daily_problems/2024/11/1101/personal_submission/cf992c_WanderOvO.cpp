/*
4 * cnt, 4 * cnt - 1, 4 * cnt - 2, 4 * cnt - 3
8 * cnt, 8 * cnt - 1, .... 8 * cnt - 6, 8 * cnt - 7
似乎是连续的一段取值
k 次之后，应该是 2^k * cnt, 2^k * cnt - 1... 2^k * cnt - (2^k - 1)，共 2^k 种可能取值
每种取值的可能性是多少？是相等的，都是 1 / 2^k，所以直接等差数列求和统一乘概率即可
*/

LL x, k;

LL qpow(LL a, LL b, LL MOD) {
    LL res = 1, base = a % MOD;
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
    cin >> x >> k;
    if (x == 0) {
        cout << "0\n";
        return;
    }

    LL res = 0;
    int mod = MOD1;
    x %= mod;
    res = (qpow(2, k, mod) * x % mod + qpow(2, k, mod) * x % mod - qpow(2, k, mod) + 1) % mod;
    res *= qpow(2, k, mod);
    res %= mod;
    res *= qpow(qpow(2, k, mod), mod - 2, mod);
    res %= mod;
    res = (res + mod) % mod;
    cout << res << "\n";
}
