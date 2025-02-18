int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<ll> w(n);
    cin >> w;
    map<ll, vector<pii>> mp;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        ll t = w[x] ^ w[y];
        mp[t].emplace_back(x, y);
    }
    
    vector<ll> p(n + 1, 1ll);
    for (int i = 1; i <= n; i ++) {
        p[i] = p[i - 1] * 2 % mod;
    }
    
    DSU dsu(n);
    ll res = ((1ll << k) - sz(mp)) % mod * p[n] % mod;
    
    for (auto& [val, vec] : mp) {
        int con = n;
        for (auto& [x, y] : vec) {
            con -= dsu.merge(x, y);
        }
        res += p[con];
        res %= mod;
        
        for (auto& [x, y] : vec) {
            dsu.f[x] = x;
            dsu.siz[x] = 1;
            dsu.f[y] = y;
            dsu.siz[y] = 1;
        }
    }
    cout << res << endl;
}