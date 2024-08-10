int n;

void solve() {
    cin >> n;
    vector<string> g(n);
    cin >> g;
    
    // 只需要记录对角线上的1的个数
    int sum = 0;
    for (auto& s : g) {
        for (auto& c : s) {
            sum += (c == '1');
        }
    }
    vector<int> cnt(n * 2);
    
    auto cal = [&]() {
        int mn = (n + sum - cnt[n] * 2);
        for (int i = 1, j = n + 1; i < n; i ++, j ++) {
            chmin(mn, n + sum - (cnt[i] + cnt[j]) * 2);
        }
        return mn;
    };
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cnt[i - j + n] += (g[i][j] - '0');
        }
    }
    int res = inf;
    
    // 开始变换行
    for (int i = 0; i < n; i ++) {
        chmin(res, cal());
        for (int j = 0; j < n; j ++) {
            cnt[0 - j + n] -= (g[i][j] - '0');
        }
        for (int k = 1; k + 1 < n * 2; k ++) {
            cnt[k] = cnt[k + 1];
        }
        cnt[n * 2 - 1] = 0;
        for (int j = 0; j < n; j ++) {
            cnt[n - 1 - j + n] += (g[i][j] - '0');
        }
    }
    cout << res << endl;
}