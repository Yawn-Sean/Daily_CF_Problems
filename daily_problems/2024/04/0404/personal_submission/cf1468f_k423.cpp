// https://codeforces.com/contest/852/submission/254986783

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    i64 ans = 0;
    map<pii, int> cnt;
    while (n--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x -= a, y -= b;
        int z = gcd(x, y);
        x /= z, y /= z;
        if (cnt.contains(pii{-x, -y})) ans += cnt[pii{-x, -y}];
        cnt[pii{x, y}]++;
    }
    cout << ans << endl;
}
