int n;

void solve() {
    // 初始朝向差180度 才可能对视
    // 记录向量
    cin >> n;
    map<pii, int> mp;
    
    for (int i = 0; i < n; i ++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c -= a;
        d -= b;
        if (c == 0) d /= abs(d);
        else if (d == 0) c /= abs(c);
        else {
            auto t = gcd(abs(c), abs(d));
            c /= t;
            d /= t;
        }
        mp[mpr(c, d)] += 1;
    }
    
    ll res = 0;
    for (auto [p, v] : mp) {
        auto x = p.fi, y = p.se;
        if (mp.count(mpr(-x, -y)))
            res += (ll)v * mp[mpr(-x, -y)];
    }
    res >>= 1;
    cout << res << endl;
}