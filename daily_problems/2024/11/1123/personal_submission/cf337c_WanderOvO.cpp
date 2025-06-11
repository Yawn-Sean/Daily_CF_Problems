/*
分数保底是 m，多是因为连续答对导致的 * 2
尽可能减少 * 2 的次数，尽可能让 * 2 之前的数小一些
最小的 * 2 次数一定是贪心满 k - 1 就及时打断
答对了 m 题，每 k - 1 题分一段，可以分 m / (k - 1) 完整段，以及可能有一个不完整段
我们至多有 n - m 个间隔，所以至多分成 n - m + 1 段连续的答对的
如何求连续 cnt 次之后能得多少分
有 cnt / k 次满 k
1 次满 k 是 k * 2
2 次满 k 是 (k * 2 + k) * 2 = k * 2^2 + k * 2
3 次满 k 是 ((k * 2 + k) * 2 + k) * 2 = k * 2^3 + k * 2^2 + k * 2
2 + 2^2 + ... + 2^cnt = 2 * (2^cnt - 1)
*/

LL n, m, k;
int mod = 1e9 + 9;

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
    cin >> n >> m >> k;
    LL seg_cnt = (m + k - 2) / (k - 1);
    if (n - m + 1 >= seg_cnt) {
        cout << m % mod << "\n";
        return;
    }
    LL cnt = m - (n - m) * (k - 1);
    LL res = 2 * k * (qpow(2, cnt / k, mod) - 1) % mod;
    res += cnt % k;
    res %= mod;
    res += (n - m) * (k - 1) % mod;
    res %= mod;
    cout << (res % mod + mod) % mod << "\n";
}
