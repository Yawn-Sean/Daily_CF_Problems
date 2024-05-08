// https://codeforces.com/contest/1114/submission/258047146

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    i64 n, b;
    cin >> n >> b;
 
    auto f = [&](i64 p) {
        i64 ret = 0, x = n;
        while (x >= p) {
            ret += x / p;
            x /= p;
        }
        return ret;
    };
 
    i64 ans = 1e18;
    for (i64 i = 2; i * i <= b; ++i) {
        if (b % i == 0) {
            int k = 0;
            while (b % i == 0) b /= i, k++;
            ans = min(ans, f(i) / k);
        }
    }
    if (b > 1) ans = min(ans, f(b));
    cout << ans << endl;
}
