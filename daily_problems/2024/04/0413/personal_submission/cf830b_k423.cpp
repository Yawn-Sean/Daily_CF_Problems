// https://codeforces.com/contest/830/submission/256448100

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) mp[a[i]].emplace_back(i);
    i64 ans = 0;
    int p = -1;
    fenwick<int> fcc(n);
    for (auto &[x, ids]: mp) {
        int j = ranges::lower_bound(ids, p) - ids.begin();
        for (int k = 0; k < ids.size(); ++k) {
            int i = ids[(j + k) % ids.size()];
            if (i > p) {
                ans += i - p - (fcc.get(i) - fcc.get(p));
            } else {
                ans += i + n - p - (fcc.get(i) + fcc.get(n - 1) - fcc.get(p));
            }
            fcc.modify(i, 1);
            p = i;
        }
    }
    cout << ans << endl;
}
