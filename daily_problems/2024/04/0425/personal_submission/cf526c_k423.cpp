// https://codeforces.com/contest/526/submission/258054893

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    i64 n, h1, h2, w1, w2;
    cin >> n >> h1 >> h2 >> w1 >> w2;
    if (w1 < w2) swap(h1, h2), swap(w1, w2);
    i64 ans = 0;
    if (n / w1 < 2e6) {
        for (int i = 0; n >= 0; ++i, n -= w1) {
            chmax(ans, i * h1 + n / w2 * h2);
        }
    } else {
        int m = w1 * w2 * 2;
        vector<i64> f(m + 1);
        for (int i = w1; i <= m; ++i) {
            chmax(f[i], f[i - w1] + h1);
        }
        for (int i = w2; i <= m; ++i) {
            chmax(f[i], f[i - w2] + h2);
        }
        for (int i = 1; i <= m && i <= n; ++i) {
            chmax(ans, (n / i) * f[i] + f[n % i]);
        }
    }
    cout << ans << endl;
}
