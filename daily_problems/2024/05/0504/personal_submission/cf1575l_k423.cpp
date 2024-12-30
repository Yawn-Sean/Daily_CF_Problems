// https://codeforces.com/contest/1575/submission/259530204

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x, x--;
    map<int, vector<int>> g;
    for (int i = 0; i < n; ++i) {
        if (i >= a[i]) {
            g[a[i]].emplace_back(i - a[i]);
        }
    }
    vector<int> lis;
    for (auto &[_, b]: g) {
        for (int x: b | views::reverse) {
            auto it = ranges::upper_bound(lis, x);
            if (it == lis.end()) lis.emplace_back(x);
            else *it = x;
        }
    }
    cout << lis.size() << endl;
}
