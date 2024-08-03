// https://codeforces.com/contest/863/submission/256986663

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<pii> p(n);
    vector<int> a;
    for (auto &[l, r]: p) {
        cin >> l >> r;
        a.emplace_back(l), a.emplace_back(r + 1);
    }
    ranges::sort(a);
    a.erase(ranges::unique(a).begin(), a.end());
    int m = a.size();
    vector<int> f(m + 1);
    for (auto &[l, r]: p) {
        l = ranges::lower_bound(a, l) - a.begin();
        r = ranges::upper_bound(a, r) - a.begin() - 1;
        f[l]++, f[r + 1]--;
    }
    for (int i = 0; i < m; ++i) f[i + 1] += f[i];
    for (int i = m, j = m; i >= 0; --i) {
        if (f[i] == 1) j = i;
        f[i] = j;
    }
    for (int i = 1; i <= n; ++i) {
        auto [l, r] = p[i - 1];
        if (f[l] > r) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}
