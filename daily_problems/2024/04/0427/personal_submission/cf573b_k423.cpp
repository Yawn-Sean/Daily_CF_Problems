// https://codeforces.com/contest/573/submission/258413978

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> f1(n + 2);
    for (int i = 1, p = 0; i <= n; ++i) {
        p = min(a[i] - i, p);
        f1[i] = i + p;
    }
    int ans = 1;
    for (int i = n, p = 0; i; --i) {
        p = min(a[i] - (n + 1 - i), p);
        ans = max(ans, min(f1[i], (n + 1 - i) + p));
    }
    cout << ans << endl;
}
