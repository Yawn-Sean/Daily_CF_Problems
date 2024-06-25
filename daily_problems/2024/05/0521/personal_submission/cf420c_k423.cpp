// https://codeforces.com/contest/420/submission/262011619

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, p;
    cin >> n >> p;
    vector<int> cnt(n);
    vector<pii> ps(n);
    map<pii, int> mp;
    for (auto &[x, y]: ps) {
        cin >> x >> y, x--, y--;
        if (x > y) swap(x, y);
        cnt[x]++, cnt[y]++;
        mp[{x, y}]++;
    }
    int64_t ans = 0;
    for (auto &[a, b]: mp) {
        auto [x, y] = a;
        if (cnt[x] + cnt[y] >= p && cnt[x] + cnt[y] - b < p) {
            ans--;
        }
    }
    ranges::sort(cnt);
    for (int i = n - 1, j = 0; i >= 0; --i) {
        while (j < i && cnt[i] + cnt[j] < p) ++j;
        ans += max(0, i - j);
    }
    cout << ans << endl;
}
