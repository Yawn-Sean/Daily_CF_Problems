// https://codeforces.com/contest/965/submission/260866449

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2, 1e9), f(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    deque<pii> Q;
    f[0] = 1e9;
    for (int i = 0, j = 1; i <= n; ++i) {
        while (j <= i + k && j <= n + 1) Q.emplace_back(a[j], j), j++;
        if (!Q.empty() && Q.front().second == i) Q.pop_front();
        while (f[i] && !Q.empty()) {
            auto &[x, p] = Q.back();
            if (x <= f[i]) {
                f[p] += x, f[i] -= x, Q.pop_back();
            } else {
                f[p] += f[i], x -= f[i], f[i] = 0;
            }
        }
    }
    cout << f[n + 1] << endl;
}
