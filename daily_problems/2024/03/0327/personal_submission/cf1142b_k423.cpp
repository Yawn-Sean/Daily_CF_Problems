// https://codeforces.com/contest/1142/submission/253428781

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n), mp(n + 1), a(m);
    for (int i = 0; i < n; ++i)
        cin >> p[i], mp[p[i]] = i;
    for (int &x: a) cin >> x, x = mp[x];
    int k = __lg(n);
    vector<vector<int>> st(k + 1, vector<int>(m + 1, m));
    vector<int> nxt(n, m);
    for (int i = m - 1; i >= 0; --i) {
        st[0][i] = nxt[(a[i] + 1) % n];
        nxt[a[i]] = i;
    }
    for (int j = 0; j < k; ++j) {
        for (int i = 0; i < m; ++i) {
            st[j + 1][i] = st[j][st[j][i]];
        }
    }
    vector<int> f(m + 1, m);
    for (int i = m - 1; i >= 0; --i) {
        f[i] = i;
        for (int j = 0; j <= k; ++j) {
            if ((n - 1) >> j & 1) {
                f[i] = st[j][f[i]];
            }
        }
        f[i] = min(f[i], f[i + 1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << int(f[l - 1] < r);
    }
    cout << endl;
}
