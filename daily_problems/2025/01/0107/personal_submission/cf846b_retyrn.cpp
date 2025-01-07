int n, m, k;

void solve() {
    cin >> n >> k >> m;
    vector<int> a(k);
    cin >> a;
    sort(all(a));
    
    int sum = accumulate(all(a), 0);
    // 枚举全部完成的任务
    ll res = 0;
    
    for (int i = 0; i <= m / sum and i <= n; i ++ ) {
        int left = m - i * sum;
        ll cur = i * (k + 1);
        for (int j = 0; j < k; j ++) {
            int need = min(n - i, left / a[j]);
            cur += need;
            left -= need * a[j];
        }
        chmax(res, cur);
    }
    
    cout << res << endl;
}