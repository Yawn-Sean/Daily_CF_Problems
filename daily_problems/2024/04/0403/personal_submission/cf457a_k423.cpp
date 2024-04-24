// https://codeforces.com/contest/457/submission/254781836

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    string s1, s2;
    cin >> s1 >> s2;
    ranges::reverse(s1), ranges::reverse(s2);
    while (s1.size() > 2 && s1.back() == '0') s1.pop_back();
    while (s2.size() > 2 && s2.back() == '0') s2.pop_back();
 
    int n = max(s1.size(), s2.size());
    if (n < 2) n = 2;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        if (i < s1.size()) a[i] = s1[i] - '0';
        if (i < s2.size()) b[i] = s2[i] - '0';
    }
    for (int i = n - 1; i >= 2; --i) {
        int t = min(a[i], b[i]);
        a[i] -= t, b[i] -= t;
        if (a[i] >= 2) {
            cout << '>' << endl;
            return;
        } else if (b[i] >= 2) {
            cout << '<' << endl;
            return;
        } else {
            a[i - 2] += a[i], a[i - 1] += a[i], a[i] = 0;
            b[i - 2] += b[i], b[i - 1] += b[i], b[i] = 0;
        }
    }
    ranges::reverse(a), ranges::reverse(b);
    if (a == b) cout << '=' << endl;
    else if (a > b) cout << '>' << endl;
    else cout << '<' << endl;
}
