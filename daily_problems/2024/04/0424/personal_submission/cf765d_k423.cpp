// https://codeforces.com/contest/765/submission/257921751

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], a[i]--;
    for (int i = 0; i < n; ++i) {
        if (a[a[i]] != a[i]) {
            return NO();
        }
    }
    vector<int> h, c(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) {
            c[i] = h.size();
            h.emplace_back(i);
        }
    }
    cout << h.size() << endl;
    for (int i = 0; i < n; ++i) {
        cout << c[a[i]] + 1 << " \n"[i == n - 1];
    }
    for (int x: h) {
        cout << x + 1 << " \n"[x == h.back()];
    }
}
