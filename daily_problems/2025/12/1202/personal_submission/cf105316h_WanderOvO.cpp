/*
和 gemini 的商量过程
https://gemini.google.com/share/700cfbd0a0f3
*/

LL n;
const int mod = 998244353;

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

void solve() {
    cin >> n;
    LL res = -n;
    for (int i = 1; i <= n; i++) {
        res += (n + 1) * qpow(i, mod - 2, mod) % mod;
        res %= mod;
    }
    cout << (res % mod + mod) % mod << "\n";
}
