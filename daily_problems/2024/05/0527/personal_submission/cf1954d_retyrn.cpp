int n;

void solve() {
    // 最大值如果大于等于其他所有球的个数 则为最大值个数
    // 否则的为总数除以2向上取整
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    int m = accumulate(all(a), 0);
    
    // f[i] 总球数为i有多少种取法
    vector<Z> f(m + 1, 0);
    f[0] = 1;
    Z res = 0;
    
    for (auto x : a) {
        for (int i = 0; i <= m; i ++) {
            if (x >= i) res += f[i] * x;
            else {
                res += (i + x + 1) / 2 * f[i];
            }
        }
        
        for (int i = m; i >= x; i --) {
            f[i] += f[i - x];
        }
    }
    
    cout << res << endl;
}