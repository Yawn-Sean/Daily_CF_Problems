void solve() {
    vector<int> a(3);
    cin >> a;
    int mx = *max_element(all(a));
    vector<vector<int>> C(mx + 1, vector<int>(mx + 1, 0));
    
    C[0][0] = 1;
    for (int i = 1; i <= mx; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (j == 0) C[i][j] = 1;
            else {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
            }
        }
    }
    
    vector<ll> fact(mx + 1, 0);
    fact[0] = 1LL;
    for (int i = 1; i <= mx; i ++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    
    auto cal = [&](int x, int y) {
        ll ret = 0;
        for (int i = 0; i <= x and i <= y; i ++) {
            ll cur = (ll)C[x][i] * C[y][i] % mod * fact[i] % mod;
            ret = (ret + cur) % mod;
        }
        return ret;
    };
    
    ll res = 1;
    for (int i = 0; i < 3; i ++) {
        for (int j = i + 1; j < 3; j ++) {
            res *= cal(a[i], a[j]);
            res %= mod;
        }
    }
    cout << res << endl;
}