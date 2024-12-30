// https://codeforces.com/contest/917/submission/261720402

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    string s;
    cin >> s;
    int ans = 0;
    for (int n = s.size(), i = 0; i < n; ++i) {
        int L = 0, R = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '(') L++, R++;
            else if (s[j] == ')') L--, R--;
            else L--, R++;
            L = max(L, 0);
            if (R < 0) break;
            ans += (j - i) % 2 == 1 && L == 0;
        }
    }
    cout << ans << endl;
}
