// https://codeforces.com/contest/960/submission/261114991

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int X, d;
    cin >> X >> d;
    vector<i64> ans(1, -d);
    while (X) {
        int k = __lg(X + 1);
        X -= (1 << k) - 1;
        i64 cur = ans.back() + d + 1;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(cur);
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
