void solve() {
    int n;
    i64 P;
    cin >> n >> P;
    Z::setMod(P);

    vector<Z> pow2(n + 1), pow3(n + 1), d(n + 1);
    pow2[0] = 1, pow3[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow2[i] = pow2[i - 1] * 2;
        pow3[i] = pow3[i - 1] * 3;
        if (i >= 2) {
            d[i] = Z(1) / (pow2[i] - 2);
        }
    }
    comb.init(n);

    vector<Z> dp(n + 1);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = pow3[i - 1] * d[i];
        Z sum = 0;
        for (int j = 1; j < i; j++) {
            sum += comb.binom(i, j) * dp[j];
        }
        dp[i] += sum * d[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " \n"[i == n];
    }
}
