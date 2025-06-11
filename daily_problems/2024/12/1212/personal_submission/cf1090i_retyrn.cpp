int n;
ll l, r, x, y, z, b1, b2;

void solve() {
    cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
    vector<ll> a(n);
    ll mask = (1ll << 32) - 1;
    
    a[0] = b1 % (r - l + 1) + l;
    a[1] = b2 % (r - l + 1) + l;
    ll res = numeric_limits<ll>::max();
    for (int i = 2; i < n; i ++) {
        ll b = (b1 * x + b2 * y + z) & mask;
        a[i] = b % (r - l + 1) + l;
        b1 = b2, b2 = b;
    }
    
    ll mn = a[0];
    
    for (int i = 1; i < n; i ++) {
        if (mn < a[i] and a[i] >= 0) chmin(res, mn * a[i]);
        chmin(mn, a[i]);
    }
    
    ll mx = a[n - 1];
    for (int i = n - 1; i >= 0; i --) {
        if (a[i] < mx and a[i] <= 0) chmin(res, mx * a[i]);
        chmax(mx, a[i]);
    }
    
    if (res == numeric_limits<ll>::max()) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << res << endl;
    }
}