// https://codeforces.com/contest/301/submission/255817155

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, neg = 0, mn = 1e9;
    cin >> n;
    vector<int> a(n * 2 - 1);
    int ans = 0;
    for (int &x: a) {
        cin >> x;
        ans += abs(x), neg += x < 0, mn = min(mn, abs(x));
    }
    if (neg % 2 && n % 2 == 0) {
        ans -= mn * 2;
    }
    cout << ans << endl;
}
