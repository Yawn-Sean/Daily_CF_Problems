// https://codeforces.com/contest/386/submission/259028093

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    string s;
    cin >> s;
    int m = set(itr(s)).size();
    vector<int> pre(27, -1);
    vector<int64_t> ans(m + 1);
    for (int i = 0; i < s.size(); ++i) {
        pre[s[i] - 'a'] = i;
        vector<int> cur = pre;
        ranges::sort(cur, greater<>{});
        for (int j = 1; j <= 26; ++j) {
            ans[j] += cur[j - 1] - cur[j];
        }
    }
    cout << m << endl;
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << endl;
    }
}
