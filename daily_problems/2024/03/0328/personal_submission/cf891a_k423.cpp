// https://codeforces.com/contest/891/submission/253563769

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    SparseTable st(itr(a), [&](int x, int y) { return gcd(x, y); });
    if (st.get(0, n - 1) > 1) {
        cout << -1 << endl;
        return;
    }
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        bool ok = false;
        for (int i = 0; i + mid <= n; ++i) {
            if (st.get(i, i + mid - 1) == 1) {
                ok = true;
                break;
            }
        }
        if (ok) hi = mid;
        else lo = mid + 1;
    }
    if (lo == 1) {
        cout << n - ranges::count(a, 1) << endl;
    } else {
        cout << n + lo - 2 << endl;
    }
}