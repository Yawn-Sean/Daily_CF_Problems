// https://codeforces.com/contest/747/submission/258931635

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int cnt = ranges::count_if(a, [&](int v) { return v < 0; });
    if (cnt > k) return NO();
    if (cnt == 0) return YES(0);
    vector<int> p;
    int first = ranges::find_if(a, [&](int v) { return v < 0; }) - a.begin();
    for (int i = first; i < n; ++i) {
        if (a[i] >= 0) {
            p.emplace_back(0);
            while (i < n && a[i] >= 0) p.back()++, i++;
        }
    }
    int m = n - first;
    auto help = [&](vector<int> p) -> int {
        int t = m, ret = 1;
        ranges::sort(p);
        while (t > k && p.size()) t -= p.back(), ret += 2, p.pop_back();
        return t <= k ? ret : int(1e9);
    };
    int ans = help(p);
    if (a.back() >= 0) {
        m -= p.back();
        p.pop_back();
        ans = min(ans, help(p) + 1);
    }
    cout << ans << endl;
}
