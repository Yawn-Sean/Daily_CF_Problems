/*
11：
0 - 3
1 - 2
2 - 1
3 - 0

01：
0 - 1
1 - 0
2 - 3
3 - 2

假如 x 的某个位是 0，则不可能有 (a, b), (c, d) 是因为这一位而导致大小翻转的
假如 x 的某个位是 1，则对于 (a, b), (c, d)，a < c 且是在这一位决出大小的，会导致 b > d
这样的数有多少个？首先高位需要一样，然后这一位强制 a 是 0，b 是 1，之后的位两边随便填
假设这个是 x 的从高到低第 i 位，i 从 1 开始，x[i] = 1
则 1-i - 1 位需要一样，有 2^(i - 1) 种填法，然后 i 位确定，之后 i + 1 到 n 位各自都可以随便填，有 2^(2n - 2i)
*/

string x;

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
    cin >> x;
    LL n = x.size();
    x = " " + x;
    int mod = 1e9 + 7;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] == '1') {
            res += qpow(2, i - 1, mod) * qpow(2, 2 * n - 2 * i, mod) % mod;
            res %= mod;
        }
    }
    cout << res << "\n";
}
