int n, k, x;

void solve() {
    cin >> n >> x >> k;
    ll res = 0;
    vector<ll> a(n);
    cin >> a;
    
    if (k == 1 or k == 0) {
        for (auto y : a) {
            if ((y % x > 0) == (k ^ 1)) res += 1;
        }
    }
    
    map<ll, int> mp;
    for (auto y : a) {
        mp[y] = 0;
    }
    int idx = 0;
    for (auto& [_, v] : mp) {
        v = idx ++;
    }
    
    int m = idx;
    
    Fenwick<int> fen(m);
    for (auto y : a) {
        fen.add(mp[y], 1);
    }
    
    // 枚举每个数作为较小值
    for (auto val : a) {
        fen.add(mp[val], -1);
        ll base = (val % x == 0 ? val : val + (x - val % x));
        ll mn = base + (ll)(k - 1) * x;
        ll mx = mn + x - 1;
        if (k == 0) {
            if (val % x == 0) {
                fen.add(mp[val], 1);
                continue;
            }
            mx = base - 1;
            mn = val;
        }
        auto it1 = mp.lower_bound(mn);
        auto it2 = mp.upper_bound(mx);
        if (it1 != mp.end() and it2 != mp.begin()) {
            it2 --;
            int l = it1->se, r = it2->se;
            res += fen.rangeSum(l, r + 1);
        }
        fen.add(mp[val], 1);
    }
    cout << res << endl;
}