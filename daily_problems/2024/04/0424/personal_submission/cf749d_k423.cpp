// https://codeforces.com/contest/749/submission/257920558

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        int j, x;
        cin >> j >> x, j--;
        g[j].emplace_back(x);
    }
    multiset<pii> S;
    S.insert({0, 0});
    for (int i = 0; i < n; ++i) {
        if (!g[i].empty()) {
            S.emplace(g[i].back(), i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> del(k);
        for (int &i: del) {
            cin >> i, --i;
            if (!g[i].empty()) {
                S.extract({g[i].back(), i});
            }
        }
        if (S.size() == 1) {
            cout << "0 0" << endl;
        } else {
            auto [_, i] = *S.rbegin();
            auto [p, j] = *next(S.rbegin());
            cout << i + 1 << ' ' << *ranges::lower_bound(g[i], p) << endl;
        }
        for (int &i: del) {
            if (!g[i].empty()) {
                S.insert({g[i].back(), i});
            }
        }
    }
}
