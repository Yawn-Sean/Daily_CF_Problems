int n, k, p;

void solve() {
    cin >> n >> k >> p;
    vector<int> a(n);
    cin >> a;
    for (auto& x : a) {
        x %= p;
    }
    vector<vector<int>> f(n + 1, vector<int>(k + 1, -inf));
    f[0][0] = 0;
    // f[i][j] 前i个数组成j段的最大
    
    vector<vector<int>> pre(k + 1, vector<int>(p, -inf));
    pre[0][0] = 0;
    
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        sum += a[i - 1];
        sum %= p;
        for (int j = k; j > 0; j --) {
            // 枚举当前段的值
            for (int w = 0; w < p; w ++) {
                f[i][j] = max(f[i][j], pre[j - 1][(sum + p - w) % p] + w);
            }
            pre[j][sum] = max(pre[j][sum], f[i][j]);
        }
    }
    
    cout << f[n][k] << endl;
}