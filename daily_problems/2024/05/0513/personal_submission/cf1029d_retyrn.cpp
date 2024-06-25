int n, k;

int cal(int x) {
    int res = 0;
    while (x > 0) {
        res += 1;
        x /= 10;
    }
    return res;
}

void solve() {
    // f[i] a[i]后面填j个0以后对k的余数
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> f(n, vector<int>(11, 0));
    vector<umap<int, int>> mp(11);
    
    for (int i = 0; i < n; i ++) {
        f[i][0] = a[i] % k;
        for (int j = 1; j <= 10; j ++) {
            f[i][j] = (f[i][j - 1] * 10ll) % k;
            mp[j][f[i][j]] += 1;
        }
    }
    ll res = 0;
    // 枚举每个数作为后面的部分的组合
    for (int i = 0; i < n; i ++) {
        int len = cal(a[i]);
        int need = (k - a[i] % k) % k;
        if (mp[len].count(need))
            res += mp[len][need] - (f[i][len] == need ? 1 : 0);
    }
    cout << res << endl;
}