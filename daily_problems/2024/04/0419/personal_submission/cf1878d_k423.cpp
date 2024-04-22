// https://codeforces.com/contest/1878/submission/225313659

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(k), r(k);
    for (int &x: l) cin >> x, --x;
    for (int &x: r) cin >> x, --x;
    int q;
    cin >> q;
    vector<int> f(n + 1);
    while (q--) {
        int x;
        cin >> x, --x;
        int i = lower_bound(itr(r), x) - r.begin();
        int a = min(x, r[i] + l[i] - x), b = max(x, r[i] + l[i] - x);
        f[a] += 1, f[b + 1] -= 1;
    }
    string t = s;
    for (int i = 0; i < n; ++i) {
        if (i) f[i] += f[i - 1];
        if (f[i] % 2 == 0) continue;
        int j = lower_bound(itr(r), i) - r.begin();
        t[i] = s[r[j] + l[j] - i];
    }
    cout << t << endl;
}
