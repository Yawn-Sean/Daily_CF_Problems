void solve() {
    LL n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;
    array<LL, 2> a, b;
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    LL ans = 0;
    if (a[0] == b[0] && a[1] == b[1]) {
        ans = fpow(k, n * m, mod);
    } else {
        ans = fpow(k, n * m - r * c, mod);
    }
    cout << ans << endl;
}
