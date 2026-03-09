void solve() {
    int n;
    cin >> n;
    i64 tot = n * (n + 1) / 2;
    if (tot & 1) {
        cout << 0 << '\n';
        return;
    }
    i64 target = tot / 2;
    vector<vector<Z>> f(n / 2 + 2, vector<Z>(target + 1));
    f[0][0] = 1;

    for (int p = 0; p <= n; p++) {
        for (int i = n / 2 + 1; i > 0; i--) {
            for (int j = p; j <= target; j++) {
                f[i][j] += f[i - 1][j - p];
            }
        }
    }
    int m = n + 1;
    Z res = (f[m / 2][target] + f[m - m / 2][target]) / 2 * comb.fac(m / 2) * comb.fac(m - m / 2);
    cout << res << '\n';
}
