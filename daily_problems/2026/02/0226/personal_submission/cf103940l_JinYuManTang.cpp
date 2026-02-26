void solve() {
    int k;
    cin >> k;
    vector<Z> f(k + 1), sum(k + 1);
    f[1] = 1, sum[1] = 1;
    for (int i = 2; i <= k; i++) {
        // f[i] = f[1] + …… + f[(i + 1) / 2]
        f[i] = sum[i - 1] - sum[(i + 1) / 2 - 1];
        sum[i] = sum[i - 1] + f[i];
    }
    cout << f[k];
}
