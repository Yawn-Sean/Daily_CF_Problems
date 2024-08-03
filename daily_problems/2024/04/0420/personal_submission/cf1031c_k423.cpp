// https://codeforces.com/contest/1031/submission/257404370

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    i64 a, b;
    cin >> a >> b;
    i64 k = 0;
    while ((k + 1) * (k + 2) / 2 <= a + b) k++;
    vector<int> ans(k + 1);
    int cnt = 0;
    for (int i = k; i >= 1; --i) if (i <= a) ans[i] = 1, a -= i, cnt++;
    cout << cnt << endl;
    for (int i = 1; i <= k; ++i) if (ans[i]) cout << i << ' ';
    cout << endl;
    cout << k - cnt << endl;
    for (int i = 1; i <= k; ++i) if (!ans[i]) cout << i << ' ';
    cout << endl;
}
