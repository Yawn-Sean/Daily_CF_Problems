// https://codeforces.com/contest/1029/submission/258178624

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, inf = 1e9;
    cin >> n;
    vector<pair<int, int>> p(n), f(n + 1, {-inf, inf});
    for (auto &[l, r]: p) cin >> l >> r;
    for (int i = n - 1, L = -inf, R = inf; i >= 0; --i) {
        auto [l, r] = p[i];
        L = max(L, l), R = min(R, r);
        f[i] = {L, R};
    }
    int ans = 0;
    for (int i = 0, L = -inf, R = inf; i < n; ++i) {
        auto [l, r] = f[i + 1];
        ans = max(ans, min(R, r) - max(L, l));
        tie(l, r) = p[i];
        L = max(L, l), R = min(R, r);
    }
    cout << ans << endl;
}
