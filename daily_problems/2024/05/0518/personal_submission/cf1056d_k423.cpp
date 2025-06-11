// https://codeforces.com/contest/1056/submission/261571112

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> fa(n), ans(n, 1);
    for (int i = 1; i < n; ++i)
        cin >> fa[i], fa[i]--, ans[fa[i]] = 0;
    for (int i = n - 1; i; --i) ans[fa[i]] += ans[i];
    ranges::sort(ans);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}
