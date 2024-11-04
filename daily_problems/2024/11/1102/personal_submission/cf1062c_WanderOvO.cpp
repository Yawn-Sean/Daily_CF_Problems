/*
发现先吃大的比较好，也就是先把 1 的都给吃了，再吃 0 的
假设区间里有 cnt1 个 1，cnt0 个 0
把 1 吃完的收益是 1 + 2 + 4 + 8 + ... + 2^(cnt1 - 1)
这个时候，剩下的那些 0 都变成了 2^cnt1 - 1
之后它们的贡献就是 2^cnt1 - 1 + 2*(2^cnt1 - 1) + 4*(2^cnt1 - 1) + ... + 2^(cnt0 - 1) * (2^cnt1 - 1)
= (2^cnt1 - 1) * (1 + 2 + 4 + 8 + ... + 2^(cnt0 - 1))
*/

string s;
int n, q;

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

LL sum(LL a1, LL q, LL n) {
    LL res = a1 * (1 - qpow(q, n, MOD1)) % MOD1;
    res *= qpow(1 - q, MOD1 - 2, MOD1);
    res %= MOD1;
    res = (res + MOD1) % MOD1;
    return res;
}

void meibao() {
    cin >> n >> q >> s;
    s = " " + s;
    vector<LL> cnt1(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt1[i] = cnt1[i - 1] + s[i] - '0';
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int c1 = cnt1[r] - cnt1[l - 1];
        int c0 = (r - l + 1) - c1;
        LL res = sum(1, 2, c1);
        res += (qpow(2, c1, MOD1) - 1) * sum(1, 2, c0);
        res = (res % MOD1 + MOD1) % MOD1;
        cout << res << "\n";
    }
}
