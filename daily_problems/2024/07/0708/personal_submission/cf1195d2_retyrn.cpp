int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i ++) {
        int x = a[i];
        while (x > 0) {
            v[i].push_back(x % 10);
            x /= 10;
        }
        reverse(all(v[i]));
    }
    
    vector<int> cnt(12);
    for (auto& vec : v) {
        cnt[sz(vec)] += 1;
    }
    ll res = 0;
    // 枚举每个数作为前面的数的贡献
    for (int i = 0; i < n; i ++) {
        auto& vec = v[i];
        for (int j = 1; j <= 10; j ++) {
            ll val = 0;
            int m = sz(vec);
            for (int k = 0; k < m; k ++) {
                val = val * 10 + vec[k];
                if (m - k <= j) val *= 10;
                val %= mod;
            }
            res = (res + val * cnt[j]) % mod;
        }
    }
    
    // 枚举每个数作为后面的数的贡献
    for (int i = 0; i < n; i ++) {
        auto& vec = v[i];
        for (int j = 1; j <= 10; j ++) {
            ll val = 0;
            int m = sz(vec);
            for (int k = 0; k < m; k ++) {
                if (m - k <= j) val *= 10;
                val = val * 10 + vec[k];
                val %= mod;
            }
            res = (res + val * cnt[j]) % mod;
        }
    }
    cout << res << endl;
}