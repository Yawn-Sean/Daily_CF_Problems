void solve() {
    i64 n, k;
    cin >> n >> k;
    i64 p = n + 1;
    for (i64 g = 1; g * g <= n; g++) {
        if (n % g == 0) {
            if (g <= k) {
                chmax(p, n + g);
            }
            if (n / g <= k) {
                chmax(p, n + n / g);
            }
        }
    }
    cout << p << '\n';
}
