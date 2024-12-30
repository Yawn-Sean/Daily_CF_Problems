// https://codeforces.com/contest/1569/submission/259711379

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> xs(n), ys(m);
    for (int &x: xs) cin >> x;
    for (int &y: ys) cin >> y;
 
    vector<pii> p(k);
    for (auto &[x, y]: p) cin >> x >> y;
 
    i64 ans = 0;
    ranges::sort(p);
    for (int i = 0, j = 0; i + 1 < n; ++i) {
        while (j < k && p[j].first <= xs[i]) j++;
        map<int, int> cnt;
        for (int t = j; t < k && p[t].first < xs[i + 1]; ++t) {
            cnt[p[t].second]++;
        }
        i64 pre = 0;
        for (auto &[_, cur]: cnt) {
            ans += cur * pre;
            pre += cur;
        }
    }
    ranges::sort(p, [&](pii &a, pii &b) { return a.second < b.second; });
    for (int i = 0, j = 0; i + 1 < m; ++i) {
        while (j < k && p[j].second <= ys[i]) j++;
        map<int, int> cnt;
        for (int t = j; t < k && p[t].second < ys[i + 1]; ++t) {
            cnt[p[t].first]++;
        }
        i64 pre = 0;
        for (auto &[_, cur]: cnt) {
            ans += cur * pre;
            pre += cur;
        }
    }
    cout << ans << endl;
}
