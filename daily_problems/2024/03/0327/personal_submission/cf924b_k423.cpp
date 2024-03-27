// https://codeforces.com/contest/924/submission/253429109

using ld = long double;

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    ld ans = -1;
    for (int i = 0, j = 0; i + 2 < n; ++i) {
        j = max(j, i);
        while (j + 1 < n && a[j + 1] - a[i] <= m) j++;
        if (i + 1 < j) ans = max(ans, (ld(a[j]) - a[i + 1]) / (a[j] - a[i]));
    }
    if (ans < 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
