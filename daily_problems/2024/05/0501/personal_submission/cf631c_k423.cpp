// https://codeforces.com/contest/631/submission/259029044

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<pii> ops;
    while (q--) {
        int op, x;
        cin >> op >> x;
        while (!ops.empty() && ops.back().second <= x) ops.pop_back();
        ops.emplace_back(op, x);
    }
    ops.emplace_back(1, 0);
    int m = ops[0].second;
    ranges::sort(a.begin(), a.begin() + m);
    deque<int> Q;
    for (int i = 0; i < m; ++i) Q.emplace_back(a[i]);
    for (int i = 1, j = m - 1; i < ops.size(); ++i) {
        int sz = ops[i - 1].second - ops[i].second;
        if (ops[i - 1].first == 1) {
            for (int k = 0; k < sz; k++) {
                a[j--] = Q.back();
                Q.pop_back();
            }
        } else {
            for (int k = 0; k < sz; k++) {
                a[j--] = Q.front();
                Q.pop_front();
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
