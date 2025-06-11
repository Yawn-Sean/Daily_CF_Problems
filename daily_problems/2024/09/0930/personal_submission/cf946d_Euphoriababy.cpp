auto solve = [] () {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> nums;
    fw(i, 0, n) {
        string s;
        cin >> s;
        vector<ll> a;
        fw(j, 0, m) {
            if(s[j] == '1') a.pb(j);
        }
        if(!a.empty()) nums.pb(a);
    }
    n = nums.size();
    vector<vector<ll>> dp;
    for(ll i = 0; i < n; i += 1) {
        ll l = nums[i].size();
        vector<ll> a(l + 1, 1e18);
        a[l] = 0;
        for(ll j = 0; j < l; j += 1) {
            for(ll o = j; o < l; o += 1) {
                // [j, o]
                a[l - (o - j + 1)] = lmin(a[l - (o - j + 1)], nums[i][o] - nums[i][j] + 1);
            }
        }
        dp.pb(a);
    }
    vector<vector<ll>> f(n + 1, vector<ll> (k + 1, 1e18));
    for(ll j = 0; j <= k; j += 1) f[n][j] = 0;
    for(ll i = n - 1; i >= 0; i -= 1) {
        for(ll cnt = k; cnt >= 0; cnt -= 1) {
            ll l = nums[i].size();
            // 枚举选几个
            for(ll j = 0; j <= l; j += 1) {
                if(cnt + j > k) break;
                f[i][cnt] = lmin(f[i][cnt], f[i + 1][cnt + j] + dp[i][j]);
            }
        }
    }
    cout << f[0][0] << endl;
};
