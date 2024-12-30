int n;

void solve() {
    cin >> n;
    // 首先计算一共多少条直线
    vector<pii> a(n);
    cin >> a;
    
    map<Frac<ll>, set<Frac<ll>>> mp;
    set<int> ver;
    
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            int dx = a[i].fi - a[j].fi;
            int dy = a[i].se - a[j].se;
            if (dx == 0) {
                ver.insert(a[i].fi);
                continue;
            }
            Frac<ll> k(dy, dx);
            Frac<ll> b = Frac<ll>(a[i].se) - Frac<ll>(a[i].fi) * k;
            mp[k].insert(b);
        }
    }
    
    int sum = sz(ver);
    ll res = -(ll)sz(ver) * (sz(ver) - 1) / 2;
    for (auto& [k, S] : mp) {
        sum += sz(S);
        res -= (ll)sz(S) * (sz(S) - 1) / 2;
    }
    res += (ll)sum * (sum - 1) / 2;
    cout << res << endl;
}