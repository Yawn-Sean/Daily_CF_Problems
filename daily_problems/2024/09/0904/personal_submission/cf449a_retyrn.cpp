int n, m, k;

ll cal(int len, int cut) {
    if (cut < 0 or cut >= len) return 0ll;
    return len / (cut + 1);
}
void solve() {
    cin >> n >> m >> k;
    if (n + m - 2 < k) {
        cout << -1 << endl;
        return;
    }
    ll res = 0;
    for (int i = 1; i <= n / i; i ++) {
        if (n % i) continue;
        int cut = i - 1;
        chmax(res, cal(n, cut) * cal(m, k - cut));
        cut = n / i - 1;
        chmax(res, cal(n, cut) * cal(m, k - cut));
    }
    for (int i = 1; i <= m / i; i ++) {
        if (m % i) continue;
        int cut = i - 1;
        chmax(res, cal(m, cut) * cal(n, k - cut));
        cut = m / i - 1;
        chmax(res, cal(m, cut) * cal(n, k - cut));
    }
    cout << res << endl;
    
}