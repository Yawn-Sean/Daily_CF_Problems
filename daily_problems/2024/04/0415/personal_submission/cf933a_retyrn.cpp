int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    // 答案应该是 一段1 + 一段2 + 一段1 + 一段2
    vector<vector<int>> s(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1];
        s[i][a[i - 1] - 1] += 1;
    }
    
    vector<int> f(n + 1, 0); // f[i] 前i个数字 中一段1+一段2的最长长度
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= i; j ++) {
            f[i] = max(f[i], s[j][0] + s[i][1] - s[j][1]);
        }
    }
    
    int res = 0;
    for (int i = 0; i <= n; i ++) {
        // 后面取 2 1 的长度为n-i
        for (int j = 0; j <= n - i; j ++) {
            res = max(res, f[i] + s[i + j][0] - s[i][0] + s[n][1] - s[i + j][1]);
        }
    }
    cout << res << endl;
}