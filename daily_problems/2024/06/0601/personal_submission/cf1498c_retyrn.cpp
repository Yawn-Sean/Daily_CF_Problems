int n, k;

void solve() {
    cin >> n >> k;
    vector<vector<int>> f(n + 1, vector<int>(k + 1, 0)); // f[i][j] 前面有i个可以走的面, 当前阶数为j的个数
    
    for (int j = 1; j <= k; j ++) {
        f[0][j] = 1;
        for (int i = 1; i <= n; i ++) {
            f[i][j] = (f[i - 1][j] + f[n - i][j - 1]) % mod;
        }
    }
    cout << f[n][k] << endl;
}