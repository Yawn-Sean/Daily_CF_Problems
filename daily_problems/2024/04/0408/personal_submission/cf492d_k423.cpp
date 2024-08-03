// https://codeforces.com/contest/492/submission/255559615

/* 我永远喜欢爱莉希雅♪ */
string ans[4] = {"", "Vanya", "Vova", "Both"};
 
void elysia() {
    int n, x, y;
    cin >> n >> x >> y;
    while (n--) {
        int a;
        cin >> a;
        i64 lo = 1, hi = 1e18;
        while (lo < hi) {
            i64 mid = (lo + hi) / 2;
            if (mid / x + mid / y >= a) hi = mid;
            else lo = mid + 1;
        }
        cout << ans[1 << (lo % x == 0) | (lo % y == 0)] << endl;
    }
}
