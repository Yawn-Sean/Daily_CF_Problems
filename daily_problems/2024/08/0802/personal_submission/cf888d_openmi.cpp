void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    vl a(5);
    a[1] = 1;
    a[2] = n * (n - 1) / 2;
    a[3] = n * (n - 1) * (n - 2) / 3;
    a[4] = n * (n - 1) * (n - 2) * (n - 3) / 8 * 3;
    rb (i, 1, k) {
        ans += a[i];
    }
    cout << ans << nl;
}
