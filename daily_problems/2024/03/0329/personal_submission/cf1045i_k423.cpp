// https://codeforces.com/contest/1045/submission/253875424

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    int64_t ans = 0;
    map<int, int> cnt;
    while (n--) {
        string s;
        cin >> s;
        int mask = 0;
        for (char x: s) mask ^= 1 << (x - 'a');
        ans += cnt[mask]++;
        for (int i = 0; i < 26; ++i) {
            if (cnt.contains(mask ^ 1 << i)) {
                ans += cnt[mask ^ 1 << i];
            }
        }
    }
    cout << ans << endl;
}