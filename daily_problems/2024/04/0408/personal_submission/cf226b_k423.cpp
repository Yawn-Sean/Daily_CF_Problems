// https://codeforces.com/contest/226/submission/255559315

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<i64> f(n + 1);
    for (int &x: a) cin >> x;
    ranges::sort(a, greater<>{});
    for (int i = 0; i < n; ++i) f[i + 1] = f[i] + a[i];
    vector<i64> ans(n);
    for (int k = 1; k < n; ++k) {
        i64 &val = ans[k], siz = k;
        for (i64 i = 1, p = 1; i < n; i += siz, p++, siz *= k) {
            int j = min(i64(n), i + siz);
            val += p * (f[j] - f[i]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << ans[min(k, n - 1)] << " \n"[q == 0];
    }
}
