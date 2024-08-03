// https://codeforces.com/contest/1220/submission/254368251

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<i64> a(n);
    vector<vector<int>> idx(60);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idx[__lg(a[i] & -a[i])].emplace_back(i);
    }
    int bit = 0;
    for (int k = 1; k < 60; ++k) {
        if (idx[k].size() > idx[bit].size()) {
            bit = k;
        }
    }
    vector<int> del(n, 1);
    for (int i: idx[bit]) del[i] = 0;
    cout << n - idx[bit].size() << endl;
    for (int i = 0; i < n; ++i) {
        if (del[i]) {
            cout << a[i] << ' ';
        }
    }
}
