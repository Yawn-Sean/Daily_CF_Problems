// https://codeforces.com/contest/870/submission/254783643

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cout << "? " << 0 << ' ' << i << endl;
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << "? " << i << ' ' << 0 << endl;
        cin >> b[i];
    }
    vector<int> ans;
    int cnt = 0;
    for (int x = 0; x < n; ++x) {
        vector<int> p(n), q(n), vp(n), vq(n);
        for (int i = 0; i < n; ++i) {
            q[i] = a[i] ^ x;
            p[i] = b[i] ^ q[0];
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (p[i] >= n || q[i] >= n || vp[p[i]] || vq[q[i]] || p[q[i]] != i) {
                ok = false;
                break;
            }
            vp[p[i]] = vq[q[i]] = 1;
        }
        if (ok) cnt++, ans = p;
    }
    cout << "!\n" << cnt << endl;
    if (cnt) {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
}
