ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}
void solve() {
    cin >> x >> y;
    cin >> a >> b;
    n = sz(a), m = sz(b);
    
    ll L = lcm(n, m);
    
    // 计算长度为L的答案找相同的个数
    ll res = L;
    ll g = gcd(n, m);
    
    vector<vector<int>> cnt(g, vector<int>(26, 0));
    
    for (int i = 0; i < n; i ++) {
        cnt[i % g][a[i] - 'a'] += 1;
    }
    for (int i = 0; i < m; i ++) {
        res -= cnt[i % g][b[i] - 'a'];
    }
    
    res *= n * x / L;
    cout << res << endl;
}