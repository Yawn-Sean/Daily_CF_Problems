// https://codeforces.com/contest/678/submission/266648176
LL qpow(LL a, LL b, LL mod) {
    LL base = a % mod;
    LL res = 1;
    while (b) {
        if (b & 1) {
            (res *= base) %= mod;
        }
        (base *= base) %= mod;
        b >>= 1;
    }
    return res;
}
void sol()
{
    LL A, B, n, x;
    cin >> A >> B >> n >> x;
    if (A == 1) {
        LL C = ((n % mod1) * (B % mod1)) % mod1;
        cout << (x + C) % mod1 << '\n';
    } else {
        // C = A ^ n * x
        LL An = qpow(A, n, mod1);
        LL C = (An * (x % mod1)) % mod1;
        // D = B * (A^n - 1) / (A - 1)
        LL D = (B * (An - 1)) % mod1;
        (D *= qpow(A - 1, mod1 - 2, mod1)) %= mod1;
        cout << (C + D) % mod1 << '\n';
    }

}
