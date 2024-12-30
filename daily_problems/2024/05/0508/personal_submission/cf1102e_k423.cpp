// https://codeforces.com/contest/1102/submission/259969619

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    map<int, int> L, R;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (!L.contains(x)) L[x] = i;
        R[x] = i;
    }
    vector<pii> p;
    for (auto &[x, l]: L) p.emplace_back(l, R[x]);
    ranges::sort(p);
    vector<int> S;
    for (auto &[l, r]: p) {
        if (S.empty() || S.back() < l) S.emplace_back(r);
        else S.back() = max(S.back(), r);
    }
    i64 ans = 1, mod = 998244353;
    for (int t = 1; t < S.size(); ++t) {
        ans = ans * 2 % mod;
    }
    cout << ans << endl;
}
