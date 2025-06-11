int n;

void solve() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    // 预处理2的幂次
    vector<ll> f(n + 1);
    f[0] = 1ll;
    for (int i = 1; i <= n; i ++) {
        f[i] = f[i - 1] * 2 % mod;
    }
    
    // 贡献
    ll res = 0;
    for (int i = 1; i <= n; i ++) {
        res = (res + f[n - i] * a[i]) % mod;
        if (i < n) res = (res + f[n - i - 1] * (n - i) % mod * a[i]) % mod;
    }
    cout << res << endl;
}