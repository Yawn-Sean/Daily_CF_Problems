// https://codeforces.com/contest/1168/submission/259252038

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
 
    auto check = [&](int val) -> bool {
        int p = 0;
        for (int x: a) {
            if (x + val < m) {
                if (x + val < p) return false;
                p = max(x, p);
            } else {
                if (p > x + val - m && p < x) p = x;
            }
        }
        return true;
    };
 
    int lo = 0, hi = m;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << (lo == m ? -1 : lo) << endl;
}
