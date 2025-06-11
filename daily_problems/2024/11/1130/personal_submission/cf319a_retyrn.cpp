int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    
    ll res = 0;
    vector<ll> f(n + 1, 1);
    for (int i = 1; i <= n; i ++) {
        f[i] = f[i - 1] * 2 % mod;
    }
    
    // 左边第一位 2^(n-1)个0 2^(n-1)个1
    
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') {
            res += f[n - i - 1] * f[n - i - 1] % mod * f[i] % mod;
            res %= mod;
        }
    }
    cout << res << endl;
}