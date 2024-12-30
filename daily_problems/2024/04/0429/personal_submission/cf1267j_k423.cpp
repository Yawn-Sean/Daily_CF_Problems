// https://codeforces.com/contest/1267/submission/258749065

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    map<int, int> cnt, mp;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        cnt[x]++;
    }
    int m = n + 1;
    for (auto [x, y]: cnt) {
        m = min(m, y + 1);
        mp[y]++;
    }
    int ans = n;
    for (int k = 2; k <= m; ++k) {
        bool ok = true;
        int cur = 0;
        for (auto &[y, c]: mp) {
            if (y % k && y % k + y / k < k - 1) {
                ok = false;
                break;
            }
            cur += (y / k + bool(y % k)) * c;
        }
        if (ok) ans = min(ans, cur);
    }
    cout << ans << endl;
}
