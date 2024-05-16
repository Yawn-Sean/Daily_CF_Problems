// https://codeforces.com/contest/954/submission/261026354

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, inf = 1e9;
    cin >> n;
    set<int> S;
    int p = -1;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x, x--;
        if (p >= 0 && abs(p - x) != 1) {
            S.insert(abs(p - x));
        }
        if (S.size() > 1) return NO();
        p = x;
    }
    if (S.empty()) {
        YES();
        cout << inf << ' ' << inf << endl;
    } else if (*S.begin() == 0) {
        NO();
    } else {
        int col = *S.begin();
        bool ok = true;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] / col == a[i + 1] / col) ok &= abs(a[i] - a[i + 1]) == 1;
            else ok &= abs(a[i] - a[i + 1]) == col;
        }
        if (!ok) return NO();
        YES();
        cout << inf << ' ' << col << endl;
    }
}
