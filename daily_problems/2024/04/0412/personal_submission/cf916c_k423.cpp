// https://codeforces.com/contest/916/submission/256192094

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    int p = 998244353;
    cout << 2 << ' ' << (n == 2 ? 2 : p) << endl;
    vector<int> id(n), w(n, 2);
    iota(itr(id), 0);
    id[0] = n;
    if (n > 2) w[n - 1] = p - n * 2 + 4;
    m -= n - 1;
    for (int i = 1; i < n; ++i) {
        cout << id[i - 1] << ' ' << id[i] << ' ' << w[i] << endl;
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j + 1 < i && m; ++j, m--) {
            cout << id[j] << ' ' << id[i] << ' ' << w[i] << endl;
        }
    }
}
