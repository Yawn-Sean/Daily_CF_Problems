// https://codeforces.com/contest/922/submission/257801200

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<string> g(n);
    vector<i64> s(n), h(n);
    for (int i = 0; i < n; ++i) {
        string &t = g[i];
        cin >> t;
        for (char x: t) {
            if (x == 's') s[i]++;
            else h[i]++;
        }
    }
    vector<int> id(n);
    iota(itr(id), 0);
    ranges::sort(itr(id), [&](int i, int j) -> bool {
        return s[i] * h[j] > s[j] * h[i];
    });
    i64 ans = 0, k = 0;
    for (int i: id) {
        for (char x: g[i]) {
            if (x == 's') k++;
            else ans += k;
        }
    }
    cout << ans << endl;
}
