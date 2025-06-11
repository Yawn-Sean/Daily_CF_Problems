void solve() {
    int n;
    cin >> n;
    vc<double> p(n), q(n);
    in(p);
    rsrt(p);
    double p1 = p[0], p0 = 1 - p[0], ans = p1;
    rep (i, 1, n) {
        p1 = p0 * p[i] + p1 * (1 - p[i]);
        p0 = p0 * (1 - p[i]);
        chmax(ans, p1);
    }
    cout << setprecision(10) << ans;
}
