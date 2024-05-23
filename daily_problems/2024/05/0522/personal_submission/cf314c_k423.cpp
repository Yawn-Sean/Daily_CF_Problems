// https://codeforces.com/contest/314/submission/262085573

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m = 0;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x, m = max(x, m);
    fenwick<Mint> fvv(m + 1);
    for (int x: a) {
        Mint pre = fvv.get(x) - fvv.get(x - 1);
        Mint cur = (fvv.get(x) + 1) * x;
        fvv.modify(x, cur - pre);
    }
    cout << fvv.get(m) << endl;
}
