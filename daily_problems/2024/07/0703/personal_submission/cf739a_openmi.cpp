void solve() {
    int n, m, ans = inf<int>;
    std::cin >> n >> m;
    for (int i = 0, l, r; i < m; ++i) {
        cin >> l >> r;
        chmin(ans, r - l + 1);
    }
    cout << ans << nl;
    rb (i, 1, n) {
        cout << i % ans << ' ';
    }
}
