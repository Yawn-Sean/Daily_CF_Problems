// https://codeforces.com/contest/1644/submission/259816568

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    i64 n;
    string s;
    cin >> n >> s;
    i64 ans;
    int R = ranges::count(s, 'R'), D = s.size() - R;
    if (R == 0 || D == 0) {
        ans = n;
    } else {
        ans = n * n;
        int pR = 0, pD = 0;
        for (int i = 0; i < s.size(); ++i) {
            (s[i] == 'R' ? pR : pD)++;
            if (s[i] == 'R') ans -= pD ? D - pD : n - 1;
            else ans -= pR ? R - pR : n - 1;
        }
    }
    cout << ans << endl;
}
