// https://codeforces.com/contest/852/submission/260522666

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m, a, q;
    cin >> n >> m >> a >> q;
    vector<i64> powers(1, 1);
    do {
        powers.emplace_back(powers.back() * a % q);
    } while (powers.back() != 1);
    md = powers.size() - 1;
    vector<int> ans(n);
    Mint cnt{};
    for (int i = 0; i < n; ++i) {
        cnt += C(m, i);
        ans[i] = cnt;
    }
    for (int i = n - 1; i >= 0; --i) {
        cout << powers[ans[i]] << " \n"[i == 0];
    }
}
