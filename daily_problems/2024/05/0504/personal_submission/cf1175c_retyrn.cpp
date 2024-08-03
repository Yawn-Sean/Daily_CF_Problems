int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    
    // 枚举x 只和最近的k+1个点有关, 是一段区间
    int mn = inf, res = -1;
    for (int i = k; i < n; i ++) {
        int val = (a[i] - a[i - k] + 1) / 2;
        if (val < mn) {
            mn = val;
            res = a[i - k] + val;
        }
    }
    cout << res << endl;
}