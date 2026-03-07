void solve() {
    int n;
    cin >> n;
    vector<string> names(n);
    vector<int> p(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> p[i];
        if (p[i] == 0) {
            d[i] = 49;
        } else if (p[i] == 100) {
            p[i] = 9950;
            d[i] = 50;
        } else {
            p[i] = p[i] * 100 - 50;
            d[i] = 99;
        }
    }
    int tot = reduce(p.begin(), p.end(), 0);
    int delta = reduce(d.begin(), d.end(), 0);
    if (tot > 10000 or tot + delta < 10000) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    int r = 10000 - tot;
    for (int i = 0; i < n; i++) {
        int mx = p[i] + min(r, d[i]);
        int mn = p[i] + max(0, r - (delta - d[i]));
        cout << names[i];
        cout << ' ' << mn / 100 << (mn % 100 < 10 ? ".0" : ".") << mn % 100;
        cout << ' ' << mx / 100 << (mx % 100 < 10 ? ".0" : ".") << mx % 100;
        cout << '\n';
    }
}
