void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    in(a);
    int costm = inf, costM = inf;
    int m = *min_element(ALL(a)), M = *max_element(ALL(a));
    if (m <= 1) costm = 0;
    if (x <= M) costM = 0;
    chmin(costm, abs(a[0] - 1));
    chmin(costm, abs(a[n-1] - 1));
    chmin(costM, abs(a[0] - x));
    chmin(costM, abs(a[n-1] - x));
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += abs(a[i + 1] - a[i]);
        chmin(costm, 2*abs(a[i] - 1));
        chmin(costM, 2*abs(a[i] - x));
    }
    cout << ans + costm + costM << nl;
}
