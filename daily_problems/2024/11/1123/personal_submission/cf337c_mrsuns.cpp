void Solve() {
    int n, m, k;cin >> n >> m >> k;
    int cnt = n / k, rem = n % k;
    if ((k - 1) * cnt + rem >= m) {
        cout << m << endl;
    }
    else {
        int use = m - rem - (k - 1) * cnt;
        int res = ((qp(2, use + 1) + MOD - 2) % MOD * k % MOD + (cnt - use) * (k - 1) % MOD + rem) % MOD;
        cout << res << endl;
    }
}
