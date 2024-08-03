// https://codeforces.com/contest/613/submission/255816208

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    i64 n, A, cf, cm, m;
    cin >> n >> A >> cf >> cm >> m;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    if (accumulate(itr(a), 0ll) + m >= A * n) {
        cout << n * cf + A * cm << endl;
        for (int i = 0; i < n; ++i) {
            cout << A << " \n"[i == n - 1];
        }
        return;
    }
    vector<int> id(n), b = a;
    iota(itr(id), 0);
    ranges::sort(id, [&](int i, int j) { return a[i] < a[j]; });
    ranges::sort(b);
    fenwick<i64> fvv(n);
    for (int i = 0; i < n; ++i) fvv.modify(i, b[i]);
    i64 mx = b[0] * cm, minv = 0, full = 0;
    for (i64 i = 0, rem = m; i <= n; ++i) {
        if (i) rem -= A - b[n - i];
        if (rem < 0) break;
        i64 j = fvv.partition([&](i64 id, i64 tot) {
            return id == n || (id + 1) * b[id] - tot > rem;
        }) - 1;
        j = min(j, n - i - 1);
        i64 s = b[j] * (j + 1) - fvv.get(j), mn = b[j] + (rem - s) / (j + 1);
        i64 cur = i * cf + mn * cm;
        if (cur > mx) {
            mx = cur, minv = mn, full = i;
        }
    }
    cout << mx << endl;
    vector<i64> ans(itr(a));
    for (int i = 0; i < full; ++i) ans[id[n - i - 1]] = A;
 
    for (int i = 0; i < n; ++i) {
        cout << max(ans[i], minv) << " \n"[i == n - 1];
    }
}
