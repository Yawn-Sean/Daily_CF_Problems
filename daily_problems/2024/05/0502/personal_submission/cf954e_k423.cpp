// https://codeforces.com/contest/954/submission/259250037

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    constexpr ld eps = 1e-12;
 
    int n, k;
    cin >> n >> k;
    vector<int> a(n), t(n);
    for (int &x: a) cin >> x;
    for (int &x: t) cin >> x;
    vector<pii> neg, pos;
    ld sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i], y = t[i];
        if (y < k) neg.emplace_back(y - k, x);
        else if (y > k) pos.emplace_back(y - k, x);
        ans += x, sum += ld(y - k) * x;
    }
    if (sum > 0) {
        ranges::sort(pos);
        while (sum > eps && !pos.empty()) {
            auto &[y, x] = pos.back();
            if (sum > ld(y) * x) {
                sum -= ld(y) * x;
                ans -= x;
                pos.pop_back();
            } else {
                ans -= sum / y;
                break;
            }
        }
    } else {
        ranges::sort(neg, greater<>{});
        while (sum < -eps && !neg.empty()) {
            auto &[y, x] = neg.back();
            if (sum < ld(y) * x) {
                sum -= ld(y) * x;
                ans -= x;
                neg.pop_back();
            } else {
                ans -= abs(sum / y);
                break;
            }
        }
    }
    cout << ans << endl;
}
