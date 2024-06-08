void solve() {
    cin >> n >> k >> l >> mod;
    if (mod == 1 or (l < 63 and k >= (1LL << l))) {
        cout << 0 << endl;
        return;
    }
    if (k > 0 and l == 0) {
        cout << 0 << endl;
        return;
    }
    ll res = 1;
    
    vector<vector<ll>> a = {{1, 1}, {1, 0}};
    vector<vector<ll>> f = {{2, 1}};
    
    auto ans = mat_pow(a, n - 2, mod);
    ans = mat_mul(f, ans, mod);
    
    auto x = (ans[0][0] + ans[0][1]) % mod;
    auto y = (powmod(2, n, mod) - x + mod) % mod;
    
    for (int i = 0; i < l; i ++) {
        if (!(k >> i & 1)) {
            res *= x;
            res %= mod;
        }
        else {
            res *= y;
            res %= mod;
        }
    }
    cout << res << endl;
}