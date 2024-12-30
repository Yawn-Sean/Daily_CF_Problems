// https://codeforces.com/contest/1025/submission/261266346

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    s += s;
    for (int i = 1, j = 0; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) j = i;
        ans = max(ans, i - j + 1);
    }
    cout << min(ans, n) << endl;
}
