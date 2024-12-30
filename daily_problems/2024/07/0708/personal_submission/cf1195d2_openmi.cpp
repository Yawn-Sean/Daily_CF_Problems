void solve() {
    int n;
    cin >> n;
    vl d(12), cnt(12);
    vi a(n);
    int x;
    rep (i, 0, n) {
        cin >> x;
        a[i] = x;
        int j = 0;
        for (; x; ++j) x /= 10;
        cnt[j] ++;
    }
    ll ans = 0;
    // 枚举作为 f(x, y) 中的x时
    for (int x: a) {
        ll  base = 1, t = 0;
        rep (len, 1, 11) {
            t = (t + x % 10 * base) % mod;
            x /= 10;
            ans += (x * 10 * base + t) % mod * cnt[len] * 10 % mod;
            ans %= mod;
            base *= 100;
            base %= mod;
        }
    }
    // 枚举作为 f(x, y) 中的y时
    for (int x: a) {
        ll  base = 1, t = 0;
        rep (len, 1, 11) {
            t = (t + x % 10 * base) % mod;
            x /= 10;
            ans += (x * 100 * base + t) % mod * cnt[len] % mod;
            ans %= mod;
            base *= 100;
            base %= mod;
        }
    }
    cout << ans << nl;
}
