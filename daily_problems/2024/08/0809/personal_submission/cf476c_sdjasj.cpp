void solve() {
    LL a, b;
    cin >> a >> b;
    if (b == 1) {
        cout << 0 << endl;
        return;
    }
    LL cnt = (a + b * (1 + a) % MOD * a % MOD * qmi(2, MOD - 2, MOD) % MOD + MOD) % MOD;
    cnt = (b * (b - 1) % MOD * qmi(2, MOD - 2, MOD) % MOD * cnt % MOD + MOD) % MOD;
    cout << cnt << endl;
}
