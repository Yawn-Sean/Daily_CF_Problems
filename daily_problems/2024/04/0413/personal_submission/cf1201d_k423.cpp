// https://codeforces.com/contest/1201/submission/256445222

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    map<int, vector<int>> mp;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        mp[x].emplace_back(y);
    }
    vector<int> b(q);
    for (int &y: b) cin >> y;
    ranges::sort(b);
    auto f = [&](int y1, int y2) -> int {
        if (y1 > y2) swap(y1, y2);
        int i = ranges::lower_bound(b, y1) - b.begin();
        int j = ranges::upper_bound(b, y2) - b.begin();
        if (i < j) return y2 - y1;
        int ret = 1e9;
        if (i) ret = min(ret, y1 - b[i - 1]);
        if (j < q) ret = min(ret, b[j] - y2);
        return ret * 2 + y2 - y1;
    };

    i64 p = 1, l = 1, r = 1, lv = 0, rv = 0;
    if (mp.contains(1)) {
        l = ranges::min(mp[1]), r = ranges::max(mp[1]);
        lv = r - 1 + r - l, rv = r - 1;
        mp.extract(1);
    }
    for (auto &[x, ys]: mp) {
        int ly = ranges::min(ys), ry = ranges::max(ys);
        tie(lv, rv) = tuple(min(f(l, ry) + lv, f(r, ry) + rv), min(f(l, ly) + lv, f(r, ly) + rv));
        int add = ry - ly + x - p;
        lv += add, rv += add, p = x, l = ly, r = ry;
    }
    cout << min(lv, rv) << endl;
}
