// https://codeforces.com/contest/1903/submission/256080349

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    int sx, sy;
    cin >> sx >> sy;
    int s = (sx + sy) % 2;
    multiset<int> a, b;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        int t = (x + y) % 2;
        (t == s ? a : b).emplace(i);
    }
    if (a.size() < b.size()) {
        cout << "Second" << endl;
        while (!a.empty() || !b.empty()) {
            int x;
            cin >> x;
            (a.contains(x) ? a : b).extract(x);
            if (a.empty() && b.empty()) break;
            x = *(a.empty() ? b : a).begin();
            cout << x << endl;
            (a.contains(x) ? a : b).extract(x);
        }
    } else {
        cout << "First" << endl;
        while (!a.empty() || !b.empty()) {
            int x = *(b.empty() ? a : b).begin();
            cout << x << endl;
            (a.contains(x) ? a : b).extract(x);
            if (a.empty() && b.empty()) break;
            cin >> x;
            (a.contains(x) ? a : b).extract(x);
        }
    }
}
