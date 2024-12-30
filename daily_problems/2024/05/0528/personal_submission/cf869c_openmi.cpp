void solve() {
    vl a(3);
    in(a);
    ll ans = 1;
    rep (i, 0, 3) {
        rep (j, i + 1, 3) {
            ll t = 0;
            rb (k, 0, min(a[i], a[j])) {
                t += (comb(a[i], k) * comb(a[j], k) % mod * fact[k] % mod)%mod;
                t %= mod;
            }
            ans *= t;
            ans %= mod;
        }
    }
    cout << ans;
}
