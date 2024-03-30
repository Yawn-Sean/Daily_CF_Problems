// https://codeforces.com/contest/744/submission/254060494

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, inf = 1e9;
    cin >> n;
    string a(n, '.');
    vector<int> b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int R = ranges::count(a, 'R'), B = n - R;
    if (R > B) {
        swap(b, c), swap(R, B);
        for (char &x: a) x = x == 'R' ? 'B' : 'R';
    }
    int m = R * (R - 1) / 2 + R * B;
    vector<vector<int>> f(1 << n, vector<int>(m + 1, -inf));
    f[0][0] = 0;
    for (int i = 1; i < 1 << n; ++i) {
        int cr = 0, cb = 0;
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1) {
                (a[j] == 'R' ? cr : cb)++;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1) {
                int p = i ^ (1 << j);
                int vr = min(cr - (a[j] == 'R'), b[j]);
                int vb = min(cb - (a[j] == 'B'), c[j]);
                for (int x = vr; x <= m; ++x) {
                    chmax(f[i][x], f[p][x - vr] + vb);
                }
            }
        }
    }
    int ans = inf, sb = accumulate(itr(b), 0), sc = accumulate(itr(c), 0);
    for (int i = 0; i <= m; ++i) {
        ans = min(ans, max(sb - i, sc - f.back()[i]));
    }
    cout << ans + n << endl;
}
