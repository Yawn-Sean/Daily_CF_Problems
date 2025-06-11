void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vl a(n), pre(n + 1), suf(n + 1);
    in(a);
    rep (i, 0, n) pre[i + 1] = pre[i] | a[i];
    br (i, n - 1, 0) suf[i] = suf[i + 1] | a[i];
    ll xk = pow(x, k), ans = 0;
    rep (i, 0, n) {
        chmax(ans, pre[i] | suf[i + 1] | (xk * a[i]));
    }
    cout << ans;
}
