// https://codeforces.com/contest/1175/submission/259526324

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    pii ans = {1e9, -1e9};
    for (int i = k; i < n; ++i) {
        ans = min(ans, pii{(a[i] - a[i - k] + 1) / 2, (a[i] + a[i - k]) / 2});
    }
    cout << ans.second << endl;
}
