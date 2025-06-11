ll cal(ll x) {
    if (x == 0) return 0LL;
    int u = std::__lg(x) + 1;
    // 一共u位
    // 少于u位的都可以随便取
    ll res = 0;
    vector<vector<ll>> f(u + 1, vector<ll>(u + 1)); // f[i][j] 长度为i 最短循环节长度为j的个数
    for (int i = 1; i < u; i ++) {
        for (int j = 1; j < i; j ++) {
            if (i % j) continue;
            f[i][j] += (1ll << j - 1);
            // 减去更短的循环节
            for (int k = 1; k < j; k ++) {
                if (j % k == 0) f[i][j] -= f[i][k];
            }
            res += f[i][j];
        }
    }
    
    // 长度为u
    for (int j = 1; j < u; j ++) {
        if (u % j) continue;
        ll last = (x >> u - j);
        f[u][j] += max(0LL, last - (1ll << j - 1));
        ll y = 0;
        for (int k = 0; k < u / j; k ++) {
            y = y << j | last;
        }
        if (x >= y) f[u][j] += 1;
        for (int k = 1; k < j; k ++) {
            if (j % k == 0) f[u][j] -= f[u][k];
        }
        
        res += f[u][j];
    }
    
    return res;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << cal(r) - cal(l-1) << endl;
}