const int N = 2e6 + 5;

int n, m, a, q, lg, fac[N], inv[N], ifac[N], coeff[N];

inline int qpow(int x, int y) {
    int ans = 1;
    for(; y; y >>= 1, x = 1LL * x * x % q) if(y & 1) ans = 1LL * ans * x % q;
    return ans;
}

inline int C(int x, int y) {
    if(x < 0 || y < 0 || x < y) return 0;
    return 1LL * fac[x] * ifac[y] % lg * ifac[x - y] % lg;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> a >> q;
    a %= q;
    lg = 1;
    for(int u = a; u != 1; u = 1LL * u * a % q) ++lg;
    fac[0] = fac[1] = inv[0] = inv[1] = ifac[0] = ifac[1] = 1;
    rep(i, 2, lg - 1) {
        fac[i] = 1LL * fac[i - 1] * i % lg;
        inv[i] = 1LL * (lg - lg / i) * inv[lg % i] % lg;
        ifac[i] = 1LL * ifac[i - 1] * inv[i] % lg;
    }
    coeff[0] = 1;
    rep(i, 1, n) coeff[i] = (coeff[i - 1] + C(m, i)) % lg;
    per(i, n, 1) cout << qpow(a, coeff[i - 1]) << " \n"[i == 1];
    return 0;
}
