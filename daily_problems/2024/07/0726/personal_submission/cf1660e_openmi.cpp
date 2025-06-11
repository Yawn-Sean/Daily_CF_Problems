void solve() {
    int n;
    cin >> n;
    vc<string> vs(n);
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) cin >> vs[i], cnt1 += count(all(vs[i]), '1');
    int rk = 0;
    rep (d, 0, n) {
        int cur = 0;
        rep (j, 0, n) {
            cur += vs[(j + d) % n][j] == '1';
        }
        chmax(rk, cur);
    }
    cout << cnt1 - rk + n - rk << nl;
}
