// https://codeforces.com/contest/444/submission/255139382

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    ld ans = 0;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        ans = max(ans, ld(a[u - 1] + a[v - 1]) / w);
    }
    cout << ans << endl;
}
